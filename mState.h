#pragma once

#include <stack>
#include <vector>
#include <iterator>
#include "mProcess.h"

using namespace std;


enum States
{
	start = 0,				//загрузка игры, код состояния 0 (последующие коды будут увеличиваться на 1)
	loadscreen,				//заставка
	menu,					//меню
	play,					//главное состояние игры, игровой процесс
	pause					//пауза
};


class mState
{
	int current;										//текущее состояние
	stack <int> stateSt;								//стек состояний
	vector <mProcess> process;							//вектор процессов класса mProcess
public:
	mState();											//присваивает по умолчанию код 0 текущему состоянию			
	~mState();

	void setTopState(int state, void(*example) (int));		//добавляет состояние игры в стек 
	int setCurrent(int state, void(*example) (int));		//устанавливает текущее состояние игры, без записи в стек

	void closeTopState();								//завершает работу верхнего в стеке состояния игры
	void closeCurrent();								//завершает работу состояния игры вне стека, возвращаясь в стек

	int getCurrent();									//возвращает текущее состояние игры
	int getQuant();										//возвращает количество рабочих состояний в стеке (количество в стеке)
};
