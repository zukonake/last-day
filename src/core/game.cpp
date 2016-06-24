#include "game.hpp"

int Game::start()
{
	isRunning = true;
	return loop();
}

int Game::loop()
{
	while( isRunning )
	{
		userInterfaceProxy.render();
		isRunning = userInterfaceProxy.handleEvents();
		//userInterfaceProxy.clear();
	}
	return end();
}

int Game::end()
{
	return 0;
}

Game::Game() :
	userInterfaceProxy()
{

}

Game::~Game()
{

}
