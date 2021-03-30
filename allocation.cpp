#include <math.h>

#include <iostream>

using namespace std;

class Foo
{
  public:
    int value;
};

class Bar
{
  public:
    double value;
};

void allocation()
{
    // new Foo crée un objet dans la mémoire
    Foo* p = new Foo();
    Foo* p2 = p;
    
    p2->value = 4;
    delete p;

    // Comme la zone mémoire ci-dessus a été libérée, elle sera
    Bar* px = new Bar();

    // l'objet n'existe en mémoire
    p2->value = 123;

    cout << "Exemple allocation" << endl;
}