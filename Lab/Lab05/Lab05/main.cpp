#include <iostream>
#define NDEBUG
#include <assert.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void main(void)
{
	int dividend, divisor, quotient;
	bool endProgram = false;
	for (int tries = 0; tries < 5; ++tries)
	{
		try
		{
			cout << "Enter dividend: ";
			cin >> dividend;
			if(dividend < 0)
			{
				throw(dividend);
			}

			else if(dividend == 0)
			{
				throw(string("Divide by zero error"));
			}

			cout << "Enter divisor: ";
			cin >> divisor;

			quotient = dividend / divisor;
			cout << "Quotient = " << quotient << endl << endl;
		}

		catch(int value)
		{
			cout << "Value must be more than 0!" << endl << endl;
		}
		catch(string error)
		{
			cout << error << endl << endl;
		}
	}
}