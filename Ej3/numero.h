#pragma once

#include <string>

//declaración de la interfaz
class Numero {
    public:
        virtual Numero* Suma(const Numero&) const = 0;
        virtual Numero* Resta(const Numero&) const = 0;
        virtual Numero* Multiplicacion(const Numero&) const = 0;
        //virtual Numero* Division(const Numero&) const = 0;
        virtual std::string toString() const = 0;
        
        virtual ~Numero()=0 ;// Destructor virtual para evitar fugas de memoria
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
        
        ~Entero();
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
        
        ~Real();
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
        
        ~Complejo();
};