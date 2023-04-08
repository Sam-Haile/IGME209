// PE13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int HandCounterRecursive(int numOfSeats) 
{
    int i = 1;
    int numOfHands = 0;

    while (i != numOfSeats + 1)
    {
        // if even
        if (i % 2 == 0)
        {
            numOfHands += 4;
            i++;
        }
        // if odd
        else
        {
            numOfHands += 3;
            i++;
        }

    }
    std::cout << "Recursive Method with " << numOfSeats << " seats =  " << numOfHands << std::endl;
    return numOfHands;
    
}


int HandCounterIterative(int numOfSeats)
{
    int numOfHands = 0;

    for (int i = 1; i < numOfSeats + 1; i++)
    {
        // if even
        if (i % 2 == 0)
        {
            numOfHands += 4;
        }
        // if odd
        else
        {
            numOfHands += 3;
        }
    }

    std::cout << "Iterative Method with "<< numOfSeats << " seats =  " << numOfHands << std::endl;
    return numOfHands;

}


int HandCounterFormula(float numOfSeats)
{
    float evenNum = floor(numOfSeats / 2);
    float oddNum = ceil(numOfSeats / 2);

    int numOfHands = 0;

    numOfHands = oddNum * 3 + evenNum * 4;
    std::cout << "Formula Method with " << numOfSeats << " seats =  " << numOfHands << std::endl;
    return numOfHands;
}

int main()
{
    HandCounterIterative(3);
    HandCounterRecursive(3);
    HandCounterFormula(3);
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
