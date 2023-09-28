#include "katutaso.h"
#include <iostream>
using namespace std;

Katutaso::Katutaso() : Kerros()
{
    cout << "Luotu Katutason kerros" << endl;
}

Katutaso::~Katutaso()
{
    cout << "Tuhotaan katutason kerros" << endl;
}

void Katutaso::lisaaKatutasonAsunto(Asunto*& asunto)
{
    this->asunnot.push_back(asunto);
    cout << "Katutaton asunto maarietty asukkaita= " << asunto->asukasMaara << " nelioita " << asunto->neliot << endl;
}
