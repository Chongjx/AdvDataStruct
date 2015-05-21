#include "Planner.h"

Planner::Planner(void)
{
}

Planner::~Planner(void)
{
	if (lessonToBeAdded != NULL)
		delete lessonToBeAdded;
}

void Planner::Init(void)
{
	this->exit = false;
	this->option = 0;

	// set each day start time, duration... Allows user to change in the future
	for(int i = 0; i < NUM_DAYS; ++i)
	{
		this->week[i].setStartDay(Time(9, 0));
		this->week[i].setDurationOfTheDay(Time(9, 0));
		this->week[i].setOccupiedTime(Time(0, 0));
	}

	this->lessonToBeAdded = NULL;
	this->moduleCode = "";
	this->duration.setTime(0, 0);

	this->maxLessonTime.setTime(9, 0);
	this->minLessonTime.setTime(0, 0);
}

void Planner::Run(void)
{
	// Start adding lesson
	system("ClS");
	cout << "Timetable planner V1.0" << endl;
	cout << endl;

	cout << "1. Enter module" << endl;
	cout << "2. Print timetable" << endl;
	cout << "3. Exit" << endl;
	cout << endl;

	cin >> option;

	switch(option)
	{
	case 1:
		{
			system("CLS");
			// Add module into the timetable
			cout << "Enter module code: ";
			cin >> moduleCode;
			cout << "Enter duration (Hr Min): ";
			cin >> duration;

			// If the duration exceeds 9 hr, fail input
			if (maxLessonTime <= duration.convertTime() || duration.convertTime() <= minLessonTime)
			{
				cout << "Invalid time input!" << endl;
				getch();
				break;
			}

			else
			{
				lessonToBeAdded = new Lesson(moduleCode, duration);
				cout << "You have entered " << *lessonToBeAdded << endl << endl;
			}

			// find a place to slot
			for(int i = 0; i < NUM_DAYS; ++i)
			{
				if ((week[i].getOccupiedTime() + duration).convertTime() <= week[i].getDurationOfTheDay() && week[i].getPacked() != true)
				{
					(*lessonToBeAdded).setStartTime(week[i].getStartDay() + week[i].getOccupiedTime());
					week[i].addLesson(lessonToBeAdded);
					lessonToBeAdded = NULL;
					//if the last lesson added fills up the day, set day packed
					if (week[i].getOccupiedTime() == week[i].getDurationOfTheDay())
					{
						week[i].setPacked(true);
					}
					break;
				}

				else if (i == (NUM_DAYS - 1) && week[i].getDurationOfTheDay() < (week[i].getOccupiedTime() + duration).convertTime())
				{
					cout << "Unable to find an empty slot" << endl << endl;
					break;
				}
			}

			// print out timetable
			for (int j = 0; j < NUM_DAYS; ++j)
			{
				switch(j)
				{
				case 0:
					cout << "Monday" << endl;
					break;
				case 1:
					cout << "Tuesday" << endl;
					break;
				case 2:
					cout << "Wednesday" << endl;
					break;
				case 3:
					cout << "Thursday" << endl;
					break;
				case 4:
					cout << "Friday" << endl;
					break;
				}

				cout << week[j] << endl;
			}
			getch();
			break;
		}
	case 2:
		{
			system("CLS");
			for (int i = 0; i < NUM_DAYS; ++i)
			{
				switch(i)
				{
				case 0:
					cout << "Monday" << endl;
					break;
				case 1:
					cout << "Tuesday" << endl;
					break;
				case 2:
					cout << "Wednesday" << endl;
					break;
				case 3:
					cout << "Thursday" << endl;
					break;
				case 4:
					cout << "Friday" << endl;
					break;
				}
				cout << week[i] << endl;
			}
			getch();
			break;
		}
	case 3:
		{
			this->exit = true;
			break;
		}
	default:
		{
			cout << "Invalid Input!" << endl;
			getch();
			break;
		}
	}
}

void Planner::Exit(void)
{
}