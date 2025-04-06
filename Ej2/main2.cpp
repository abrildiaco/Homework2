#include "curso.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main() {
    
    cout<<"\n==== Bienvenido al campus de Administrador General de la carrera Ingeniería en IA ====\n"<<endl;
    
    //CARRERA DE TRES CURSOS
    
    unique_ptr<vector<Curso>> cursos_carrera = make_unique<vector<Curso>>(); //puntero a vector que contiene los cursos
    unique_ptr<vector< shared_ptr<Estudiante>>> alumnos_carrera = make_unique<vector< shared_ptr<Estudiante>>>(); //puntero a los extudiantes de la carrera
    
    //inicializacion de cursos
    cout<<"Por favor, cargue los tres cursos de la carrera:"<<endl;

    for(int i = 0; i<3; i++){

        cout<<"\n==Cargando curso=="<<endl;
        
        cout<<"\nIngrese el nombre del curso: ";
        string nombre_curso;
        getline(cin, nombre_curso);

        Curso curso(nombre_curso);

        cursos_carrera->push_back(curso);

    }
    
    //inicializacion de alumnos
    cout<<"\n---------------------------------------------------------------------------------- ";
    cout<<"\nPor favor, cargue a los alumnos de la carrera:"<<endl;
    cout<<"\n==Cargando alumnos=="<<endl;

    bool agregar = true;
    while (agregar){
        cout<<"\nIngrese el nombre del alumno: ";
        string nombre_alumno;
        getline(cin, nombre_alumno);
        
        cout<<"\nIngrese el legajo del alumno: ";
        int legajo;
        cin>>legajo;
        cin.ignore();

        shared_ptr<Estudiante> alumno = make_shared<Estudiante>(nombre_alumno, legajo);

        alumnos_carrera->push_back(alumno);

        //inscribiendo alumno a los cursos
        
        bool inscribir = true;
        
        while(inscribir){
            cout<<"¿A que curso le gustaría inscribir al alumno?"<<endl;
            
            for(int i = 0; i<3; i++){
                cout<<i<<" - "<<(*cursos_carrera)[i].getNombreCurso()<<endl;
            }

            int num_curso;
            cout<<">>"; cin>>num_curso;
            cin.ignore();
            
            try{
                        
                cout<<"\n¿Cual es la nota del alumno en el curso?: ";
                float nota;
                cin>>nota;
                cin.ignore();            
                
                //el metodo AgregarNota se prueba dentro del metodo InscribirAlumno
                (*cursos_carrera)[num_curso].InscribirAlumno(alumno, nota);
            }
            catch (const exception& e) {
                
                cout << "\n===Error: " << e.what() << "==="<<endl;
                cout<<"Vuelve a intenterlo..\n"<<endl;
                continue;
            
            }
            string respuesta;
            cout<<"\n¿Desea inscribirlo a otro curso? [si/no]: ";
            getline(cin, respuesta);
            
            if(respuesta == "no") break;    
        }
        cout<<"\n---------------------------------------------------------------------------------- ";
        
        string ver_promedio;
        cout<<"\n¿Desea ver el promedio del alumno? [si/no]: ";
        getline(cin, ver_promedio);
        
        if(ver_promedio == "si"){
            cout<<"Promedio general del alumno: " <<alumno->getPromedioGeneral()<<endl;
        }
        
        cout<<"\n---------------------------------------------------------------------------------- ";
        
        string respuesta;
        cout<<"\n¿Desea cargar otro alumno? [si/no]: ";
        getline(cin, respuesta);
        
        if(respuesta == "no") break;
        
    }

    cout<<"\n== Fin de carga de datos =="<<endl;
    
    cout<<"\n== Inicializando acciones =="<<endl;
    
    cout<<"\n¿Sobre que curso desea accionar? (presione el numero corrspondiente)"<<endl;
    
    for(int i = 0; i<3; i++){
            cout<<i<<" - "<<(*cursos_carrera)[i].getNombreCurso()<<endl;
    }

    int num_curso;
    cout<<">>"; cin>>num_curso;
    cin.ignore();

    //inicializacion de acciones
    bool continuar = true;
    while(continuar){

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
            //avanzo hasta el indice del curso sobre el cual accionar
            int index;
            for(index = 0; index <num_curso; index++);
            
            int legajo;
            cout<<"Ingrese el numero de legajo del alumno a desinscribir: ";
            cin>>legajo;
            cin.ignore();
            
            (*cursos_carrera)[index].DesinscribirAlumno(legajo);
            continue;

        }if(accion == 2){
            //avanzo hasta el indice del curso sobre el cual accionar
            int index;
            for(index = 0; index <num_curso; index++);
            
            int legajo;
            cout<<"Ingrese el numero de legajo del alumno: ";
            cin>>legajo;
            cin.ignore();
            
            bool inscripcion = (*cursos_carrera)[index].isInscripto(legajo);

            if(inscripcion) cout<<"El alumno está inscripto al curso"<<endl;
            else cout<<"El alumno no está inscripto al curso"<<endl;

            continue;

        }if(accion == 3){
            //avanzo hasta el indice del curso sobre el cual accionar
            int index;
            for(index = 0; index <num_curso; index++);
            
            bool completo = (*cursos_carrera)[index].isCompleto();

            if(completo) cout<<"El curso esta compelto"<<endl;
            else cout<<"El curso no esta completo"<<endl;

            continue;

        }if(accion == 4){
            //avanzo hasta el indice del curso sobre el cual accionar
            int index;
            for(index = 0; index <num_curso; index++);
            
            (*cursos_carrera)[index].ImprimirEstudiantes();
            
            continue;

        }if(accion == 5){
            //avanzo hasta el indice del curso sobre el cual accionar
            int index;
            for(index = 0; index <num_curso; index++);
            
            Curso curso2 = (*cursos_carrera)[index];

            cout<<"copia de curso hecha"<<endl;
            
            continue;

        }

        else cout<<"\nNo existe esa opción. Intente Nuevamente"<<endl;

    }
        
    return 0;
}

