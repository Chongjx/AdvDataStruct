#ifndef LESSON_H
#define LESSON_H

#include <string>
#include "Time.h"

using std::string;

class Lesson
{
private:
	string moduleCode;
	Time duration;
	Time startTime;
	Time endTime;
public:
	Lesson(void);
	Lesson(string moduleCode, Time duration);
	Lesson(Lesson &copy);
	~Lesson(void);

	void setLesson(string moduleCode, Time duration);
	void setModuleCode(string moduleCode);
	void setDuration(Time duration);
	void setStartTime(Time startTime);

	string getModuleCode(void) const;
	Time getDuration(void) const;
	Time getStartTime(void) const;
	Time getEndTime(void);

	Lesson & operator= (Lesson &input);
	friend ostream &operator<<(ostream &os, Lesson &output);
};

#endif