#ifndef APOINT_H
#define APOINT_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <class classtype>
class APoint
{
private:
	classtype x;
	classtype y;
public:
	APoint(void)
	{
		this->x = this->y = 0;
	}
	APoint(classtype x, classtype y)
	{
		this->x = x;
		this->y = y;
	}
	~APoint(void)
	{
	}

	void setPoint(classtype x, classtype y)
	{
		this->x = x;
		this->y = y;
	}

	void Print(void)
	{
		cout << this->x << ", " << this->y << endl;
	}

	friend std::ostream & operator<<(std::ostream &os, APoint<classtype> &output)
	{
		os << "[" << output.x << ", " << output.y << "]";

		return os;
	}

	friend std::istream & operator>>(std::istream &is, APoint<classtype> &input)
	{
		is >> input.x >> input.y;

		return is;
	}
};

#endif