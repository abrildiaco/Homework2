/*
4. Se tiene una clase abstracta que representa una cuenta de banco genérica. Esta clase 
tiene los siguiente atributos y métodos: 
i. balance: el total de la cuenta (tipo int). 
ii. titularCuenta: nombre del dueño de la cuenta (string). 
iii. depositar(): deposita una cantidad de dinero en la cuenta. 
iv. retirar(): retira una cantidad de dinero de la cuenta (método virtual puro). 
v. mostrarInfo(): muestra la información de la cuenta (método virtual puro) que 
consta del balance, el tipo de cuenta y el nombre del titular. 
*/

#pragma once

#include <string>
#include <memory>

//declaración de clase abstracta

class CuentaBanco{
    protected: //es protected para que enntonces las clases derivada spueden acceder a ellos
        mutable int balance;
        std::string titularCuenta;
    
    public:
        CuentaBanco(std::string&);
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
        CajaDeAhorro(std::string&);
        void Depositar(int&) override;
        int Retirar(int&) override;
        void MostrarInfo() const override;
};

class CuentaCorriente: public CuentaBanco{
    private:
        int fondos;
        std::shared_ptr<CajaDeAhorro> cajaAhorro;
    
    public:
        CuentaCorriente(std::string&, std::shared_ptr<CajaDeAhorro>);
        void Depositar(int&) override;
        int Retirar(int&) override;
        void MostrarInfo() const override;
    
    friend CajaDeAhorro;
};