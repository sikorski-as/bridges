#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <vector>
#include "Graph.hpp"
#include "LongBridges.hpp"

namespace aisdi
{
	
class Interface
{
public:	
	void readInputTo(Graph&);
	void printOutputFrom(LongBridges::list);	
};

}
#endif