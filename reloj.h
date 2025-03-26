// Programe una clase que permita expresar un determinado momento en el tiempo en 
// el siguiente formato: HHh, MMm, SSs p.m./a.m. Por ejemplo: “03h, 14m, 42s p.m.”.  
// Para este ejercicio, puede utilizar la librería iomanip con la funcionalidad provista por 
// setw y/o setfill. 
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