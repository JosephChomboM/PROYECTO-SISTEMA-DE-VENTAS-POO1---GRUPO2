#pragma once
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
using namespace std;
class Venta
{
private:
    int     codVenta,
            codCliente,
            codVendedor;
    float   total;
    string fec;
public:
    Venta();
    void setCodVenta(int);
    void setCodCliente(int);
    void setCodVendedor(int);
    void setTotal(float);
    string setFecha(string);

    int getCodVenta();
    int getCodCliente();
    int getCodVendedor();
    float getTotal();
    //string getFecha();

};

Venta::Venta()
{
}
void Venta::setCodVenta(int codVenta)
{
    this->codVenta = codVenta;
}
void Venta::setCodCliente(int codCliente)
{
    this->codCliente = codCliente;
}
void Venta::setCodVendedor(int codVendedor)
{
    this->codVendedor = codVendedor;
}
void Venta::setTotal(float total)
{
    this->total = total;
}
string Venta::setFecha(string fec)
{   
    stringstream stream;
    string resultado;
    time_t t;
    t = time(NULL);
    struct tm* fecha;
    fecha = localtime(&t);
    stream << fecha->tm_mday << "-" << (fecha->tm_mon + 1) << "-" << (fecha->tm_year + 1900);

    resultado = stream.str();

    return resultado;
}
//get
int Venta::getCodVenta()
{
    return this->codVenta;
}
int Venta::getCodCliente()
{
    return this->codCliente;
}
int Venta::getCodVendedor()
{
    return this->codVendedor;
}
float Venta::getTotal()
{
    return this->total;
}
