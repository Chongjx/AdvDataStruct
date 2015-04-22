#ifndef APOINT_H
#define APOINT_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class APoint
{
private:
	int nXcoord, nYcoord;

public:
	APoint(void);
	APoint(int x, int y);
	~APoint(void);

	void setCoord(int nXcoord, int nYcoord);
	void print(void);

	friend void setSomething(APoint &pt, int nValue);

	APoint operator+(const APoint &pt);
	void operator+=(const APoint &pt);
};

#endif APOINT_H