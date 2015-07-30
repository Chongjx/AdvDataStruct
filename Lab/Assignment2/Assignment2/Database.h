#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "Patient.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;

static const int MAX_PATIENT = 20;
static const int MAX_NAME_LENGTH = 32;

enum SORT_TYPE
{
	SORT_NAME,
	SORT_ID,
	MAX_SORT,
};

class Database
{
private:
	Patient* list[MAX_PATIENT];
	bool listSorted;
	bool listOrder;
	bool listFull;
	bool listEmpty;
	int patientCount;

	SORT_TYPE sortMethod;
public:
	Database(void);
	~Database(void);

	void setSortMethod(SORT_TYPE sortType);
	void setSortOrder(bool order);

	bool getListSorted(void) const;
	bool getListOrder(void) const;
	bool getListFull(void) const;
	bool getListEmpty(void) const;
	SORT_TYPE getSortMethod(void) const;

	bool validateName(string &name);
	bool validateID(string &ID);

	bool addPatient(Patient *newPatient);
	bool removePatient(int pos);

	bool sequentialSearch(string searchName, int &pos);
	bool sequentialSearch(int searchID, int &pos);
	
	bool binarySearch(string searchName, int &pos);
	bool binarySearch(int searchID, int &pos);

	void sort(void);
	void merge(int first, int middle, int last);
	void mergeSort(int first, int last);

	void printSpace(int numSpace);
	void printList(void);

	void cleanUp(void);
};

#endif