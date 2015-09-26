#include "stdafx.h"
#include "mProcess.h"
#include <thread>

using namespace std;

mProcess::mProcess()
{
	stateProcess = 1;			//?	
	function = NULL;
}

mProcess::mProcess(void (*example) (int))
{
	function = example;
	stateProcess = 1;
}



int mProcess::getState()
{
	return stateProcess;
}

void mProcess::setState(int state)
{
	stateProcess = state;
}

void mProcess::setFunction(void(*example)(int))
{
	function = example;
}

int mProcess::runFunc()
{
	(*function) (8);
	return 1;
}

