#include <iostream>
#include "asunto.h"
#include "kerros.h"
#include "katutaso.h"
#include "kerrostalo.h"

#include <vector>
using namespace std;

int main()
{
    // Katutaso ekaKerros;
    // Kerros tokaKerros;
    // Kerros kolmasKerros;
    // Kerrostalo kerrostalo;
    Katutaso* ekaKerros = new Katutaso();
    Kerros* tokaKerros = new Kerros();
    Kerros* kolmasKerros = new Kerros();
    Kerrostalo* kerrostalo = new Kerrostalo();

    Asunto* as1 = new Asunto(2, 10);
    Asunto* as2 = new Asunto(2, 10);
    Asunto* as3 = new Asunto(2, 10);
    Asunto* as4 = new Asunto(2, 10);
    Asunto* as5 = new Asunto(2, 10);
    Asunto* as6 = new Asunto(2, 10);


    cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;
    ekaKerros->lisaaKatutasonAsunto(as1);
    ekaKerros->lisaaKatutasonAsunto(as2);

    tokaKerros->lisaaAsunto(as3);
    tokaKerros->lisaaAsunto(as4);

    kolmasKerros->lisaaAsunto(as5);
    kolmasKerros->lisaaAsunto(as6);


    vector<Kerros*> kerrokset;
    kerrokset.push_back(ekaKerros);
    kerrokset.push_back(tokaKerros);
    kerrokset.push_back(kolmasKerros);

    kerrostalo->lisaaKaikkiKerrokset(kerrokset);

    int hinta = 1;
    kerrostalo->laskeKerrostalonKulutus(hinta);

    return 0;
}
