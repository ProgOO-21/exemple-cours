#pragma once

#include <iostream>
using namespace std;

class Wheel {
  public:
    Wheel();
    ~Wheel();

    void setPressure(double value);
    double getPressure();

  private:
    double pressure;
};

#define NBR_WHEEL 2
class Car {
  public:
    Car();
    Car(string txt);
    Car(const Car&);

    ~Car();

    Car& operator=(Car c);

    Wheel& get_wheel(int id)
    {
        return wheel[id];
    }

    void setPressure(double val);

  private:
    Wheel wheel[NBR_WHEEL];
    int nbr_door;
};