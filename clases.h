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
        bool pm_am;

    public:
        Reloj (int h,  int m, int s, string )
            : horas {h}, minutos {m}, segundos {s}
        
}