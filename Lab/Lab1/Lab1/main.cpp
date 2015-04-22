#include <iostream>
#include "APoint.h"
#include "BaseClass.h"
#include "DerivedClass.h"

using std::cin;
using std::cout;
using std::endl;

void setSomething(APoint &pt, int value)
{
	pt.nXcoord = value;
	pt.nYcoord = value;
}

void newLine(void)
{
	cout << endl;
}

void main(void)
{
	APoint pt1, pt2, result;
	pt1.setCoord(10, 20);
	pt1.print();

	newLine();

	pt2.setCoord(30, 40);
	pt2.print();

	newLine();

	result = pt1 + pt2;
	result.print();

	DerivedClass dClass;
	dClass.setValue(5);

	newLine();

	dClass.print();
	dClass.BaseClass::print();
}