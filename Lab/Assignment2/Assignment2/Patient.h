#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using std::string;

class Patient
{
private:
	string name;
	int ID;
public:
	Patient(void);
	Patient(string name, int ID);
	~Patient(void);

	void Init(string name, int ID);

	void setName(string name);
	void setID(int ID);

	string getName(void) const;
	int getID(void) const;
};

#endif