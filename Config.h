#pragma once
#include <fstream>

using namespace std;
class Config
{
	// i/o vars)
	ofstream out;												//выходной поток
	ifstream in;												//входной поток
	char* fileName;												//хранит имя (путь) файла конфигурации

public:
	// config - info variables
	int xStart;													//начальное положение по x
	int yStart;													//начальное положение по y
	int length;													//длина окна
	int width;													//ширина окна
	char* windowName;											//название окна

	Config();
	Config(const Config& obj);
	Config(int x, int y, int wdth, int leng, char* winName, char* fName);		//перегруженный конструктор устанавливающий конфигурационные данные
	~Config();

	void changeConfig();										//выгружает конфигурацию в файл (fileName)
	void loadConfig();											//загружает конфигурацию из файла
	void setFile(char *file);									//устанавливает загрузочный конфигурационный файл

	void setWidth(int w);										//устанавливает ширину
	void setLength(int l);										//устанавливает  длину
	void setWindowName(char *name);								//устанавливает имя окна
	void setXstart(int x);										//устанавливает позицию по оси X								
	void setYstart(int y);										//устанавливает позицию по оси Y

	Config operator=(Config temp);
};

