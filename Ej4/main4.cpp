#include "cuenta.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    
    cout<<"=== Cuenta Bancaria ===";
    
    //inicializacion caja de ahorro
    cout<<"\nPor favor cree una caja de ahorro: "<<endl;

    string nombre_titular;
    cout<<"Ingrese su nombre completo: ";
    getline(cin, nombre_titular);

    unique_ptr<CajaDeAhorro> miahorro = make_unique<CajaDeAhorro>(nombre_titular);

    int monto;
    cout<<"Ingrese un primer monto a depositar: ";
    cin>>monto;
    cin.ignore();
    
    try{
        miahorro->Depositar(monto);

    }catch (const exception& e) {
            
        cout << "\n===Error: " << e.what() << "==="<<endl;
        cout<<"Vuelve a intenterlo..\n"<<endl;
        return 1;
        
    }

    bool continuar = true;

    //acciones sobre caja de ahorro
    while(continuar){
        
        cout<<"¿Que acción desea realizar sobre su caja de ahorro? (presione 0 para salir)"<<endl;
        int opcion;
        cout<<"1 - Depositar más dinero"<<endl;
        cout<<"2 - Retirar dinero"<<endl;
        cout<<"3 - Mostrar información de la cuenta"<<endl;
        cout<<">>"; cin>>opcion;
        cin.ignore();
        
        if (opcion == 0){
            cout<<"\nGracias por confiar en nosotros!"<<endl;
            break;
        }
        else if(opcion == 1){
            int monto;
            cout<<"Ingrese un monto a depositar: ";
            cin>>monto;
            cin.ignore();

            try{
            miahorro->Depositar(monto);

            }catch (const exception& e) {
                
                cout << "\n===Error: " << e.what() << "==="<<endl;
                cout<<"Vuelve a intenterlo..\n"<<endl;
                continue;
            
            }

        }else if(opcion == 2){
            
            int monto;
            cout<<"Ingrese un monto a retirar: ";
            cin>>monto;
            cin.ignore();

            try{
            miahorro->Retirar(monto);

            }catch (const exception& e) {
                
                cout << "\n===Error: " << e.what() << "==="<<endl;
                cout<<"Vuelve a intenterlo..\n"<<endl;
                continue;
            
            }        
        }else if(opcion == 3){
            
           miahorro->MostrarInfo();
        
        }
        
        else cout<<"No se encontro opción"<<endl;
    }
    
    cout<<"---------------------------------------------------------------------------------------"<<endl;    
    //inicializacion Cuenta corriente
    cout<<"\nPor favor cree una cuenta corrienteo: "<<endl;

    string nombre_titular2;
    cout<<"Ingrese su nombre completo: ";
    getline(cin, nombre_titular2);

    CuentaCorriente micuenta(nombre_titular2, move(miahorro));
    
    int monto2;
    cout<<"Ingrese un primer monto a depositar: ";
    cin>>monto2;
    cin.ignore();
    
    try{
        micuenta.Depositar(monto2);

    }catch (const exception& e) {
            
        cout << "\n===Error: " << e.what() << "==="<<endl;
        cout<<"Vuelve a intenterlo..\n"<<endl;
        return 1;
        
    }

    bool continuar2 = true;

    //acciones sobre la cuenta corriente
    while(continuar2){
        
        cout<<"\n ¿Que acción desea realizar sobre su cuenta corriente? (presione 0 para salir)"<<endl;
        int opcion;
        cout<<"1 - Depositar más dinero"<<endl;
        cout<<"2 - Retirar dinero"<<endl;
        cout<<"3 - Mostrar información de la cuenta"<<endl;
        cout<<">>"; cin>>opcion;
        cin.ignore();
        
        if (opcion == 0){
            cout<<"\nGracias por confiar en nosotros!"<<endl;
            break;
        }
        else if(opcion == 1){
            int monto;
            cout<<"Ingrese un monto a depositar: ";
            cin>>monto;
            cin.ignore();

            try{
                micuenta.Depositar(monto);

            }catch (const exception& e) {
                
                cout << "\n===Error: " << e.what() << "==="<<endl;
                cout<<"Vuelve a intenterlo..\n"<<endl;
                continue;
            
            }

        }else if(opcion == 2){
            
            int monto;
            cout<<"Ingrese un monto a retirar: ";
            cin>>monto;
            cin.ignore();

            try{
                micuenta.Retirar(monto);

            }catch (const exception& e) {
                
                cout << "\n===Error: " << e.what() << "==="<<endl;
                cout<<"Vuelve a intenterlo..\n"<<endl;
                continue;
            
            }        
        }else if(opcion == 3){
            
            micuenta.MostrarInfo();
        
        }
        
        else cout<<"No se encontro opción"<<endl;
    }
    return 0;
}