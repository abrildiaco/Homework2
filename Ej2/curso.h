#pragma once

#include <string>
#include <vector>
#include <memory>

class Estudiante{
    private:
      const std::string nombre_completo;
      const double legajo;
      std::vector<std::pair<std::string, const float>> notas; //vector que contiene pares (curso, nota final)
    
    public:
      Estudiante(std::string, const double);
      
      std::string getNombreCompleto()const;
      const double getLegajo()const;
      float getPromedioGeneral()const;
      
      void AgregarNota(const std::string&, float);

      bool operator<(const Estudiante&);
      friend std::ostream& operator<<(std::ostream&, const std::shared_ptr<Estudiante>&);

};

class Curso{
   private:
      const std::string nombre_curso;
      int capacidad;
      std::vector<std::shared_ptr<Estudiante>> estudiantes;
   
   public:   
      Curso(const std::string&);
      Curso(const Curso&);
      std::string getNombreCurso();
      void InscribirAlumno(std::shared_ptr<Estudiante>&);
      void DesinscribirAlumno(std::shared_ptr<Estudiante>&);
      bool isInscripto(const double) const;
      bool isCompleto()const;
      void ImprimirEstudiantes();

      void SimuladorCurso(Curso&); //función para crear un curso con estudiantes

};

/*
El tipo de relacion entre curso y estudiante es agregación. El surso no es dueño del estudiante, o viceversa.
Es más, el curso no contiene estudiantes, sino punteros a ellos. Tambien, tienen ciclos de vida separados,
ninguno sepende del otro: si el curso desaparece, los alumnos pueden buscar un nuevo curso, y si pasa al reves,
...
*/

