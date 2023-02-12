#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster* boss = new Monster();
	//Player* pOne = new Player();

	/* The difference with the pOne object is that 
	it is now treated as an object of type MovableObject,
	rather than Player. As a result, the memory for the 
	Player object's name variable is not freed when 
	the object is deleted, which will lead to an error */
	
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster* fakeMonster = (Monster*)pOne;

	// Adressess of variables
	cout << "Address of the boss: " << &boss << endl;
	cout << "Address of the pOne: " << &pOne << endl;
	cout << "Address of the fakeMonster: " << &fakeMonster << endl;

	boss->xPos = 10;
	boss->yPos = 40;
	pOne->xPos = 13;
	pOne->yPos = 26;

	boss->PrintPos();
	pOne->PrintPos();

	delete boss;
	delete pOne;

	/* When deleting fakeMonster the program
	   is trying to free the same memory that
	   was deleted during 'delete pOne'. */
	   //delete fakeMonster;
	return 0;
}