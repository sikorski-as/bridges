#include <utility>
#include <functional>
#include "LongBridges.hpp"

namespace aisdi
{	
	
	const LongBridges::list & LongBridges::findLongBridges(const Graph & graph)
	{
		listOfLongBridges.clear();
		auto numberOfVertices = graph.getNumberOfVertices();
		if(numberOfVertices <= 3)
			return listOfLongBridges; // graf spojny
		
		std::vector<bool> allNeighboursAreChecked(numberOfVertices, false);
		for(Graph::vertex aVertex = 0; aVertex < numberOfVertices; aVertex++)
		{
			for(auto & aNeighbour: graph.getListOfNeighbours(aVertex))
			{
				if(!allNeighboursAreChecked[aNeighbour])
					if(checkIfLongBridge(graph, aVertex, aNeighbour))
						listOfLongBridges.push_back(std::make_pair(aVertex, aNeighbour));
			}
			
			allNeighboursAreChecked[aVertex] = true;
		}
		
		return listOfLongBridges;
	}
	
	bool LongBridges::checkIfLongBridge(const Graph & graph, Graph::vertex first, Graph::vertex second)
	{
		/*
			znajdz dowolnego sasiada S wierzcholka first (S != second)
			lub dowolnego sasiada S wierzcholka second (S != first)
			odpal na nim DFSa
			i sprawdz czy DFS(...) < |V|-2
			jest warunek spelniony, to (first, second) jest mostem rozleglym
			w przeciwnym razie nie jest
		*/
		
		auto numberOfVertices = graph.getNumberOfVertices();
		std::vector<bool> visitedList(numberOfVertices, false);
		visitedList[first] = true;
		visitedList[second] = true;
		
		std::function<Graph::size_type(Graph::size_type)> 
		DFS = [&DFS, &graph, &visitedList](Graph::vertex aVertex) -> Graph::size_type // zwraca, ile wierzcholkow przeszlo
		{
			visitedList[aVertex] = true;
			Graph::size_type sumOfVisited = 1;
			for(auto & neighbour: graph.getListOfNeighbours(aVertex))
			{
				if(!visitedList[neighbour])
					sumOfVisited += DFS(neighbour);
			}
			return sumOfVisited;
		};
		
		bool vertexFound = false;
		Graph::vertex vertexForDFS;
		
		for(auto & neighbour: graph.getListOfNeighbours(first))
		{
			if(neighbour != second)
			{
				vertexFound = true;
				vertexForDFS = neighbour;
			}
		}
		if(!vertexFound)
		{
			for(auto & neighbour: graph.getListOfNeighbours(second))
			{
				if(neighbour != first)
				{
					vertexFound = true;
					vertexForDFS = neighbour;
				}
			}
		}
		
		if(DFS(vertexForDFS) < graph.getNumberOfVertices() - 2)
			return true;
		
		return false;
	}	
}