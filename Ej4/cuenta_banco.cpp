#include "cuenta.h"
#include <string>
#include <iostream>

using namespace std;

CuentaBanco::CuentaBanco(string &Titular)
    :titularCuenta(Titular), balance(0) {}
