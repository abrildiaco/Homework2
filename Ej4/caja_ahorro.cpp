#include "cuenta.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor

CajaDeAhorro::CajaDeAhorro(const string &Titular)
    :CuentaBanco::CuentaBanco(Titular) {}

//definición de metodos

void CajaDeAhorro::Depositar(int& dinero_depositar){
    if (dinero_depositar <= 0)
        throw invalid_argument("El monto a depositar debe ser positivo.");
    
    balance += dinero_depositar;
    cout<<"Dinero depositado exitosamente ("<<dinero_depositar<<")\n"<<endl;
    return;
}

int CajaDeAhorro::Retirar(int& dinero_retirar){
    if (dinero_retirar <= 0)
        throw invalid_argument("El monto a retirar debe ser positivo.");

    if (dinero_retirar > balance){
        throw out_of_range("No hay dinero suficuente en la cuenta");
        return 1;
    }
    balance -= dinero_retirar;
    cout<<"Retiro exitoso ("<<dinero_retirar<<")\n"<<endl;
    
    return dinero_retirar;
}

void CajaDeAhorro::MostrarInfo() const{
    
    cout<<"=== Caja de Ahorro ==="<<endl;
    cout<<"Titular de cuenta: "<<titularCuenta<<endl;
    cout<<"Balance: "<<balance<<endl;
    
    contador_info++; 

    if (contador_info > 2){

        if(balance < 20) balance = 0;
        else balance -= 20;

        cout<<"\nSe descontaron $20 de la cuenta por consultas frecuentes"<<endl;

    }

    return;
}