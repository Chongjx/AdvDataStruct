#include "Application.h"

Application::Application(void) :
exit(false)
{
}

Application::~Application(void)
{
}

void Application::Init(void)
{
	this->exit = false;
	this->option = NULL;
}

void Application::Run(void)
{
	// start up
	system("CLS");
	cout << "Jx Clinic Patient's Database" << endl;
	cout << endl;

	// display options
	cout << "1. Add Patient" << endl;
	cout << "2. Remove Patient" << endl;
	cout << "3. Search Patient" << endl;
	cout << "4. Sort Patients" << endl;
	cout << "5. Print records" << endl;
	cout << "6. Exit program" << endl;

	cin >> option;

	switch (option)
	{
	case '1':
		{
			// ADD PATIENT
			system("CLS");

			// if list is full, do not proceed
			if (jxClinic.getListFull())
			{
				cout << "Database is full!" << endl;
				flushInput();
				_getch();
				break;
			}

			string tempName;
			string tempID;
			flushInput();
			cout << "Enter Patient's name: ";
			getline(cin, tempName);

			// handle error checking for name
			if (!jxClinic.validateName(tempName))
			{
				cout << "Name must be contain at least 1 character!" << endl;
				flushInput();
				_getch();
				break;
			}

			cin.clear();
			cout << "Enter Patient's ID: ";
			cin >> tempID;

			// handle error checking for ID
			if (!jxClinic.validateID(tempID))
			{
				cout << "Invalid ID entered! ID must be between 0 to 99999" << endl;
				flushInput();
				_getch();
				break;
			}

			Patient* newPatient = new Patient(tempName, atoi(tempID.c_str()));
			jxClinic.addPatient(newPatient);

			cout << endl << "New Patient added!" << endl;
			cout << "Patient: " << newPatient->getName() << endl;
			cout << "ID: " << newPatient->getID();

			flushInput();
			_getch();
			break;
		}
	case '2':
		{
			// REMOVE PATIENT
			system("CLS");

			// if list is empty, do not proceed
			if (HandleEmptyDatabase())
			{
				break;
			}

			string patientInfo;
			flushInput();
			cout << "Enter patient name or ID: ";
			getline(cin, patientInfo);
			int pos = -1;

			// if the list is sorted
			if (jxClinic.getListSorted())
			{
				// if the list is sorted by name, use binary search for name and linear search for ID
				if (jxClinic.getSortMethod() == SORT_NAME)
				{
					if (!jxClinic.binarySearch(patientInfo, pos) && !jxClinic.sequentialSearch(atoi(patientInfo.c_str()), pos))
					{
						cout << "No record found!" << endl;
						flushInput();
						_getch();
						break;
					}
				}
				// else if the list is sorted by id use binary search for ID and linear search for name
				else if (jxClinic.getSortMethod() == SORT_ID)
				{
					if (!jxClinic.binarySearch(atoi(patientInfo.c_str()), pos) && !jxClinic.sequentialSearch(patientInfo, pos))
					{
						cout << "No record found!" << endl;
						flushInput();
						_getch();
						break;
					}
				}
			}

			// else use linear search to find the patient
			else
			{
				if (!jxClinic.sequentialSearch(patientInfo, pos) && !jxClinic.sequentialSearch(atoi(patientInfo.c_str()), pos))
				{
					cout << "No record found!" << endl;
					flushInput();
					_getch();
					break;
				}
			}

			cout << "Removing now... " << endl;
			jxClinic.removePatient(pos);
			cout << "Patient removed!" << endl;

			_getch();
			break;
		}
	case '3':
		{
			// SEARCH PATIENT
			system("CLS");

			// if list is empty, do not proceed
			if (HandleEmptyDatabase())
			{
				break;
			}

			char searchOption;
			cout << "Search by name<N> or ID<D>: ";
			cin >> searchOption;

			searchOption = toupper(searchOption);
			// invalid search option
			if (searchOption != 'N' && searchOption != 'D')
			{
				cout << "Invalid search option!" << endl;
				flushInput();
				_getch();
				break;
			}

			flushInput();
			string searchString;
			int pos = -1;
			cout << "Enter search text: ";
			getline(cin, searchString);

			// if the list is sorted by name and the search option is name, use binary search
			// if the list is sorted by name and the search option is ID, use linear search
			// if the list is sorted by ID and the search option is name, use linear search
			// if the list is sorted by ID and the search option is ID, use binary search
			// if the list is unsorted, use linear search

			if (!jxClinic.getListSorted())
			{
				if (searchOption == 'N')
				{
					if (!jxClinic.sequentialSearch(searchString, pos))
					{
						cout << "No record found!" << endl;
					}
				}

				else
				{
					if (!jxClinic.sequentialSearch(atoi(searchString.c_str()), pos))
					{
						cout << "No record found!" << endl;
					}
				}
			}

			else
			{
				if (jxClinic.getSortMethod() == SORT_NAME)
				{
					if (searchOption == 'N')
					{
						if (!jxClinic.binarySearch(searchString, pos))
						{
							cout << "No record found!" << endl;
						}
					}

					else
					{
						if (!jxClinic.sequentialSearch(atoi(searchString.c_str()), pos))
						{
							cout << "No record found!" << endl;
						}
					}
				}

				else if(jxClinic.getSortMethod() == SORT_ID)
				{
					if (searchOption == 'N')
					{
						if (!jxClinic.sequentialSearch(searchString, pos))
						{
							cout << "No record found!" << endl;
						}
					}

					else
					{
						if (!jxClinic.binarySearch(atoi(searchString.c_str()), pos))
						{
							cout << "No record found!" << endl;
						}
					}
				}
			}

			_getch();
			break;
		}
	case '4':
		{
			// SORT PATIENT
			system("CLS");

			// if list is empty, do not proceed
			if (HandleEmptyDatabase())
			{
				break;
			}

			char sortOption;
			cout << "Sort by name<N> or ID<D>: ";
			cin >> sortOption;

			sortOption = toupper(sortOption);
			// invalid sort option
			if (sortOption != 'N' && sortOption != 'D')
			{
				cout << "Invalid sort option!" << endl;
				flushInput();
				_getch();
				break;
			}

			char sortOrder;
			cout << "Ascending <A> or Descending <D> order: ";
			cin >> sortOrder;

			sortOrder = toupper(sortOrder);
			if (sortOrder != 'A' && sortOrder != 'D')
			{
				cout << "Invalid sort option!" << endl;
				flushInput();
				_getch();
				break;
			}

			cout << "Sorting... " << endl;
			// if the list is to be sorted by name and in ascending order, use SORT_TYPE SORT_NAME, sort order true
			// if the list is to be sorted by name and in descending order, use SORT_TYPE SORT_NAME, sort order false
			// if the list is to be sorted by ID and in ascending order, use SORT_TYPE SORT_ID, sort order true
			// if the list is to be sorted by ID and in descending order, use SORT_TYPE SORT_ID, sort order false
			if (sortOption == 'N')
			{
				jxClinic.setSortMethod(SORT_NAME);
				if (sortOrder == 'A')
				{
					jxClinic.setSortOrder(true);
				}
				else
				{
					jxClinic.setSortOrder(false);
				}
			}

			else
			{
				jxClinic.setSortMethod(SORT_ID);
				if (sortOrder == 'A')
				{
					jxClinic.setSortOrder(true);
				}
				else
				{
					jxClinic.setSortOrder(false);
				}
			}

			jxClinic.sort();

			cout << "Sorted!" << endl;

			_getch();
			break;
		}
	case '5':
		{
			// PRINT DATABASE
			system("CLS");

			// if list is empty, do not proceed
			if (HandleEmptyDatabase())
			{
				break;
			}

			this->jxClinic.printList();

			_getch();
			break;
		}
	case '6':
		{
			this->exit = true;
			break;
		}
	default:
		{
			cout << "Invalid Input!" << endl;
			_getch();
			break;
		}
	}
}

void Application::Exit(void)
{
	jxClinic.cleanUp();
}

bool Application::HandleEmptyDatabase(void)
{
	// if list is empty, do not proceed
	if (jxClinic.getListEmpty())
	{
		cout << "Database is empty!" << endl;
		flushInput();
		_getch();
		return true;
	}

	return false;
}

void Application::flushInput(void)
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

bool Application::getExit(void)
{
	return exit;
}