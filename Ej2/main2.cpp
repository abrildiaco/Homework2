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

    cout<<"\n==== Bienvenido al campus de Administrador General de la carrera Ingeniería en IA ====\n"<<endl;
    cout<<"Por favor, cargue los cuatro cursos de la carrera y a sus alumnos:"<<endl;
    
    //CARRERA DE TRES CURSOS
    
    unique_ptr<vector<Curso>> cursos_carrera = make_unique<vector<Curso>>(); //puntero a vector que contiene los cursos

    
    string cargar_curso = "si";

    for(int i = 0; i<3; i++){

        cout<<"\n==Cargando curso=="<<endl;
        
        cout<<"\nIngrese el nombre del curso: ";
        string nombre_curso;
        getline(cin, nombre_curso);

        Curso curso(nombre_curso);

        cout<<"\n==Cargando alumnos=="<<endl;

        bool agregar = true;
        while (agregar){
            try{
                cout<<"\nIngrese el nombre del alumno: ";
                string nombre_alumno;
                getline(cin, nombre_alumno);
                
                cout<<"\nIngrese el legajo del alumno: ";
                int legajo;
                cin>>legajo;
                cin.ignore();

                shared_ptr<Estudiante> alumno = make_shared<Estudiante>(nombre_alumno, legajo);
                
                cout<<"\n¿Cual es la nota del alumno en el curso?: ";
                int nota;
                cin>>nota;
                cin.ignore();            
                
                curso.InscribirAlumno(alumno, nota);
            
            }catch (const exception& e) {
                
                cout << "Error: " << e.what() << endl;
                cout<<"Vuelve a intenterlo.."<<endl;
                continue;
            
            }    
            
            string respuesta;
            cout<<"\n¿desea cargar otro alumno? [si/no]: ";
            getline(cin, respuesta);
            
            if(respuesta == "no") break;
            
        }
        
        cursos_carrera->push_back(curso);

    }

    cout<<"\n== Fin de carga de datos =="<<endl;
    
    cout<<"\n== Inicializando acciones =="<<endl;
    
    bool continuar = true;
    while(continuar){
        
        int accion;
        cout<<"\n¿Que le gustaria hacer? (presione 0 para salir)"<<endl;
        cout<<"1 - Accionar sobre un curso"<<endl;
        cout<<"2 - Accionar sobre un estuduante"<<endl;
        cout<<"<<"; cin>>accion;
        cin.ignore();

        if(accion == 0) break;

        if(accion == 1){
            cout<<"\n¿Sobre que curso desea accionar? (presione el numero corrspondiente)"<<endl;
            
            for(int i = 0; i<3; i++){
                 cout<<i<<" - "<<(*cursos_carrera)[i].getNombreCurso()<<endl;
            }

            int num_curso;
            cout<<">>"; cin>>num_curso;
            cin.ignore();

            if(num_curso >= 3){cout<<"\nNo existe ese numero de curso"<<endl; continue;}

            bool continuar = true;
            while(continuar){
                int index;
                for(index = 0; index <num_curso; index++);

                cout<<"\n ¿Que accion desea realizar? (presione 0 para salir)"<<endl;
                cout<<"1 - Desinscribir alumno"<<endl;
                cout<<"2 - Ver si un alumno esta inscripto"<<endl;
                cout<<"3 - Ver si el curso esta completo"<<endl;
                cout<<"4 - Ver a los estudiantes del curso"<<endl;
                cout<<"5 - Hacer una copia del curso"<<endl;

                int accion;
                cout<<"<<"; cin>>accion;
                cin.ignore();
                
                if (accion  == 0) break;

                if(accion == 1){
                    
                }

            }
            
            
        }

        else cout<<"\nNo existe esa opción. Intente Nuevamente"<<endl;
    }
    // shared_ptr<Estudiante> e1 = make_shared<Estudiante>("Juan Perez", 101);
    // shared_ptr<Estudiante> e2 = make_shared<Estudiante>("Ana Gomez", 102);
    // shared_ptr<Estudiante> e3 = make_shared<Estudiante>("Luis Fernandez", 103);

    //   Curso curso("Programación");
    //   curso.InscribirAlumno(e1, 10);
    //   curso.InscribirAlumno(e2, 7);
    //   curso.InscribirAlumno(e3, 8);

    //   cout << "Lista de estudiantes en orden alfabético:\n";
    //   curso.ImprimirEstudiantes();
    //   curso.DesinscribirAlumno(e1);

    //   curso.ImprimirEstudiantes();

    //   cout<< curso.isInscripto(102)<<endl;
    //   cout<< curso.isInscripto(1)<<curso.isCompleto()<<endl;

    //   e1->AgregarNota(curso, 10);
    //   //e1->AgregarNota("ciencias", 8);
    //   //e1->AgregarNota("ciencias", 10);
    //   cout<<e1->getPromedioGeneral()<<endl;

    // // // Curso curso2 = curso;

    return 0;
    }

