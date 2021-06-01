#include <iostream>

using namespace std;

class Vector{

};

Vector operator+(const Vector& p1, const Vector& p2){
    return Vector();
}


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

    void add(const Point& p1)
    {
        this->x += p1.x;
        this->y += p1.y;
    }

    Point& operator+=(const Point& p)
    {
        this->add(p);
        return *this;
    }

    friend bool operator==(const Point& p1, const Point& p2);

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

Point operator+(const Point& p1, const Point& p2)
{
    return add_point(p1, p2);
}

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y; // a cause de friend
    //return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}

ostream& operator<<(ostream& out, const Point& p)
{
    return out << "x : " << p.getX() << " / y : " << p.getY();
}

void surcharge()
{
    cout << "Surcharge opérateur" << endl;

    Point p1(12, 4);
    Point p2(3, 1);

    Point p = p1 + p2;

    cout << "Test add p " << endl;
    Point pp(1,2);
    pp += Point(3,4);
    cout << pp << endl;

    if( p == Point(15,5) ){
        cout << "Les points sont égaux" << endl;
    }

    int val1 = 12;
    val1 += 3;

    int res = val1 + 5;
}