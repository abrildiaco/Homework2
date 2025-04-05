#pragma once
#include <string>


class Reloj{
    
    private:
        int horas;
        int minutos;
        int segundos;
        std::string pm_am;

    public:
        
        //sobrecarga de constructores
        Reloj();
        Reloj(int);
        Reloj(int, int);
        Reloj(int, int, int);
        Reloj (int,  int, int, std::string);
        
        //metodos
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

        //destructor
        ~Reloj() = default; //le digo explicitamente al compilador que cree un destructor
};

//CAMBIAR A STATIC
void MenuMetodos(Reloj&);