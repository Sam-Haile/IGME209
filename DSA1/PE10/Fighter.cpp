#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter() 
{
}

Fighter::Fighter(char* name, char* skill, int vigor, int endurance, int dexterity)
	: Player(name, vigor, endurance, dexterity)
{
	m_skill = skill;
}

void Fighter::printFighter() 
{
	printPlayer();
	std::cout << "Weapon Skill: " << m_skill << std::endl;
}