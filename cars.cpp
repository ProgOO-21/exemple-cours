#include "cars.h"

#include <iostream>

using namespace std;

// Class Wheel
Wheel::Wheel()
{
    cout << "La roue est construite" << endl;
    pressure = 4.2;
}

Wheel::~Wheel() 
{ 
    cout << "La roue est détruite" << endl; 
}

void Wheel::setPressure(double value) { pressure = value; }

double Wheel::getPressure() { return pressure; }


// Class Car
Car::Car()
{
    cout << "La voiture est construite" << endl;
    nbr_door = 4;
}

Car::Car(string txt)
{
    cout << txt << endl;
    nbr_door = 4;
}

Car::Car(const Car& c){
    cout << "La voiture est copiée" << endl;
}

Car& Car::operator=(Car c)
{
    std::cout << "Operateur = Car\n";
    return *this;
}

Car::~Car() { cout << "La voiture est détruite" << endl; }

void Car::setPressure(double val)
{
    for (int i = 0; i < NBR_WHEEL; i++)
    {
        wheel[i].setPressure(val);
    }
}