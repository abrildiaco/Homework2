#include "numero.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
Entero::Entero(int UnEntero)
    : entero(UnEntero) {}


//definicion de métodos
Numero* Entero::Suma(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return new Entero( entero + otro_entero->entero);
}

Numero* Entero::Resta(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return new Entero( entero - otro_entero->entero);
}


Numero* Entero::Multiplicacion(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return new Entero( entero*otro_entero->entero);
}

Numero* Entero::Division(const Numero& otro) const{
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro);
    return new Entero( entero/otro_entero->entero);
}

string Entero::toString()const{
    return to_string(entero);
}


//destructor
Entero::~Entero() {
    //cout<<"se eliminó el entero "<<endl;
}

//destructor interfaz

Numero::~Numero(){
    //cout<<"destructor numero"<<endl;
}