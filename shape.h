#pragma once

#include <iostream>

using namespace std;

void forme();

// entière
enum Color
{
    Black,
    Red
};

class Screen
{
  public:
    void print(string message);
};

// tout est public
struct Point
{
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;

    // convert Point to String
    string toString()
    {
        return "X=" + std::to_string(x) + ", Y=" + to_string(y);
    }
};

// Class shape
class Shape
{
  public:
    // Oblige de définir les valeurs
    Shape(int nbrSide, string name, Color color = Color::Black);

    int getSideNumber()
    {
        return nbrSide;
    }

    void setScreen(Screen* s){
        screen = s;
    }

    void show();

    string toString();

    void calculArea();

  protected:
    int nbrSide;
    string name;
    Color color;
    double area;
    // toujours init pointeur
    // init pour toute les classes
    Screen* screen = nullptr; // agrégation

    private:
        // composition
        Point origin;
};

// Class Square
class Square : public Shape
{
  public:
    // pas de contructeur par défaut, on oblige paramètre
    Square(string name, int sideLength);

    void calculArea();

  private:
    int sideLength;
};

// Class Hexagon
class Hexagon : public Shape
{
  public:
    // pas de contructeur par défaut, on oblige paramètre
    Hexagon(string name, int sideLength);

    void calculArea();

  private:
    int sideLength;
};