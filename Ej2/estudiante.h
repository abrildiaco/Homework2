/*
a. El objeto estudiante simplemente cuenta con el nombre completo, su legajo 
(que es único por alumno), una lista de cursos con su nota final y los métodos 
que crea necesarios para obtener los datos del alumno: nombre completo, 
legajo y su promedio general. En función de esto, califique todos los atributos 
correctamente. 
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Estudiante{
    private:
       const std::string nombre_completo;
       const double legajo;
       std::vector<pair<string, float>> notas;
    
    public:
       Estudiante(std::string, const double);
       
       std::string getNombreCompleto()const;
       const double getLegajo()const;
       float getPromedioGeneral()const;

       void AgregarNota(const std::string&, float);


}