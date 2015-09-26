#pragma once

#include <iostream>
using namespace std;

enum ProcessState
{
	hover = 0,									//ожидание
	active = 1									//активный
};

class mProcess
{
	void (*function) (int);						//указател ть на функцию - хранит адресс функции процесса
	int stateProcess;							//состояние процесса		
public:
	mProcess();
	mProcess(void (*p) (int));
	

	int getState();								//возвращает идентификатор состояния процесса
	void setState(int state);					//устанавливает идентификатор состояния процесса
	
	void setFunction(void(*example) (int));
	
	int runFunc();

};
