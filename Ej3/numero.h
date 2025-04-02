#pragma once

#include <string>

//declaración de la interfaz
class Numero {
    public:
        virtual Numero* Suma(const Numero&) const = 0;
        virtual Numero* Resta(const Numero&) const = 0;
        virtual Numero* Multiplicacion(const Numero&) const = 0;
        virtual std::string toString() const = 0;
};

//declaración de clases derivadas

class Entero: public Numero{
    private:
        int entero;
    
    public:
        Entero(int);
        Numero* Suma(const Numero&) const override;
        Numero* Resta(const Numero&) const override;
        Numero* Multiplicacion(const Numero&) const override;
        Numero* Division(const Numero&) const;
        std::string toString() const override;
        
        ~Entero() = default;
};

class Real: public Numero{
    private:
        double real;
    
    public:
        Real(double);
        Numero* Suma(const Numero&) const override;
        Numero* Resta(const Numero&) const override;
        Numero* Multiplicacion(const Numero&) const override;
        Numero* Division(const Numero&) const;
        std::string toString() const override;
        
        ~Real() = default;
};

class Complejo: public Numero{
    private:
        double real, imaginario;
    
    public:
        Complejo(double, double);
        Numero* Suma(const Numero&) const override;
        Numero* Resta(const Numero&) const override;
        Numero* Multiplicacion(const Numero&) const override;
        //Numero* Division(const Numero&) const override;
        std::string toString() const override;
        
        ~Complejo() = default;
};