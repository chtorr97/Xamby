#pragma once

#include <SFML\Graphics.hpp>
#include <boost\variant.hpp>
#include <bitset>
#include <vector>

#include "Physic.h"

using namespace std;
using namespace sf;

class Entity;

namespace comp
{
	using compVar = boost::variant<
		Physic
	>;

	static bitset<NUMBER_OF_COMPONENTS> maskOf(compType type)
	{
		return bitset<NUMBER_OF_COMPONENTS>(1 << type);
	}
}