#pragma once

#include "Window\Window.h"
#include <iostream>

class Game
{
	Window* load;
public:
	Game();					
	~Game();

	int GameWindow(char* name);
	
};

