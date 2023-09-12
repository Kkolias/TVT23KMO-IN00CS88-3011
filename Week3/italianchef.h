#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"


class ItalianChef: public Chef
{
public:
    ItalianChef(string, int , int);
    string getName();
    void makePasta(); // eihän tälle tarvitse antaa parametrejä koska vesi ja jauho asetetaan luokkaa luodessa

private:
    int vesi;
    int jauho;
};

#endif // ITALIANCHEF_H
