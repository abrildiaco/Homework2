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
ningun valor de tipo std::unique_ptr<Numero>, sino de alguna de sus derivadas. Sinembargo, todos lo métodos
declarados devuelven número. Por ello, usamos punteros.
*/

//declaración de clases derivadas

class Entero: public Numero{
    private:
        int entero;
    
    public:
        Entero(int);
        std::unique_ptr<Numero> Suma(const Numero&) const override;
        std::unique_ptr<Numero> Resta(const Numero&) const override;
        std::unique_ptr<Numero> Multiplicacion(const Numero&) const override;
        std::unique_ptr<Numero> Division(const Numero&) const;
        std::string toString() const override;
        
        ~Entero() = default;
};

class Real: public Numero{
    private:
        double real;
    
    public:
        Real(double);
        std::unique_ptr<Numero> Suma(const Numero&) const override;
        std::unique_ptr<Numero> Resta(const Numero&) const override;
        std::unique_ptr<Numero> Multiplicacion(const Numero&) const override;
        std::unique_ptr<Numero> Division(const Numero&) const;
        std::string toString() const override;
        
        ~Real() = default;
};

class Complejo: public Numero{
    private:
        double real, imaginario;
    
    public:
        Complejo(double, double);
        std::unique_ptr<Numero> Suma(const Numero&) const override;
        std::unique_ptr<Numero> Resta(const Numero&) const override;
        std::unique_ptr<Numero> Multiplicacion(const Numero&) const override;
        std::string toString() const override;
        
        ~Complejo() = default;
};