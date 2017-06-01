#pragma once

namespace comp
{
	enum compType
	{
		NONE = -1,
		IS_ACTIVE,
		PHYSIC,
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

