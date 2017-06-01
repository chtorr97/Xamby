#pragma once

#include <memory>
#include <iostream>
#include <bitset>
#include <unordered_map>

#include "ComponentsManager.h"

using comp::compType;

class Entity
{
public:
	Entity();
	Entity(ComponentsManager& _CM);
	~Entity();

	void setComponentManager(ComponentsManager& _CM);

	void setID(int newID);
	int getID();

	bitset<compType::NUMBER_OF_COMPONENTS> getMask();

	bool isActive();
	void activate();
	void deactivate();

	void setTag(string newTag);
	string getTag();

	template<class T>
	bool has();

	template<class T>
	bool add();

	template<class T>
	void remove();

	template<class T>
	T& get();

	//Release all the components
	void dispose();

private:
	bitset<compType::NUMBER_OF_COMPONENTS> mask;
	int ID;
	unordered_map<int, int> componentIndex;
	ComponentsManager* CM;
	string tag;
};

template<class T>
inline bool Entity::has()
{
	return componentIndex.find(T::getType()) != componentIndex.end();
}

template<class T>
inline bool Entity::add()
{
	if (has<T>())
		return false;
	componentIndex[T::getType()] = CM->add<T>();
	mask |= comp::maskOf(T::getType());
	return true;
}

template<class T>
inline void Entity::remove()
{
	if (has<T>())
	{
		CM->remove(componentIndex[T::getType()]);
		componentIndex.erase(T::getType());
		mask = mask & ~comp::maskOf(T::getType());
	}
	else
		cerr << "ID doesn't have component " << T::getType() << endl;
}

template<class T>
inline T & Entity::get()
{
	if (has<T>())
	{
		return CM->get<T>(componentIndex[T::getType()]);
	}
	cerr << "ID doesnt have component " << T::getType() << endl;
	T a;
	return a;
}
