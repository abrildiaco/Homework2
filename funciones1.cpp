#include "reloj.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Definición de constructores

Reloj::Reloj()
        : horas{0}, minutos{0}, segundos{0}, pm_am{"a.m."} {}

Reloj::Reloj(int HH)
        : horas{HH}, minutos{0}, segundos{0}, pm_am{"a.m."} {

            if(HH < 0 || HH >12) {
                cout<<"Hora fuera del rango horario"<<endl;
                horas = 0;
            }
            
}

Reloj::Reloj(int HH,  int MM)
        : horas{HH}, minutos{MM}, segundos{0}, pm_am{"a.m."} {

            if(HH < 0 || HH >12){
                cout<<"Hora fuera del rango horario"<<endl;
                horas = 0;
            }
            if(MM < 0 || MM >60){
                cout<<"Minutos fuera de rango"<<endl;
                minutos = 0;
            }
}

Reloj::Reloj(int HH,  int MM, int SS)
        : horas{HH}, minutos{MM}, segundos{SS}, pm_am{"a.m."} {

            if(HH < 0 || HH >12){
                cout<<"Hora fuera del rango horario"<<endl;
                horas = 0;
            }
            if(MM < 0 || MM >60){
                cout<<"Minutos fuera de rango"<<endl;
                minutos = 0;
            }
            if(SS < 0 || SS >60){
                cout<<"Segundos fuera de rango"<<endl;
                segundos = 0;
            }
}

Reloj::Reloj(int HH,  int MM, int SS, string PmAm)
        : horas{HH}, minutos{MM}, segundos{SS}, pm_am{PmAm} {

            if(HH < 0 || HH >12){
                cout<<"Hora fuera del rango horario"<<endl;
                horas = 0;
            }
            if(MM < 0 || MM >60){
                cout<<"Minutos fuera de rango"<<endl;
                minutos=0;
            }
            if(SS < 0 || SS >60){
                cout<<"Segundos fuera de rango"<<endl;
                segundos = 0;
            }
            if(PmAm != "p.m." || PmAm != "a.m."){
                cout<<"Error! Ingrese a.m. / p.m."<<endl;
                pm_am = "a.m.";
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

void Reloj::CambiarHoras(int HH){horas = HH;}
void Reloj::CambiarMinutos(int MM){minutos = MM;}
void Reloj::CambiarSegundos(int SS){segundos = SS;}
void Reloj::CambiarPmAm(string PmAm){pm_am = PmAm;}

void Reloj::Show24(){
    if (pm_am == "p.m."){
        cout << setw(2) << setfill('0') << horas+12 <<"hs" <<endl;
    }
    else{
        cout << setw(2) << setfill('0') << horas <<"hs"<<endl;
    }
}