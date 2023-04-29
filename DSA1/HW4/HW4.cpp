// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Stack.h"
using namespace std;

int main()
{

#pragma region IntStack

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);


    std::cout << "INT STACK:" << std::endl;
    Stack<int> intStack(2);
    
    intStack.Push(17);
    intStack.Push(53);
    intStack.Push(235);
    intStack.Push(9);
    intStack.Print();

    std::cout << "Used pop TWICE on the intStack" << std::endl;  
    intStack.Pop();
    intStack.Pop();
    intStack.Print();
    std::cout << std::endl;

#pragma endregion

#pragma region BoolStack

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);


    std::cout << "BOOL STACK:" << std::endl;
    Stack<bool> boolStack(5);

    boolStack.Push(true);
    boolStack.Push(false);
    boolStack.Push(true);
    boolStack.Push(true);
    boolStack.Print();

    std::cout << "Used pop once on the boolStack" << std::endl;
    boolStack.Pop();
    intStack.Print();
    std::cout << std::endl;

#pragma endregion

#pragma region CharStack

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


    std::cout << "CHAR STACK:" << std::endl;
    Stack<char> charStack(6);

    charStack.Push('a');
    charStack.Push('b');
    charStack.Push('1');
    charStack.Push('2');
    charStack.Print();
    
    std::cout << "Used pop ONE times on the charStack" << std::endl;
    charStack.Pop();
    charStack.Print();
    std::cout << std::endl;
#pragma endregion
    
#pragma region Copy Constructor

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

    std::cout << "NEW CHAR STACK USING COPY CONSTRUCTOR:" << std::endl;

    Stack<char> charStack2(charStack);
    charStack2.Print();

    std::cout << "NEW CHAR STACK AFTER POP:" << std::endl;
    charStack2.Pop();
    charStack2.Print();
    std::cout << "PREVIOUSE CHAR STACK:" << std::endl;
    charStack.Print();

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
