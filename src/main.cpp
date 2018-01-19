#include <cstdio>
#include "Graph.hpp"

using namespace aisdi;
int main()
{
	Graph::size_type N = 5;
	Graph graph(N);
	graph.areConnected(0, 1);
	return 0;
}