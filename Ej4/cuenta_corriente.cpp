/*
CuentaCorriente: 
• El método retirar() permite retirar dinero de la caja de ahorro si no existen 
suficientes fondos en este tipo de cuenta. 
• En caso de que la caja de ahorro tampoco tenga dinero, se imprimirá un aviso 
de que la cuenta no posee dinero. Utilizar friend para esto.
*/

#include "cuenta.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor

CuentaCorriente::CuentaCorriente(string &Titular, CajaDeAhorro* caja)
    :titularCuenta(Titular), fondos(0), cajaAhorro(caja) {}


//definición de metodos

void CuentaCorriente::Depositar(double &dinero_depositar){
    fondo += dinero_depositar;
    cout<<"Dinero depositado exitosamente"<<endl;
    return;
}

double CuentaCorriente::Retirar(double& dinero_retirar){
    if(dinero_retirar > fondos){
        fondos -= fondos;
        double retirados_ahorro = cajaAhorro->Retirar(dinero_retirar-fondos);

        return dinero_retirar;
    }
    
    balance -= dinero_retirar;
    return dinero_retirar;
}

void CuentaCorriente::MostrarInfo() const{
    
    cout<<"Cuenta Corriente:"<<endl;
    cout<<"Titular de cuenta: "<<titularCuenta<<endl;
    cout<<"Fondos: "<<balance<<endl;

}