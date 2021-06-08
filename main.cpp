#include <iostream>

#include "cars.h"
#include "shape.h"
#include "poly.h"
#include "exstatic.h"
#include "main.h"
#include "template.hpp"

using namespace test_template;

int main() {
    //Car c1;
    //c1.setPressure(2);

    //forme();

    //poly();

    exstatic();

    allocation();

    heritage();

    exceptions();

    surcharge();

    test_template::test();
    namespace1::test();

    cout << "End" << endl;
    // les destructeurs sont appelés à la sortie de la fonction
}