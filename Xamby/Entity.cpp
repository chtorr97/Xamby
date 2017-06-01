#include "Entity.h"

Entity::Entity()
	: mask(0)
{
}

Entity::Entity(ComponentsManager& _CM)
	: CM(&_CM), mask(0)
{
}

Entity::~Entity()
{
}

void Entity::setComponentManager(ComponentsManager & _CM)
{
	CM = &_CM;
}

void Entity::setID(int newID)
{
	ID = newID;
}

int Entity::getID()
{
	return ID;
}

bitset<compType::NUMBER_OF_COMPONENTS> Entity::getMask()
{
	return mask;
}

bool Entity::isActive()
{
	return mask[compType::IS_ACTIVE];
}

void Entity::activate()
{
	mask |= comp::maskOf(compType::IS_ACTIVE);
}

void Entity::deactivate()
{
	mask = mask & ~comp::maskOf(compType::IS_ACTIVE);
}

void Entity::setTag(string newTag)
{
	tag = newTag;
}

string Entity::getTag()
{
	return tag;
}

void Entity::dispose()
{
	mask = comp::maskOf(compType::NONE);

	for (int k = 0; k < componentIndex.size(); k++)
	{
		if (componentIndex.find(k) != componentIndex.end())
		{
			CM->remove(componentIndex[k]);
		}
	}
	componentIndex.clear();
}
