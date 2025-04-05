#pragma once

#include <string>
#include <vector>
#include <memory>

class Curso;

class Estudiante{
    private:
      const std::string nombre_completo;
      const int legajo;
      std::vector<std::pair<Curso, const float>> notas; //vector que contiene pares (curso, nota final)
    
    public:
      //constructor
      Estudiante(std::string, const int);
      
      //metodos
      std::string getNombreCompleto()const;
      const int getLegajo()const;
      float getPromedioGeneral()const;
      void AgregarNota(const Curso&, float);

      //sobreeescritura de operadores
      bool operator<(const Estudiante&);
      friend std::ostream& operator<<(std::ostream&, const std::shared_ptr<Estudiante>&);

      //destructor
      ~Estudiante() = default; //le digo explicitamente al compilador que cree un destructor

};

class Curso{
   private:
      const std::string nombre_curso;
      int capacidad;
      std::vector<std::shared_ptr<Estudiante>> estudiantes;
   
   public:   
      //constructores
      Curso(const std::string&);
      Curso(const Curso&);

      //metodos
      std::string getNombreCurso() const;
      void InscribirAlumno(std::shared_ptr<Estudiante>&, const int&);
      void DesinscribirAlumno(const int&);
      bool isInscripto(const int) const;
      bool isCompleto()const;
      void ImprimirEstudiantes();

      //destructor
      ~Curso() = default;

      //friend Estudiante;

};

/*
El tipo de relacion entre curso y estudiante es agregación. El curso no es dueño del estudiante, o viceversa.
Ttienen ciclos de vida separados, ninguno depende del otro: si el curso desaparece, los alumnos pueden buscar un
nuevo curso, y si pasa al reves, el curso sigue existiendo pero vacío.
Ademas, podemos referirnos al curso como un "todo" y a los alumnos
como sus "partes": los alumnos forman parte del curso. Hay una relacion mas estrecha entre ellos, pues el
alumno necesita del curso para aprender y el curso necesita de los alumnos para poder funcionar
*/

