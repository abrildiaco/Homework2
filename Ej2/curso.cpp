#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

//Constructor

Curso::Curso(const string &curso)
    :capacidad(0), nombre_curso(curso){ cout << "curso "<<curso<<" creado con éxito"<<endl;}

//Deep copy constructor

 Curso::Curso(const Curso& original)
         :capacidad(original.capacidad), nombre_curso(original.nombre_curso){
          
             //hago copia de los alumnos
             for (const shared_ptr<Estudiante>&estudiante: original.estudiantes ) {
                 estudiantes.push_back(make_shared<Estudiante>(estudiante->getNombreCompleto(), estudiante->getLegajo()));
        
             }
 }
/*
hago uso de un deep copy constructor pues se trata de la copia de un objeto que contiene punteros.
Lo que hice fue hacer una sobrecarga de constructores en la cual, si a un constructor se le pasa un objeto de
la misma clase, creara un objeto nuevo con sus mismo atributos. Asi, obtuve dos objetos con los
mismos atributos, pero distintos en si. Es importante observar, qu etambien se crearon nuevos punteros a alumnos,
de no ser asi, si elimino un alumno de un curso, tambien se eliminaría del otro
*/


//Definción de métodos

string Curso::getNombreCurso()const{
    return nombre_curso;
}

void Curso::InscribirAlumno(shared_ptr<Estudiante> &alumno, const int &nota_alumno){
    if(capacidad == 20){
        cout<<"El curso "<<nombre_curso<<" no tiene más capacidad";
        return;
    }
    for (const shared_ptr<Estudiante>&estudiante: estudiantes ) {
        if (estudiante->getLegajo() == alumno ->getLegajo()) throw invalid_argument("El numero de legajo ya existe");

    }
    
    estudiantes.push_back(alumno);
    
    alumno->AgregarNota( *this, nota_alumno);
    
    capacidad++;
    
    cout<<"El alumno "<<alumno->getNombreCompleto()<<" fue inscripto al curso "<<nombre_curso<<endl;
    
    return;
}

void Curso::DesinscribirAlumno(const int &un_legajo){
    int pos = 0;
    
    for(shared_ptr<Estudiante> estudiante: estudiantes){
        if (estudiante->getLegajo() == un_legajo){
            
            estudiantes.erase(estudiantes.begin() + pos);
            cout<<"Alumno "<<estudiante->getNombreCompleto()<<" eliminado del curso "<<nombre_curso<<endl;
            
            capacidad --;
            
            return;
        }
        pos ++;
    
    }
    cout<<"No se encontró el alumno"<<endl;
}  

bool Curso::isInscripto(const int legajo_alumno)const{
    
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
        return *estudiante1 < *estudiante2; //hice uso de la sobreescritura del operador <
    };
    
    sort(estudiantes.begin(), estudiantes.end(), funcion_comparar); //ordena el vector de principio a fin en orden alfabetico
    
    for (shared_ptr<Estudiante> &estudiante: estudiantes ) cout << estudiante;
}

