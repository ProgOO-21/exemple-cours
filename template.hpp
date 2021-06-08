#pragma once

#include <iostream>
using namespace std;

template <typename T>
T maximum(const T& a, const T& b)
{
    if (a > b)
        return a;
    else
        return b;
}


template <typename T, int N>
class List
{
  public:
    List(int capacity) : capacity(capacity)
    {
        tab = new T(capacity);
    }
    ~List()
    {
        delete[] tab;
    }

    void add(T val)
    {
        tab[nbr++] = val;
    }

    T operator[](int ind){
        return tab[ind];
    }

  private:
    int nbr = 0;
    int capacity;
    T* tab;
    T staticTab[N];
};



template <typename T>
T sum(T tab[], int nbr)
{
    T sum = 0;
    for (int i = 0; i < nbr; i++)
    {
        sum += tab[i];
    }
    return sum;
}

template <typename T, typename A>
A avarage(T tab[], int size)
{
    A sum(0);
    for (int i = 0; i < size; i++)
    {
        sum += tab[i];
    }
    return sum / size;
}


// fichier A
class B;

class A {
  public:
    int value;
    B* p;
};


// Fichier B
class A;

class B {
  public:
    int value;
    A* a;
};


namespace test_template {
void test();
}


namespace namespace1{
    void test();
}