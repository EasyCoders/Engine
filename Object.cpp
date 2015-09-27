#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	
}

Object::Object(int state)
{
	ObjState = state;
}

Object::~Object()
{
}

int Object::getState()
{
	return ObjState;
}

void Object::setId(int identify)
{
	id = identify;
}

int Object::getId()
{
	return id;
}

void Object::setState(int state)
{
	ObjState = state;
}
