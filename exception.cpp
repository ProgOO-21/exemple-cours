#include <math.h>

#include <iostream>
#include <exception>

using namespace std;

const int ERROR_FLOATING_POINT = 100;

// classe pour créer une exception personnalisée
class MyException : public exception
{
  public:
    MyException(string const& phrase = "", int num = 0) throw() : 
        num(num), phrase(phrase) {}

    virtual const char* what() const throw()
    {
        return phrase.c_str();
    }

    // méthode virtuelle donc destructeur virtuel
    virtual ~MyException() throw() {}

    int num;
  private:
    // on peut ajouter un numéro ou priorité...    
    int priorite;
    string phrase;
};


// Méthode qui permet de lever une exception de différents types
int func2(int value){
    if( value == 0 )
    {
        //throw ERROR_FLOATING_POINT;
        //throw "BOOM";
        //return ERROR_FLOATING_POINT;
        throw MyException("Problème BOOM", ERROR_FLOATING_POINT);
    }
   
    int calc = 14 / value;
    cout << "Le résultat est : " << calc << endl;

    return 0;
}

int func1(int value){

    // Pour avoir accès à val dans le bloc try et catch, il faut déclarer
    // la variable en dehors des deux blocs
    int ret = 45;
    int val;
    try
    {
        // visibilité
        val = 12;
        ret = func2(value);

        val = 125;
        // code 1
    }
    catch(MyException& e)
    {
        val = 1;
        cout << "Exc func1 " << endl;
        //throw; // propage l'exception
    }
    
    // attention si une erreur arrive avant la ligne 58, la valeur de val sera fausse
    cout << "La valeur de val : " << val << endl;
    cout << "La valeur de ret : " << ret << endl;

    //if( ret != 0 ){
    //    return ret;
    //}

    int tmp = value * 4;
    ret = func2(tmp);
    //if( ret != 0 ){
    //    return ret;
    //}

    return 0;
}

void exceptions()
{
    cout << "\033[1;32m" << "Exemple sur les exceptions" << "\033[0m" << endl;

    try
    {
        int ret = func1(0);
    }
    catch(double value)
    {
       cout << "Il y a eu un problème double : " << value << endl; 
    }
    catch(int var)
    {
       cout << "Il y a eu un problème entier : " << var << endl; 
    }
    catch(const char* txt){
        cout << "Il y a eu un problème : " << txt << endl;    
    }
    catch(MyException& e){
        cout << "Il y a eu un problème : " << e.what() << " le num : "  << e.num << endl;    
    }
    catch(...)
    {
       cout << "Il y a eu un problème" << endl; 
    }
    
    //if( ret == ERROR_FLOATING_POINT ){
    //    cout << "BOOM" << endl;
    //}

    cout << "Fin de l'exemple pour les excéptions" << endl;
    
}