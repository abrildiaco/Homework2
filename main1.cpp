#include "reloj.h"

int main(){
    Reloj nuevo(90, 70, 56, "p.m.");

    nuevo.ShowReloj();
    nuevo.Show24();
    nuevo.CambiarHoras(6);
    nuevo.ShowHoras();
    nuevo.ShowReloj();
    nuevo.Show24();

    return 0;
}