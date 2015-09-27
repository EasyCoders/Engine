// Core.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "Game.h"
#include "Config.h"


using namespace std;

void easyFunc(int one)
{
	cout << "Example of function: " << one << endl;
}

int main(int Arg_N, char ** Arg_V)
{
	int xPos, yPos;
	int wid, len;
	char *name = new char[100];
	cout << "input start position (x,y): ";
	cin >> xPos >> yPos;
	cout << "input width and length of game window: ";
	cin >> wid >> len;
	cout << "input name of game window: ";
	cin >> name;
	Config easyCon(xPos, yPos, wid, len, name, "config.txt");
	Game example(easyCon, easyFunc);
	example.GameWindow();
    return 0;
}


