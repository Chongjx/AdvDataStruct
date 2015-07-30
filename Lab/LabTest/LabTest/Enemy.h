#pragma once
#include <iostream>
using namespace std;

class CEnemy
{
private:
	int strength;
	int dexterity;
	int intelligence;
public:
	CEnemy(void);
	CEnemy(int strength, int dexterity, int intelligence);
	~CEnemy(void);

	void set(int strength, int dexterity, int intelligence);

	int getStrength(void);
	int getDexterity(void);
	int getIntelligence(void);

	//Any other functions you may wish to add
	// . . .
	void setStrength(int strength);
	void setDexterity(int dexterity);
	void setIntelligence(int intelligence);

	CEnemy & operator= (CEnemy &input);

	void print(void);
};