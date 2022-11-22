#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "../model/Personal.h"
#include "TipoPersonalController.h"
#include <fstream>
using namespace std;

class PersonalController
{
private:
	vector<Personal> vectorPersonal;

public:
	PersonalController();
	void add(Personal);
	Personal get(int);
	int size();
	int getCorrelativo();
	Personal buscar(int);
	int busquedaPersonal(string);
	bool modificar(Personal, Personal);
	int getPostVector(Personal);
	void eliminar(Personal);
	bool verificarDatos(string, string);
	void listar();
	void grabarEnArchivo(Personal);
	void grabarModificarEliminar();
	void cargarDatosDelArchivoAlVector();
};
PersonalController::PersonalController()
{
	cargarDatosDelArchivoAlVector();
}
void PersonalController::add(Personal obj)
{
	vectorPersonal.push_back(obj); // Usuario obj
}
Personal PersonalController::get(int pos)
{
	return vectorPersonal[pos]; // vectorUsuario[0].getCodigo() = 1; vectorUsuario[0].getContra() = "xd";
}
int PersonalController::size()
{
	return vectorPersonal.size(); // si el vectorUsuario tiene posicion 0 y 1, vectorUsuario.size() = 2 porque empieza a contar desde 1;
}
int PersonalController::getCorrelativo()
{
	if (size() == 0)
	{
		return 1; // vectorUsuario[0].getCodigo() = 1;
	}
	else
	{
		return vectorPersonal[size() - 1].getCodPer() + 1; // vectorUsuario[0] size() = 1; vectorUsuario[1-1].getCodigo() + 1 = 1+1 = 2, vectorUsuario[1].getCodigo() = 2;
	}
}
Personal PersonalController::buscar(int dato)
{
	Personal objError;
	objError.setUser("Error");
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (dato == vectorPersonal[i].getCodPer())
		{
			return vectorPersonal[i];
		}
	}
	return objError;
}
int PersonalController::busquedaPersonal(string dato)
{
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (dato == vectorPersonal[i].getUser())
		{
			return vectorPersonal[i].getCodPer();
		}
	}
	return -1;
}
bool PersonalController::modificar(Personal ObjOld, Personal ObjNew)
{
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (ObjOld.getCodPer() == vectorPersonal[i].getCodPer())
		{
			vectorPersonal[i].setNomApe(ObjNew.getNomApe());
			vectorPersonal[i].setDniPer(ObjNew.getDni());
			vectorPersonal[i].setSuePer(ObjNew.getSue());
			vectorPersonal[i].setCodTipPer(ObjNew.getCodTipPer());
			vectorPersonal[i].setUser(ObjNew.getUser());
			vectorPersonal[i].setContra(ObjNew.getContra());
			return true;
		}
	}
	return false;
}
int PersonalController::getPostVector(Personal obj)
{
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (obj.getCodPer() == vectorPersonal[i].getCodPer())
		{
			return i;
		}
	}
	return -1;
}
void PersonalController::eliminar(Personal objEncontrado)
{
	vectorPersonal.erase(vectorPersonal.begin() + getPostVector(objEncontrado));
}
bool PersonalController::verificarDatos(string user, string contra)
{
	TipoPersonalController *obj = new TipoPersonalController;
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (user == vectorPersonal[i].getUser() && contra == vectorPersonal[i].getContra()) // verifica si la contrase�a y el usuario son iguales
		{
			cout << "\n\nUsuario y contrasenia correctos.\n";
			cout << "Ha ingresado al sistema como " << obj->listarTipo(vectorPersonal[i]) << "\n";
			return true;
		}
	}
	return false;
}
void PersonalController::listar()
{
	TipoPersonalController *obj = new TipoPersonalController;
	cout	<< setw(20) << left << "Nombres y Apellidos"
			<< setw(12) << left << "Dni"
			<< setw(8) << left << "Sueldo"
			<< setw(12) << left << "Tipo de Personal"
			<< "Usuario\n";
	cout << "---------------------------------------------------------\n\n";
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		cout	<< setw(20) << left << vectorPersonal[i].getNomApe()
				<< setw(12) << left << vectorPersonal[i].getDni()
				<< setw(8) << left << vectorPersonal[i].getSue()
				<< setw(12) << left << obj->listarTipo(vectorPersonal[i])
				<< vectorPersonal[i].getUser() << endl;
	}
}
void PersonalController::grabarEnArchivo(Personal obj)
{
	try
	{
		fstream archivoPersonal;
		archivoPersonal.open("personal.csv", ios::app); // ios::app = las operaciones se realizan al final del archivo
		string temporal;

		if (archivoPersonal.is_open())
		{
			archivoPersonal << obj.getCodPer() << ";" << obj.getNomApe() << ";" << obj.getDni() << ";" << obj.getSue() << ";" << obj.getCodTipPer() << ";" << obj.getUser() << ";" << obj.getContra() << ";" << endl;
			archivoPersonal.close();
		}
	}
	catch (exception e)
	{
		cout << "Ocurrio un error al grabar el archivo";
	}
}
void PersonalController::grabarModificarEliminar()
{
	try
	{
		fstream archivoPersonal;
		archivoPersonal.open("personal.csv", ios::out);
		string temporal;
		// Encriptando datos
		if (archivoPersonal.is_open())
		{
			for (Personal x : vectorPersonal)
			{
				archivoPersonal << x.getCodPer() << ";" << x.getNomApe() << ";" << x.getDni() << ";" << x.getSue() << ";" << x.getCodTipPer() << ";" << x.getUser() << ";" << x.getContra() << ";" << endl;
			}
			archivoPersonal.close();
		}
	}
	catch (exception e)
	{
		cout << "Ocurrio un error al grabar el archivo";
	}
}
void PersonalController::cargarDatosDelArchivoAlVector()
{
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[7];
		fstream archivoPersonal;
		archivoPersonal.open("personal.csv", ios::in); // ios::in = modo lectura(entrada)
		if (archivoPersonal.is_open())
		{
			while (!archivoPersonal.eof() && getline(archivoPersonal, linea)) // mientras archivoUsuario tenga datos;
			{
				i = 0;
				while ((posi = linea.find(";")) != string::npos) // string::npos = -1, posi = 1
				{
					temporal[i] = linea.substr(0, posi); // temporal[0] = linea.substr(0, 1); temporal[0] = 1
					linea.erase(0, posi + 1);			 // linea.erase(0,2);
					++i;								 // i = 1
					// Vuelve a iterar
				}
				// Desencriptando datos
				string contraNew;
				//contraNew = temporal[6];
				Personal objPer(stoi(temporal[0]), temporal[1], temporal[2], stoi(temporal[3]), stoi(temporal[4]), temporal[5], temporal[6]);
				add(objPer);
			}
		}
	}
	catch (exception e)
	{
		cout << "Ocurrio  un error al grabar el archivo";
	}
}