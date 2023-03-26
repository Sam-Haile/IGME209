// PE11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Item.h"
#include "Sword.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
using namespace std;

int main()
{
	Sword* sword = new Sword("Sword", 50, 10, 100);
	Helmet* helmet = new Helmet("Helmet", 3, 7, 90);
	Armor* armor = new Armor("Armor", 2, 9, 60);
	Shield* shield = new Shield("Shield", 5, 8, 30);

	std::vector<Item*> inventory;

	inventory.push_back(sword);
	inventory.push_back(helmet);
	inventory.push_back(armor);
	inventory.push_back(shield);

	for (int i = 0; i < inventory.size(); i++)
	{
		inventory[i]->print();
	}

	delete sword;
	delete helmet;
	delete armor;
	delete shield;
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
