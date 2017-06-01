#include "Game.h"

Game::Game()
	:world(b2Vec2(0, 0))
{
}


Game::~Game()
{
}

void Game::init()
{
	cout << sizeof(Physic) << " " << sizeof(Graphic);
	int x;
	cin >> x;
	Physic::setWorld(world);
}

void Game::run()
{
}

int Game::stop()
{
	return 0;
}
