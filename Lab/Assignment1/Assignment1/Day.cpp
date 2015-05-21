#include "Day.h"

Day::Day(void) : startDay(9, 0),  durationOfTheDay(9, 0), occupiedTime(0, 0), lessonsOfTheDay(NULL), packed(false)
{
}

Day::Day(Day &copy)
{
	for(int i = 0; i < copy.lessonsOfTheDay.size(); ++i)
	{
		*(this->lessonsOfTheDay[i]) = *(copy.lessonsOfTheDay[i]);
	}
	this->startDay = copy.startDay;
	this->durationOfTheDay = copy.durationOfTheDay;
	this->occupiedTime = copy.occupiedTime;
	this->packed = copy.packed;
}

Day::~Day(void)
{
	while(this->lessonsOfTheDay.size() > 0)
	{
		Lesson* old = lessonsOfTheDay.back();
		delete old;
		lessonsOfTheDay.pop_back();
	}
}

void Day::setStartDay(Time startDay)
{
	this->startDay = startDay;
}

void Day::setDurationOfTheDay(Time durationOfTheDay)
{
	this->durationOfTheDay = durationOfTheDay;
}

void Day::setOccupiedTime(Time occupiedTime)
{
	this->occupiedTime = occupiedTime;
}

void Day::setPacked(bool packed)
{
	this->packed = packed;
}

Time Day::getStartDay(void) const
{
	return this->startDay;
}

Time Day::getDurationOfTheDay(void) const
{
	return this->durationOfTheDay;
}

Time Day::getOccupiedTime(void) const
{
	return this->occupiedTime;
}

bool Day::getPacked(void) const
{
	return this->packed;
}

bool Day::addLesson(Lesson* newLesson)
{
	this->lessonsOfTheDay.push_back(newLesson);
	this->occupiedTime += (*newLesson).getDuration();
	this->occupiedTime.convertTime();

	if(this->durationOfTheDay <= this->occupiedTime)
	{
		this->packed = true;
	}
	return true;
}

bool Day::operator!()
{
	if (this->occupiedTime < this->durationOfTheDay)
	{
		return true;
	}

	else
	{
		return false;
	}
}

ostream &operator<<(ostream &os, Day &output)
{
	for (int i = 0; i < output.lessonsOfTheDay.size(); ++i)
	{
		// start time hr
		if (output.lessonsOfTheDay[i]->getStartTime().getHr() < 10)
		{
			os << "0" << output.lessonsOfTheDay[i]->getStartTime().getHr();
		}

		else
		{
			os << output.lessonsOfTheDay[i]->getStartTime().getHr();
		}

		os << ":";

		// start time min
		if (output.lessonsOfTheDay[i]->getStartTime().getMin() < 10)
		{
			os << "0" << output.lessonsOfTheDay[i]->getStartTime().getMin();
		}

		else
		{
			os << output.lessonsOfTheDay[i]->getStartTime().getMin();
		}

		os << " - ";

		// end time hr
		if (output.lessonsOfTheDay[i]->getEndTime().getHr() < 10)
		{
			os << "0" << output.lessonsOfTheDay[i]->getEndTime().getHr();
		}

		else
		{
			os << output.lessonsOfTheDay[i]->getEndTime().getHr();
		}

		os << ":";

		// end time min
		if (output.lessonsOfTheDay[i]->getEndTime().getMin() < 10)
		{
			os << "0" << output.lessonsOfTheDay[i]->getEndTime().getMin();
		}

		else
		{
			os << output.lessonsOfTheDay[i]->getEndTime().getMin();
		}

		os << " " << output.lessonsOfTheDay[i]->getModuleCode() << endl;
	}

	return os;
}