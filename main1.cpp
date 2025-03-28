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
    
    
    try{
        
        //Inicialización sin argumentos
        if(opcion == 1) {
            string continuar = "si";

            while(continuar ==  "si"){
                Reloj MiReloj;
                
                catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n ¿Desea volver a intentarlo? [si/no]"
                    cin >> continuar;
                    if (continuar == "no") return 1;
                    continue;
                }
                MenuMetodos(MiReloj);
                continuar = "no";
                }
                
            }
        }
        
        //Inicialización solo con la hora
        else if(opcion == 2){
            string continuar = "si";
            
            while(continuar ==  "si"){
                int HH;
                cout<<"Ingrese una hora (0-12)"<<endl;
                cin>> HH;

                Reloj MiReloj(HH);
                catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n ¿Desea volver a intentarlo? [si/no]"
                    cin >> continuar;
                    if (continuar == "no") return 1;
                    continue;
                }
                continuar = "no";
            }
            MenuMetodos(MiReloj);
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

                Reloj MiReloj(HH, MM);
                catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n ¿Desea volver a intentarlo? [si/no]"
                    cin >> continuar;
                    continue;
                    if (continuar == "no") return 1;
                    continue;
                }
                continuar = "no";
            }
            MenuMetodos(MiReloj);

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

                Reloj MiReloj(HH, MM, SS);
                catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n ¿Desea volver a intentarlo? [si/no]"
                    cin >> continuar;
                    if (continuar == "no") return 1;
                }            }
            
            MenuMetodos(MiReloj);

        } 

        //Inicialización con la hora, minutos, segundos y período
        else if(opcion == 5){

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

            Reloj MiReloj(HH, MM, SS, PmAm);
            MenuMetodos(MiReloj);
        }
        else{
            cout<<"No se encontró la opción. Vuelve a intentarlo"<<endl;
            return 1;
        }
        

    }
    return 0;
    
}
    
//    //Inicialización sin argumentos
//    Reloj MiReloj_0;
//    cout <<"== Inicializando Relojes ==\n"<<endl;
//    MiReloj_0.ShowReloj();
//    
//    //inicialización sólo con horas
//    cout <<"\n== Inicializando Reloj1 =="<<endl;
//    try {
//        cout << "\nIngrese la hora (1-12): ";
//        cin >> HH;
//        Reloj MiReloj_1(HH);
//        MiReloj_1.ShowReloj();
//        
//        string cambioH;
//        cout<<"\nDesea cambiar la hora ingresada? (si/no): ";
//        cin>> cambioH;
//        if(cambioH == "si"){
//            int NuevaHora;
//            cout << "\nIngrese la nueva hora (1-12): ";
//            cin>>NuevaHora;
//            MiReloj_1.CambiarHoras(NuevaHora);
//            cout << "Nueva hora seteada: ";
//            MiReloj_1.ShowHoras();
//        }
//
//        cout<<"\nReloj1 inicializado: "; MiReloj_1.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_1.Show24(); cout<<endl;
//
//    } 
//    catch (const exception& e) {
//        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
//        return 1;;
//    }
//
//    //inicialización con horas y minutos
//    cout <<"\n== Inicializando Reloj2 =="<<endl;
//    try {
//        cout << "\nIngrese minutos (0-59): ";
//        cin >> MM;
//        Reloj MiReloj_2(HH, MM);
//        MiReloj_2.ShowReloj();
//        
//        string cambioM;
//        cout<<"\nDesea cambiar los minutos ingresados? (si/no): ";
//        cin>> cambioM;
//        if(cambioM == "si"){
//            int NuevoMinuto;
//            cout << "\nIngrese la nos nuevos minutos (0-59): ";
//            cin>>NuevoMinuto;
//            MiReloj_2.CambiarMinutos(NuevoMinuto);
//            cout << "Nuevo minuto seteado: ";
//            MiReloj_2.ShowMinutos();
//        }
//        
//        cout<<"\nReloj2 inicializado: "; MiReloj_2.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_2.Show24(); cout<<endl;
//
//    } 
//    catch (const exception& e) {
//        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
//        return 1;;
//    }
//
//    //inicialización con horas, minutos y segundos
//    cout <<"\n== Inicializando Reloj3 =="<<endl;
//    try {
//        cout << "\nIngrese segundos (0-59): ";
//        cin >> SS;
//        Reloj MiReloj_3(HH, MM, SS);
//        MiReloj_3.ShowReloj();
//
//        string cambioS;
//        cout<<"\nDesea cambiar los segundos ingresados? (si/no): ";
//        cin>> cambioS;
//        if(cambioS == "si"){
//            int NuevoSegundo;
//            cout << "\nIngrese la nos nuevos segundos (0-59): ";
//            cin>>NuevoSegundo;
//            MiReloj_3.CambiarSegundos(NuevoSegundo);
//            cout << "Nuevos segundos seteados: ";
//            MiReloj_3.ShowSegundos();
//        }
//    
//        cout<<"\nReloj3 inicializado: "; MiReloj_3.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_3.Show24(); cout<<endl;
//
//    } 
//    catch (const exception& e) {
//        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
//        return 1;
//    }
//
//    //inicialización con horas, minutos, segundos y período
//    cout <<"\n== Inicializando Reloj4 =="<<endl;
//    try {
//        cout << "\nIngrese el período (a.m. / p.m.): ";
//        cin >> PmAm;
//        Reloj MiReloj_4(HH, MM, SS, PmAm);
//        MiReloj_4.ShowReloj();
//
//        string cambioPA;
//        cout<<"\nDesea cambiar el período? (si/no): ";
//        cin>> cambioPA;
//        if(cambioPA == "si"){
//            string NuevoPA;
//            cout << "\nIngrese el nuevo período (a.m. / p.m.): ";
//            cin>>NuevoPA;
//            MiReloj_4.CambiarPmAm(NuevoPA);
//            cout << "Nuevo período seteados: ";
//            MiReloj_4.ShowPmAm();
//        }
//    
//        cout<<"\nReloj4 inicializado: "; MiReloj_4.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_4.Show24(); cout<<endl;
//    
//    } 
//    catch (const exception& e) {
//        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
//        return 1;;
//    }
//
//    cout<<"== Inicialización de relojes terminada =="<<endl;
//
//    return 0;
//}