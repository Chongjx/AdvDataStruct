#include "APoint.h"

template <class t>
void Print(t abc)
{
	cout << abc << endl;
}

void main(void)
{
	int ivalue = 1;
	double dvalue = 2.0;
	float fvalue = 3.f;
	long lvalue = 4;
	short svalue = 5;
	
	Print(ivalue);
	Print(dvalue);
	Print(fvalue);
	Print(lvalue);
	Print(svalue);

	APoint<int> iPoint(1, 2);
	APoint<double> dPoint(3.00, 4.00);
	APoint<float> fPoint(5.f, 6.f);
	APoint<long> lPoint(7, 8);
	APoint<short> sPoint(9, 10);

	iPoint.Print();
	dPoint.Print();
	fPoint.Print();
	lPoint.Print();
	sPoint.Print();

	cout << iPoint << endl;
	cout << dPoint << endl;
	cout << fPoint << endl;
	cout << lPoint << endl;
	cout << sPoint << endl;
}