#pragma once

#include <string>
#include <memory>

//declaración de clase abstracta
class CuentaCorriente;

class CuentaBanco{
    protected: //es protected para que enntonces las clases derivada spueden acceder a ellos
        mutable int balance;
        std::string titularCuenta;
    
    public:
        CuentaBanco(const std::string&);
        virtual void Depositar(int&) = 0;
        virtual int Retirar(int&) = 0;
        virtual void MostrarInfo() const = 0;
        virtual ~CuentaBanco() = default;
};

//declaración de clases derivadas

class CajaDeAhorro: public CuentaBanco{
    private:
        mutable int contador_info; //es declarado atributo mutable, pues sera usado en un metodo const
    
    public:
        //constructor    
        CajaDeAhorro(const std::string&);

        //metodos
        void Depositar(int&) override;
        int Retirar(int&) override;
        void MostrarInfo() const override;

        //destructor
        ~CajaDeAhorro() = default;

        friend CuentaCorriente;
};

class CuentaCorriente: public CuentaBanco{
    private:
        int fondos;
        std::unique_ptr<CajaDeAhorro> cajaAhorro;
    
    public:
        //constructor    
        CuentaCorriente(const std::string&, std::unique_ptr<CajaDeAhorro>);

        //metodos
        void Depositar(int&) override;
        int Retirar(int&) override;
        void MostrarInfo() const override;

        //destructor
        ~CuentaCorriente() = default;
    
};