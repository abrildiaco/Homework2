#include "numero.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//constructor
Real::Real(double UnReal)
    : real(UnReal) {}


//definicion de métodos
Numero* Real::Suma(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro);
    return new Real( real + otro_real->real);
}

Numero* Real::Resta(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro);
    return new Real( real - otro_real->real);
}


Numero* Real::Multiplicacion(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro);
    return new Real( real*otro_real->real);
}

Numero* Real::Division(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro); 
    return new Real( real/otro_real->real);
}

string Real::toString()const{
    return to_string(real);
}

