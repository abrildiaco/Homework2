#include "numero.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

//constructor
Real::Real(double UnReal)
    : real(UnReal) {}


//definicion de métodos
std::unique_ptr<Numero> Real::Suma(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro);
    return make_unique<Real>(real + otro_real->real);
}

std::unique_ptr<Numero> Real::Resta(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro);
    return make_unique<Real>(real - otro_real->real);
}


std::unique_ptr<Numero> Real::Multiplicacion(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro);
    return make_unique<Real>(real*otro_real->real);
}

std::unique_ptr<Numero> Real::Division(const Numero& otro) const{
    const Real* otro_real = dynamic_cast<const Real*>(&otro); 
    return make_unique<Real>(real/otro_real->real);
}

string Real::toString()const{
    return to_string(real);
}

