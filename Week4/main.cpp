#include <iostream>
#include "asunto.h"
#include "kerros.h"
#include "katutaso.h"
#include "kerrostalo.h"

#include <vector>
using namespace std;

int main()
{
    Katutaso ekaKerros;
    Kerros tokaKerros;
    Kerros kolmasKerros;
    Kerrostalo kerrostalo;
    cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;
    ekaKerros.lisaaKatutasonAsunto(Asunto(2, 10));
    ekaKerros.lisaaKatutasonAsunto(Asunto(2, 10));

    tokaKerros.lisaaAsunto(Asunto(2, 10));
    tokaKerros.lisaaAsunto(Asunto(2, 10));

    kolmasKerros.lisaaAsunto(Asunto(2, 10));
    kolmasKerros.lisaaAsunto(Asunto(2, 10));


    vector<Kerros> kerrokset;
    kerrokset.push_back(ekaKerros);
    kerrokset.push_back(tokaKerros);
    kerrokset.push_back(kolmasKerros);

    kerrostalo.lisaaKaikkiKerrokset(kerrokset);

    int hinta = 1;
    kerrostalo.laskeKerrostalonKulutus(hinta);

    return 0;
}
