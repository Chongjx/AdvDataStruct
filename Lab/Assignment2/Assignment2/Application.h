#ifndef APPLICATION_H
#define APPLICATION_H

// for getch function
#include <conio.h>
#include "Database.h"

class Application
{
private:
	bool exit;
	char option;

	Database jxClinic;
public:
	Application(void);
	~Application(void);

	void Init(void);
	void Run(void);
	void Exit(void);

	bool HandleEmptyDatabase(void);
	void flushInput(void);

	bool getExit(void);
};

#endif