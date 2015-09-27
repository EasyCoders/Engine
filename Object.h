#pragma once



enum ObjState
{
	statics = 0,
	active
};

class Object
{
	int id;						//id обьекта
	int ObjState;				//состояние обьекта относительно физического движка
public:				
	Object();
	Object(int state);			//перегруженый конструктор, принимающий состояние обьекта
	~Object();
	
	void setState(int state);			//устанавливает состояние 
	int getState();						//возвращает состояние

	void setId(int id);
	int  getId();
};

