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

struct Measure
{
    Measure() { cout << "Measure construit" << endl; }
    ~Measure() { cout << "Measure détruit" << endl; }
    int value;
};

// Pour avoir une classe plus sûre, il faut que l'allocation et libération se
// fasse dans le constructeur et destructeur
struct DataMeasure
{
    void init(int capacite)
    {
        tab = new Measure*[capacite];
        this->capacite = capacite;
        nombreMeasure = 0;
    }

    void liberer()
    {
        for (int i = 0; i < nombreMeasure; i++)
        {
            delete tab[i];
        }

        delete[] tab;
        tab = nullptr;
        capacite = 0;
        nombreMeasure = 0;
    }

    void ajouter()
    {
        ajouter(new Measure());
    }

    void ajouter(Measure* m)
    {
        if (nombreMeasure >= capacite)
        {
            delete m;
            throw 100;
        }

        if(tab == nullptr)
          throw 200;

        tab[nombreMeasure++] = m;
    }

    int getNumber()
    {
        return nombreMeasure;
    }

    int capacite;
    int nombreMeasure = 0;
    Measure** tab = nullptr;
};

void allocation()
{
    cout << "Exemple DataMeasure" << endl;
    DataMeasure d;
    try
    {        
        d.init(2);
        d.ajouter();
        d.ajouter(new Measure());
        d.liberer();
    }
    catch(...)
    {
        cout << "Erreur avec l'allocation de measure" << endl;   
        cout << "Il reste " << d.getNumber() << " Measure dans le tableau" << endl;   
    }
    cout << "Fin exemple DataMeasure" << endl;
    

    // new Foo crée un objet dans la mémoire
    Foo* p = new Foo();
    Foo* p2 = p;

    p2->value = 4;
    delete p;

    // Comme la zone mémoire ci-dessus a été libérée, elle sera peut-être réutilisée
    // pour cette nouvelle variable
    Measure* px = new Measure();

    // l'objet n'existe plus en mémoire
    p2->value = 123;
    delete px;


    // en utilisant un bloc try...catch, il est possible de contrôler que 
    // l'allocation de mémoire se passe bien
    try
    {
        int* tab_i = new int[10];
        int value = *tab_i;
        delete[] tab_i;
    }
    catch (...)
    {}


    Foo** tab = alloc(10);
    cout << "La valeur allocation : " << tab[0]->value << endl;
    delete tab[0];  // supprime objet foo
    delete[] tab;   // supprime le tableau

    cout << "Exemple allocation" << endl;
}