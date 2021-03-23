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

    private:
    string name;
};

class Man : public Human
{
  public:
    Man(string name) : Human(name) {}

    // pas obligatoire
    void speak() override
    {
        //Human::speak(); // appelle de la méthode parent
        cout << "Je suis un homme et je mesure " << height << endl;
    }

    double height = 1.2;

    double getHeiht() const
    {
        return height;
    }
};

class Women : public Human
{
  public:
    Women(string name) : Human(name) {}

    void speak()
    {
        cout << "Je suis une femme" << endl;
    }
};

void printMan(Man& m){
    m.printName();
    m.speak();
}

void printName(Human& h){
    h.printName();
    h.speak();
    //h.height; h n'est pas un Man -> pas d'accès sur height
}



void poly()
{
    Human human("Human");
    Man man1("Jean");
    Women women1("Alice");

    // appelle méthode calsse parente
    human.printName();
    man1.printName();

    // appelle direct
    human.speak();
    man1.speak();

    // appelle fonction
    printName(human);
    printName(man1);
    //printMan(man1);
    printName(women1);


    Human* tab[4];
    tab[0] = &human;
    tab[1] = &man1;
    tab[2] = &women1;

    for(int i=0; i<3; i++){
        tab[i]->speak();
    }

}