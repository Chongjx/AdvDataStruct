#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void bubbleSort(int list[], int size, bool ascending = true)
{
	for (int iter = 1; iter < size; ++iter)
	{
		for (int index = 0; index < size - iter; ++index)
		{
			if (ascending)
			{
				// check value
				if (list[index] > list[index + 1])
				{
					int temp = list[index];
					list[index] = list[index + 1];
					list[index + 1] = temp;
				}
			}

			else
			{
				if (list[index] < list[index + 1])
				{
					int temp = list[index];
					list[index] = list[index + 1];
					list[index + 1] = temp;
				}
			}
		}
	}
}

template <int row, int col>
void bubbleSort(int (&list)[row][col], bool ascending = true)
{
	bool stop = false;
	for (int iter = 1; iter < row; ++iter)
	{
		for (int i = 0; i < row - iter; ++i)
		{
			stop = false;
			if (ascending)
			{
				// check through colum
				for (int j = 0; j < col && stop != true; ++j)
				{
					stop = true;
					// if R(j) is greater, swap everything then stop checking
					if (list[i][j] > list[i + 1][j])
					{
						int temp[1][col];

						for (int colorVar = 0; colorVar < col; ++colorVar)
						{
							temp[0][colorVar] = list[i][colorVar];
							list[i][colorVar] = list[i + 1][colorVar];
							list[i + 1][colorVar] = temp[0][colorVar];
						}
					}

					else if (list[i][j] == list[i + 1][j])
					{
						stop = false;
					}
				}
			}

			else
			{
				// check through colum
				for (int j = 0; j < col && stop != true; ++j)
				{
					stop = true;
					// if R is smaller, swap then stop checking
					if (list[i][j] < list[i + 1][j])
					{
						int temp[1][col];

						for (int colorVar = 0; colorVar < col; ++colorVar)
						{
							temp[0][colorVar] = list[i][colorVar];
							list[i][colorVar] = list[i + 1][colorVar];
							list[i + 1][colorVar] = temp[0][colorVar];
						}
					}

					else if (list[i][j] == list[i + 1][j])
					{
						stop = false;
					}
				}
			}
		}
	}
}

void selectionSort(int list[], int size, bool ascending = true)
{
	int value, index;

	// run through all the variable in the list
	for (int iter = 0; iter < size - 1; ++iter)
	{
		value = list[iter];
		index = iter;
		// find the value starting from starting pos
		for (int pos = iter + 1; pos < size; ++pos)
		{
			if (ascending)
			{
				// comparing the value and swap
				if (value > list[pos])
				{
					value = list[pos];
					index = pos;
				}
			}

			else
			{
				if (value < list[pos])
				{
					value = list[pos];
					index = pos;
				}
			}
		}

		// swap the value base on the pos found (if the index is not the same as the current loop)
		if (index != iter)
		{
			int temp = list[iter];
			list[iter] = list[index];
			list[index] = temp;
		}
	}
}

void insertionSort(int list[], int size, bool ascending = true)
{
	int index, temp;

	for (int iter = 1; iter < size; ++iter)
	{
		if (ascending)
		{
			// if the value is smaller than the number before in the list
			if (list[iter] < list[iter - 1])
			{
				temp = list[iter];
				index = iter;

				do
				{
					list[index] = list[index - 1];
					--index;
				}
				while(index > 0 && list[index - 1] > temp);
				list[index] = temp;
			}
		}

		else
		{
			if (list[iter] > list[iter - 1])
			{
				temp = list[iter];
				index = iter;

				do
				{
					list[index] = list[index - 1];
					--index;
				}
				while(index > 0 && list[index - 1] < temp);
				list[index] = temp;
			}
		}
	}
}

void swap(int &first, int &last)
{
	int temp = first;
	first = last;
	last = temp;
}

int partition(int list[], int first, int last, bool ascending = true)
{
	int middle = (first + last)/2;
	// bring the middle value to the front
	swap(list[first], list[middle]);

	int pivot = list[first];
	int smallIndex = first;

	// start after first value
	for (int i = first + 1; i <= last; ++i)
	{
		if (ascending)
		{
			if (list[i] < pivot)
			{
				++smallIndex;
				swap(list[smallIndex], list[i]);
			}
		}
		else
		{
			if (list[i] > pivot)
			{
				++smallIndex;
				swap(list[smallIndex], list[i]);
			}
		}
	}

	// swap the middle value to its right location
	swap(list[first], list[smallIndex]);
	return smallIndex;
}

void quickSort(int list[], int first, int last, bool ascending = true)
{
	// base case to prevent infinite recursive (heap corruption)
	if (first < last)
	{
		// midPoint will be at the correct location after partition
		int midPoint = partition(list, first, last, ascending);
		// Start from first, end before midPoint
		quickSort(list, first, midPoint - 1, ascending);
		// Start after midPoint, end at last
		quickSort(list, midPoint + 1, last, ascending);
	}
}

