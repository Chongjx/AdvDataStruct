#include "DerivedClass.h"

DerivedClass::DerivedClass(void)
{
}

DerivedClass::~DerivedClass(void)
{
}

void DerivedClass::setValue(const int value)
{
	this->value = value;
	this->BaseClass::value = value;
}

void DerivedClass::print(void)
{
	cout << value << endl;
}