#include "Enemy.h"

void insertionSort(CEnemy list[], int size)
{
	int index;
	CEnemy temp;

	for (int iter = 1; iter < size; ++iter)
	{
		if (list[iter].getDexterity() == list[iter - 1].getDexterity())
		{
			if (list[iter].getStrength() == list[iter - 1].getStrength())
			{
				if (list[iter].getIntelligence() == list[iter - 1].getIntelligence())
				{
					continue;
				}

				else if (list[iter].getIntelligence() > list[iter - 1].getIntelligence())
				{
					temp = list[iter];
					index = iter;

					do
					{
						list[index] = list[index - 1];
						--index;
					}
					while(index > 0 && list[index - 1].getIntelligence() <= temp.getIntelligence());
					list[index] = temp;
				}
			}

			else if (list[iter].getStrength() > list[iter - 1].getStrength())
			{
				temp = list[iter];
				index = iter;

				do
				{
					list[index] = list[index - 1];
					--index;
				}
				while(index > 0 && list[index - 1].getStrength() <= temp.getStrength());
				list[index] = temp;
			}
		}

		else if (list[iter].getDexterity() > list[iter - 1].getDexterity())
		{
			temp = list[iter];
			index = iter;

			do
			{
				list[index] = list[index - 1];
				--index;
			}
			while(index > 0 && list[index - 1].getDexterity() <= temp.getDexterity());
			list[index] = temp;
		}

		// check against previous adjacent enemy
		// comapring dex, descending order
		/*if (list[iter].getDexterity() > list[iter - 1].getDexterity())
		{
			temp = list[iter];
			index = iter;

			do
			{
				list[index] = list[index - 1];
				--index;
			}
			while(index > 0 && list[index - 1].getDexterity() <= temp.getDexterity());
			list[index] = temp;

			// if their dex is the same, compare str
			if(list[index].getDexterity() == list[index - 1].getDexterity())
			{
				if (list[iter].getStrength() > list[iter - 1].getStrength())
				{
					temp = list[iter];
					index = iter;

					do
					{
						list[index] = list[index - 1];
						--index;
					}
					while(index > 0 && list[index - 1].getStrength() <= temp.getStrength());
					list[index] = temp;

					// if their str is the same, compare int
					if(list[index].getStrength() == list[index - 1].getStrength())
					{
						if (list[iter].getIntelligence() > list[iter - 1].getIntelligence())
						{
							temp = list[iter];
							index = iter;

							do
							{
								list[index] = list[index - 1];
								--index;
							}
							while(index > 0 && list[index - 1].getIntelligence() <= temp.getIntelligence());
							list[index] = temp;
						}
					}
				}
			}
		}*/
	}
}

void main(void)
{
	static const int NUM_ENEMIES = 10;
	CEnemy e1(65,32,12);
	CEnemy e2(14,55,23);
	CEnemy e3(34,77,15);
	CEnemy e4(23,62,48);
	CEnemy e5(59,24,38);
	CEnemy e6(34,77,98);
	CEnemy e7(73,41,55);
	CEnemy e8(45,62,48);
	CEnemy e9(34,99,13);
	CEnemy e10(88,88,88);

	CEnemy enemyList[10] = {e1,e2,e3,e4,e5,e6,e7,e8,e9,e10};

	insertionSort(enemyList, NUM_ENEMIES);

	std::cout << "DEX STR INT" << std::endl;

	for (int i = 0; i < NUM_ENEMIES; ++ i)
	{
		enemyList[i].print();
	}
}