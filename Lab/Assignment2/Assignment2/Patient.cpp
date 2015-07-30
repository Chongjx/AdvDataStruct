#include "Patient.h"

Patient::Patient(void) :
	name(""),
	ID(0)
{
}

Patient::Patient(string name, int ID) :
	name(name),
	ID(ID)
{
}

Patient::~Patient(void)	
{
}

void Patient::Init(string name, int ID)
{
	this->name = name;
	this->ID = ID;
}

void Patient::setName(string name)
{
	this->name = name;
}

void Patient::setID(int ID)
{
	this->ID = ID;
}

string Patient::getName(void) const
{
	return this->name;
}

int Patient::getID(void) const
{
	return this->ID;
}