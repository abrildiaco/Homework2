#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int main() {
    Estudiante e1("Juan Perez", 101);
    Estudiante e2("Ana Gomez", 102);
    Estudiante e3("Luis Fernandez", 103);

    e1.AgregarNota("Matemáticas", 8.5);
    e2.AgregarNota("Física", 9.0);
    e3.AgregarNota("Historia", 7.5);

    Curso curso("Programación");
    curso.InscribirAlumno(e1);
    curso.InscribirAlumno(e2);
    curso.InscribirAlumno(e3);

    cout << "Lista de estudiantes en orden alfabético:\n";
    curso.ImprimirEstudiantes();

    Curso cursoCopia = CopiarCurso(curso);
    cout << "\nLista de estudiantes en la copia del curso:\n";
    cursoCopia.ImprimirEstudiantes();

    return 0;
}
