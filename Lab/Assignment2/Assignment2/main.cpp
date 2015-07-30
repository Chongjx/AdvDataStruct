#include "Application.h"

void main(void)
{
	Application clinicDatabase;

	clinicDatabase.Init();

	while (!clinicDatabase.getExit())
	{
		clinicDatabase.Run();
	}

	clinicDatabase.Exit();
}