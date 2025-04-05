#include "numero.h"
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
using namespace std;

//constructor
Complejo::Complejo(double UnComplejo, double UnImaginario = 0)
    : real(UnComplejo), imaginario(UnImaginario) {}


//definicion de métodos
std::unique_ptr<Numero> Complejo::Suma(const Numero& otro) const{
    const Complejo* otro_complejo = dynamic_cast<const Complejo*>(&otro); //uso dynamic cast pues es type safe con clases
    return make_unique<Complejo>(real + otro_complejo->real, imaginario + otro_complejo->imaginario);
}

std::unique_ptr<Numero> Complejo::Resta(const Numero& otro) const{
    const Complejo* otro_complejo = dynamic_cast<const Complejo*>(&otro);
    return make_unique<Complejo>(real - otro_complejo->real, imaginario - otro_complejo->imaginario);
}


std::unique_ptr<Numero> Complejo::Multiplicacion(const Numero& otro) const{
    const Complejo* otro_complejo = dynamic_cast<const Complejo*>(&otro);
    
    //multiplicación en complejos: (a+bi)×(c+di)=(ac−bd)+(ad+bc)i
    return make_unique<Complejo>((real*otro_complejo->real - imaginario*otro_complejo->imaginario), (real*otro_complejo->imaginario + imaginario*otro_complejo->real));
}


string Complejo::toString()const{
    
    stringstream numero_complejo;
    string signo = (imaginario >= 0) ? " + " : " - ";
    numero_complejo << real << signo << abs(imaginario) << "i";
    return numero_complejo.str();
}
