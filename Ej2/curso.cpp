#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

//CLASE ESTIDIANTE    

//constructor

Estudiante::Estudiante(string NombreCompleto, const double Legajo)
    :nombre_completo{NombreCompleto}, legajo{Legajo} {}


//definición de métodos

string Estudiante::getNombreCompleto()const{
    return nombre_completo;
}

const double Estudiante::getLegajo()const{
    return legajo;
}

float Estudiante::getPromedioGeneral()const{
    if(notas.empty()) return 0.0;
    
    float suma = 0;
    int q_notas = notas.size();
    
    for(const pair<string, float>& nota: notas) suma = suma + nota.second;

    float promedio = suma/q_notas;
    return promedio;
}

void Estudiante::AgregarNota(const std::string& nombre_curso, float nota){
    notas.push_back({nombre_curso, nota});
    return;
}

bool Estudiante::operator<(const shared_ptr<Estudiante>& otro){
    
    return nombre_completo < otro->getNombreCompleto();
}

ostream& operator<<(ostream& os, const shared_ptr<Estudiante>& alumno){
    os << alumno->getNombreCompleto()<<"\n";
    return os;
}


//CLASE CURSO

//Constructor

Curso::Curso(const string &curso)
    :capacidad(0), nombre_curso(curso){}

//Deep copy constructor

Curso::Curso(const Curso& original) // Deep copy de engine
        :capacidad(original.capacidad), nombre_curso(original.nombre_curso){}

        /*
hago uso de un deep copy constructor pues se trata de la copia de un objeto que contiene punteros.
Lo que hice fue hacer una sobrecarga de constructores en la cual, si a un constructor se le pasa un objeto de
la misma clase, creara un objeto nuevo con sus mismo atributos. Mas adelante, en la funcion CopiarCurso,
se inscribió a cada alumno de la clase original a la clase copia. Asi, obtuve dos objetos con los
mismos atributos, pero distintos en si.
*/


//Definción de métodos

string Curso::getNombreCurso(){
    return nombre_curso;
}

void Curso::InscribirAlumno(shared_ptr<Estudiante> &alumno){
    if(capacidad == 20){
        cout<<"El curso "<<nombre_curso<<" no tiene más capacidad";
        return;
    }
    
    estudiantes.push_back(alumno);
    capacidad++;
    
    cout<<"El alumno "<<alumno->getNombreCompleto()<<" fue inscripto al curso"<<endl;
    
    return;
}

void Curso::DesinscribirAlumno(const Estudiante &alumno){
    int pos=0;
    for(shared_ptr<Estudiante> estudiante: estudiantes){
        if (estudiante->getLegajo() == alumno.getLegajo()){
            
            estudiantes.erase(estudiantes.begin() + pos);
            cout<<"Alumno "<<alumno.getNombreCompleto()<<" eliminado del curso"<<endl;
            
            capacidad --;
            
            return;
        }
        pos ++;
    
    }
    cout<<"No se encontró el alumno"<<endl;
}  

bool Curso::VerInscripto(const double legajo_alumno)const{
    
    for(shared_ptr<Estudiante> estudiante: estudiantes){
        if (estudiante->getLegajo() == legajo_alumno) return true;
    }
    
    return false;
}

bool Curso::isCompleto()const{
    return capacidad >= 20;
}


void Curso::ImprimirEstudiantes(){
    //funcion lambda que compara que estudiante va antes en el alfabeto
    auto funcion_comparar = [](const shared_ptr<Estudiante>& estudiante1, const shared_ptr<Estudiante>& estudiante2)->bool {
        return estudiante1 < estudiante2; //hice uso de la sobreescritura del operador <
    };
    
    sort(estudiantes.begin(), estudiantes.end(), funcion_comparar); //ordena el vector de principio a fin en orden alfabetico
    
    for (shared_ptr<Estudiante> &estudiante: estudiantes ) cout << estudiante;
}

//Curso Curso::CopiarCurso(const Curso &original){
//    Curso copia = original;  // Deep copy usando copy constructor
//    for (auto &estudiante: original.estudiantes ) {
//        copia.InscribirAlumno(*estudiante);
//    }
//
//    return copia;
//}
