#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "../model/DetalleVenta.h"
using namespace std;
using std::stoi;
class DetalleVentaController
{
private:
    vector<DetalleVenta> vectorDetalleVenta;
public:
    DetalleVentaController();
    void add(DetalleVenta);
    DetalleVenta get(int);
    int rows();
    void grabarDetalleVenta();
    void cargarDatosAlArhivoDetalle();
    void grabarModificarEliminarArchivo();
    void listarProducto(DetalleVenta);

};
DetalleVentaController::DetalleVentaController()
{

}
void DetalleVentaController::add(DetalleVenta obj)
{
    vectorDetalleVenta.push_back(obj);
}
DetalleVenta DetalleVentaController::get(int pos)
{
    return vectorDetalleVenta[pos];
}
int DetalleVentaController::rows()
{
    return vectorDetalleVenta.size();
}
void DetalleVentaController::grabarDetalleVenta()
{
    try
    {
        fstream archivoDetalle;
        archivoDetalle.open("DetalleVenta.csv", ios::app);
        if (archivoDetalle.is_open())
        {
            for (DetalleVenta x : vectorDetalleVenta)
            {
                archivoDetalle  << x.getCodVenta() << ";"
                                << x.getCodProducto() << ";"
                                << x.getCantidadProducto() << ";"
                                << x.getPrecioVenta() << ";" 
                                << x.getSubTotal() << ";" << endl; 
            }
            archivoDetalle.close();
        }
        
    }
    catch(exception e)
    {
        cout << "OCURRIO UN ERROR\n";
    }
    
}
void DetalleVentaController::cargarDatosAlArhivoDetalle()
{
    try
    {   
        int i;
        size_t posi;
        string linea;
        string temporal[5];
        fstream archivoDetalle;

        archivoDetalle.open("DetalleVenta.csv", ios::in);
        if (archivoDetalle.is_open())
        {
            while (!archivoDetalle.eof())
            {
                while (getline(archivoDetalle, linea))
                {
                    i = 0;
                    while ((posi = linea.find(";")) != string::npos)
                    {
                        temporal[i] = linea.substr(0, posi);
                        linea.erase(0, posi + 1);
                        i++;
                    }
                    //creaObjeto
                    DetalleVenta objDetalle;
                    
                    objDetalle.setCodVenta(stoi(temporal[0]));
                    objDetalle.setDescripcion(temporal[1]);
                    objDetalle.setCodProducto(stoi(temporal[2]));
                    objDetalle.setCantidadProducto(stoi(temporal[3]));
                    objDetalle.setPrecioVenta(stoi(temporal[4]));
                    objDetalle.getSubTotal();

                    add(objDetalle);
                    
                }
                
            }
            
        }
        archivoDetalle.close();
    }
    catch(exception e)
    {
        cout << "ERROR AL LEER EL ARCHIVO\n";
    }
    
}

void DetalleVentaController::listarProducto(DetalleVenta obj)
{
    cout    << setw(6) << left << ""
            << setw(8) << left << "COD"
            << setw(8) << left << "CANT"
            << setw(8) << left << "PREC/U"
            << "SUBTOTAL\n";
    cout    << setw(6) << left << ""
            << setw(8) << left << obj.getCodProducto()
            << setw(8) << left << obj.getCantidadProducto()
            << setw(8) << left << obj.getPrecioVenta()
            << obj.getSubTotal() << endl;
}