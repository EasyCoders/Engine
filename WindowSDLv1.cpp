// WindowSDLv1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <SDL.h>
#include "Game.h"
#include <SDL_image.h>

Game* g_game = 0;
int main(int argc, char* args[])
{

	g_game = new Game;
	g_game->init("Chapter 1", 200, 200, 640, 480, SDL_WINDOW_SHOWN);
	//инициализирует окно заголовое, х позиция, у позиция, ширина, высота, флаги(их может быть несколько, указавать через "|") 

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}
