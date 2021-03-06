#pragma once

#include "Asset.h"

class Game
{
public:
	Game();
	~Game();

	void init();

	void run();

	int stop();

private:
	b2World world;
	EntityManager em;
};

