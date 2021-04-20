#include <math.h>

#include <iostream>

using namespace std;

class Foo
{
  public:
    int getValue() const
    {
        return value;
    }

    int value;
};

class Bar
{
  public:
    double value;
};

// Exemple d'une structure pour gérer un tableau dynamique
struct Data
{
    int nbr;
    int capacite;
    Foo** tab;

    // add
    // delete
    // init
};


// fonction qui permet d'allouer un tableau dynamique
Foo** alloc(int capa)
{
    Foo** tab = new Foo*[capa]();  // tableau de pointeurs

    for (int i = 0; i < capa; i++)
    {
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

    // Comme la zone mémoire ci-dessus a été libérée, elle sera peut-être réutilisée
    // pour cette nouvelle variable
    Bar* px = new Bar();

    // l'objet n'existe plus en mémoire
    p2->value = 123;


    int* tab_i = new int[10];
    int value = *tab_i;
    delete[] tab_i;


    Foo** tab = alloc(10);
    cout << "La valeur allocation : " << tab[0]->value << endl;
    delete tab[0];  // supprime objet foo
    delete[] tab;   // supprime le tableau

    cout << "Exemple allocation" << endl;
