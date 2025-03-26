#include "reloj.h"
#include <iomanip>
#include <iostream>
using namespace std


Reloj::Reloj (int HH = 0,  int MM = 0, int SS = 0, string PmAm = "a.m.")
        : horas{HH}, minutos{MM}, segundos{SS}, pm_am{PmAm} {

            if(HH < 0 || HH >12){
                cout<<"Hora fuera del rango horario"<<endl;
            }
            elif(MM < 0 || MM >60){
                cout<<"Hora fuera del rango horario"<<endl;
            }
            elif(SS < 0 || SS >60){
                cout<<"Hora fuera del rango horario"<<endl;
            }
        }
        void ShowReloj();
        void ShowHoras();
        void ShowMinutos();
        void ShowSegundos();
        void ShowPmAm();

        void CambiarHoras(int);
        void CambiarMinutos(int);
        void CambiarSegundos(int);
        void CambiarPmAm(int);

        void Show24();