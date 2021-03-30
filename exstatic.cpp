#include <math.h>

#include <iostream>

using namespace std;

class Color
{
    public:
    Color(int r, int g, int b) : r(r), g(g), b(b){}
    
    int r;
    int g;
    int b;

    static int test;

    static Color fromString(string color){
        return Color(255,255,255);
    }

    static Color Red(){
        return Color(255,0,0);
    }
};


class Parent
{
  public:
    Parent()
    {
        instance[cpt] = this;
        cpt++;
    }

    virtual void execute() = 0;

    int test = 0;

    static void convert(int a)
    {
        cout << "Conversion : " << a << endl;
    }

    static int cpt;
    static int value;

    static Parent* instance[10];
};

// initialisation des statics
int Parent::cpt = 0;
int Parent::value = 0;
Parent* Parent::instance[] = {nullptr};


class Enfant1 : public Parent
{
  public:
    void execute() override
    {
        cout << "Exec enfant 1" << endl;
    }
};

class Enfant2 : public Parent
{
  public:
    void execute() override
    {
        cout << "Exec enfant 2" << endl;
    }
};


// init des static
int Color::test = 4;

void exstatic(){
    
    // appelle sans instance de Color, on appelle avec le nom de la classe
    Color c1(125, 125, 125);
    // On modifie test pour toutes les instances de Color
    Color::test = 6;
    Color c2(230, 230 ,0);

    c1.r = 23; // Ici on modifie une propriété uniquement pour l'instance c1

    
    Enfant1 e1;
    Enfant2 e2;
    Enfant2 e22;

    Enfant1 e10;
    Enfant1 e12;

    // Même valeur pour tout le monde
    Enfant2::value = 4;
    cout << "Enfant 1 : " << Enfant1::value << " / Enfant 2 : " << Enfant2::value << endl;

    cout << "Il y a " << Enfant1::cpt << " instances de Parent" << endl;

    for(int i=0; i<Parent::cpt; i++){
        Parent::instance[i]->execute();
    }
}