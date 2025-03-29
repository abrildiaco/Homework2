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
        
        void ShowReloj()const; //el uso de const significa que es un método que no modifica el estado de un objeto
        void ShowHoras()const;
        void ShowMinutos()const;
        void ShowSegundos()const;
        void ShowPmAm()const;

        void CambiarHoras(int);
        void CambiarMinutos(int);
        void CambiarSegundos(int);
        void CambiarPmAm(std::string);

        void Show24()const;
};

void MenuMetodos(Reloj&);