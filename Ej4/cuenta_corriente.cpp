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

CuentaCorriente::CuentaCorriente(string &Titular, shared_ptr<CajaDeAhorro> caja)
    :CuentaBanco::CuentaBanco(Titular), cajaAhorro(caja) {}


//definición de metodos

void CuentaCorriente::Depositar(int &dinero_depositar){
    fondos += dinero_depositar;
    cout<<"Dinero depositado exitosamente ("<<dinero_depositar<<")\n"<<endl;
    return;
}

int CuentaCorriente::Retirar(int& dinero_retirar){
    /*
    si no hay suficiente dinero en la cuenta, extrae lo que puede de la cuenta corriente y
    el resto de la caja de ahorro
    */
    
    if(dinero_retirar > fondos){
        fondos -= fondos;
        int retiro_ahorro = dinero_retirar-fondos;
        int retirados_ahorro = cajaAhorro->Retirar(retiro_ahorro);

        cout<<"se han retirado fondos de la caja de ahorro"<<endl;

        return dinero_retirar;
    }
    
    fondos -= dinero_retirar;
    cout<<"Dinero retirado exitosamente ("<<dinero_retirar<<")\n"<<endl;
    return dinero_retirar;
}

void CuentaCorriente::MostrarInfo() const{
    
    cout<<"=== Cuenta Corriente ==="<<endl;
    cout<<"Titular de cuenta: "<<titularCuenta<<endl;
    cout<<"Fondos: "<<fondos<<endl;

}