#include "curso.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;
    
//constructor

Estudiante::Estudiante(string NombreCompleto, const int Legajo)
    :nombre_completo(NombreCompleto), legajo(Legajo) {}


//definición de métodos

string Estudiante::getNombreCompleto()const{
    return nombre_completo;
}

const int Estudiante::getLegajo()const{
    return legajo;
}

float Estudiante::getPromedioGeneral()const{
    if(notas.empty()) return 0.0;
    
    float suma = 0;
    int q_notas = notas.size();
    
    for(const pair<Curso, const float>& nota: notas) suma = suma + nota.second;

    float promedio = suma/q_notas;
    return promedio;
}

void Estudiante::AgregarNota(const Curso& curso, float nota){
    notas.push_back({curso, nota});
    return;
}

bool Estudiante::operator<(const Estudiante& otro){
    
    return this->nombre_completo < otro.getNombreCompleto();
}

ostream& operator<<(ostream& os, const shared_ptr<Estudiante>& alumno){
    os << alumno->getNombreCompleto()<<", "<< alumno->getLegajo()<<"\n";
    return os;
}

