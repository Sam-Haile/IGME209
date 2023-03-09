#pragma once
//Declared in header file

class Player
{
	// public private or protected?
		//constructor ex) Point();
		// method ex) int getX();

	public:
		Player();
		Player(char* name, int vigor, int endurance, int dexterity);
		void printPlayer();

	private:
		const char* m_name;
		int m_vigor;
		int m_endurance;
		int m_dexterity;
};

