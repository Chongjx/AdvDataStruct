#ifndef TIME_H
#define TIME_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Time
{
private:
	unsigned int hr, min;
public:
	Time(void);
	Time(unsigned int hr,unsigned int min);
	Time(const Time &copy);
	~Time(void);

	void setTime(unsigned int hr, unsigned int min);
	void setHr(unsigned int hr);
	void setMin(unsigned int min);

	int getHr(void) const;
	int getMin(void) const;

	Time & convertTime(void);

	Time & operator+= (Time &input);
	Time & operator= (Time &input);
	friend Time operator+ (Time &input1, Time &input2);
	friend bool operator<= (Time &input1, Time &input2);
	friend bool operator< (Time &input1, Time &input2);
	friend bool operator== (Time &input1, Time &input2);

	friend ostream & operator<<(ostream &os, Time &output);
	friend istream & operator>>(istream &is, Time &input);
};

#endif