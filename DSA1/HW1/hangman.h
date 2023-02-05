#include <iostream>
#include <vector>
using namespace std;

//Declare functions to be used
void startGame();
void showGallows(int wrongGuessesRemaing);
void showSolveDisplay(string answer, std::vector<char> incorrect);
void endGame(string answer, string codeword);
