// PE18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include "NumberPrinter.h"
#include "GamePlay.h"
using namespace std;

int main()
{
#pragma region  Part 1: Main Method

	vector<thread*> threads;

	for (int i = 0; i < 50 ; i++)
	{
		NumberPrinter numPrnt = NumberPrinter(1);
		//numPrnt.Print();
		
		thread* threadPt1 = new thread(&NumberPrinter::Print, numPrnt);
		threads.push_back(threadPt1);
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->join();
		delete threads[i];
	}

#pragma endregion


#pragma region Part 2: A Real-World Example

	vector<thread*> threads2;

	GamePlay* gamePlay = new GamePlay("Physics");
	GamePlay* gamePlay2 = new GamePlay("Pathfinding");
	GamePlay* gamePlay3 = new GamePlay("Rendering");
	GamePlay* gamePlay4 = new GamePlay("Compression");
	GamePlay* gamePlay5 = new GamePlay("Encryption");

	thread* thread1 = new thread(&GamePlay::Update, gamePlay);
	thread* thread2 = new thread(&GamePlay::Update, gamePlay2);
	thread* thread3 = new thread(&GamePlay::Update, gamePlay3);
	thread* thread4 = new thread(&GamePlay::Update, gamePlay4);
	thread* thread5 = new thread(&GamePlay::Update, gamePlay5);

	threads2.push_back(thread1);
	threads2.push_back(thread2);
	threads2.push_back(thread3);
	threads2.push_back(thread4);
	threads2.push_back(thread5);

	for (int i = 0; i < threads2.size(); i++)
	{
		threads2[i]->join();
		delete threads2[i];
	}

	std::cout << "Update Complete! Time to Draw" << std::endl;

#pragma endregion





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
