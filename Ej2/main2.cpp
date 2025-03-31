#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int main() {
    auto e1 = make_shared<Estudiante>("Juan Perez", 101);
    auto e2 = make_shared<Estudiante>("Ana Gomez", 102);
    auto e3 = make_shared<Estudiante>("Luis Fernandez", 103);

    Curso curso("Programación");
    curso.InscribirAlumno(&e1);
    curso.InscribirAlumno(&e2);
    curso.InscribirAlumno(&e3);

    cout << "Lista de estudiantes en orden alfabético:\n";
    curso.ImprimirEstudiantes();

    Curso cursoCopia = CopiarCurso(curso);
    cout << "\nLista de estudiantes en la copia del curso:\n";
    cursoCopia.ImprimirEstudiantes();

    return 0;
}
