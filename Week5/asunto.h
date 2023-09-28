#ifndef ASUNTO_H
#define ASUNTO_H
#include <vector>
#include <iostream>
using namespace std;

class Asunto
{
    public:
        Asunto(int , int);
        ~Asunto();

        int asukasMaara;
        int neliot;

        void maarita(int, int);
        double laskeKulutus(double);




};

#endif // ASUNTO_H
