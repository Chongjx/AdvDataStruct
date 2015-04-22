#include "APoint.h"

APoint::APoint(void)
{
	nXcoord = nYcoord = 0;
}

APoint::APoint(int x, int y) : nXcoord(x), nYcoord(y)
{
}

APoint::~APoint(void)
{
}

void APoint::setCoord(int nXcoord, int nYcoord)
{
	this->nXcoord = nXcoord;
	this->nYcoord = nYcoord;
}

void APoint::print(void)
{
	cout << "X coord: " << nXcoord << endl;
	cout << "Y coord: " << nYcoord << endl;
}

APoint APoint::operator+(const APoint &pt)
{
	APoint temp;

	temp.nXcoord = this->nXcoord + pt.nXcoord;
	temp.nYcoord = this->nYcoord + pt.nYcoord;

	return temp;
}

void APoint::operator+=(const APoint &pt)
{
	nXcoord += pt.nXcoord;
	nYcoord += pt.nYcoord;
}