#include "Database.h"

Database::Database(void)
{
	for (int i = 0; i < MAX_PATIENT; ++i)
	{
		list[i] = NULL;
	}

	listSorted = false;
	listOrder = true;
	listFull = false;
	listEmpty = true;
	patientCount = 0;
	sortMethod = MAX_SORT;
}

Database::~Database(void)
{
	for (int i = 0; i < MAX_PATIENT; ++i)
	{
		if (list[i])
		{
			delete list[i];
			list[i] = NULL;
		}
	}
}

void Database::setSortMethod(SORT_TYPE sortType)
{
	sortMethod = sortType;
}

void Database::setSortOrder(bool order)
{
	listOrder = order;
}

bool Database::getListSorted(void) const
{
	return this->listSorted;
}

bool Database::getListOrder(void) const
{
	return this->listOrder;
}

bool Database::getListFull(void) const
{
	return this->listFull;
}

bool Database::getListEmpty(void) const
{
	return this->listEmpty;
}

SORT_TYPE Database::getSortMethod(void) const
{
	return this->sortMethod;
}

bool Database::validateName(string &name)
{
	if (name.length() <= 0)
		return false;

	// truncate extra characters
	if (name.length() > MAX_NAME_LENGTH)
	{
		name.resize(MAX_NAME_LENGTH);
	}

	return true;
}

bool Database::validateID(string &ID)
{
	// check if all chars are numbers
	for (int i = 0; i < ID.length(); ++i)
	{
		if (ID[i] >= '0' && ID[i] <= '9')
		{
			continue;
		}

		else
		{
			return false;
		}

	}

	// check if value is within limit
	if (atoi(ID.c_str()) < 0 || atoi(ID.c_str()) > 99999)
		return false;

	return true;
}

bool Database::addPatient(Patient *newPatient)
{
	list[patientCount] = newPatient;
	++patientCount;

	// list is not empty anymore
	this->listEmpty = false;

	// list becomes unsorted after adding a patient
	this->listSorted = false;
	this->sortMethod = MAX_SORT;

	// list becomes full if reach max
	if (patientCount == MAX_PATIENT)
	{
		this->listFull = true;
	}

	return true;
}

bool Database::removePatient(int pos)
{
	Patient *temp = new Patient[patientCount - 1];

	// copy the first part of the array
	for (int i = 0; i < pos; ++i)
	{
		temp[i].Init(list[i]->getName(), list[i]->getID());
	}

	// copy the second part of the array
	for (int j = pos + 1; j < patientCount; ++j)
	{
		temp[j - 1].Init(list[j]->getName(), list[j]->getID());
	}

	--patientCount;

	// copy everything back into the original list
	for (int i = 0; i < patientCount; ++i)
	{
		list[i]->Init(temp[i].getName(), temp[i].getID());
	}

	// list is empty once no patient
	if (patientCount == 0)
	{
		this->listEmpty = true;
	}

	return true;
}

bool Database::sequentialSearch(string searchName, int &pos)
{
	cout << "Using sequential search to search for name..." << endl;
	for (int i = 0; i < patientCount; ++i)
	{
		if (searchName == list[i]->getName())
		{
			cout << "Patient name: " << list[i]->getName() << endl;
			cout << "Patient ID: " << list[i]->getID() << endl;
			pos = i;
			return true;
		}
	}

	return false;
}

bool Database::sequentialSearch(int searchID, int &pos)
{
	cout << "Using sequential search to search for ID..." << endl;
	for (int i = 0; i < patientCount; ++i)
	{
		if (searchID == list[i]->getID())
		{
			cout << "Patient name: " << list[i]->getName() << endl;
			cout << "Patient ID: " << list[i]->getID() << endl;
			pos = i;
			return true;
		}
	}

	return false;
}

bool Database::binarySearch(string searchName, int &pos)
{
	cout << "Using binary search to search for name..." << endl;
	int midPoint = 0;
	int startPoint = 0;
	int endPoint = patientCount - 1;

	while (startPoint <= endPoint)
	{
		midPoint = (int)((startPoint + endPoint) * 0.5f);

		if (searchName == list[midPoint]->getName())
		{
			cout << "Patient name: " << list[midPoint]->getName() << endl;
			cout << "Patient ID: " << list[midPoint]->getID() << endl;
			pos = midPoint;
			return true;
		}

		// if the list is sorted in ascending order, true
		if (listOrder)
		{
			// if search name is 'less than' the name in the list
			if (searchName < list[midPoint]->getName())
			{
				endPoint = midPoint - 1;
			}
			else
			{
				startPoint = midPoint + 1;
			}
		}

		else
		{
			// if search name is 'greater than' the name in the list
			if (searchName > list[midPoint]->getName())
			{
				endPoint = midPoint - 1;
			}
			else
			{
				startPoint = midPoint + 1;
			}
		}
	}

	return false;
}

