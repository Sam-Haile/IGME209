// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Logic for game
#include <iostream>
#include <vector>
#include "hangman.h"
using namespace std;

int main()
{
	startGame();

	string wordToGuess = "espionage";
	string answer = "_________";
	int misses = 0;
	vector<char> incorrect;
	bool guess = false;
	char letter;


	while (answer != wordToGuess && misses < 7)
	{
		showGallows(misses);
		showSolveDisplay(answer, incorrect);

		cout << "\n\nPlease enter your guess: ";
		cin >> letter;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < wordToGuess.length(); i++)
		{
			if (letter == wordToGuess[i])
			{
				answer[i] = letter;
				guess = true;
			}
		}
		if (guess)
		{
			cout << "\nCorrect!\n";
		}
		else
		{
			cout << "\nIncorrect!\n";
			incorrect.push_back(letter);
			misses++;
		}
		guess = false;
	}

	endGame(answer, wordToGuess);
	return 0;
}