void merge(int list[], int first, int middle, int last, bool ascending = true)
{
	// temp array to hold the 1st half of the list
	int *temp = new int[middle - first + 1];

	// i - index for the temp array
	// j - index for the 2nd half of the list
	// k - index for the combine list
	int i, j, k;
	// Copy into the temp array
	for (j = first, i = 0; j <= middle; ++i, ++j)
	{
		temp[i] = list[j];
	}

	i = 0;
	k = first;

	while (k < j && j <= last)
	{
		if (ascending)
		{
			// copy from temp array
			if (temp[i] <= list[j])
			{
				// copy from 1st list, then increment the position
				list[k] = temp[i];
				++i;
			}

			// copy from 2nd half of the list
			else
			{
				list[k] = list[j];
				++j;
			}

			++k;
		}

		else
		{
			// copy from temp array
			if (temp[i] > list[j])
			{
				// copy from 1st list, then increment the position
				list[k] = temp[i];
				++i;
			}

			// copy from 2nd half of the list
			else
			{
				list[k] = list[j];
				++j;
			}

			++k;
		}
	}

	// copy remaining elements from temp array, if any
	while (k < j)
	{
		list[k] = temp[i];
		++i;
		++k;
	}

	// remove temp array
	delete []temp;
}

void mergeSort(int list[], int first, int last, bool ascending = true)
{
	if (first < last)
	{
		// find the middle value and split
		int middle = (first + last)/ 2;
		mergeSort(list, first, middle, ascending);
		mergeSort(list, middle + 1, last, ascending);
		merge(list, first, middle, last, ascending);
	}
}

void printList(int list[], int size)
{
	cout << "{ ";
	for (int i = 0; i < size; ++i)
	{
		cout << list[i] << " ";
	}
	cout << "}" << endl;
}

template <int row, int col>
void printList(int (&list)[row][col])
{
	cout << "Colors    R   G   B  " << endl;
	for (int i = 0; i < row; ++i)
	{
		cout << "Color " << i + 1 << " :";
		for (int j = 0; j < col; ++j)
		{
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void ex1(void)
{
	cout << "Ex1" << endl;

	int list[10] = {34, 45, 12, 2, 456, 78, 103, 423, 67, 4};
	cout << "Original list" << endl;
	printList(list, sizeof(list)/4);

	bubbleSort(list, sizeof(list)/4);
	cout << "Ascending list" << endl;
	printList(list, sizeof(list)/4);

	bubbleSort(list, sizeof(list)/4, false);
	cout << "Descending list" << endl;
	printList(list, sizeof(list)/4);

	cout << endl;
}

void ex2(void)
{
	cout << "Ex2" << endl;
	int list[10] = {34, 45, 12, 2, 456, 78, 103, 423, 67, 4};
	cout << "Original list" << endl;
	printList(list, sizeof(list)/4);

	selectionSort(list, sizeof(list)/4);
	cout << "Ascending list" << endl;
	printList(list, sizeof(list)/4);

	selectionSort(list, sizeof(list)/4, false);
	cout << "Descending list" << endl;
	printList(list, sizeof(list)/4);

	cout << endl;
}

void ex3(void)
{
	cout << "Ex3" << endl;
	int list[10] = {34, 45, 12, 2, 456, 78, 103, 423, 67, 4};
	cout << "Original list" << endl;
	printList(list, sizeof(list)/4);

	insertionSort(list, sizeof(list)/4);
	cout << "Ascending list" << endl;
	printList(list, sizeof(list)/4);

	insertionSort(list, sizeof(list)/4, false);
	cout << "Descending list" << endl;
	printList(list, sizeof(list)/4);

	cout << endl;
}

void ex4(void)
{
	cout << "Additional Ex" << endl;
	int list[8][3] = {
		{144, 33, 123},
		{21, 134, 1},
		{144, 234, 12},
		{243, 123, 212},
		{144, 33, 21},
		{32, 123, 78},
		{123, 21, 1},
		{21, 231, 2}
	};

	cout << "Original list" << endl;
	printList(list);

	bubbleSort(list);
	cout << "Ascending list" << endl;
	printList(list);

	bubbleSort(list, false);
	cout << "Descending list" << endl;
	printList(list);

	cout << endl;
}

void ex5(void)
{
	cout << "Ex5" << endl;
	int list[10] = {34, 45, 12, 2, 456, 78, 103, 423, 67, 4};
	cout << "Original list" << endl;
	printList(list, sizeof(list)/4);

	quickSort(list, 0, sizeof(list)/4 - 1);
	cout << "Ascending list" << endl;
	printList(list, sizeof(list)/4);

	quickSort(list, 0, sizeof(list)/4 - 1, false);
	cout << "Descending list" << endl;
	printList(list, sizeof(list)/4);

	cout << endl;
}

void ex6(void)
{
	cout << "Ex6" << endl;
	int list[10] = {34, 45, 12, 2, 456, 78, 103, 423, 67, 4};
	cout << "Original list" << endl;
	printList(list, sizeof(list)/4);

	mergeSort(list, 0, sizeof(list)/4 - 1);
	cout << "Ascending list" << endl;
	printList(list, sizeof(list)/4);

	mergeSort(list, 0, sizeof(list)/4 - 1, false);
	cout << "Descending list" << endl;
	printList(list, sizeof(list)/4);

	cout << endl;
}

void main(void)
{
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
}