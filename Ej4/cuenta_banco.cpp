#include "cuenta.h"
#include <string>
#include <iostream>

using namespace std;

CuentaBanco::CuentaBanco(string &Titular)
    :titularCuenta(Titular), balance(0) {}


void CuentaBanco::Depositar(int& dinero_depositar){
    balance += dinero_depositar;
    cout<<"Dinero depositado exitosamente"<<endl;
    return;
}