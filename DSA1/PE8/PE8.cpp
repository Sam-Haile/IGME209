// PE8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    int myNumber = 10;
    cout << "variables value is initially: " << myNumber << endl;
    changeVariable(myNumber);
    changePointer(&myNumber);

    cout << "---------------------------------" << endl;
    int numArray[] = {23, 63, 45, 4, 85, 24, 74, 13, 67, -1};
    int* intPointer = numArray;

    cout << "Num of elements using the getLengthArray method: " << getLengthArray(intPointer) << endl;
    cout << "Num of elements using the getLngthPointer method: " << getLengthPointer(numArray) << endl;

    cout << "---------------------------------" << endl;

    int *ptr1 = createStackArrray();
    cout << "Contents in stack array:  ";
    for (size_t i = 0; i < 5; i++)
    {
        cout << *(ptr1 + i) << " ";
    }

    cout << endl;

    int* ptr2 = createHeapArray(5);
    cout << "Contents in heap array:  ";
    for (size_t i = 0; i < 5; i++)
    {
        cout << *(ptr2 + i) << " ";
    }

    delete[] ptr2;
    cout << "\n---------------------------------" << endl;

    // ANSWER TO QUESTION
    // The array created on the stack returns a pointer to a local variable 
    // that is deleted when the function ends. If you wanted to access the
    // memory that was previously pointed to, your program will crash.

}

// Changing the variables value directly
void changeVariable(int number) 
{
    number = 55;
    cout << "variables value is now: " << number << endl;
}

// Changing the data stored at a pointers memory location 
void changePointer(int* myIntPointer)
{
    *myIntPointer = 100;
    cout << "variables value is now: " << *myIntPointer << endl;
}

int getLengthArray(int intArray[]) 
{
    int numOfElements = 0;
    int i = 0;
    
    // until the null terminator is hit,
    // increment the num of elements in array
    while (intArray[i] != -1)
    {
        i++;
        numOfElements++;
    }

    return numOfElements;
}

int getLengthPointer(int* ptr) 
{
    int numOfElements = 0;
    while (*ptr != -1)
    {
        numOfElements++;
        ptr++;
    }

    return numOfElements;
}

int* createStackArrray() 
{
    int intArray[5];

    intArray[0] = 0;
    intArray[1] = 1;
    intArray[2] = 2;
    intArray[3] = 3;
    intArray[4] = 4;


    return intArray;
}

int* createHeapArray(int sizeOfArr)
{
    int* intArray = new int[sizeOfArr];

    for (size_t i = 0; i < sizeOfArr; i++)
    {
        intArray[i] = i;
    }
    
    return intArray;
}