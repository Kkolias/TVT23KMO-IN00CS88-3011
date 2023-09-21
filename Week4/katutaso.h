#ifndef KATUTASO_H
#define KATUTASO_H
#include "kerros.h"


class Katutaso: public Kerros
{
public:
    Katutaso();
    ~Katutaso();

    void lisaaKatutasonAsunto(Asunto);
};

#endif // KATUTASO_H
