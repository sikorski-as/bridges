//#include <cassert>
#include <cstdio>
#include <iostream>
#include "../src/Graph.hpp"

using namespace aisdi;
using namespace std;

#define TEST_CASE(name) cout << (name) << ":" << endl;
#define TEST_DONE() cout << endl
#define ASSERT(condition) if(!(condition)) cout << "\tAssertion failed \"" << #condition << "\" in " << __FILE__ << " @ line " << __LINE__ << "." << endl; else cout << "\tAssertion successful." << endl
#define TEST_MSG(msg) cout << "\t" << #msg << endl

int main()
{
	cout << "=================================================================================" << endl;
	cout << "Running tests..." << endl << endl;
	
	TEST_CASE("Graph constructed with zero vertices has no vertices")
	{
		Graph graph(0);
		ASSERT(graph.getNumberOfVertices() == 0);
	}
	TEST_DONE();
	
	TEST_CASE("Graph constructed with 1 vertex has 1 vertex")
	{
		Graph graph(1);
		ASSERT(graph.getNumberOfVertices() == 1);
	}
	TEST_DONE();
	
	TEST_CASE("Constructed graph has no edges")
	{
		Graph graph(0);
		ASSERT(graph.getNumberOfEdges() == 0);
	}
	TEST_DONE();
	
	TEST_CASE("When an edge is added, the graph has only one edge")
	{
		Graph graph(2);
		graph.addEdge(0, 1);
		ASSERT(graph.getNumberOfEdges() == 1);
	}
	TEST_DONE();
	
	TEST_CASE("Number of vertices changes after graph resizing")
	{
		Graph graph(2);
		graph.resize(3);
		ASSERT(graph.getNumberOfVertices() == 3);
	}
	TEST_DONE();
	
	TEST_CASE("Number of edges changes to zero after graph resizing")
	{
		Graph graph(2);
		graph.resize(3);
		ASSERT(graph.getNumberOfEdges() == 0);
	}
	TEST_DONE();
	
	TEST_CASE("Graph contains the added edge")
	{
		Graph graph(2);
		graph.addEdge(0, 1);
		ASSERT(graph.areConnected(0, 1));
		ASSERT(graph.areConnected(1, 0));
	}
	TEST_DONE();
	
	TEST_CASE("Graph with 3 vertices contains vertex with ID 2")
	{
		Graph graph(3);
		ASSERT(graph.isInGraph(2));
	} TEST_DONE();
	
	TEST_CASE("Graph with 3 vertices does not contain vertex with ID 3")
	{
		Graph graph(3);
		ASSERT(!graph.isInGraph(3));
	} TEST_DONE();
	
	TEST_CASE("Graph has no edges when the only edge is removed")
	{
		Graph graph(2);
		graph.addEdge(0, 1);
		graph.removeEdge(0, 1);
		
		ASSERT(graph.getNumberOfEdges() == 0);
	} TEST_DONE();
	
	TEST_CASE("Each vertex has an expected number of neighbours")
	{
		Graph graph(3);
		graph.addEdge(0, 1);
		
		ASSERT(graph.getNumberOfNeighbours(0) == 1);
		ASSERT(graph.getNumberOfNeighbours(1) == 1);
		ASSERT(graph.getNumberOfNeighbours(2) == 0);
		
		graph.addEdge(1, 2);
		
		ASSERT(graph.getNumberOfNeighbours(0) == 1);
		ASSERT(graph.getNumberOfNeighbours(1) == 2);
		ASSERT(graph.getNumberOfNeighbours(2) == 1);
		
	} TEST_DONE();
	
	// 11 tests so far
	
	cout << endl << "Tests finished." << endl;
	cout << "=================================================================================" << endl;
	
	return 0;
}