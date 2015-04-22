#ifndef DERIVED_CLASS_H
#define DERIVED_CLASS_H

#include "BaseClass.h"

class DerivedClass : public BaseClass
{
private:
	int value;
public:
	DerivedClass(void);
	~DerivedClass(void);

	void setValue(const int value);
	void print(void);
};

#endif