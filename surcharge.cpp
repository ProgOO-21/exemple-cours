#include <iostream>

using namespace std;

class Vector{

};

class Point
{
  public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

  private:
    int x;
    int y;
};

Point add_point(const Point& p1, const Point& p2){
    int x = p1.getX() + p2.getX();
    int y = p1.getY() + p2.getY();
    Point p(x,y);
    return p;
}


Vector operator+(const Vector& p1, const Vector& p2){
    return Vector();
}

Point operator+(const Point& p1, const Point& p2)
{
    return add_point(p1, p2);
}

void surcharge()
{
    cout << "Surcharge opérateur" << endl;

    Point p1(12, 4);
    Point p2(3, 1);

    Point p = p1 + p2;

    int val1 = 12;
    val1 += 3;

    int res = val1 + 5;
}