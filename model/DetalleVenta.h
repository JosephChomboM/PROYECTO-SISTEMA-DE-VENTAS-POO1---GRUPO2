#pragma once
#include <iostream>
using namespace std;
class DetalleVenta
{
private:
    int     codVenta,
            codPro,
            cantidadPro;
    float   precioVenta;
    string  descripcion;

public:
    DetalleVenta();
    //set   
    void setCodVenta(int);
    void setCodProducto(int);
    void setCantidadProducto(int);
    void setPrecioVenta(float);
    void setDescripcion(string);
    //get
    int getCodVenta();
    int getCodProducto();
    int getCantidadProducto();
    float getPrecioVenta();
    string getDescripcion();
    float getSubTotal();

};

DetalleVenta::DetalleVenta()
{
}
void DetalleVenta::setCodVenta(int codVenta)
{
    this->codVenta = codVenta;
}
void DetalleVenta::setCodProducto(int codPro)
{
    this->codPro = codPro;
}
void DetalleVenta::setCantidadProducto(int cantidadPro)
{
    this->cantidadPro = cantidadPro;
}
void DetalleVenta::setPrecioVenta(float precioVenta)
{
    this->precioVenta = precioVenta;
}
void DetalleVenta::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}
//get
int DetalleVenta::getCodVenta()
{
    return this->codVenta;
}
int DetalleVenta::getCodProducto()
{
    return this->codPro;
}
int DetalleVenta::getCantidadProducto()
{
    return this->cantidadPro;
}
float DetalleVenta::getPrecioVenta()
{
    return this->precioVenta;
}
string DetalleVenta::getDescripcion()
{
    return this->descripcion;
}
float DetalleVenta::getSubTotal()
{
    return this->getCantidadProducto() * this->getPrecioVenta();
}