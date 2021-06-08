#include "template.hpp"

using namespace std;

namespace test_template{

void func_test2();

void func_test1(){
    func_test2();
}

void func_test2(){
}

A* getObject(){
    return new A();
}

// on doit dupliquer les fonctions
double max(const double v1, const double v2){
    return v1 > v2 ? v1 : v2;
}
int max(const int v1, const int v2){
    return v1 > v2 ? v1 : v2;
}

void test(){
    std::cout << "Test template" << std::endl;

    cout << "Test max : " << maximum<double>(5.4, 3.2) << endl;
    cout << "Test max : " << maximum<int>(5.4, 3.2) << endl;

    List<int, 10> maList(10);
    int result = maList[0];

    int tab[] = {1,2,3,4,5};
    cout << "Moyenne : " << avarage<int,double>(tab,5) << endl;

    int val1 = 12;
    int val2 = 12.3;

    auto val3 = 34;
    auto val4 = 34.5;

    A* p1 = getObject();
    auto p2 = getObject();

    std::cout << "End test template" << std::endl;
}

}

namespace namespace1{
    void test(){
    }    
}