#include "stdafx.h"
#include "block.h"
#include <iostream>

using namespace std;
block::block()
{
	object = nullptr;
}


block::~block()
{
	delete object;
}

bool block::checkBlock(blockObject* checkObj)
{
	if (object == nullptr)
	{
		return true;
	}
	else if (object == checkObj)
	{
		return true;
	}

	return false;
}

bool block::show()
{
	if (object == nullptr)
	{
		return true;
	}
	return false;
}


void block::setFree()
{
	object = nullptr;
}

void block::setDepend(blockObject *_object)
{
	object = _object;
}

//phisWide implementation
phisWide::phisWide()
{
	xLen = yLen = 0;
}

phisWide::phisWide(int _yLen, int _xLen)
{
	xLen = _xLen;
	yLen = _yLen;

	matrix = new block*[yLen];				//create 2-d dynamic array
	for (int i = 0; i < yLen; i++)
	{
		matrix[i] = new block[xLen];
	}
}


void phisWide::setBlock(int _yPos, int _xPos, blockObject *object)
{
	matrix[_yPos][_xPos].setDepend(object);			//set false block in matrix
}

void phisWide::freeBlock(int _yPos, int _xPos)
{
	matrix[_yPos][_xPos].setFree();				//set true block in matrix
}

bool phisWide::getState(int _yPos, int _xPos, blockObject *object)
{
	return matrix[_yPos][_xPos].checkBlock(object);	//return access state of block in matrix (true/false)
}

bool phisWide::dispBlock(int _yPos, int _xPos)
{
	return matrix[_yPos][_xPos].show();
}





void phisWide::setSqare(int _yPos, int _xPos, int _higth, int _length, blockObject *object)
{
	for (int y = _yPos; y < (_yPos + _higth); y++)
	{
		for (int x = _xPos; x < (_xPos + _length); x++)
		{
			matrix[y][x].setDepend(object);
		}
	}
}

void phisWide::freeSquare(int _yPos, int _xPos, int _higth, int _length)
{
	for (int y = _yPos; y < (_yPos + _higth); y++)
	{
		for (int x = _xPos; x < (_xPos + _length); x++)
		{
			matrix[y][x].setFree();
		}
	}
}

bool phisWide::getSquare(int _yPos, int _xPos, int _higth, int _length, blockObject *object)
{
	for (int y = _yPos; y < (_yPos + _higth + 1); y++)
	{
		for (int x = _xPos; x < (_xPos + _length + 1); x++)
		{
			if (!(matrix[y][x].checkBlock(object)))		//if element of matrix is depend - return false
			{
				return false;
			}
		}
	}

	return true;
}


bool phisWide::checkCoordinates(int _yPos, int _xPos, int hight, int length)
{
	if ((_yPos < 0))
	{
		return false;
	}
	else if (_yPos >= (yLen - hight + 1))
	{
		return false;
	}
	else if (_xPos < 0)
	{
		return false;
	}
	else if (_xPos >= (xLen - length + 1))
	{
		return false;
	}
	return true;
}

int phisWide::getXLEN()
{
	return xLen;
}

int phisWide::getYLEN()
{
	return yLen;
}

phisWide::~phisWide()
{
}

//blockObject implementation

blockObject::blockObject()
{
	yStart = xStart = heigth = length = 0;
}

blockObject::blockObject(int _heigth, int _length)
{
	heigth = _heigth;
	length = _length;
}

blockObject::~blockObject()
{

}

bool blockObject::putBlock(phisWide &wide, int _yStart, int _xStart)
{
	if (!wide.checkCoordinates(_yStart, _xStart, heigth, length))
	{
		return false;
	}

	if (wide.getSquare(_yStart, _xStart, heigth, length, this))
	{
		//wide.freeSquare(yStart, xStart, heigth, length);
		yStart = _yStart;
		xStart = _xStart;

		wide.setSqare(yStart, xStart, heigth, length, this);
		return true;
	}

	return false;
}

bool blockObject::portBlock(phisWide &wide, int _yPort, int _xPort)
{

	if (!wide.checkCoordinates(_yPort, _xPort, heigth, length))
	{
		return false;
	}



	if (wide.getSquare(_yPort, _xPort, heigth, length, this))
	{
		wide.freeSquare(yStart, xStart, heigth, length);
		yStart = _yPort;
		xStart = _xPort;

		wide.setSqare(yStart, xStart, heigth, length, this);

		return true;
	}

	return false;
}

void blockObject::moveBlock(phisWide & wide, int move)
{
	switch (move)
	{
	case 1:									//move up
	{
		portBlock(wide, yStart - 1, xStart);
		break;
	}
	case 2:									//move down
	{
		portBlock(wide, yStart + 1, xStart);
		break;
	}
	case 3:									//move left
	{
		portBlock(wide, yStart, xStart - 1);
		break;
	}
	case 4:									//move rigth
	{
		portBlock(wide, yStart, xStart + 1);
		break;
	}
	case 5:									//move upLeft
	{
		portBlock(wide, yStart - 1, xStart - 1);
		break;
	}
	case 6:									//move upRigth
	{
		portBlock(wide, yStart - 1, xStart + 1);
		break;
	}
	case 7:									//downLeft
	{
		portBlock(wide, yStart + 1, xStart - 1);
		break;
	}
	case 8:									//downRight
	{
		portBlock(wide, yStart + 1, xStart + 1);
		break;
	}
	}
}

