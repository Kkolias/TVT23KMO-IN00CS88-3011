#include "kerros.h"
#include <iostream>
#include <vector>
using namespace std;

Kerros::Kerros()
{
    cout << "Luotu Kerros" << endl;
}

Kerros::~Kerros()
{
    cout << "Tuhotaan kerros" << endl;
}

void Kerros::maaritaAsunnot(vector<Asunto>& asunnot)
{
    this->asunnot = asunnot;
}

double Kerros::laskeKulutus(double hinta)
{
    double kulutus = 0;
    for (const auto& asunto : asunnot) {
        int asukasMaara = asunto.asukasMaara;
        int neliot = asunto.neliot;

        double asuntoKulutus = asukasMaara * neliot * hinta;
        kulutus = kulutus + asuntoKulutus;
    }
    return kulutus;
}

void Kerros::lisaaAsunto(Asunto asunto)
{
    this->asunnot.push_back(asunto);
    cout << "Asunto maarietty asukkaita= " << asunto.asukasMaara << " nelioita " << asunto.neliot << endl;
}
