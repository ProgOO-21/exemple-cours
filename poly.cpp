#include "poly.h"

#include <iostream>

using namespace std;

class Human
{
  public:
    Human(string name) : name(name) {}
    
    void speak()
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

    void speak()
    {
        cout << "Je suis un homme" << endl;
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

void poly()
{
    Human human("Human");
    Man man1("Jean");
    Women women1("Alice");
}