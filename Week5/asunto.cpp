#include "asunto.h"
#include <iostream>
using namespace std;

Asunto::Asunto(int maara, int neliot)
{
    this->maarita(maara, neliot);
    // this->laskeKulutus(kulutus);
}

Asunto::~Asunto()
{
    // cout << "Tuhotaan asunto" << endl;
}

void Asunto::maarita(int maara, int neliot)
{
    this->asukasMaara = maara;
    this->neliot = neliot;

    // cout << "Asunto maarietty asukkaita= " << this->asukasMaara << " nelioita " << this->neliot << endl;
}

double Asunto::laskeKulutus(double hinta)
{
    double kulutus = this->asukasMaara * this->neliot * hinta;
    cout << "Asunnon kulutus, kun hinta=" << hinta << " on " << kulutus << endl;
    return kulutus;
}
