#pragma once
#include "Player.h"

class Fighter :
    public Player
{
public:
    Fighter();
    Fighter(char* name, char* skill, int vigor, int endurance, int dexterity);
    void printFighter();

private:
    const char* m_skill;
};

