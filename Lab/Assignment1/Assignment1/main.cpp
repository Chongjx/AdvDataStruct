#include "Planner.h"

void main(void)
{
	Planner timetablePlanner;

	// Init variables
	timetablePlanner.Init();

	while(timetablePlanner.exit != true)
	{
		timetablePlanner.Run();
	}

	timetablePlanner.Exit();
}