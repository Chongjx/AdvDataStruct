#ifndef BASE_CLASS_H
#define BASE_CLASS_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class BaseClass
{
protected:
	int value;
public:
	BaseClass(void);
	~BaseClass(void);

	virtual void print(void);
};

#endif