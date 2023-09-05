#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int max)
{
    cout << "GAME CONSTRUCTOR: object initialized with " << max << " as a maximum value" << endl;
    setMaxNumbers(max);
}

Game::~Game()
{
    cout << "GAME DESCTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{
    setPlayerGuess(0);

    srand(time(0));
    int generatedRand = rand()%getMaxNumbers()+1;
    setRandomNumber(generatedRand);
    int randomNumber = getRandomNumber();
    int inputNumber = -1;
    int max = getMaxNumbers();

    while(inputNumber != randomNumber) {
        cout << "Give your guess between 1-" << max << endl;

        cin >> inputNumber;

        cout << inputNumber << endl;
        if(inputNumber < randomNumber) {
            cout << "Your guess is too small" << endl;
        } else if (inputNumber > randomNumber) {
            cout << "Your guess is too big" << endl;
        }
        int guesses = getNumOfGuesses() + 1;
        setNumOfGuesses(guesses);
    }
    setPlayerGuess(inputNumber);
    printGameResult();
}

int Game::getMaxNumbers() const
{
    return maxNumbers;
}

void Game::setMaxNumbers(int newMaxNumbers)
{
    maxNumbers = newMaxNumbers;
}

int Game::getPlayerGuess() const
{
    return playerGuess;
}

void Game::setPlayerGuess(int newPlayerGuess)
{
    playerGuess = newPlayerGuess;
}

int Game::getRandomNumber() const
{
    return randomNumber;
}

void Game::setRandomNumber(int newRandomNumber)
{
    randomNumber = newRandomNumber;
}

int Game::getNumOfGuesses() const
{
    return numOfGuesses;
}

void Game::setNumOfGuesses(int newNumOfGuesses)
{
    numOfGuesses = newNumOfGuesses;
}

void Game::printGameResult()
{
    cout << "Your guess is right = " << getPlayerGuess() << endl;
    cout << "You guessed the right answer " << getPlayerGuess() << " with " << getNumOfGuesses() << " guesses" << endl;

}
