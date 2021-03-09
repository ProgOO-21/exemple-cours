#include <math.h>

#include <iostream>

using namespace std;

class Shape
{
  public:
    Shape(double length, string name, int side)
        : side_length(length),  // list initialisation
          name(name),
          nbr_side(side)
    {}

    double side_length;
    string name;
    int nbr_side;

    void printName()
    {
        cout << "Je suis un : " << name << endl;
    }
};

class Hexagon : public Shape
{
  public:
    Hexagon(double length) : Shape(length, "Hexagon", 6) {}

    double area()
    {
        return 3.0 * sqrt(3.0) / 2.0 * pow(side_length, 2);
    }
};

class Square : public Shape
{
  public:
    Square(double length) : Shape(length, "Square", 4) {}

    double area()
    {
        return pow(side_length, 2);
    }
};

void forme()
{
    // Shape
    Shape shape(2.0, "Shape", 9);
    cout << "Forme : " << shape.name << " / Coté : " << shape.nbr_side << endl;

    Square sh(2.0);
    Hexagon hh(3.0);

    cout << "Forme : " << sh.name << " / Longueur coté : " << sh.side_length
         << " / Air : " << sh.area() << endl;

    cout << "Forme : " << hh.name << " / Longueur coté : " << hh.side_length
         << " / Air : " << hh.area() << endl;
}
