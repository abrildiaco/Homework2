#include "cuenta.h"
#include <string>
#include <iostream>
using namespace std;

//g++ -std=c++20 main4.cpp cuenta_banco.cpp cuenta_corriente.cpp caja_ahorro.cpp -o main4

int main(){
    string nombre ="Abril diaco";
    CajaDeAhorro miahorro(nombre);
    int num1 = 3000; 
    int num2 = 2000;
    miahorro.Depositar(num1);
    // miahorro.MostrarInfo();
    // int retiro = miahorro.Retirar(num2);
    // miahorro.MostrarInfo();
    // //int retiro2 = miahorro.Retirar(num2);
    // miahorro.MostrarInfo();
    // miahorro.MostrarInfo();

    CuentaCorriente micuenta(nombre, &miahorro);
    micuenta.MostrarInfo();
    int num3 = 20;
    int num4 = 200;
    micuenta.Depositar(num4);
    int retiro2 = micuenta.Retirar(num3);
    micuenta.MostrarInfo();
    int retiro5 = micuenta.Retirar(num4);
    micuenta.MostrarInfo();
    //int retiro8 = miahorro.Retirar(num1);

}