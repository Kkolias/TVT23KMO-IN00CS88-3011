#ifndef KERROSTALO_H
#define KERROSTALO_H
#include "katutaso.h"
#include "kerros.h"
#include <vector>
#include <iostream>
using namespace std;

class Kerrostalo
{
    public:
    Kerrostalo();
    ~Kerrostalo();

    // void lisaaKerros(const Kerros& floor);
    // void lisaaKaikkiKerrokset(const vector<Kerros>& floors);
    void lisaaKerros(Kerros* floor);
    void lisaaKaikkiKerrokset(vector<Kerros*>& floors);

    void laskeKerrostalonKulutus(double);


    private:
        Katutaso* katutaso;
        vector<Kerros*> kerrokset;

};

#endif // KERROSTALO_H
