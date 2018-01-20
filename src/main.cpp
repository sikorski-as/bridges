#include <iostream>
#include "Graph.hpp"
#include "Interface.hpp"
#include "LongBridges.hpp"

using namespace aisdi;
int main()
{
	
	Graph graph(0);
	Interface interface;
	interface.readInputTo(graph);
	
	LongBridges finder;
	
	interface.printOutputFrom(finder.findLongBridges(graph));
	
	
	return 0;
}