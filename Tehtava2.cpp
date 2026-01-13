#include "Tehtava2.h"
#include <iostream>
using namespace std;
int main() {
    Game game(10);
    game.play();
    return 0;
}

Game::Game(int maxNum)
{
    maxNumber = maxNum;
    numOfGuesses = 0;
    randomNumber = rand() % maxNumber + 1;
    cout << "Constructing a game with max number " << maxNumber << endl;
}
Game::~Game()
{
    cout << "Deconstructing" << endl;
}
void Game::play()
{
    while(true)
    {
        numOfGuesses++;
        cout << "Enter your guess: ";
        cin >> playerGuess;
        if (playerGuess < randomNumber)
        {
            cout << "Too low" << endl;
        }
        else if (playerGuess > randomNumber)
        {
            cout << "Too high" << endl;
        }
        else
        {
            printGameResult();
            break;
        }
    }
}
void Game::printGameResult()
{
    cout << "You took " << numOfGuesses << " tries to guess the number: " << randomNumber << endl;
}
