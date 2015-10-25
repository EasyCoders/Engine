#pragma once

#include <iostream>
#include "ModuleBase.h"
using namespace std;

enum ProcessState
{
	hover = 0,									//ожидание
	active = 1									//активный
};

class mProcess
{
	ModuleBase *obj;						    //указател ть на функцию - хранит адресс функции процесса
	int stateProcess;							//состояние процесса		
public:
	mProcess();
	mProcess(ModuleBase *_obj);					//конструктор принимающий указатель на функцию
	

	int getState();								//возвращает идентификатор состояния процесса
	void setState(int state);					//устанавливает идентификатор состояния процесса
	
	void setRuntimeObject(ModuleBase *_obj);		//альтернатива конструктору
	
	int runFunc();								//запускает процесс на выполнение

};
