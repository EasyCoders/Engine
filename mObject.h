#pragma once
#include <vector>
#include <iterator>
#include "Object.h"

using namespace std;
class mObject
{
	vector <Object> Env;			//Object Environment - обьектная среда (хранит набор всех игровых обьектов)
	int iterator;					//? - будет пересатриватся смысл переменной.
public:
	mObject();
	~mObject();

	void AddObject(Object Example);	//добавляет обьект в вектор обьектов Env (не проверено на работоспособность!)
};

