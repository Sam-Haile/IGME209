#include "Level.h"
#include <string>
#include <iostream>
using namespace std;


Level::Level()
{
	m_levelNumber = 0;
	m_exitLocation = "Exit Door";
	m_numOfEnemies[0] = "Enemy1";
	m_numOfEnemies[1] = "Enemy2";
	m_numOfEnemies[2] = "Enemy3";
}
