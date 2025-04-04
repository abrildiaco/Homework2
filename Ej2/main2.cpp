#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

//g++ -std=c++20 main2.cpp curso.cpp -o main2 

int main() {
    
    //programa para que un profesor arme su curso

     cout<<"==== Bienvenido al campus de Administrador General de la carrera Ingeniería en IA ====\n"<<endl;
     cout<<"Por favor, cargue los cuatro cursos de la carrera y a sus alumnos:"<<endl;
    
     //carrera de cuatro cursoso

     vector<Cursos> cursos_carrera(4);

     string cargar_curso = "si";

    for(int i = 0, i<4, 4++){

        cout<<"\nIngrese el nombre del curso: ";
        string nombre_curso;
        getline(cin, nombre_curso);

        Curso curso(nombre_curso);

        
        bool agregar = true
        while (agregar){
            cout<<"\nIngrese el nombre del alumno: ";
            string nombre_alumno;
            getline(cin, nombre_alumno);
            
            cout<<"\nIngrese el legajo del alumno: ";
            int legajo;
            cin>>legajo;
            cin_igore(legajo);

            shared_ptr<Estudiante> alumno = make_shared<Estudiante>(nombre_alumno, legajo);
            
            cout<<"\n¿Cual es la nota del alumno en el curso?: ";
            int nota;
            cin>>nota;
            cin_igore(nota);            
            
            curso.InstribirAlumno(alumno, nota);
        }
        
        carrera_cursos.push_back(curso);
    }




    shared_ptr<Estudiante> e1 = make_shared<Estudiante>("Juan Perez", 101);
    shared_ptr<Estudiante> e2 = make_shared<Estudiante>("Ana Gomez", 102);
    shared_ptr<Estudiante> e3 = make_shared<Estudiante>("Luis Fernandez", 103);

    Curso curso("Programación");
    curso.InscribirAlumno(e1);
    curso.InscribirAlumno(e2);
    curso.InscribirAlumno(e3);

    cout << "Lista de estudiantes en orden alfabético:\n";
    curso.ImprimirEstudiantes();
    curso.DesinscribirAlumno(e1);

    curso.ImprimirEstudiantes();

    cout<< curso.isInscripto(102)<<endl;
    cout<< curso.isInscripto(1)<<curso.isCompleto()<<endl;

    e1->AgregarNota(curso, 10);
    // e1->AgregarNota("ciencias", 8);
    // e1->AgregarNota("ciencias", 10);
    cout<<e1->getPromedioGeneral()<<endl;

    Curso curso2 = curso;

    return 0;
}
