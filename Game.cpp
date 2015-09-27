#include "stdafx.h"
#include "Game.h"


Game::Game(Config Con, void (*example) (int))
{
	objCon = Con;
	load = new Window;
	gameState.setCurrent(start, example);
}


Game::~Game()
{
	load->clean();
}

void Game::GameWindow()
{
	load->init(objCon.windowName, objCon.xStart, objCon.yStart, objCon.length, objCon.width, SDL_WINDOW_SHOWN);
	while (load->running())
	{
		load->handleEvents();
		load->update();
		load->render();
	}
}
