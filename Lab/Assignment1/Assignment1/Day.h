#ifndef DAY_H
#define DAY_H

#include <vector>

#include "Lesson.h"

using std::vector;

class Day
{
private:
	vector<Lesson*> lessonsOfTheDay;
	Time startDay;
	Time durationOfTheDay;
	Time occupiedTime;
	bool packed;
public:
	Day(void);
	Day(Day &copy);
	~Day(void);

	void setStartDay(Time startDay);
	void setDurationOfTheDay(Time durationOfTheDay);
	void setOccupiedTime(Time occupiedTime);
	void setPacked(bool packed);

	Time getStartDay(void) const;
	Time getDurationOfTheDay(void) const;
	Time getOccupiedTime(void) const;
	bool getPacked(void) const;

	bool addLesson(Lesson* newLesson);
	bool operator! ();

	friend ostream &operator<<(ostream &os, Day &output);
};

#endif