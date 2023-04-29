#include "GamePlay.h"


GamePlay::GamePlay(string name)
{
	m_name = name;
}

void GamePlay::Update()
{
	int j = 10;
	for (int i = 0; i < 10; i++)
	{
		std::cout << m_name << ": " << j << "% Complete" << std::endl;
		j += 10;
	}
}





