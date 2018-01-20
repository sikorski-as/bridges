#ifndef LONGBRIDGES_HPP
#define LONGBRIDGES_HPP

#include <vector>
#include <utility>
#include "Graph.hpp"

namespace aisdi
{
	
class LongBridges
{
public:
	using list = std::vector< std::pair<Graph::vertex, Graph::vertex> >;

	const list & findLongBridges(const Graph & graph);
	bool checkIfLongBridge(const Graph &, Graph::vertex, Graph::vertex);
private:
	list listOfLongBridges;
};

}
#endif