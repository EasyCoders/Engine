#include "stdafx.h"
#include "Config.h"


Config::Config()
{
	fileName = new char[100];

	width = length = 0;
	windowName = new char[100];
}

Config::Config(const Config & obj)
{
	xStart = obj.xStart;
	yStart = obj.yStart;
	fileName = obj.fileName;
	length = obj.length;
	width = obj.width;
	windowName = obj.windowName;
}

Config::Config(int x, int y, int wdth, int len, char *winName, char *fName)
{
	xStart = x;
	yStart = y;
	width = wdth;
	length = len;
	windowName = winName;
	fileName = fName;
}


Config::~Config()
{
	//dctor
}

void Config::changeConfig()
{
	out.open(fileName);
		out << fileName;
		out << width;
		out << length;
	out.close();
}

void Config::loadConfig()
{
	in.open(fileName);
		in >> windowName;
		in >> width;
		in >> length;
	in.close();
}

void Config::setFile(char *tempFile)
{
	fileName = tempFile;
}

void Config::setWidth(int w)
{
	width = w;
}

void Config::setLength(int l)
{
	length = l;
}


void Config::setWindowName(char * name)
{
	windowName = name;
}

void Config::setXstart(int x)
{
	xStart = x;
}

void Config::setYstart(int y)
{
	yStart = y;
}

Config Config::operator=(Config temp)
{
	xStart = temp.xStart;
	yStart = temp.yStart;
	fileName = temp.fileName;
	length = temp.length;
	width = temp.width;
	windowName = temp.windowName;
	return *this;
}

