#include "Lesson.h"

Lesson::Lesson(void) : moduleCode("NULL"), duration(0, 0), startTime(0, 0), endTime(0, 0)
{
}

Lesson::Lesson(string moduleCode, Time duration)
{
	this->moduleCode = moduleCode;
	this->duration = duration;
	startTime.setTime(0, 0);
	endTime.setTime(0, 0);
}

Lesson::Lesson(Lesson &copy)
{
	this->moduleCode = copy.moduleCode;
	this->duration = copy.duration;
	this->startTime = copy.startTime;
	this->endTime = copy.endTime;
}

Lesson::~Lesson(void)
{
}

void Lesson::setLesson(string moduleCode, Time duration)
{
	this->moduleCode = moduleCode;
	this->duration = duration;
	startTime.setTime(0, 0);
	endTime.setTime(0, 0);
}

void Lesson::setModuleCode(string moduleCode)
{
	this->moduleCode = moduleCode;
}

void Lesson::setDuration(Time duration)
{
	this->duration = duration;
}

void Lesson::setStartTime(Time startTime)
{
	this->startTime = startTime;
}

string Lesson::getModuleCode(void) const
{
	return this->moduleCode;
}

Time Lesson::getDuration(void) const
{
	return this->duration;
}

Time Lesson::getStartTime(void) const
{
	return this->startTime;
}

Time Lesson::getEndTime(void)
{
	this->endTime = (this->startTime + this->duration).convertTime();

	return this->endTime;
}

Lesson &Lesson::operator=(Lesson &input)
{
	this->moduleCode = input.moduleCode;
	this->duration = input.duration;
	this->startTime = input.startTime;
	this->endTime = input.endTime;

	return *this;
}

ostream &operator<<(ostream &os, Lesson &output)
{
	os << "Module: " << output.getModuleCode() << " with a duration of " << output.getDuration().convertTime();

	return os;
}