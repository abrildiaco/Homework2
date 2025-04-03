#include "reloj.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//Definición de constructores


Reloj::Reloj() //si no ingresan ningón parámetro, el reloj es inicializado en 0
        : horas{0}, minutos{0}, segundos{0}, pm_am{"a.m."} {} 


Reloj::Reloj(int HH)//inicializacíon sólo con horas
        : horas{HH}, minutos{0}, segundos{0}, pm_am{"a.m."} {

            //Si el horario puesto está fuera de rango, lanza una excepción
            if(HH < 0 || HH >12){
                horas = 0;
                throw out_of_range("Hora fuera de rango (0-12)");
            }
            if(pm_am == "a.m." && HH == 12){
                pm_am = "p.m.";
                throw invalid_argument("No existe la hora 12 am");
            }
            else if(pm_am == "p.m." && HH == 0){
                pm_am = "a.m.";
                throw invalid_argument("No existe la hora 00 pm");
            }
}


Reloj::Reloj(int HH,  int MM)
        : horas{HH}, minutos{MM}, segundos{0}, pm_am{"a.m."} {

            if(HH < 0 || HH >12){
                horas = 0;
                throw out_of_range("Hora fuera de rango (0-12)");
            }
            if(MM < 0 || MM >60){
                minutos=0;
                throw out_of_range("Minutos fuera de rango (0-59)");
            }
            if(pm_am == "a.m." && HH == 12){
                pm_am = "p.m.";
                throw invalid_argument("No existe la hora 12 am");
            }
            else if(pm_am == "p.m." && HH == 0){
                pm_am = "a.m.";
                throw invalid_argument("No existe la hora 00 pm");
            }
}

Reloj::Reloj(int HH,  int MM, int SS)
        : horas{HH}, minutos{MM}, segundos{SS}, pm_am{"a.m."} {

            if(HH < 0 || HH >12){
                horas = 0;
                throw out_of_range("Hora fuera de rango (0-12)");
            }
            if(MM < 0 || MM >60){
                minutos=0;
                throw out_of_range("Minutos fuera de rango (0-59)");
            }
            if(SS < 0 || SS >60){
                segundos = 0;
                throw out_of_range("Segundos fuera de rango (0-59)");
            }
            if(pm_am == "a.m." && HH == 12){
                pm_am = "p.m.";
                throw invalid_argument("No existe la hora 12 am");
            }
            else if(pm_am == "p.m." && HH == 0){
                pm_am = "a.m.";
                throw invalid_argument("No existe la hora 00 pm");
            }
        

}

Reloj::Reloj(int HH,  int MM, int SS, string PmAm)
        : horas{HH}, minutos{MM}, segundos{SS}, pm_am{PmAm} {

            if(HH < 0 || HH >12){
                horas = 0;
                throw out_of_range("Hora fuera de rango (0-12)");
            }
            if(MM < 0 || MM >60){
                minutos=0;
                throw out_of_range("Minutos fuera de rango (0-59)");
            }
            if(SS < 0 || SS >60){
                segundos = 0;
                throw out_of_range("Segundos fuera de rango (0-59)");
            }
            if (PmAm != "p.m." && PmAm != "a.m.") {
                pm_am = "a.m.";
                throw invalid_argument("Formato incorrecto. Use 'a.m.' o 'p.m.'");
            }
            if(PmAm == "a.m." && HH == 12){
                pm_am = "p.m.";
                throw invalid_argument("No existe la hora 12 am");
            }
            else if(PmAm == "p.m." && HH == 0){
                pm_am = "a.m.";
                throw invalid_argument("No existe la hora 00 pm");
            }
        
}


//Definición de métodos

void Reloj::ShowReloj()const{
    
    //con swet me aseguro que se muestren dos dígitos, y con Setfil me aseguro 
    //que aquellos lugares vacíos se rellenen con 0
    cout << setw(2) << setfill('0') << horas <<"h, " 
    << setw(2) << setfill('0') << minutos <<"m, "
    << setw(2) << setfill('0') << segundos <<"s, "
    <<pm_am<<endl;
}

void Reloj::ShowHoras()const{cout << setw(2) << setfill('0') << horas <<"h"<<endl;}
void Reloj::ShowMinutos()const{cout << setw(2) << setfill('0') << minutos <<"m"<<endl;}
void Reloj::ShowSegundos()const{cout << setw(2) << setfill('0') << segundos <<"s"<<endl;}
void Reloj::ShowPmAm()const{cout<< pm_am <<endl;}

