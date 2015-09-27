#pragma once

#include "Window\Window.h"

class Game
{
	Window* load;
public:
	Game();					
	~Game();

	int GameWindow(char* name);
	
};

