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
	Physic::setWorld(world);
}

void Game::run()
{
}

int Game::stop()
{
	return 0;
}
