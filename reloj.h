#pragma once
#include <string>


class Reloj{
    
    private:
        int horas;
        int minutos;
        int segundos;
        std::string pm_am;

    public:
        
    Reloj();
        Reloj(int);
        Reloj(int, int);
        Reloj(int, int, int);
        Reloj (int,  int, int, std::string);
        
        void ShowReloj();
        void ShowHoras();
        void ShowMinutos();
        void ShowSegundos();
        void ShowPmAm();

        void CambiarHoras(int);
        void CambiarMinutos(int);
        void CambiarSegundos(int);
        void CambiarPmAm(std::string);

        void Show24();
};