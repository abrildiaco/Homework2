/*
CajaDeAhorro: 
• El método retirar() impide retirar más dinero del que existe en el balance. 
• Se realizará un descuento de $20 del balance luego de mostrar más de 2 veces 
la información de la cuenta. 
*/

#include "cuenta.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor

CajaDeAhorro::CajaDeAhorro(string &Titular)
    :CuentaBanco::CuentaBanco(Titular) {}

//definición de metodos

double CajaDeAhorro::Retirar(double& dinero_retirar){
    if (dinero_retirar > balance){
        throw out_of_range("No hay dinero suficuente en la cuenta");
        return;
    }
    balance -= dinero_retirar;
    cout<<"Retiro exitoso"<<endl;
    
    return dinero_retirar;
}

void CajaDeAhorro::MostrarInfo() const{
    
    
    cout<<"Caja de Ahorro:"<<endl;
    cout<<"Titular de cuenta: "<<titularCuenta<<endl;
    cout<<"Balance: "<<balance<<endl;
    
    contador_info++;

    if (contador_info > 2){

        if(balance < 20) balance = 0;
        else balance -= 20;

        cout<<"Se descontaron $20 de la cuenta por consultas frecuentes"<<endl;

    }

    return;
}