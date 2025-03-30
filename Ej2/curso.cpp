#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//CLASE ESTIDIANTE    

//constructor

Estudiante::Estudiante(string NombreCompleto, const double Legajo)
    :nombre_completo{NombreCompleto}, legajo{Legajo} {}


//definición de métodos

std::string Estudiante::getNombreCompleto()const{
    return nombre_completo;
}

const double Estudiante::getLegajo()const{
    return legajo;
}

float Estudiante::getPromedioGeneral()const{
    if(notas.empty()) return 0.0;
    
    float suma;
    q_notas = notas.size();
    
    for(const float nota: notas) suma = suma + nota[1];

    promedio = suma/q_notas
    return promedio;
}

void Estudiante::AgregarNota(const std::string& nombre_curso, float nota){
    notas.push_back({nombre_curso, nota});
    return;
}


//CLASE CURSO

/*
      Curso(int);
      ~Curso();
      void InscribirAlumno(Estudiante);
      void DesinscribirAlumno(Estudiante);
      bool VerInscripto(double);
      bool Completo();
      void ImprimirEstudiantes();
      void CopiarCurso();

*/

//Constructor

Curso::Curso(string curso)
    :capacidad{0}, nombre_curso{curso}{}

//Destructor
    
Curso::~Curso(){
    for(shared_ptr<estudiante> estudiante: estudiantes){
        if (!estudiante) return;

        delete estudiante;
    }
    cout<<"El curso "<< nombre_curso<<" fue eliminado"<<endl;
}
    
//Definción de métodos

void Curso::getNombreCurso(){
    return nombre_curso;
}

void Curso::InscribirAlumno(Estudiante alumno){
    shared_ptr<Estudiante> nuevo_alumnno = make_shared(alumno);
    estudiantes.push_back(nuevo_alumno);
    cout<<"El alumno "<<alumno.getNombreCompleto()<<" fue inscripto al curso"<<endl;
    return;
}

void Curso::DesinscribirAlumno(Estudiante alumno){
    for(shared_ptr<Estudiante> estudiante: estudiantes){
        if (estudiante.legajo == alumno.legajo){
            estudiantes.erase(estudiante);
            cout<<"Alumno "<<alumno.getNombreCompleto()<<" eliminado del curso"<<endl;
            return;
        }
    
    }
    cout<<"No se encontró el alumno"<<endl;
}  

