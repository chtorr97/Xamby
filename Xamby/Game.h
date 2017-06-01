#pragma once

#include "MyECS\Asset.h"

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

