#include "reloj.h"
#include <stdexcept>
#include <iostream>
using namespace std;
//g++ -std=c++20 main1.cpp reloj.cpp -o main1

int main() {
    
    int HH, MM, SS;
    string PmAm ;
    
    int opcion;
    cout<<"Elija como quiere inicializar su reloj:"<<endl;
    cout<<"1 - Inicializar en 0"<<endl;
    cout<<"2 - Inicializar sólo la hora"<<endl;
    cout<<"3 - Inicializar hora y minutos" <<endl;
    cout<<"4 - Inicializar horas, minutos y segundos"<<endl;
    cout<<"5 - Inicializar horas, minutos, segundos y período (am/pm)"<<endl;
    cin>>opcion;
    cin.ignore();
    
    
    //Inicialización sin argumentos
    if(opcion == 1) {
            
        Reloj MiReloj;
        MenuMetodos(MiReloj);
            
    }
        
    //Inicialización solo con la hora
    else if(opcion == 2){
        string continuar = "si";
        
        while(continuar ==  "si"){
            
            int HH;
            cout<<"Ingrese una hora (0-12)"<<endl;
            cin>> HH;
            
            try{
                Reloj MiReloj(HH);
                MenuMetodos(MiReloj);
            }
            
            catch (const exception& e) {
                
                cout << "Error: " << e.what() << endl;
                cout<<"\n¿Desea volver a intentarlo? [si/no]";
                cin >> continuar;
                
                if (continuar == "no") return 1;
                continue;
            
            }
            
            continuar = "no";
        }
    } 

        //Inicialización con la hora y los minutos
        else if(opcion == 3){
            string continuar = "si";
            
            while(continuar ==  "si"){
                
                int HH;
                cout<<"Ingrese una hora (0-12)"<<endl;
                cin>> HH;

                int MM;
                cout<<"Ingrese los minutos (0-59)"<<endl;
                cin>> MM;

                try{
                Reloj MiReloj(HH, MM);
                MenuMetodos(MiReloj); 
                }
                
                catch (const exception& e) {
                    
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n¿Desea volver a intentarlo? [si/no]";
                    cin >> continuar;
                    
                    if (continuar == "no") return 1;
                    continue;
                }
                
                continuar = "no";
            }
        } 
    
     //Inicialización con la hora, minutos y segundos
     else if(opcion == 4){
         
        string continuar = "si";      
         
        while(continuar ==  "si"){
            
            int HH;
            cout<<"Ingrese una hora (0-12)"<<endl;
            cin>> HH;
            
            int MM;
            cout<<"Ingrese los minutos (0-59)"<<endl;
            cin>> MM;
             
            int SS;
            cout<<"Ingrese los segundos (0-59)"<<endl;
            cin>> SS;
             
            try{
            Reloj MiReloj(HH, MM, SS);
            MenuMetodos(MiReloj);
            }
             
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                cout<<"\n¿Desea volver a intentarlo? [si/no]";
                cin >> continuar;
                
                if (continuar == "no") return 1;
                continue;
            }
            
            continuar = "no";            
        }      
    }
     
    //Inicialización con la hora, minutos, segundos y período
    else if(opcion == 5){
        
        string continuar = "si";      
         
        while(continuar ==  "si"){
            
            int HH;
            cout<<"Ingrese una hora (0-12)"<<endl;
            cin>> HH;
            
            int MM;
            cout<<"Ingrese los minutos (0-59)"<<endl;
            cin>> MM;
    
            int SS;
            cout<<"Ingrese los segundos (0-59)"<<endl;
            cin>> SS;
            
            string PmAm;
            cout<<"Ingrese el período (a.m./p.m.)"<<endl;
            cin>> PmAm;      
            
            try{
            Reloj MiReloj(HH, MM, SS, PmAm);
            MenuMetodos(MiReloj);
            }
            
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                cout<<"\n¿Desea volver a intentarlo? [si/no]";
                cin >> continuar;
                
                if (continuar == "no") return 1;
                continue;
            }
            
            continuar = "no";            
        }
    }
    else{
        cout<<"No se encontró la opción. Vuelve a intentarlo"<<endl;
        return 1;
    }

    return 0;
    
}