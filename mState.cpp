#include "stdafx.h"
#include "mState.h"
#include <cstdlib>

mState::mState()
{
	current = 0;
}


mState::~mState()
{
}


void mState::setTopState(int state, ModuleBase *obj)		
{		
	stateSt.push(state);										//добавляем новое состояние игры в стек
	current = state;											//устанавливаем идентификатор текушего состояния
																
	mProcess objProcess(obj);								    //создаём обьект процесса и передаём ему указатель на функцию

	process.insert(process.end(), objProcess);					//добавляём процесс в вектор процессов используя средства итератора
	objProcess.runFunc();										//запускаём функцию (процесс)				
}

// данная функция, возможно будет подвержена рефакторингу, после перестройки ядра
int mState::setCurrent(int state, ModuleBase *obj)			    //из алгоритма setTopState убрано добавление состояния в стек 
{																
	mProcess objProcess(obj);

	process.insert(process.end(), objProcess);

	objProcess.runFunc();
	current = state;


	return 1;
}


void mState::closeTopState()
{
	stateSt.pop();										//выгружаем верхнее состояние из стека
	if (stateSt.empty())								//если стек остался пуст, завершаем с кодом 1
	{
		exit(1);
	}
	current = stateSt.top();							//верхнее состояние в стеке становится текущим состоянием игры
}

void mState::closeCurrent()
{
	current = stateSt.top();							//в процессе доработки ядра это место, еще будет дорабатыватся
}

int mState::getCurrent()
{
	return current;										
}

int mState::getQuant()
{
	return stateSt.size();
}



