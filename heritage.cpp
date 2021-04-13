#include <iostream>

#include "main.h"

using namespace std;

struct GrandMere 
{
    GrandMere(){ cout << "Grand-mère construite" << endl; }
    int value;
};

struct Pere : public virtual GrandMere{
    Pere(){ cout << "Pere construit" << endl; }
};

struct Mere : public virtual GrandMere{
    Mere(){ cout << "Mere construite" << endl; }
};

struct  Enfant : public Mere, public Pere
{
    Enfant(){ cout << "Enfant construit" << endl; }
};

void heritage()
{
    cout << "Example heritage" << endl;
    Enfant e;
    cout << "Value = " << e.value << endl;
}
