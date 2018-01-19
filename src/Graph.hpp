#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace aisdi
{
	
class Graph
{
public:	
	using size_type = std::size_t;
	using vertex = std::size_t;
	using neighbour_list = std::vector<vertex>;
	
	Graph(size_type);
	
	void resize(size_type);
	void addEdge(vertex, vertex);
	void removeEdge(vertex, vertex);
	
	bool isInGraph(vertex) const;
	bool areConnected(vertex, vertex) const;
	size_type getNumberOfVertices() const;
	size_type getNumberOfEdges() const;
	neighbour_list getListOfNeighbours(vertex) const;
	size_type getNumberOfNeighbours(vertex) const;
	
private:
	size_type numberOfVertices;
	size_type numberOfEdges;
	std::vector<neighbour_list> neighbourList;
};

}
#endif