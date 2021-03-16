#include "shape.h"

#include <iostream>

using namespace std;

void Screen::print(string message)
{
    cout << "\033[1;32m" << message << "\033[0m" << endl;
}

// origin(1,2)
// origin(Point(1,2))
Shape::Shape(int nbrSide, string name, Color color) : nbrSide(nbrSide), origin(1, 2)
{
    // on préfère la liste
    // this->nbrSide = nbrSide;
    this->name = name;
    area = 0.0;
}

void Shape::show(){
    screen->print( this->toString() );
}

void Shape::calculArea(){

}

string Shape::toString(){
    return "Shape area : " + std::to_string(this->area) + " / " + origin.toString();
}

// class square
Square::Square(string name, int sideLength) : Shape(4, name, Color::Red), sideLength(sideLength)
{
    // liste init
    // this->sideLength = sideLength;
}

void Square::calculArea()
{
    area = sideLength * sideLength;
}


void Hexagon::calculArea()
{
    
}


void forme()
{
    Screen screen;

    Square square("carre", 4);
    square.setScreen(&screen);

    square.calculArea();
    square.show();
}
