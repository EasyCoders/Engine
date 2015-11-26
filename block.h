
#pragma once

//pre-declaration of blockObject for block class
class blockObject;


//class block that contain info about access and pointer of blockObject 
class block
{
	blockObject *object;					//store info about access to block (free or not)
public:
	block();
	~block();

	bool checkBlock(blockObject* checkObj);
	bool show();

	void setFree();
	void setDepend(blockObject *_object);
};






//class phisWide that contain matrix of block class type 
class phisWide
{
	int yLen, xLen;					//x and y length of blocks matrix
	block **matrix;
public:
	phisWide();
	phisWide(int _xLen, int _yLen);

	void setBlock(int _yPos, int _xPos, blockObject *object);				//set false access for block (engage block)
	void freeBlock(int _yPos, int _xPos);				//set true access for block (free block)

	bool getState(int _yPos, int _xPos, blockObject *object);				//return state of block
	bool dispBlock(int _yPos, int _xPos);

	void setSqare(int _yPos, int _xPos, int _higth, int _length, blockObject *object);   //set false access for square of blocks (engage square)
	void freeSquare(int _yPos, int _xPos, int _higth, int _length); //set true access for square of blocks (free square)

	bool getSquare(int _yPos, int _xPos, int _higth, int _length, blockObject *object);	//return state of square of blocks

	bool checkCoordinates(int _yPos, int _xPos, int hight, int length);

	int getXLEN();
	int getYLEN();
	~phisWide();
};






//class blockObject contain info about top-left point position 
//and hight and length of phisic block on matrix

class blockObject
{
	int yStart, xStart;											//coordinates of start point of object (top left point of quadro)
	int heigth, length;											//size parameters of quadro block (counts from start point)
public:
	blockObject();
	blockObject(int _heigth, int _length);						//creates block with size parameters
	~blockObject();

	bool putBlock(phisWide &wide, int _yStart, int _xStart);	//put object on specified position if this is possible
	bool portBlock(phisWide &wide, int _yPort, int _xPort);		//port object on specified position if this is possible

	void moveBlock(phisWide &wide, int move);					//move block for one position
};

enum movement
{
	Up = 1,
	Down = 2,
	Left = 3,
	Right = 4,
	UpLeft = 5,
	UpRigth = 6,
	DownLeft = 7,
	DownRigth = 8
};
