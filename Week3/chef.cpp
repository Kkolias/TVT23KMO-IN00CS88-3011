#include "chef.h"
#include <iostream>
using namespace std;

Chef::Chef(string name)
{
    this->name = name;
    cout << "Chef " << this->name << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << this->name << " destruktori" << endl;
}

void Chef::makeSalad()
{
    cout << "Chef " << this->name << "makes salad" << endl;
}

void Chef::makeSoup()
{
    cout << "Chef " << this->name << "makes soup" << endl;
}
