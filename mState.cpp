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


void mState::setTopState(int state, void(*example) (int))
{
	stateSt.push(state);
	current = state;

	mProcess objProcess(example);

	process.insert(process.end(), objProcess);

}


int mState::setCurrent(int state, void(*example) (int))
{
	mProcess objProcess(example);

	process.insert(process.end(), objProcess);

	objProcess.runFunc();
	current = state;


	return 1;
}


void mState::closeTopState()
{
	stateSt.pop();
	if (stateSt.empty())
	{
		exit(1);
	}
	current = stateSt.top();
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


