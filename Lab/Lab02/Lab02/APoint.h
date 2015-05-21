#ifndef APOINT_H
#define APOINT_H

#include <iostream>

class APoint
{
private:
	int x, y;
	
public:
	int *ptrZ;

	APoint(void);
	APoint(int x, int y, int z);
	APoint(APoint &copy);
	~APoint(void);

	void SetPos(int x, int y, int z);
	int GetPos_X(void);
	int GetPos_Y(void);
	
	friend APoint operator+ (APoint &input1, APoint &input2);
	friend APoint operator+ (int value, APoint &input1);
	friend APoint operator+ (APoint &input1, int value);
	friend APoint operator- (APoint &input1, APoint &input2);

	friend std::ostream & operator<<(std::ostream &os, APoint &output);
	friend std::istream & operator>>(std::istream &is, APoint &input);

	APoint & operator= (APoint &input);
	APoint operator++(void);
	APoint operator++(int ignore);
	APoint operator--(void);
	APoint operator--(int ignore);
	APoint operator-() const;
	bool operator!() const;
};

#endif