#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int max) {
    cout << "RANDMAX" << endl;
    cout << "Time = " << time(0) << endl;
    srand(time(0));


    int randomNumber = rand()%max+1;
    int inputNumber = -1;

    int guesses = 0;

    while(inputNumber != randomNumber) {
        cout << "Arvaa luku valilta 1-" << max << endl;
        // cin.ignore();
        cin >> inputNumber;

        cout << "Arvattu luku: " << inputNumber << endl;
        if(inputNumber < randomNumber) {
            cout << "Luku on suurempi kuin arvattu luku" << endl;
        } else if (inputNumber > randomNumber) {
            cout << "Luku on pienempi kuin arvattu luku" << endl;
        }
        guesses++;
    }
    cout << "Oikea luku!" << endl;
    return guesses;
}

int main()
{
    int max;
    cout << "Anna suurin arvattava luku";
    cin >> max;

    int guesses = game(max);

    cout << "Arvauksia tuli yhteensa: " << guesses << endl;
    return 0;
}
