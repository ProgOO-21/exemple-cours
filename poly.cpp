#include "poly.h"

#include <iostream>

using namespace std;

class Human
{
  public:
    Human(string name) : name(name) {}
    
    virtual void speak()
    {
        cout << "Je suis un humain" << endl;
    }

    void printName()
    {
        cout << "Mon nom est : " << name << endl;
    }

    string name;
};

class Man : public Human
{
  public:
    Man(string name) : Human(name) {}

    void speak() override
    {
        cout << "Je suis un homme" << endl;
    }

    double height = 1.2;
};

class Women : public Human
{
  public:
    Women(string name) : Human(name) {}

    // Si pas définit, on appelle la méthode parent
    /*void speak() override
    {
        cout << "Je suis une femme" << endl;
    }*/
};

void printMan(Man m){
    m.printName();
}

void printInfo(Human& h){
    // ici on a pas accès au paramètres enfant
    h.printName();

    h.speak();
}

void poly()
{
    Human human("Human");
    Man man1("Jean");
    Women women1("Alice");

    //human.printName();
    //women1.printName();

    man1.speak();

    printInfo(human);
    // on a le droit car Man est un Human
    printInfo(man1);
    printInfo(women1);

    // pour avoir accès au propriété class enfant
    //printMan(man1);
}