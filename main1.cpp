#include "reloj.h"
#include <stdexcept>
#include <iostream>
using namespace std;
//g++ -std=c++20 main1.cpp reloj.cpp -o main1

int main() {
    int HH, MM, SS;
    string PmAm ;
    
    //Inicialización sin argumentos
    Reloj MiReloj_0;
    cout <<"== Inicializando Relojes ==\n"<<endl;
    MiReloj_0.ShowReloj();
    
    //inicialización sólo con horas
    cout <<"\n== Inicializando Reloj1 =="<<endl;
    try {
        cout << "\nIngrese la hora (1-12): ";
        cin >> HH;
        Reloj MiReloj_1(HH);
        MiReloj_1.ShowReloj();
        
        string cambioH;
        cout<<"\nDesea cambiar la hora ingresada? (si/no): ";
        cin>> cambioH;
        if(cambioH == "si"){
            int NuevaHora;
            cout << "\nIngrese la nueva hora (1-12): ";
            cin>>NuevaHora;
            MiReloj_1.CambiarHoras(NuevaHora);
            cout << "Nueva hora seteada: ";
            MiReloj_1.ShowHoras();
        }

        cout<<"\nReloj1 inicializado: "; MiReloj_1.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_1.Show24(); cout<<endl;

    } 
    catch (const exception& e) {
        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
        return 1;;
    }

    //inicialización con horas y minutos
    cout <<"\n== Inicializando Reloj2 =="<<endl;
    try {
        cout << "\nIngrese minutos (0-59): ";
        cin >> MM;
        Reloj MiReloj_2(HH, MM);
        MiReloj_2.ShowReloj();
        
        string cambioM;
        cout<<"\nDesea cambiar los minutos ingresados? (si/no): ";
        cin>> cambioM;
        if(cambioM == "si"){
            int NuevoMinuto;
            cout << "\nIngrese la nos nuevos minutos (0-59): ";
            cin>>NuevoMinuto;
            MiReloj_2.CambiarMinutos(NuevoMinuto);
            cout << "Nuevo minuto seteado: ";
            MiReloj_2.ShowMinutos();
        }
        
        cout<<"\nReloj2 inicializado: "; MiReloj_2.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_2.Show24(); cout<<endl;

    } 
    catch (const exception& e) {
        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
        return 1;;
    }

    //inicialización con horas, minutos y segundos
    cout <<"\n== Inicializando Reloj3 =="<<endl;
    try {
        cout << "\nIngrese segundos (0-59): ";
        cin >> SS;
        Reloj MiReloj_3(HH, MM, SS);
        MiReloj_3.ShowReloj();

        string cambioS;
        cout<<"\nDesea cambiar los segundos ingresados? (si/no): ";
        cin>> cambioS;
        if(cambioS == "si"){
            int NuevoSegundo;
            cout << "\nIngrese la nos nuevos segundos (0-59): ";
            cin>>NuevoSegundo;
            MiReloj_3.CambiarSegundos(NuevoSegundo);
            cout << "Nuevos segundos seteados: ";
            MiReloj_3.ShowSegundos();
        }
    
        cout<<"\nReloj3 inicializado: "; MiReloj_3.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_3.Show24(); cout<<endl;

    } 
    catch (const exception& e) {
        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
        return 1;
    }

    //inicialización con horas, minutos, segundos y período
    cout <<"\n== Inicializando Reloj4 =="<<endl;
    try {
        cout << "\nIngrese el período (a.m. / p.m.): ";
        cin >> PmAm;
        Reloj MiReloj_4(HH, MM, SS, PmAm);
        MiReloj_4.ShowReloj();

        string cambioPA;
        cout<<"\nDesea cambiar el período? (si/no): ";
        cin>> cambioPA;
        if(cambioPA == "si"){
            string NuevoPA;
            cout << "\nIngrese el nuevo período (a.m. / p.m.): ";
            cin>>NuevoPA;
            MiReloj_4.CambiarPmAm(NuevoPA);
            cout << "Nuevo período seteados: ";
            MiReloj_4.ShowPmAm();
        }
    
        cout<<"\nReloj4 inicializado: "; MiReloj_4.ShowReloj(); cout <<"Hora 24hs: "; MiReloj_4.Show24(); cout<<endl;
    
    } 
    catch (const exception& e) {
        cout << "Error: " << e.what() << " Inténtelo nuevamente." << endl;
        return 1;;
    }

    cout<<"== Inicialización de relojes terminada =="<<endl;

    return 0;
}