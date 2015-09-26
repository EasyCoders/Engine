// Core.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "mState.h"


using namespace std;

void f1()
{
	while (true)
	{
		cout << "lol!" << endl;
	}
}

void f2(int one)
{
	cout << "one: " << one << endl;
}


class example
{
public:
	void func()
	{
		cout << "hello!" << endl;
	}
};
int main()
{
	mState game;
	if (game.setCurrent(start, f2));
		{
			if (game.setCurrent(loadscreen, f2))
			{
				if (game.setCurrent(menu, f2))
				{
					cout << "Wellcome to the game!" << endl;
				}
			}
		}
	while (!_kbhit());
    return 0;
}

