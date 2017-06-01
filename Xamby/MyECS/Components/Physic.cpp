#include "Physic.h"

b2World* Physic::world = nullptr;

Physic::Physic()
{
}

Physic::~Physic()
{
}

void Physic::setWorld(b2World & newWorld)
{
	Physic::world = &newWorld;
}

b2World* Physic::getWorld()
{
	return Physic::world;
}

b2Body & Physic::getBodyRef()
{
	return *body;
}

void Physic::setBody(const b2BodyDef & definition)
{
	body = world->CreateBody(&definition);
}

comp::compType Physic::getType()
{
	return comp::PHYSIC;
}

void Physic::init()
{
}
