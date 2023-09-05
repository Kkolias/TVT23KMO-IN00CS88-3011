#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game(int);
        ~Game();

        void play();



        int getMaxNumbers() const;
        void setMaxNumbers(int newMaxNumbers);

        int getPlayerGuess() const;
        void setPlayerGuess(int newPlayerGuess);

        int getRandomNumber() const;
        void setRandomNumber(int newRandomNumber);

        int getNumOfGuesses() const;
        void setNumOfGuesses(int newNumOfGuesses);

private:
        int maxNumbers;
        int playerGuess;
        int randomNumber;
        int numOfGuesses;

        void printGameResult();

};

#endif // GAME_H
