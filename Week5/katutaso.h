#ifndef KATUTASO_H
#define KATUTASO_H
#include "kerros.h"


class Katutaso: public Kerros
{
public:
    Katutaso();
    ~Katutaso();

    // void lisaaKatutasonAsunto(Asunto);
    void lisaaKatutasonAsunto(Asunto*& asunto);
};

#endif // KATUTASO_H
