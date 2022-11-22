#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../model/Venta.h"
using namespace std;
using std::stoi;
using std::stof;
class VentaController
{
private:
    vector<Venta> vectorVenta;
public:
    VentaController();
    void addVenta(Venta);
    Venta getVenta(int);
    int rowsVenta();
    int getCorrelativoVenta();
    void grabarArchivoVenta();
    void cargarDatosDelArchivoAlVector();
};

VentaController::VentaController()
{
    
}

void VentaController::addVenta(Venta obj)
{
    vectorVenta.push_back(obj);//agrega al final del vector
}
Venta VentaController::getVenta(int posicion)
{
    return vectorVenta[posicion];//pos del vector
}
int VentaController::rowsVenta()
{
    return vectorVenta.size();//cant del elem dl vector
}
int VentaController::getCorrelativoVenta()
{
    int i = 0;
    try
    {
        size_t posi;//max de una cadena
        string linea;
        string temporal[6];
        fstream archivoVenta;
        archivoVenta.open("Venta.csv", ios::in);

        if (archivoVenta.is_open())
        {
            while (!archivoVenta.eof())//no se cierra
            {
                while (getline(archivoVenta, linea))//se guarda en cada linea
                {
                    i++;
                }
                
            }
            archivoVenta.close();
        }
        
    }
    catch(exception e)
    {
        cout << "OCURRIO UN ERROR AL LEER EL ARCHIVO\n";
    }
    return i;   
}
void VentaController::grabarArchivoVenta()
{   
    string arg;
    try
    {
        fstream archivoVenta;
        archivoVenta.open("Venta.csv", ios::app);
        if (archivoVenta.is_open())
        {
            for (Venta x : vectorVenta)
            {
                archivoVenta    << x.getCodVenta() << ";"
                                << x.getCodCliente() << ";"
                                << x.getCodVendedor() << ";"
                                << x.setFecha(arg) << ";"
                                << x.getTotal() << ";" << endl;
            }
            archivoVenta.close();
        }
        
    }
    catch(exception e)
    {
        cout << "ERROR AL GRABAR\n";
    }
}
void VentaController::cargarDatosDelArchivoAlVector()
{
    try
    {   
        int i;
        size_t posi;
        string linea;
        string temporal[5];
        fstream archivoVenta;
        archivoVenta.open("Venta.csv", ios::in);

        if (archivoVenta.is_open())
        {
            while (!archivoVenta.eof() && getline(archivoVenta, linea))
            {
                i = 0;
                while ((posi = linea.find(";")) != string::npos)
                {
                    temporal[i] = linea.substr(0, posi);
                    linea.erase(0, posi + 1);
                    i++;
                }
                //crear objeto
                Venta objVenta;
                objVenta.setCodVenta(stoi(temporal[0]));
                objVenta.setCodCliente(stoi(temporal[1]));
                objVenta.setCodVendedor(stoi(temporal[2]));
                objVenta.setFecha(temporal[3]);
                objVenta.setTotal(stof(temporal[4]));

                addVenta(objVenta);
            }
        }
        archivoVenta.close();
    }
    catch(exception e)
    {
        cout << "Ocurrio un error al leer el archivo\n";
    }
    
}