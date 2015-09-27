#include "stdafx.h"
#include "mObject.h"


mObject::mObject()
{
	iterator = -1;
	
}


mObject::~mObject()
{
}

void mObject::AddObject(Object Example)
{
	Example.setId(++iterator);
	Env.push_back(Example);
}
