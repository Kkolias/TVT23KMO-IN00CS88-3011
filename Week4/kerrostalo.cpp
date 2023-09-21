#include "kerrostalo.h"
#include <vector>
#include <iostream>
using namespace std;

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu" << endl;
}

Kerrostalo::~Kerrostalo()
{
    cout << "Tuhotaan kerrostalo" << endl;
}

void Kerrostalo::lisaaKerros(const Kerros& floor) {
    kerrokset.push_back(floor);
}

void Kerrostalo::lisaaKaikkiKerrokset(const vector<Kerros> &floors)
{
    for(const auto&floor : floors)
    {
        cout << "Maaritetaan " << floors.size() << " kpl kerroksen asuntoja" << endl;
        this->lisaaKerros(floor);
    }
}

void Kerrostalo::laskeKerrostalonKulutus(double hinta)
{
    double kokoKulutus;
    vector<Kerros> kaikkiKerrokset = this->kerrokset;
    for (Kerros& kerros : kaikkiKerrokset) {
        double kerroksetKulutus = kerros.laskeKulutus(hinta);

        kokoKulutus = kokoKulutus + kerroksetKulutus;
    }

    cout << "Kerrostalon kulutus = " << kokoKulutus << endl;
}

