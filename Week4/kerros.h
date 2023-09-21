#ifndef KERROS_H
#define KERROS_H
#include "asunto.h"
#include <vector>
#include <iostream>
using namespace std;

class Kerros
{
public:
    Kerros();
    ~Kerros();

    void maaritaAsunnot(vector<Asunto>& asunnot);
    double laskeKulutus(double);
    void lisaaAsunto(Asunto);

    vector<Asunto> asunnot;
};

#endif // KERROS_H
