#include <iostream>
#include <algorithm>
#include "Interface.hpp"
#include "LongBridges.hpp"

namespace aisdi
{
	void Interface::readInputTo(Graph & graph)
	{
		int n;
		std::cin >> n;
		
		graph.resize(n);
		
		Graph::size_type v1, v2; 
		while(std::cin >> v1)
		{
			std::cin >> v2;
			graph.addEdge(v1, v2);
		}
	}
	
	void Interface::printOutputFrom(LongBridges::list listOfLongBridges)
	{
		for(auto &pair: listOfLongBridges)
		{
			std::cout << pair.first << " " << pair.second << std::endl;
		}
	}
}