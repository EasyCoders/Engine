#include "stdafx.h"
#include "mProcess.h"
#include <thread>

using namespace std;

mProcess::mProcess()
{
	stateProcess = 1;							//возможен рефакторинг данной части кода
}

mProcess::mProcess(ModuleBase *_obj)
{
	obj = _obj;
	stateProcess = 1;							//присваиваем состоянию процесса статус "активный"			
}



int mProcess::getState()
{
	return stateProcess;
}

void mProcess::setState(int state)
{
	stateProcess = state;
}

void mProcess::setRuntimeObject(ModuleBase *_obj)
{
	obj = _obj;
}

int mProcess::runFunc()
{
	thread stream(&ModuleBase::method, obj);	//передаём адресс метода и адресс вызывающего этот метод объекта в поток (объект thread)
	stream.detach();							//отсоединяем данный поток от дескриптора его вызова (от главного потока) 
												//метод detach на данный момент является источником описанной в Core.cpp проблемы
	return 1;									
}
