#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int main() {
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

    e1->AgregarNota("paradigmas", 10);
    e1->AgregarNota("ciencias", 8);
    e1->AgregarNota("ciencias", 10);
    cout<<e1->getPromedioGeneral()<<endl;

    Curso curso2 = curso;

    return 0;
}
