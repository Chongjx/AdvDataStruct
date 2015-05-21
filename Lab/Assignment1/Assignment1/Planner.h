#ifndef PLANNER_H
#define PLANNER_H

#include "Day.h"
#include <conio.h>

class Planner
{
private:
	static const int NUM_DAYS = 5;
public:
	Planner(void);
	~Planner(void);

	void Init(void);
	void Run(void);
	void Exit(void);

	bool exit;
	int option;
	Day week[NUM_DAYS];
	Lesson* lessonToBeAdded;
	string moduleCode;
	Time duration;

	Time maxLessonTime;
	Time minLessonTime;
};

#endif