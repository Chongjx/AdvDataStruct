#include "Time.h"

Time::Time(void) : hr(0), min(0)
{
}

Time::Time(unsigned int hr, unsigned int min)
{
	this->hr = hr;
	this->min = min;
}

Time::Time(const Time &copy)
{
	this->hr = copy.hr;
	this->min = copy.min;
}

Time::~Time(void)
{
}

void Time::setTime(unsigned int hr, unsigned int min)
{
	this->hr = hr;
	this->min = min;
}

void Time::setHr(unsigned int hr)
{
	this->hr = hr;
}

void Time::setMin(unsigned int min)
{
	this->min = min;
}

int Time::getHr(void) const
{
	return this->hr;
}

int Time::getMin(void) const
{
	return this->min;
}

Time &Time::convertTime(void)
{
	if (this->min >= 60)
	{
		this->hr += this->min / 60;
		this->min %= 60;
	}

	return *this;
}

Time &Time::operator+=(Time &input)
{
	this->hr += input.hr;
	this->min += input.min;

	return *this;
}

Time &Time::operator=(Time &input)
{
	this->hr = input.hr;
	this->min = input.min;

	return *this;
}

Time operator+ (Time &input1, Time &input2)
{
	Time tempTime(input1.hr + input2.hr, input1.min + input2.min);
	tempTime.convertTime();

	return tempTime;
}

bool operator<= (Time &input1, Time&input2)
{
	if (input1.hr < input2.hr)
	{
		return true;
	}

	else if (input1.hr == input2.hr)
	{
		if (input1.min <= input2.min)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	else
	{
		return false;
	}
}

bool operator< (Time &input1, Time&input2)
{
	if (input1.hr < input2.hr)
	{
		return true;
	}

	else if (input1.hr == input2.hr)
	{
		if (input1.min < input2.min)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	else
	{
		return false;
	}
}

bool operator== (Time &input1, Time&input2)
{
	if (input1.hr == input2.hr && input1.min == input2.min)
	{
		return true;
	}

	else
	{
		return false;
	}
}

ostream &operator<<(ostream &os, Time &output)
{
	os << output.hr << "hr ";
		
	if (output.min < 10)
	{
		os << "0" << output.min << "min";
	}

	else
	{
		os << output.min << "min";
	}

	return os;
}

istream &operator>>(istream &is, Time &input)
{
	is >> input.hr >> input.min;

	return is;
}