#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::pair;

void main(void)
{
	bool endProgram = false;
	bool addIzan = false;
	map<string, string> nameList;
	map<string, string>::iterator stringIter;

	nameList["12345"] = "A";
	nameList["23456"] = "B";
	nameList["34567"] = "C";
	nameList["45678"] = "D";
	nameList["56789"] = "E";
	nameList["67890"] = "F";

	while (!endProgram)
	{
		string name;

		cout << "Enter name: ";
		cin >> name;

		if (name != "nil")
		{
			string adminNo;

			cout << "Enter adminNo: ";
			cin >> adminNo;

			stringIter = nameList.begin();
			nameList.insert(stringIter, pair<string, string>(adminNo, name));
		}

		else
		{
			endProgram = true;
		}

		if (!addIzan)
		{
			stringIter = nameList.begin();
			++stringIter;
			nameList.insert(stringIter, pair<string, string>("00000", "Izan"));
			addIzan = true;
		}

		cout << endl;

		if (endProgram)
		{
			string searchAdmin;

			cout << "Enter the admin no you want to find: ";

			cin >> searchAdmin;

			stringIter = nameList.find(searchAdmin);

			if(stringIter != nameList.end())
			{
				cout << "Name: " << stringIter->second << endl;
			}
			else
			{
				cout << "Admin number not found!" << endl;
			}

			cout << endl;
			for (stringIter = nameList.begin(); stringIter != nameList.end(); ++stringIter)
			{
				cout << stringIter->second << "'s admin no is: " << stringIter->first << endl;
			}
			break;
		}
	}
}