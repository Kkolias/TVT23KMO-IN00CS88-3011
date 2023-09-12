#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef chef("Kokki Kolmone");
    chef.makeSalad();
    chef.makeSoup();

    ItalianChef italianChef("Italialaine kokki", 10, 20);
    italianChef.makeSoup();
    italianChef.makePasta(); // bruh
    italianChef.makeSalad();

    return 0;
}
