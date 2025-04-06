#include "cuenta.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor

CuentaCorriente::CuentaCorriente(const string& Titular, unique_ptr<CajaDeAhorro> caja)
    : CuentaBanco(Titular), cajaAhorro(move(caja)) {}

//definición de metodos

void CuentaCorriente::Depositar(int &dinero_depositar){
    if (dinero_depositar <= 0)
        throw invalid_argument("El monto a depositar debe ser positivo.");
    
    balance += dinero_depositar;
    cout<<"Dinero depositado exitosamente ("<<dinero_depositar<<")\n"<<endl;
    return;
}

int CuentaCorriente::Retirar(int& dinero_retirar){
    /*
    si no hay suficiente dinero en la cuenta, extrae lo que puede de la cuenta corriente y
    el resto de la caja de ahorro
    */
    if (dinero_retirar <= 0)
        throw invalid_argument("El monto a retirar debe ser positivo.");
    
    if(dinero_retirar > balance){
        int retiro_ahorro = dinero_retirar-balance;
        balance = 0; //pongo en 0 los fondos
        
        //puedo acceder a los atributos private de caja de ahorro, pues utilice friend
        if(cajaAhorro->balance > retiro_ahorro)
            cajaAhorro->balance -= retiro_ahorro;
        
            else{
            throw out_of_range("No hay dinero suficuente en la cuenta");
            return 1;    
        }

        cout<<"se han retirado fondos de la caja de ahorro"<<endl;

        return dinero_retirar;
    }
    
    balance -= dinero_retirar;
    cout<<"Dinero retirado exitosamente ("<<dinero_retirar<<")\n"<<endl;
    return dinero_retirar;
}

void CuentaCorriente::MostrarInfo() const{
    
    cout<<"\n=== Cuenta Corriente ==="<<endl;
    cout<<"Titular de cuenta: "<<titularCuenta<<endl;
    cout<<"Fondos: "<<balance<<endl;

}