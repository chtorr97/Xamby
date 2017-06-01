#pragma once

#include "Component.h"

class Graphic :
	public Component
{
public:
	Graphic();
	~Graphic();

	static comp::compType getType();

	// Inherited via Component
	virtual void init() override;

private:
	Texture* tex;
	Sprite sprite;
};

