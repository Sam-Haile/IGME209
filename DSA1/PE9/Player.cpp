#include "Player.h"
#include <iostream>
// Class definitions
// defines methods constructors and desructors


/*
ex) Point::Point()
{
	x = 0;
	y = 0;
	
	
	Methods – Again, class name
	before ::
		int Point::getX() { return x; }
	int Point::getY() { return y; }
	
	
	}
*/

Player::Player() 
{
	//Use the string 'unknown' below
	//name

	vigor = 10;
	endurance = 10;
	dexterity = 10;
}

Player::Player(/*char* name,*/ int vigor, int endurance, int dexterity)
{
	//this->name = new char[strlen(name) + 1];
	//strcpy(this->name, name);

	this->vigor = vigor;
	this->endurance = endurance;
	this->dexterity = dexterity;
}

void Player::printPlayer()
{
	//std::cout << name << std::endl;
	std::cout << "Vigor: " << vigor << std::endl;
	std::cout << "Endurance: " << endurance << std::endl;
	std::cout << "Dexterity: " << dexterity << std::endl;
}