bool Database::binarySearch(int searchID, int &pos)
{
	cout << "Using binary search to search for ID..." << endl;
	int midPoint = 0;
	int startPoint = 0;
	int endPoint = patientCount - 1;

	while (startPoint <= endPoint)
	{
		midPoint = (int)((startPoint + endPoint) * 0.5f);

		if (searchID == list[midPoint]->getID())
		{
			cout << "Patient name: " << list[midPoint]->getName() << endl;
			cout << "Patient ID: " << list[midPoint]->getID() << endl;
			pos = midPoint;
			return true;
		}

		// if the list is sorted in ascending order, true
		if (listOrder)
		{
			// if value is less than midpoint value
			if (searchID < list[midPoint]->getID())
			{
				endPoint = midPoint - 1;
			}
			// if value is more than midpoint value
			else 
			{
				startPoint = midPoint + 1;
			}
		}

		else
		{
			// if value is more than midpoint value
			if (searchID > list[midPoint]->getID())
			{
				endPoint = midPoint - 1;
			}
			// if value is more than midpoint value
			else 
			{
				startPoint = midPoint + 1;
			}
		}
	}

	return false;
}

void Database::sort(void)
{
	mergeSort(0, patientCount - 1);

	listSorted = true;
}

void Database::merge(int first, int middle, int last)
{
	// temp array to hold the 1st half of the list
	Patient *temp = new Patient[middle - first + 1];

	// i - index for the temp array
	// j - index for the 2nd half of the list
	// k - index for the combine list
	int i, j, k;

	// copy into temp array
	for (j = first, i = 0; j <= middle; ++i, ++j)
	{
		temp[i].Init(list[j]->getName(), list[j]->getID());
	}

	i = 0;
	k = first;

	while (k < j && j <= last)
	{
		// if sort by ID
		if (sortMethod == SORT_ID)
		{
			// if ascending
			if (listOrder)
			{
				// copy from temp array
				if (temp[i].getID() <= list[j]->getID())
				{
					// copy from 1st list, then increment the position
					list[k]->Init(temp[i].getName(), temp[i].getID());
					++i;
				}

				// copy from 2nd half of the list
				else
				{
					list[k]->Init(list[j]->getName(), list[j]->getID());
					++j;
				}

				++k;
			}

			// descending order
			else
			{
				// copy from temp array
				if (temp[i].getID() > list[j]->getID())
				{
					// copy from 1st list, then increment the position
					list[k]->Init(temp[i].getName(), temp[i].getID());;
					++i;
				}

				// copy from 2nd half of the list
				else
				{
					list[k]->Init(list[j]->getName(), list[j]->getID());
					++j;
				}

				++k;
			}
		}

		else if (sortMethod == SORT_NAME)
		{
			// ascending order
			if (listOrder)
			{
				if (temp[i].getName() <= list[j]->getName())
				{
					// copy from 1st list, then increment the position
					list[k]->Init(temp[i].getName(), temp[i].getID());
					++i;
				}
	
				// copy from 2nd half of the list
				else
				{
					list[k]->Init(list[j]->getName(), list[j]->getID());
					++j;
				}

				++k;
			}

			else
			{
				// copy from temp array
				if (temp[i].getName() > list[j]->getName())
				{
					// copy from 1st list, then increment the position
					list[k]->Init(temp[i].getName(), temp[i].getID());;
					++i;
				}

				// copy from 2nd half of the list
				else
				{
					list[k]->Init(list[j]->getName(), list[j]->getID());
					++j;
				}

				++k;
			}
		}
	}

	// copy remaining elements from temp array, if any
	while (k < j)
	{
		list[k]->Init(temp[i].getName(), temp[i].getID());
		++i;
		++k;
	}

	// remove temp array
	delete []temp;
}

void Database::mergeSort(int first, int last)
{
	if (first < last)
	{
		// find the middle value and split
		int middle = (first + last) / 2;
		mergeSort(first, middle);
		mergeSort(middle + 1, last);
		merge(first, middle, last);
	}
}

void Database::printSpace(int numSpace)
{
	if (numSpace > 0)
	{
		for (int i = 0; i < numSpace; ++i)
		{
			cout << " ";
		}
	}
}

void Database::printList(void)
{
	// Display header
	cout << "Index";
	printSpace(2);
	cout << "Name";
	printSpace(30);
	cout << "ID" << endl;

	for (int i = 0; i < patientCount; ++i)
	{
		// print index
		cout << i + 1;

		// set the spacing 
		if (i < 10)
			printSpace(6);

		else
			printSpace(5);

		// print the name
		cout << list[i]->getName();

		// set the spacing
		printSpace(34 - (list[i]->getName()).size());

		// print the id
		cout << list[i]->getID() << endl;
	}
}

void Database::cleanUp(void)
{
	for (int i = 0; i < patientCount; ++i)
	{
		if (list[i])
		{
			delete list[i];
			list[i] = NULL;
		}
	}
}