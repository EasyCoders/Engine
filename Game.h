#pragma once

#include "Window.h"
#include "Config.h"
#include "mState.h"

class Game
{
	Config objCon;								//создаём обьект конфигурации окна
	Window* load;								//указательна обьект менеджирования окна
	mState gameState;							//cоздаём обьект менеджера состояний							
public:
	Game(Config Con, void (*example)(int));		//конструктор принимающий конфигурацию окна игры и функцию 
												//на исполнение которая будет загружена в менеджер состояний			
	~Game();

	void GameWindow();							//создаёт окно по данным обьекта конфигурации objCon
};

