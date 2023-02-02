// PE4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	// Define a string
	char word[100] = "supercalifragilistic";

	// Determine it's length
	cout << "The length of the string is " << strlen(word) << endl;

	// Define second string
	char word2[15] = "expialidocious";

	// Concatinate the second word to the first one
	strcat_s(word, word2);
	cout << "\nThe word is: " << word << endl;

	// Determine how many times the letter 'i' appears in the word
	int countLetters(string s);
	{
		int numOfLetters = 0;

		// Loop through the given words
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] == 'i')
			{
				numOfLetters++;
			}
		}

		// Display number of letters
		cout << "\nNumber of letter I's in the word: " << numOfLetters << endl;
	}


 }