void Reloj::CambiarHoras(int HH){//aunque horas sea un atributo private, lo puedo cambiar ya que lo estoy
                                //haciendo dentro de la propia clase
    if(HH < 0 || HH >12){
        horas = 0;
        throw out_of_range("Hora fuera de rango (0-12)");
    }
    horas = HH;

} 
void Reloj::CambiarMinutos(int MM){
    
    if(MM < 0 || MM >60){
        minutos=0;
        throw out_of_range("Minutos fuera de rango (0-59)");
    }
    minutos = MM;
}
void Reloj::CambiarSegundos(int SS){
    
    if(SS < 0 || SS >60){
        segundos = 0;
        throw out_of_range("Segundos fuera de rango (0-59)");
    }
    segundos = SS;
}
void Reloj::CambiarPmAm(string PmAm){
    
    if (PmAm != "p.m." && PmAm != "a.m.") {
        pm_am = "a.m.";
        throw invalid_argument("Formato incorrecto. Use 'a.m.' o 'p.m.'");
    }
    if(PmAm == "a.m." && horas == 12){
        pm_am = "p.m.";
        throw invalid_argument("No existe la hora 12 am");
    }
    else if(PmAm == "p.m." && horas == 0){
        pm_am = "a.m.";
        throw invalid_argument("No existe la hora 00 pm");
    }
    pm_am = PmAm;
}

void Reloj::Show24()const{
    
    if (pm_am == "p.m."){ //si mi hora es después del mediodía, le sumo 12 para pasarla al formato 24hs
        cout << setw(2) << setfill('0') << horas+12 <<"hs, "
        << setw(2) << setfill('0') << minutos <<"m, "
        << setw(2) << setfill('0') << segundos <<"s, "
        <<pm_am<<endl;
    }
    else{
        cout << setw(2) << setfill('0') << horas <<"hs, "
        << setw(2) << setfill('0') << minutos <<"m, "
        << setw(2) << setfill('0') << segundos <<"s, "
        <<pm_am<<endl;
    }
}

//Definición de función para poner a prueba los métodos

void MenuMetodos(Reloj &MiReloj){
    
    int opcion =1;
    
    cout<<"\n¿Que acción desea realizar? (presione 0 para salir)"<<endl;
    while (opcion != 0){
        cout<<"1 - Mostrar el reloj"<<endl;
        cout<<"2 - Mostrar solo la hora"<<endl;
        cout<<"3 - Mostrar solo los minutos" <<endl;
        cout<<"4 - Mostrar solo los segundos"<<endl;
        cout<<"5 - Mostrar sólo el período"<<endl;
        cout<<"6 - Cambiar la hora"<<endl;
        cout<<"7 - Cambiar los minutos"<<endl;
        cout<<"8 - Cambiar los segundos" <<endl;
        cout<<"9 - Cambiar el período"<<endl;
        cout<<"10 - Mostrar el reloj en formato 24hs\n"<<endl;
        
        cout<<">>";cin>>opcion;
        cin.ignore();

        if(opcion == 0){
            cout <<"Programa terminado"<<endl;
            return;
        }
        
        else if (opcion == 1) MiReloj.ShowReloj();
        else if (opcion == 2)  MiReloj.ShowHoras();
        else if (opcion==3) MiReloj.ShowMinutos();
        else if (opcion==4) MiReloj.ShowSegundos();
        else if (opcion==5) MiReloj.ShowPmAm();
        
        else if (opcion == 6) {

            string continuar = "si";

            while (continuar == "si"){

                int HH;
                cout<<"Ingrese la nueva Hora: ";
                cout<<">>";cin>> HH;
                cin.ignore();
                
                try{
                MiReloj.CambiarHoras(HH);
                }
                
                catch (const exception& e) {
                
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n¿Desea volver a intentarlo? [si/no]";
                    cout<<">>";cin >> continuar;
                    if (continuar == "no") return;
                    
                    continue;
                }
                continuar = "no";
                
            }
        }
        else if (opcion == 7) {

            string continuar = "si";

            while (continuar == "si"){
                
                int MM;
                cout<<"Ingrese los nuevos minutos: ";
                cout<<">>";cin>> MM;
                cin.ignore();
                
                try{
                MiReloj.CambiarMinutos(MM);
                }
                catch (const exception& e) {
                
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n¿Desea volver a intentarlo? [si/no]";
                    cout<<">>";cin >> continuar;
                    if (continuar == "no") return;
                    
                    continue;
                }
                continuar = "no";
            }


        }
        else if (opcion == 8) {

            string continuar = "si";
            
            while (continuar == "si"){
                
                int SS;
                cout<<"Ingrese los nuevos segundos: ";
                cout<<">>";cin>> SS;
                cin.ignore();
                
                try{
                MiReloj.CambiarSegundos(SS);
                }
                catch (const exception& e) {
                
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n¿Desea volver a intentarlo? [si/no]";
                    cout<<">>";cin >> continuar;
                    if (continuar == "no") return;
                    
                    continue;
                }
                continuar = "no";
            }
        }
        else if (opcion == 9) {

            string continuar = "si";
            
            while (continuar == "si"){
                string PmAm;
                cout<<"Ingrese el nuevo período (a.m./p.m.) ";
                cout<<">>";cin>> PmAm;
                
                try{
                MiReloj.CambiarPmAm(PmAm);
                }
                catch (const exception& e) {
                
                    cout << "Error: " << e.what() << endl;
                    cout<<"\n ¿Desea volver a intentarlo? [si/no]";
                    cout<<">>";cin >> continuar;
                    if (continuar == "no") return;
                    
                    continue;
                }
                continuar = "no";
            }

        }
        else if(opcion == 10) MiReloj.Show24();

        cout<<"\n¿Que otra acción desea realizar? (presione 0 para salir)"<<endl;

    }
}