#include "cuenta.h"
#include <string>
#include <iostream>
using namespace std;

//g++ -std=c++20 main4.cpp cuenta_banco.cpp cuenta_corriente.cpp caja_ahorro.cpp -o main4

int main(){
    
    // cout<<"=== Cuenta Bancaria ===";
    
    // cout<<"\nPor favor cree una caja de ahorro: "<<endl;

    // string nombre_titular;
    // cout<<"Ingrese su nombre completo: ";
    // getline(cin, nombre_titular);

    // CajaDeAhorro ahorro(nombre_titular);

    // int monto;
    // cout<<"Ingrese un primer monto a depositar: ";
    // cin>>monto;
    // cin.ignore();
    
    // ahorro.Depositar(monto);

    // string continuar = "si";

    // cout<<"\n ¿Que acción desea realizar sobre su caja de ahorro? (presione 0 para salir)"<<endl;
    // while(continuar = "si"){
        
    //     int opcion;
    //     cout"1 - Depositar más dinero"<<endl;
    //     cout"2 - Retirar dinero"<<endl;
    //     cout"3 - Mostrar información de la cuenta"<<endl;
    //     cout<<">>"; cin>>opcion;
    //     cin.ignore()
        
    //     if (opcion == 0){
    //         cou<<"\nGracias por confiar en nosotros!"<<endl;
    //         break;
    //     }
    //     else if(opcion == 1){
    //         int monto;
    //         cout<<"Ingrese un monto a depositar: ";
    //         cin>>monto;
    //         cin.ignore();

    //     }
    // }
    
    
    // cout<<"¿Desea también crear una cuenta corriente? [si/no]"<<endl;
    string nombre_titular = "Abril Diaco";
    //CajaDeAhorro miahorro(nombre_titular);
    shared_ptr<CajaDeAhorro> miahorro = make_shared<CajaDeAhorro> (nombre_titular);
    int num1 = 3000; 
    int num2 = 2000;
    miahorro->Depositar(num1);
    miahorro->MostrarInfo();
    int retiro = miahorro->Retirar(num2);
    miahorro->MostrarInfo();
    //int retiro2 = miahorro.Retirar(num2);
    miahorro->MostrarInfo();
    miahorro->MostrarInfo();

    CuentaCorriente micuenta(nombre_titular, miahorro);
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