#include "Player.h"
#include <iostream>
#include <string.h>
using namespace std;
// Class definitions
// defines methods constructors and desructors
Player::Player() 
{
	m_name = "Uknown";
	m_vigor = 10;
	m_endurance = 10;
	m_dexterity = 10;
}

Player::Player(char* name, int vigor, int endurance, int dexterity)
{
	m_name = name;
	m_vigor = vigor;
	m_endurance = endurance;
	m_dexterity = dexterity;
}

void Player::printPlayer()
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Vigor: " << m_vigor << std::endl;
	std::cout << "Endurance: " << m_endurance << std::endl;
	std::cout << "Dexterity: " << m_dexterity << std::endl;
}