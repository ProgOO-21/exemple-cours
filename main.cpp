#include <iostream>

#include "cars.h"

int main() {
    Car c1;
    c1.setPressure(2);

    cout << "End" << endl;
    // les destructeurs sont appelés à la sortie de la fonction
}