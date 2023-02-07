#include <iostream>
#include "functions.h"
#include <time.h>
using namespace std;

int main()
{
	
	// PT1 of PE6
	cout << "How many random number do you want?   ";
	int numberOfRandoms;
	cin >> numberOfRandoms;
	generateRandom(numberOfRandoms);

	// PT2 of PE6
	char inputString[128 ];
	cout << "Input a string:   ";
	cin >> inputString;
	cout << reverseString(inputString);
}

// Generates random numbers 
void generateRandom(int numberOfRandoms)
{
	// Seed Random 
	srand(time(NULL));

	for (int i = 0; i < numberOfRandoms; i++)
	{
		int number = rand();
		cout << "Position: " << i + 1 << "\t Random number: " << number << endl;
	}
}

char* reverseString(char inputString[]){
		char newString[256] = "";
		int length = strlen(inputString);
		for (int i = 0; i < length; i++)
		{
			char c = inputString[i];
			// The for loop was using the wrong index here
			// Arrays are 0 indexed
			newString[length - i - 1] = c;
		}
		strcpy_s(inputString, 128, newString);
		return inputString;
}
