#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

namespace comp
{
	enum compType
	{
		NONE = -1,
		IS_ACTIVE,
		PHYSIC,
		GRAPHIC,
		NUMBER_OF_COMPONENTS
	};
}

class Component
{
public:
	Component();
	~Component();

	virtual void init() = 0;
};

