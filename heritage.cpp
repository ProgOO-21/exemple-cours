#include <iostream>

#include "main.h"

using namespace std;

struct GrandMere
{
    GrandMere(){ cout << "Grand-mère construite" << endl; }
    GrandMere(int a) : value(a) { cout << "Grand-mère construite avec val " << a << endl; }
    int value;
};

struct Pere : public virtual GrandMere{
    Pere(){ cout << "Père construit" << endl; }
    Pere(int a) : GrandMere(a) { cout << "Père construit avec val" << endl; }
};

struct Mere : public virtual GrandMere{
    Mere(){ cout << "Mère construite" << endl; }
    Mere(int a) : GrandMere(a) { cout << "Mère construite avec val" << endl; }
};

struct Enfant : public Mere, public Pere
{
    Enfant(){ cout << "Enfant construit" << endl; }
    Enfant(int a) : GrandMere(a), Mere(8) { cout << "Enfant construit avec val" << endl; }
};


void heritage()
{
    cout << "Example héritage" << endl;
    Enfant e(12);
    cout << "Value = " << e.value << endl;
}
