#include "ComponentsManager.h"

ComponentsManager::ComponentsManager()
{
}

ComponentsManager::~ComponentsManager()
{
}

void ComponentsManager::remove(int index)
{
	freeIndex.insert(index);
}

int ComponentsManager::popPool()
{
	int tmp = *freeIndex.begin();
	freeIndex.erase(freeIndex.begin());
	return tmp;
}