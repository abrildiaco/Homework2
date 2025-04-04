#include "numero.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

//g++ -std=c++20 main3.cpp real.cpp entero.cpp complejo.cpp -o main3

int main(){
    
    cout<<"===Bienvenido a la calculadora ===\n"<<endl;

    //ENTEROS----------------------------------------------------------------------------------------------------
    {
    cout<<"--- Operaciones con numeros enteros ---"<<endl;
    Entero num1(10);
    Entero num2(5);
    
    //suma
    unique_ptr<Numero> resultado_sum = num1.Suma(num2);
    cout<<"Suma: "<<num1.toString()<<" + "<<num2.toString()<< " = " <<resultado_sum->toString()<<endl;
    
    //resta
    unique_ptr<Numero> resultado_res = num1.Resta(num2);
    cout<<"Resta: "<<num1.toString()<<" - "<<num2.toString()<< " = " <<resultado_res->toString()<<endl;
    
    //multiplicación
    unique_ptr<Numero> resultado_mul = num1.Multiplicacion(num2);
    cout<<"Multiplicación: "<<num1.toString()<<" * "<<num2.toString()<< " = " <<resultado_mul->toString()<<endl;
    
    //división
    unique_ptr<Numero> resultado_div = num1.Division(num2);
    cout<<"División: "<<num1.toString()<<" / "<<num2.toString()<< " = " <<resultado_div->toString()<<endl;
    }

    //REALES------------------------------------------------------------------------------------------------------
    {
    cout<<"\n--- Operaciones con numeros reales ---"<<endl;
    Real num1(10.8);
    Real num2(1.0/3.0);
    
    //suma
    unique_ptr<Numero> resultado_sum = num1.Suma(num2);
    cout<<"Suma: "<<num1.toString()<<" + "<<num2.toString()<< " = " <<resultado_sum->toString()<<endl;
    
    //resta
    unique_ptr<Numero> resultado_res = num1.Resta(num2);
    cout<<"Resta: "<<num1.toString()<<" - "<<num2.toString()<< " = " <<resultado_res->toString()<<endl;
    
    //multiplicación
    unique_ptr<Numero> resultado_mul = num1.Multiplicacion(num2);
    cout<<"Multiplicación: "<<num1.toString()<<" * "<<num2.toString()<< " = " <<resultado_mul->toString()<<endl;
    
    //división
    unique_ptr<Numero> resultado_div = num1.Division(num2);
    cout<<"División: "<<num1.toString()<<" / "<<num2.toString()<< " = " <<resultado_div->toString()<<endl;
    }    
    
    //COMPLEJOS------------------------------------------------------------------------------------------------------------------------
    {
    cout<<"\n--- Operaciones con numeros complejos ---"<<endl;
    Complejo num1(10.8, 5);
    Complejo num2(5, 3);
    
    //suma
    unique_ptr<Numero> resultado_sum = num1.Suma(num2);
    cout<<"Suma: ("<<num1.toString()<<") + ("<<num2.toString()<< ") = " <<resultado_sum->toString()<<endl;
    
    //resta
    unique_ptr<Numero> resultado_res = num1.Resta(num2);
    cout<<"Resta: ("<<num1.toString()<<") - ("<<num2.toString()<< ") = " <<resultado_res->toString()<<endl;
    
    //multiplicación
    unique_ptr<Numero> resultado_mul = num1.Multiplicacion(num2);
    cout<<"Multiplicación: ("<<num1.toString()<<") * ("<<num2.toString()<< ") = " <<resultado_mul->toString()<<endl;
    }
    
    return 0;
}