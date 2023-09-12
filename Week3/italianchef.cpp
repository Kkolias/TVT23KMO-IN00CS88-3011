#include "italianchef.h"
#include "chef.h"

ItalianChef::ItalianChef(string name, int vesi, int jauho) : Chef(name)
{
    this->name = name;
    this->vesi = vesi; // täälä asetetaan vesi ja jauhot
    this->jauho = jauho;
}

string ItalianChef::getName()
{
    return this->name;
}

void ItalianChef::makePasta()
{
    cout << "Chef " << this->name << " makes pasta with special recipe" << endl;
    cout << "Chef " << this->name << " users jauhot = " << this->jauho << endl;
    cout << "Chef " << this->name << " users vesi = " << this->vesi << endl;
}
