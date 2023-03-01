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
	name == "Unknown"; //CHECK 
	vigor = 10;
	endurance = 10;
	dexterity = 10;
}

Player::Player(char* name, int vigor, int endurance, int dexterity)
{
	this->name = name;
	this->vigor = vigor;
	this->endurance = endurance;
	this->dexterity = dexterity;
}

Player::printPlayer()
{
	std::cout << name << std::endl;
	std::cout << "Strength: " << 

}