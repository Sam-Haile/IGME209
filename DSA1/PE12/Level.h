#pragma once
#include <string>
#include <iostream>

class Level
{

public:

	int m_levelNumber;
	std::string m_exitLocation;
	std::string m_numOfEnemies[3];
	
	Level()
	{
		std::cout << "Constructor Executed" << endl;
	}

	~Level() {

		std::cout << "Destructor Executed" << endl;
	}
	

};

