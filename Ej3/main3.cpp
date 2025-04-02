#include "numero.h"
#include <iostream>

using namespace std;

int main(){
    Complejo num(4.5, 5);
    Complejo num2(5, 3);
    Numero* resultado_sum = num.Suma(num2);
    Numero* resultado_res = num.Resta(num2);
    Numero* resultado_mul = num.Multiplicacion(num2);
    //Numero* resultado_div = num.Division(num2);

    cout<<resultado_sum->toString()<<endl;
    cout<<resultado_res->toString()<<endl;
    cout<<resultado_mul->toString()<<endl;
    //cout<<resultado_div->toString()<<endl;
    
    return 0;
}