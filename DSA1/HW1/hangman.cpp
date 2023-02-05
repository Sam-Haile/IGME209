#include <iostream>
#include <vector>
#include "hangman.h"
using namespace std;

// Define the body of each function
void startGame()
{
    std::cout << "__________________\n";
    std::cout << "WELCOME TO HANGMAN\n";
}

void showGallows(int wrongGuessesRemaing) {

    switch (wrongGuessesRemaing) {
    case 0:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 1:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |                 " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 2:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |          |       " << endl
            << "| |          |       " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 3:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |         /|       " << endl
            << "| |          |       " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 4:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |         /|\\      " << endl
            << "| |          |       " << endl
            << "| |                  " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 5:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |         /|\\      " << endl
            << "| |          |       " << endl
            << "| |         /        " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 6:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |         /|\\      " << endl
            << "| |          |       " << endl
            << "| |         / \\     " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
        break;
    case 7:
        cout << "____________..______" << endl
            << "| .__________)______| " << endl
            << "| | / /      |       " << endl
            << "| |/ /       |       " << endl
            << "| |         (_)      " << endl
            << "| |         /|\\      " << endl
            << "| |          |       " << endl
            << "| |         / \\     " << endl
            << "| |                  " << endl
            << "| |                  " << endl;
    }
}

void showSolveDisplay(string answer, vector<char> incorrect )
{
    cout << "Wrong Guesses: \n";

    for (int i = 0; i < incorrect.size(); i++)
    {
        cout << incorrect[i] << " ";
    }

    cout << "\nWord to solve:\n";

    for (int i = 0; i < answer.length(); i++)
    {
        cout << answer[i] << " ";
    }
}


void endGame(string answer, string word)
{
    if (answer == word
        )
    {
        cout << "You Win!\n";
    }
    else
    {
        cout << "GAME OVER\n";
    }
}
