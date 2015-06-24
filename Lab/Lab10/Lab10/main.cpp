#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool linearSearchValue(int list[], int value, int listSize)
{
	for (int i = 0; i < listSize; ++i)
	{
		if (value == list[i])
		{
			return true;
		}
	}

	return false;
}

bool binarySearchValue(int list[], int value, int listSize)
{
	unsigned int midPoint = 0;
	unsigned int startPoint = 0;
	unsigned int endPoint = listSize - 1;

	while (startPoint <= endPoint)
	{
		midPoint = (startPoint + endPoint) * 0.5f;

		if (value == list[midPoint])
		{
			return true;
		}

		// if value is less than midpoint value
		else if (value < list[midPoint])
		{
			endPoint = midPoint - 1;
		}

		// if value is more than midpoint value
		else
		{
			startPoint = midPoint + 1;
		}
	}

	return false;
}

int findPosition(int list[], int value, int listSize)
{
	for (int i = 0; i < listSize; ++i)
	{
		if (value == list[i])
		{
			return i;
		}
	}

	return 0;
}

bool addValue(int list[], int value,const int listSize)
{
	unsigned int previous = 0;
	unsigned int next = previous + 1;

	// temporary storage
	vector<int> tempList;

	for (int i = 0; i < listSize; ++i)
	{
		tempList.push_back(list[i]);
	}

	// if value to be added is smallest
	if (value < list[0])
	{
		list[0] = value;

		for (int i = 1; i < listSize; ++i)
		{
			list[i] = tempList[i - 1];
		}

		return true;
	}

	else
	{
		while(next < listSize)
		{
			// check if the value should be added inbetween
			if(value > list[previous] && value < list[next])
			{
				// copy value from vector back into array
				for (int i = 0; i < next; ++i)
				{
					list[i] = tempList[i];
				}

				// add value into array
				list[next] = value;

				// copy the remaining values from vector back into array
				for (int i = next + 1; i < listSize; ++i)
				{
					list[i] = tempList[i - 1];
				}

				return true;
			}

			previous = next;
			next = previous + 1;
		}
	}

	// else if the value is largest
	if (value > list[listSize - 1])
	{
		list[listSize - 1] = value;

		return true;
	}

	return false;
}

bool removeValue(int list[], int value, int listSize)
{
	unsigned int current = 0;

	// temporary storage
	vector<int> tempList;

	for (int i = 0; i < listSize; ++i)
	{
		tempList.push_back(list[i]);
	}

	current = findPosition(list, value, listSize);

	// push value from vector into array
	for (int i = 0; i < current; ++i)
	{
		list[i] = tempList[i];
	}

	for (int i = current; i < listSize; ++i)
	{
		if (i + 1 < listSize)
		{
			list[i] = tempList[i + 1];
		}

		else
		{
			list[i] = NULL;
		}
	}

	return true;
}

void printList(int list[], int listSize)
{
	cout << "[";
	for (int i = 0; i < listSize; ++i)
	{
		cout << list[i] << " ";
	}
	cout << "]";
}

void ex1(void)
{
	cout << "Exercise 1" << endl;

	int value = 0;
	int searchMethod = 0;
	bool exit = false;

	int list[] = {1, 2, 8, 15, 99, 111, 200, 201, 800, 1010, 1500};

	do
	{
		cout << "Enter the number you want to search: ";

		cin >> value;

		if (value == 666)
		{
			exit = true;
			break;
		}

		cout << "Enter the search mehtod you want (1. Linear search, 2. Binary search): ";

		cin >> searchMethod;

		if (searchMethod == 1)
		{
			if(linearSearchValue(list, value, sizeof(list)/4))
			{
				cout << value << " is at index " << findPosition(list, value, sizeof(list)/4) << endl;
			}

			else
			{
				cout << "Number not found!" << endl;
			}
		}

		else if (searchMethod == 2)
		{
			if(binarySearchValue(list, value, sizeof(list)/4))
			{
				cout << value << " is at index " << findPosition(list, value, sizeof(list)) << endl;
			}

			else
			{
				cout << "Number not found!" << endl;
			}
		}

		else
		{
			cout << "Invalid input!" << endl;
		}

		cout << endl;
	}

	while (!exit);
}

void ex2(void)
{
	cout << "Exercise 2" << endl;

	int value = 0;
	int option = 0;
	bool exit = false;

	int list[] = {1, 2, 8, 15, 99, 111, 200, 201, 800, 1010, 1500};

	do
	{
		cout << "What do you want to do? (1. Add number, 2. Remove number): ";

		cin >> option;

		if (option == 1)
		{
			cout << "Enter the number you want to add: ";
			cin >> value;

			if (linearSearchValue(list, value, sizeof(list)/4))
			{
				cout << "Number is already in the list!" << endl;
			}

			else
			{
				if(addValue(list, value, sizeof(list)/4))
				{
					cout << value << " added!" << endl;
					printList(list, sizeof(list)/4);
					cout << endl;
				}
			}
		}

		else if (option == 2)
		{
			if (list[0] != NULL)
			{
				cout << "Enter the number you want to remove: ";
				cin >> value;

				if (!linearSearchValue(list, value, sizeof(list)/4))
				{
					cout << "Number not found!" << endl;
				}

				else
				{
					if(removeValue(list, value, sizeof(list)/4))
					{
						cout << value << " removed!" << endl;
						printList(list, sizeof(list)/4);
						cout << endl;
					}
				}
			}

			else
			{
				cout << "List is empty!" << endl;
			}
		}

		else if (option == 3)
		{
			exit = true;
			break;
		}

		else
		{
			cout << "Invalid input!" << endl;
		}

		cout << endl;
	}

	while (!exit);
}

void main(void)
{
	//ex1();

	//cout << endl;

	ex2();
}