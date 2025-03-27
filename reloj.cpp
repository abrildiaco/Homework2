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
}


//Definición de métodos

void Reloj::ShowReloj(){
    
    //con swet me aseguro que se muestren dos dígitos, y con Setfil me aseguro 
    //que aquellos lugares vacíos se rellenen con 0
    cout << setw(2) << setfill('0') << horas <<"h, " 
    << setw(2) << setfill('0') << minutos <<"m, "
    << setw(2) << setfill('0') << segundos <<"s, "
    <<pm_am<<endl;
}

void Reloj::ShowHoras(){cout << setw(2) << setfill('0') << horas <<"h"<<endl;}
void Reloj::ShowMinutos(){cout << setw(2) << setfill('0') << minutos <<"m"<<endl;}
void Reloj::ShowSegundos(){cout << setw(2) << setfill('0') << segundos <<"s"<<endl;}
void Reloj::ShowPmAm(){cout<< pm_am <<endl;}

void Reloj::CambiarHoras(int HH){horas = HH;} //aunque horas sea un atributo private, lo puedo cambiar ya que lo estoy
                                              //haciendo dentro de la propia clase
void Reloj::CambiarMinutos(int MM){minutos = MM;}
void Reloj::CambiarSegundos(int SS){segundos = SS;}
void Reloj::CambiarPmAm(string PmAm){pm_am = PmAm;}

void Reloj::Show24(){
    if (pm_am == "p.m."){ //si mi hora es después del mediodía, le sumo 12 para pasarla al formato 24hs
        cout << setw(2) << setfill('0') << horas+12 <<"hs" <<endl;
    }
    else{
        cout << setw(2) << setfill('0') << horas <<"hs"<<endl;
    }
}