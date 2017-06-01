#pragma once

#include <Box2D\Box2D.h>

#include "Component.h"

class Physic :
	public Component
{
public:
	Physic();
	~Physic();

	static comp::compType getType();

	static b2World* getWorld();
	static void setWorld(b2World& newWorld);

	b2Body& getBodyRef();
	void setBody(const b2BodyDef& definition);

	void init() override;

private:
	static b2World* world;
	b2Body* body;
};

