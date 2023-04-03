#pragma once
#include <string>
#include <iostream>

class Level
{

public:

	int m_levelNumber;
	std::string m_exitLocation;
	std::string m_numOfEnemies[3];
	
	Level();

	~Level() {

		std::cout << "Destructor Executed" << std::endl;
	}
	

};

