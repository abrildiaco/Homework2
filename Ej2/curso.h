#pragma once

#include <iostream>
#include <string>
#include <vector>

class Estudiante{
    private:
       const std::string nombre_completo;
       const double legajo;
       std::vector<pair<string, const float>> notas; //vector que contiene pares (curso, nota final)
    
    public:
       Estudiante(std::string, const double);
       
       std::string getNombreCompleto()const;
       const double getLegajo()const;
       float getPromedioGeneral()const;

       void AgregarNota(const std::string&, float);

};

class Curso{
   private:
      const string nombre_curso;
      int capacidad;
      std::vector<std::shared_ptr<estudiante>> estudiantes; //como los cursos comparten estudiantes, los cursos pueden apuntar a loa mismos estudiantes
   
   public:   
      Curso(const std::string&);
      ~Curso();
      void getNombreCurso();
      void InscribirAlumno(Estudiante);
      void DesinscribirAlumno(Estudiante);
      bool VerInscripto(double) const;
      bool Completo()const;
      void ImprimirEstudiantes()const;
      void CopiarCurso();

};