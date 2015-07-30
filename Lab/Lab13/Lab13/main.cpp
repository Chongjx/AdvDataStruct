#include <conio.h>
#include "BTree.h"

void main(void)
{
	BTree intTree;

	int option = 0;
	int value = 0;
	bool exit = false;

	while (!exit)
	{
		cout << "Int Binary Tree" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Add value" << endl;
		cout << "2. Print tree" << endl;
		cout << "3. Exit" << endl;

		cin >> option;

		switch(option)
		{
			case 1:
			{
				cout << "Enter the number you would like to add: ";
				cin >> value;
				intTree.add(value);
				_getch();
				break;
			}
			case 2:
			{
				intTree.print();
				_getch();
				break;
			}
			case 3:
			{
				exit = true;
				_getch();
				break;
			}
		}
	}
}