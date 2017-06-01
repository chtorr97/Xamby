#pragma once

#include <vector>
#include <set>
#include <iostream>

#include "Components\Components.h"

using namespace std;

class ComponentsManager
{
public:
	ComponentsManager();
	~ComponentsManager();

	template<class T>
	int add();

	template<class T>
	T& get(int index);

	void remove(int index);

private:
	vector<comp::compVar> components;
	set<int> freeIndex;

	int popPool();
};

template<class T>
inline T & ComponentsManager::get(int index)
{
	return boost::get<T>(components.at(index));
}

template<class T>
inline int ComponentsManager::add()
{
	int componentIndex = -1;
	if (!freeIndex.empty())
	{
		componentIndex = popPool();
	}
	else
	{
		components.resize(components.size() + 1);
		componentIndex = components.size() - 1;
	}
	//components.at(componentIndex).element = T();
	get<T>(componentIndex).init();
	return componentIndex;
}
