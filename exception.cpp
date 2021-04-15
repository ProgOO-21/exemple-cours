#include <math.h>

#include <iostream>

using namespace std;

const int ERROR_FLOATING_POINT = 100;

int func2(int value){
    if( value == 0 )
        return ERROR_FLOATING_POINT;
    
    int calc = 14 / value;
    cout << "Le résultat est : " << calc << endl;

    return 0;
}

int func1(int value){

    int ret = func2(value);
    if( ret != 0 ){
        return ret;
    }
    
    int tmp = value * 4;
    ret = func2(tmp);
    if( ret != 0 ){
        return ret;
    }

    return 0;
}

void exceptions()
{
    cout << "\033[1;32m" << "Exemple sur les exceptions" << "\033[0m" << endl;

    int ret = func1(0);
    if( ret == ERROR_FLOATING_POINT ){
        cout << "BOOM" << endl;
    }

    cout << "Fin de l'exemple pour les excéptions" << endl;
    
}