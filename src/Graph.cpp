#include <stdexcept>
#include <algorithm>
#include "Graph.hpp"

namespace aisdi
{
	Graph::Graph(size_type numberOfVertices)
	: numberOfVertices(numberOfVertices), numberOfEdges(0), neighbourList(numberOfVertices)
	{
		
	}
	
	void Graph::resize(size_type newNumberOfVertices)
	{
		neighbourList.clear();
		neighbourList.resize(newNumberOfVertices);
		numberOfVertices = newNumberOfVertices;
	}
	
	void Graph::addEdge(vertex firstVertex, vertex secondVertex)
	{
		if(areConnected(firstVertex, secondVertex))
			throw std::logic_error("Attempt to add an edge that already exists in the graph.");
		if(firstVertex == secondVertex)
			throw std::logic_error("A vertex cannot be connected to itself.");
		
		neighbourList[firstVertex].push_back(secondVertex);	
		neighbourList[secondVertex].push_back(firstVertex);	
		
		numberOfEdges++;
	}
	
	void Graph::removeEdge(vertex firstVertex, vertex secondVertex)
	{
		if(!areConnected(firstVertex, secondVertex))
			throw std::logic_error("Attempt to remove an edge that is not in the graph.");
		
		auto iteratorOfFirstVertex = std::find(neighbourList[firstVertex].begin(), neighbourList[firstVertex].end(), secondVertex);
		auto iteratorOfSecondVertex = std::find(neighbourList[secondVertex].begin(), neighbourList[secondVertex].end(), firstVertex);
		
		neighbourList[firstVertex].erase(iteratorOfFirstVertex);
		neighbourList[secondVertex].erase(iteratorOfSecondVertex);
		
		numberOfEdges--;
	}
	
	bool Graph::isInGraph(vertex theVertex) const
	{
		return theVertex < numberOfVertices;
	}
	
	bool Graph::areConnected(vertex firstVertex, vertex secondVertex) const
	{
		if(!isInGraph(firstVertex) || !isInGraph(secondVertex))
			throw std::logic_error("Vertex with such ID does not exist.");
		
		auto iteratorOfFoundElement = std::find(neighbourList[firstVertex].begin(), neighbourList[firstVertex].end(), secondVertex);
		return iteratorOfFoundElement != neighbourList[firstVertex].end();
	}
	
	Graph::size_type Graph::getNumberOfVertices() const
	{
		return numberOfVertices;
	}
	
	Graph::size_type Graph::getNumberOfEdges() const
	{
		return numberOfEdges;
	}
	
	Graph::neighbour_list Graph::getListOfNeighbours(vertex theVertex) const
	{
		if(!isInGraph(theVertex))
			throw std::logic_error("Vertex with such ID does not exist.");
		return neighbourList[theVertex];
	}
	
	Graph::size_type Graph::getNumberOfNeighbours(vertex theVertex) const
	{
		if(!isInGraph(theVertex))
			throw std::logic_error("Vertex with such ID does not exist.");
		return neighbourList[theVertex].size();
	}
}