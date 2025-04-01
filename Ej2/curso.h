#pragma once

#include <iostream>
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

      bool operator<(const std::shared_ptr<Estudiante>&);
      friend std::ostream& operator<<(std::ostream&, const std::shared_ptr<Estudiante>&);

};

class Curso{
   private:
      const std::string nombre_curso;
      int capacidad;
      std::vector<std::shared_ptr<Estudiante>> estudiantes; //como los cursos comparten estudiantes, los cursos pueden apuntar a loa mismos estudiantes
   
   public:   
      Curso(const std::string&);
      Curso(const Curso&);
      std::string getNombreCurso();
      void InscribirAlumno(std::shared_ptr<Estudiante>&);
      void DesinscribirAlumno(const Estudiante&);
      bool VerInscripto(const double) const;
      bool isCompleto()const;
      void ImprimirEstudiantes();
      Curso CopiarCurso(const Curso&);

   friend class Estudiante;
};