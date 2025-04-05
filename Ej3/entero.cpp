#include "numero.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

//constructor
Entero::Entero(int UnEntero)
    : entero(UnEntero) {}


//definicion de métodos
std::unique_ptr<Numero> Entero::Suma(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return make_unique<Entero>( entero + otro_entero->entero);
}

std::unique_ptr<Numero> Entero::Resta(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return make_unique<Entero>( entero - otro_entero->entero);
}


std::unique_ptr<Numero> Entero::Multiplicacion(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return make_unique<Entero>( entero*otro_entero->entero);
}

std::unique_ptr<Numero> Entero::Division(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return make_unique<Entero>( entero/otro_entero->entero);
}

string Entero::toString()const{
    return to_string(entero); //uso el método propio de string
}
