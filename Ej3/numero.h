#pragma once

#include <string>
#include <memory>

//declaración de la interfaz
class Numero {
    //es una interfaz, pues todos sus métodos son virtuales puros, no tiene constructores ni atributos
    public:
        virtual std::unique_ptr<Numero> Suma(const Numero&) const = 0;
        virtual std::unique_ptr<Numero> Resta(const Numero&) const = 0;
        virtual std::unique_ptr<Numero> Multiplicacion(const Numero&) const = 0;
        virtual std::string toString() const = 0;
};
/*
Se trabaja con punteros, pues, como la interfaz no puede ser instanciada, no podría existir
ningun valor de tipo Numero, sino de alguna de sus derivadas. Sinembargo, todos lo métodos
declarados devuelven Número. Por ello, usamos punteros, para no instanciar explicitamente a Numero
*/

//declaración de clases derivadas

class Entero: public Numero{
    private:
        int entero;
    
    public:
        //constructor
        Entero(int);

        //metodos
        std::unique_ptr<Numero> Suma(const Numero&) const override;
        std::unique_ptr<Numero> Resta(const Numero&) const override;
        std::unique_ptr<Numero> Multiplicacion(const Numero&) const override;
        std::unique_ptr<Numero> Division(const Numero&) const;
        std::string toString() const override;
        
        //destructor
        ~Entero() = default;
};

class Real: public Numero{
    private:
        double real;
    
    public:
        //constructor
        Real(double);
        
        //metodos
        std::unique_ptr<Numero> Suma(const Numero&) const override;
        std::unique_ptr<Numero> Resta(const Numero&) const override;
        std::unique_ptr<Numero> Multiplicacion(const Numero&) const override;
        std::unique_ptr<Numero> Division(const Numero&) const;
        std::string toString() const override;
        
        //destructor
        ~Real() = default;
};

class Complejo: public Numero{
    private:
        double real, imaginario;
    
    public:
        //constructor
        Complejo(double, double);

        //metodos
        std::unique_ptr<Numero> Suma(const Numero&) const override;
        std::unique_ptr<Numero> Resta(const Numero&) const override;
        std::unique_ptr<Numero> Multiplicacion(const Numero&) const override;
        std::string toString() const override;
        
        //destructor
        ~Complejo() = default;
};