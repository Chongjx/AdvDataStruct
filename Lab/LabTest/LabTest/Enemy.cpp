#include "Enemy.h"

CEnemy::CEnemy(void) :
strength(0),
	dexterity(0),
	intelligence(0)
{
}

CEnemy::CEnemy(int strength, int dexterity, int intelligence)	:
strength(strength),
	dexterity(dexterity),
	intelligence(intelligence)
{
}

CEnemy::~CEnemy(void)
{
}

void CEnemy::set(int strength, int dexterity, int intelligence)
{
	this->strength = strength;
	this->dexterity = dexterity;
	this->intelligence = intelligence;
}

int CEnemy::getStrength(void)
{
	return this->strength;
}

int CEnemy::getDexterity(void)
{
	return this->dexterity;
}

int CEnemy::getIntelligence(void)
{
	return this->intelligence;
}

void CEnemy::setStrength(int strength)
{
	this->strength = strength;
}

void CEnemy::setDexterity(int dexterity)
{
	this->dexterity = dexterity;
}

void CEnemy::setIntelligence(int intelligence)
{
	this->intelligence = intelligence;
}

CEnemy &CEnemy::operator=(CEnemy &input)
{
	this->strength = input.strength;
	this->dexterity = input.dexterity;
	this->intelligence = input.intelligence;

	return *this;
}

void CEnemy::print(void)
{
	std::cout << this->dexterity << ", " << this->strength << ", " << this->intelligence << std::endl;
}