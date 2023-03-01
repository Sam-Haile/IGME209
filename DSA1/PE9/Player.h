#pragma once
//Declared in header file

class Player
{
	// public private or protected?
		//constructor ex) Point();
		// method ex) int getX();
	public:
		Player(char* name, int vigor, int endurance, int dexterity);
		char printPlayer();

	private:
		char* name;
		int vigor;
		int endurance;
		int dexterity;






};

