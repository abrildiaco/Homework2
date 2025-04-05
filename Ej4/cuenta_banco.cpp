#include "cuenta.h"
#include <string>
#include <iostream>

using namespace std;

//como es una clase abstracta, solo instancio el constructor

CuentaBanco::CuentaBanco(const string &Titular)
    :titularCuenta(Titular), balance(0) {}
