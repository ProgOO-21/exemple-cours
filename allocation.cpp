#include <math.h>

#include <iostream>

using namespace std;

class Foo
{
  public:
    int getValue() const { return value; }

    int value;
};

class Bar
{
  public:
    double value;
};

struct Data
{
  int nbr;
  int capacite;
  Foo** tab;

  // add
  // delete
  // init
};

Foo** alloc(int capa){
    Foo** tab = new Foo*[capa](); // tableau de pointeurs

    for( int i=0; i<capa; i++){
      tab[i] = nullptr;
    }

    tab[0] = new Foo();
    tab[0]->value = 12;

    // tab[0] -> type -> Foo*
    // tab    -> type -> Foo**

    return tab;
}

void allocation()
{
    // new Foo crée un objet dans la mémoire
    Foo* p = new Foo();
    Foo* p2 = p;
    
    p2->value = 4;
    delete p;

    int* tab_i = new int[10];
    int value = *tab_i;
    delete[] tab_i;

    Foo** tab = alloc(10);
    cout << "La valeur allocation : " << tab[0]->value << endl;
    delete tab[0]; // supprime objet foo
    delete[] tab; // supprime le tableau

    // Comme la zone mémoire ci-dessus a été libérée, elle sera
    Bar* px = new Bar();

    // l'objet n'existe en mémoire
    p2->value = 123;

    cout << "Exemple allocation" << endl;
}