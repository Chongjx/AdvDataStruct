#include "APoint.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std;

void main(void)
{
	APoint p1(3, 5, 5);
	APoint p2 = p1;

	//p2 = p1;

	cout << "P1: " << p1 << endl;
	cout << "P2: " << p2 << endl;

	*(p2.ptrZ) = 888;

	cout << "P1: " << p1 << endl;
	cout << "P2: " << p2 << endl;

	p1.SetPos(10, 20, 30);

	cout << "P1++: " << p1++ << endl;
	cout << "P1: " << p1 << endl;

	p1.SetPos(10, 20, 30);

	cout << "++P1: " << ++p1 << endl;
	cout << "P1: " << p1 << endl;

	p1.SetPos(10, 20, 30);

	cout << "P1--: " << p1-- << endl;
	cout << "P1: " << p1 << endl;

	p1.SetPos(10, 20, 30);

	cout << "--P1: " << --p1 << endl;
	cout << "P1: " << p1 << endl;

	p1.SetPos(10, 20, 30);
	p2 = -p1;

	cout << "P1: " << p1 << endl;
	cout << "P2: " << p2 << endl;

	p1.SetPos(9, 20, 30);
	if(!p1)
	{
		cout << "Less than [10, 20, 30]" << endl;
	}

	else
	{
		cout << "More than or equal to [10, 20, 30]" << endl;
	}
}