#include "APoint.h"

APoint::APoint(void)
{
	x = y = 0;
	ptrZ = new int;
	*ptrZ = 0;
}

APoint::APoint(int x, int y, int z)
{
	this->x = x;
	this->y = y;

	ptrZ = new int;
	*ptrZ = z;
}

APoint::APoint(APoint &copy)
{
	this->x = copy.x;
	this->y = copy.y;
	ptrZ = new int;
	*ptrZ = *copy.ptrZ;
}

APoint::~APoint(void)
{
	delete ptrZ;
}

void APoint::SetPos(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	*ptrZ = z;
}

int APoint::GetPos_X(void)
{
	return x;
}

int APoint::GetPos_Y(void)
{
	return y;
}

APoint operator+ (APoint &input1, APoint &input2)
{
	return APoint(input1.x + input2.x, input1.y + input2.y, *(input1.ptrZ) + *(input2.ptrZ));
}

APoint operator+(int value, APoint &input1)
{
	return APoint(input1.x + value, input1.y + value, *(input1.ptrZ) + value);
}

APoint operator+(APoint &input1, int value)
{
	return APoint(input1.x + value, input1.y + value, *(input1.ptrZ) + value);
}

APoint operator- (APoint &input1, APoint &input2)
{
	return APoint(input1.x - input2.x, input1.y - input2.y, *(input1.ptrZ) - *(input2.ptrZ));
}

std::ostream & operator<<(std::ostream &os, APoint &output)
{
	os << "[" << output.x << ", " << output.y << ", " << *(output.ptrZ) << "]";

	return os;
}

std::istream & operator>>(std::istream &is, APoint &input)
{
	is >> input.x >> input.y;

	return is;
}

APoint &APoint::operator=(APoint &input)
{
	if (this->ptrZ != input.ptrZ)
	{
		this->x = input.x;
		this->y = input.y;
		*this->ptrZ = *(input.ptrZ);
	}

	return *this;
}

APoint APoint::operator++(void)
{
	APoint tempPoint(1, 1, 1);

	(*this) = (*this) + tempPoint;

	return (*this);
}

APoint APoint::operator++(int ignore)
{
	APoint returnPoint = (*this);

	APoint tempPoint(1, 1, 1);

	(*this) = (*this) + tempPoint;

	return returnPoint;
}

APoint APoint::operator--(void)
{
	APoint tempPoint(1, 1, 1);

	(*this) = (*this) - tempPoint;

	return (*this);
}

APoint APoint::operator--(int ignore)
{
	APoint returnPoint = (*this);

	APoint tempPoint(1, 1, 1);

	(*this) = (*this) - tempPoint;

	return returnPoint;
}

APoint APoint::operator-() const
{
	APoint returnPoint;

	returnPoint.x = -x;
	returnPoint.y = -y;
	*(returnPoint.ptrZ) = *(ptrZ);

	return returnPoint;
}

bool APoint::operator!() const
{
	if (x < 10 && y < 20 && *(ptrZ) < 30)
	{
		return true;
	}

	else
	{
		return false;
	}
}