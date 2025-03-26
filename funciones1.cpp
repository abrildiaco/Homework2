#include "reloj.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Reloj::Reloj(int HH = 0,  int MM = 0, int SS = 0, string PmAm = "a.m.")
        : horas{HH}, minutos{MM}, segundos{SS}, pm_am{PmAm} {

            if(HH < 0 || HH >12){
                cout<<"Hora fuera del rango horario"<<endl;
            }
            else if(MM < 0 || MM >60){
                cout<<"Hora fuera del rango horario"<<endl;
            }
            else if(SS < 0 || SS >60){
                cout<<"Hora fuera del rango horario"<<endl;
            }
        }

        //03h, 14m, 42s p.m.
void Reloj::ShowReloj(){cout<< horas <<"h, "<< minutos <<"m, "<< segundos <<"s, "<<pm_am<<endl;}
void Reloj::ShowHoras(){cout<< horas <<"h, "<<endl;}
void Reloj::ShowMinutos(){cout<< minutos <<"m, "<<endl;}
void Reloj::ShowSegundos(){cout<< segundos <<"s, "<<endl;}
void Reloj::ShowPmAm(){cout<< pm_am <<endl;}

void CambiarHoras(int HH){horas = HH;}
void CambiarMinutos(int MM){minutos = MM;}
void CambiarSegundos(int SS){segundos = SS;}
void CambiarPmAm(string PmAm){pm_am = PmAm;}

//void Show24();