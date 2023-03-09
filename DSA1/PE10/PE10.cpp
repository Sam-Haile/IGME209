// PE10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;

int main()
{

	//PE9 WORK
	/*
	std::cout<< "STACK / DEFAULT CONSTRUCTOR" << endl;
	Player player1 = Player();
	player1.printPlayer();
	std::cout << endl;

	std::cout<< "STACK / PARAMETERIZED CONSTRUCTOR" << endl;
	char myString[] = "Sam";
	Player player2 = Player(myString, 18, 21, 25);
	player2.printPlayer();
	std::cout << endl;

	std::cout << "HEAP / DEFAULT CONSTRUCTOR" << endl;
	Player* player3 = new Player();
	player3->printPlayer();
	std::cout << endl;

	std::cout << "HEAP / PARAMETERIZED CONSTRUCTOR" << endl;
	char myString2[] = "Mas";
	Player* player4 = new Player(myString2, 81, 72, 28);
	player4->printPlayer();
	std::cout << endl;

	delete[] player3;
	delete[] player4;*/

	Fighter* fighter1 = new Fighter();
	fighter1->printFighter();
	std::cout << endl;

	char name[] = "Sam";
	char skill[] = "Slash";
	Fighter* fighter2 = new Fighter(name, skill, 53, 38, 95);
	fighter2->printFighter();




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
