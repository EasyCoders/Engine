// Core.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Window.h"
#include "mState.h"

#include "Config.h"


using namespace std;

//создаём пользовательский класс 
class user : public ModuleBase	   //все пользовательские модули(классы), должны наследовать абстрактный класс ModuleBase	
{
public:
	void method()
	{
		while (true)
		{
			cout << "\a" << endl;
			Sleep(1000);
		}
	}
};

//создаём класс отвечающий за создание окна
class winStart : public ModuleBase
{
	Config objCon;
	Window* load;			       //указательна обьект менеджирования окна
public:

	winStart(Config _objCon)
	{
		objCon = _objCon;
		load = new Window;
	}

	void method()
	{
									
		//функция инициализации окна по переданным в обьект конфигурации objCon параметрам
		load->init(objCon.windowName, objCon.xStart, objCon.yStart, objCon.length, objCon.width, SDL_WINDOW_SHOWN);

		while (load->running())		   //пока окно запущено будут обрабатываться следующие события		
		{
			load->handleEvents();	   //обработка событий
			load->update();		       //обновление окна
			load->render();			   //рендер окна
		}
	}
};

int main(int Arg_N, char ** Arg_V)
{
	
	int xPos, yPos;								//временные переменные позиции окна
	int wid, len;								//временные переменные размеров окна
	char *name = new char[100];						//врменная переменная имя окна
	cout << "input start position (x,y): ";					
	cin >> xPos >> yPos;
	cout << "input width and length of game window: ";
	cin >> wid >> len;
	cout << "input name of game window: ";
	cin >> name;
	Config easyCon(xPos, yPos, wid, len, name, "config.txt");		//создаём обьект конфигурации окна передавая временные переменные
	
	user obj;														//создаём обьект пользовательского класса
	winStart win(easyCon);											//создаём обьект класса создания окна по переданной в easyCon конфигурации

	mState game;													//создаём обьект менеджера состояний игры

	game.setTopState(start, &win);									//устанавливаем верхнее состояние как "старт" и передаём обьект с методом на выполнение
	game.setTopState(play, &obj);									//после создания окна передаём в стек новое состояние игры по тому же принципу


	/*Так как потоки несинхронизированы с основным (функцией main) потоком, нужно событие
	(в даном случае функция ожидания нажатия клавиши) которое будет "удерживать выполнение"
	функции main. Иначе функция main закончит своё выполнение в даной точке, не дожидаясь выполнения
	потоков, что приведёт к их завершению. Даная проблема связана с тем, что обьекты thread(потоки) 
	создаются и выполняются внутри методов, таким образом они становятся зависимыми
	от своих дескрипторов(адрессного пространства), по этому потоки отсоединяются от своих дескрипторов 
	и больше не синхронизируются с основным потоком, что является огромной проблемой, которую нужно решить. 
	В процессе дальнейшей разработчки будет вестись работы над улучшением данных принцыпов работы ядра.
	Но на данный момент, используется такой "некрасивый" приём в виде задержки основного потока.*/ 

	while (!_kbhit());												
    return 0;
}


