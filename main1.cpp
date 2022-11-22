#include <iostream>
#include <cstdlib>
#include <conio.h> // astericos en la contrasenia
#include <string>
#include <ctime>  // fecha y hora
#include <iomanip> // ordenar mejor las listas
#include <algorithm> // convertir datos a mayusculas
#include "controller/ClienteController.h"
#include "controller/PersonalController.h"
#include "controller/TipoPersonalController.h"
#include "controller/ProductoController.h"
#include "controller/CategoriaController.h"
#include "controller/VentaController.h"
#include "controller/DetalleVentaController.h"
using namespace std;
// Variables globales
ClienteController *objClienteController = new ClienteController();
PersonalController *objPersonalController = new PersonalController();
TipoPersonalController *tipController = new TipoPersonalController();
ProductoController *objProductoController = new ProductoController();
CategoriaController *objCategoriaController = new CategoriaController();
VentaController* objVentaController = new VentaController();
DetalleVentaController* objDetalleVentaController = new DetalleVentaController(); 
// Prototipos
void title();
// Seguridad
void login();
// Sistema principal
void MenuDelSistema();
// CLIENTES
void MenuDeClientes();
void addCliente();
void buscarCliente();
void listarCliente();
void modificarCliente();
void eliminarCliente();
// PERSONAL
void MenuDePersonal();
void addPersonal();
void buscarPersonal();
void listarPersonal();
void modificarPersonal();
void eliminarPersonal();
// TIPO DE PERSONAL
void MenuDeTipoDePersonal();
void addTipoPersonal();
void buscarTipoPersonal();
void listarTipoPersonal();
void modificarTipoPersonal();
void eliminarTipoPersonal();
// PRODUCTOS
void MenuDeProductos();
void addProducto();
void buscarProducto();
void listarProducto();
void modificarProducto();
void eliminarProducto();
// CATEGORIA DE PRODUCTOS
void MenuDeCategoria();
void addCategoria();
void buscarCategoria();
void listarCategoria();
void modificarCategoria();
void eliminarCategoria();
// VENTA
void fechaYHoraBoleta();
void MenuDeVenta();

string users;

int main()
{
	login();
	return 0;
}
// Implementacion
void title()
{
	system("cls");
	cout << "__      __        _          __  __" << endl;
	cout << "\\ \\    / /       | |        |  \\/  |" << endl;
	cout << " \\ \\  / /__ _ __ | |_ __ _  | \\  / | __ _ ___ " << endl;
	cout << "  \\ \\/ / _ \\ '_ \\| __/ _` | | |\\/| |/ _` / __|" << endl;
	cout << "   \\  /  __/ | | | || (_| | | |  | | (_| \\__ \"" << endl;
	cout << "    \\/ \\___|_| |_|\\__\\__,_| |_|  |_|\\__,_|___/\n"
		 << endl;
	cout << endl;
}
void login()
{
	string contrasenia;
	bool bandera;
	int contador;

	title();
	cout << "\t     LOG IN\n";
	cout << "\t----------------\n\n";
	cout << "Escriba su Usuario: ";
	getline(cin, users);
	
	cout << "Escriba su Contrasenia: ";
	// getline(cin, contrasenia);

	// contrasena con asteriscos
	char caracter;
	caracter = getch();
	while (caracter != 13) // mientras caracter sea diferente de enter
	{
		if (caracter != 8) // si el caracter es diferente de backspace
		{
			contrasenia.push_back(caracter); // mete el caracter al string contra
			cout << "*";					 // muestra los * en la consola
			caracter = getch();
		}
		else
		{
			if (contrasenia.length() > 0) // si el contra.length es mayor a 0
			{
				cout << "\b \b";											   // muestra como si borrara un caracter en la consola
				contrasenia = contrasenia.substr(0, contrasenia.length() - 1); // borra de verdad el dato en contrasenia
				caracter = getch();
			}
		}
	}
	//objPersonalController->verificarDatos(users, contrasenia);

	if (objPersonalController->verificarDatos(users, contrasenia) == true)
	{	
		system("pause");
		MenuDelSistema();
		bandera = true;
	}
	else
	{
		cout << "\nLos datos son erroneos\n";
		system("pause");
	}
}
void MenuDelSistema()
{
	int opt;
	do
	{
		title();
		cout << "\t   MENU PRINCIPAL\n";
		cout << "\t----------------------\n\n";
		cout << "[1] Clientes\n";
		cout << "[2] Personal\n";
		cout << "[3] Tipo de personal\n";
		cout << "[4] Productos\n";
		cout << "[5] Categoria de Productos\n";
		cout << "[6] Generar venta\n";
		cout << "[7] Salir\n";
		cout << "Ingrese una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			MenuDeClientes();
			break;
		case 2:
			system("cls");
			MenuDePersonal();
			break;
		case 3:
			system("cls");
			MenuDeTipoDePersonal();
			break;
		case 4:
			system("cls");
			MenuDeProductos();
			break;
		case 5:
			system("cls");
			MenuDeCategoria();
			break;
		case 6:
			system("cls");
			MenuDeVenta();
			system("pause");
			break;
		case 9:
			cout << "Gracias por usar nuestro programa\n";
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-9].\n";
		}
	} while (opt != 7);
}

// CLIENTE
void MenuDeClientes()
{
	int opt;

	do
	{
		title();
		cout << "\t   MANTENIMIENTO DE CLIENTES\n";
		cout << "\t-------------------------------\n\n";
		cout << "Add cliente********[1]\n";
		cout << "Buscar cliente*****[2]\n";
		cout << "Listar cliente*****[3]\n";
		cout << "Modificar cliente**[4]\n";
		cout << "Eliminar cliente***[5]\n";
		cout << "Volver atras*******[6]\n";
		cout << "Ingresa una opcion correcta [1-6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addCliente();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarCliente();
			system("pause");
			system("cls");
			break;
		case 3:
			listarCliente();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarCliente();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarCliente();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la pagina anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			cout << "Ingrese una opcion valida [1 - 7]: \n";
		}
	} while (opt != 6);
}
void addCliente()
{
	int cod, dni;
	string nomb, apell, direc, flag;
	title();
	cout << "\t   ANIADIR CLIENTE\n";
	cout << "\t---------------------\n\n";
	do
	{
		cod = objClienteController->getCorrelativo();
		cout << "\tCodigo [ " << cod << " ]\n";
		cout << "Dni: ";
		cin >> dni;
		cin.ignore();
		cout << "Nombres: ";
		getline(cin, nomb);
		transform(nomb.begin(), nomb.end(), nomb.begin(), ::toupper);
		cout << "Apellidos: ";
		getline(cin, apell);
		transform(apell.begin(), apell.end(), apell.begin(), ::toupper);
		cout << "Direccion: ";
		getline(cin, direc);
		transform(direc.begin(), direc.end(), direc.begin(), ::toupper);
		Cliente Cliente(cod, dni, nomb, apell, direc);
		objClienteController->addCliente(Cliente);
		objClienteController->grabarEnArchivo(Cliente);

		cout << "Continuar(S/s): ";
		cin >> flag;
		cout << "-------------------------\n";
	} while (flag == "s" || flag == "S");
}
void buscarCliente()
{
	int cod;
	title();
	cout << "Ingrese codigo a buscar: ";
	cin >> cod;

	Cliente ClienteObj = objClienteController->buscarPorCodigoCliente(cod);

	if (ClienteObj.getNombreCliente() != "ERROR")
	{
		cout << "\tREGISTRO ENCONTRADO\n\n";
		cout << "Codigo: " << ClienteObj.getCodCliente() << endl;
		cout << "Dni: " << ClienteObj.getDniCliente() << endl;
		cout << "Nombres: " << ClienteObj.getNombreCliente() << endl;
		cout << "Apellidos: " << ClienteObj.getApellidoCliente() << endl;
		cout << "Dirrecion: " << ClienteObj.getDireccionCliente() << endl;
	}
	else
	{
		cout << "No se encontro el registro";
	}
}
void listarCliente()
{
	title();
	cout << "\t   REPORTE DE CLIENTES\n";
	cout << "\t-------------------------\n\n";
	objClienteController->listarCliente();
}
void modificarCliente()
{
	int cod;
	title();
	cout << "\t   MODIFICACION DE DATOS\n";
	cout << "\t---------------------------\n\n";

	cout << "Ingresar el codigo a modificar: ";
	cin >> cod;
	Cliente ClienteObj = objClienteController->buscarPorCodigoCliente(cod);
	// Buscar objeto a modificar
	cout << "\tREGISTRO ENCONTRADO\n\n";
	cout << "Codigo: " << ClienteObj.getCodCliente() << endl;
	cout << "Dni: " << ClienteObj.getDniCliente() << endl;
	cout << "Nombres: " << ClienteObj.getNombreCliente() << endl;
	cout << "Apellidos: " << ClienteObj.getApellidoCliente() << endl;
	cout << "Dirrecion: " << ClienteObj.getDireccionCliente() << endl;
	// fin del objeto a modificar
	int dniM;
	string nomM, apellM, direcM;

	cout << "MODIFICANDO CAMPOS...\n\n";
	cout << "Modificando el Dni...:";
	cin >> dniM;
	cin.ignore();
	cout << "Modificando los nombres...: ";
	getline(cin, nomM);
	transform(nomM.begin(), nomM.end(), nomM.begin(), ::toupper);
	cout << "Modificando los apellidos...: ";
	getline(cin, apellM);
	transform(apellM.begin(), apellM.end(), apellM.begin(), ::toupper);
	cout << "Modificando la direccion...: ";
	getline(cin, direcM);
	transform(direcM.begin(), direcM.end(), direcM.begin(), ::toupper);
	bool estado = objClienteController->modificar(ClienteObj, dniM, nomM, apellM, direcM);
	if (estado = true)
	{
		cout << "Registro modificado satisfactoriamente\n";
		objClienteController->grabarModificarEliminar();
	}
	else
	{
		cout << "No enconto el registro a modificar\n";
	}
}
void eliminarCliente()
{
	int cod;
	title();
	cout << "\t   ELIMINAR CLIENTE\n";
	cout << "\t----------------------\n\n";
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Cliente objEliminar = objClienteController->buscarPorCodigoCliente(cod);
	if (objEliminar.getNombreCliente() != "ERROR")
	{
		objClienteController->removeCliente(objEliminar);
		cout << "Registro eliminado satisfactoriamente!!\n";
		objClienteController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el registro\n";
	}
}
// PERSONAL
void MenuDePersonal()
{
	int opt;

	do
	{
		title();
		cout << "\t   MANTENIMIENTO DEL PERSONAL\n";
		cout << "\t--------------------------------\n\n";
		cout << "[1] Add personal\n";
		cout << "[2] Buscar personal\n";
		cout << "[3] Listar personal\n";
		cout << "[4] Modificar personal\n";
		cout << "[5] Eliminar personal\n";
		cout << "[6] Volver atras\n";
		cout << "Ingresa una opcion correcta [1-6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addPersonal();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarPersonal();
			system("pause");
			system("cls");
			break;
		case 3:
			listarPersonal();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarPersonal();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarPersonal();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la pagina anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			cout << "Ingrese una opcion valida [1 - 7]: \n";
		}
	} while (opt != 6);
}
void addPersonal()
{
	string bandera, nomApe, dni, usuario, contrasenia;
	int codPer, sue, codTipPer;

	do
	{
		title();
		codPer = objPersonalController->getCorrelativo();
		cout << "CODIGO  (" << codPer << ")\n";
		cin.ignore();
		cout << "Ingresar nombre y apellido:";
		getline(cin, nomApe);
		transform(nomApe.begin(), nomApe.end(), nomApe.begin(), ::toupper);
		cout << "Ingresar dni:";
		cin >> dni;
		cout << "Ingresar sueldo:";
		cin >> sue;
		tipController->listar();
		cin >> codTipPer;
		cin.ignore();
		cout << "Registrar nuevo usuario: ";
		getline(cin, usuario);
		cout << "Registrar contrasenia: ";
		// getline(cin, contrasenia);
		char caracter;
		caracter = getch();	   // getch() = funcion para leer caracter uno por uno caracter = a
		while (caracter != 13) // mientras caracter sea diferente de enter
		{
			if (caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contrasenia.push_back(caracter); // mete el caracter al string contra || contra = adolf
				cout << "*";					 // muestra los * en la consola
			}
			else
			{
				if (contrasenia.length() > 0) // si el contra.length es mayor a 0
				{
					cout << "\b \b";											   // muestra como si borrara un caracter en la consola
					contrasenia = contrasenia.substr(0, contrasenia.length() - 1); // borra de verdad el dato en el string contra
				}
			}
			caracter = getch(); // vuelve a leer el siguiente caracter
		}
		cout << endl;
		cout << "Desea continuar? (S/s):";
		cin >> bandera;
		// Creando el obj personal con usuario y contras
		Personal objPer(codPer, nomApe, dni, sue, codTipPer, usuario, contrasenia);
		objPersonalController->add(objPer);
		// grabar en archivo
		objPersonalController->grabarEnArchivo(objPer);
		system("cls");
	} while (bandera == "S" || bandera == "s");
}
void buscarPersonal()
{
	int cod;
	title();
	cout << "\t   BUSQUEDA DE PERSONAL\n";
	cout << "\t--------------------------\n\n";
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Personal objEncontrado = objPersonalController->buscar(cod);
	if (objEncontrado.getUser() != "Error")
	{
		cout << "\tPERSONAL ENCONTRADO\n\n";
		cout << "Nombres y Apellidos:" << objEncontrado.getNomApe() << endl;
		cout << "DNI:" << objEncontrado.getDni() << endl;
		cout << "Sueldo:" << objEncontrado.getSue() << endl;
		cout << "Tipo de personal:" << tipController->listarTipo(objEncontrado) << endl;
		cout << "Usuario:" << objEncontrado.getUser() << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void listarPersonal()
{
	title();
	objPersonalController->listar();
}
void modificarPersonal()
{
	int cod;
	title();
	cout << "\t   MODIFICANDO DATOS\n";
	cout << "\t-----------------------\n\n";
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	Personal objEncontrado = objPersonalController->buscar(cod);
	if (objEncontrado.getUser() != "Error")
	{
		cout << "\tPERSONAL ENCONTRADO\n";
		cout << "Modificando nombres y apellidos...:" << objEncontrado.getNomApe() << endl;
		cout << "Modificando DNI...:" << objEncontrado.getDni() << endl;
		cout << "Modificando sueldo...:" << objEncontrado.getSue() << endl;
		cout << "Modificando tipo de personal...:" << tipController->listarTipo(objEncontrado) << endl;
		cout << "Modificando usuario...: " << objEncontrado.getUser() << endl;
		cout << "Modificando contrasenia...: " << objEncontrado.getContra() << endl;
		cin.ignore();
		// Modificacion
		string nomApe;
		string dni;
		int sue;
		int codTipPer;
		string usuario;
		string contrasenia;
		cout << "Ingresar nombre y apellido:";
		getline(cin, nomApe);
		transform(nomApe.begin(), nomApe.end(), nomApe.begin(), ::toupper);
		cout << "Ingresar dni:";
		cin >> dni;
		cout << "Ingresar sueldo:";
		cin >> sue;
		tipController->listar();
		cin >> codTipPer;
		cin.ignore();
		cout << "Ingresar usuario:";
		getline(cin, usuario);
		cout << "Ingresar contrasenia:";
		char caracter;
		caracter = getch();	   // getch() = funcion para leer caracter uno por uno
		while (caracter != 13) // mientras caracter sea diferente de enter
		{
			if (caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contrasenia.push_back(caracter); // mete el caracter al string contra
				cout << "*";					 // muestra los * en la consola
			}
			else
			{
				if (contrasenia.length() > 0) // si el contra.length es mayor a 0
				{
					cout << "\b \b";											   // muestra como si borrara un caracter en la consola
					contrasenia = contrasenia.substr(0, contrasenia.length() - 1); // borra de verdad el dato en el string contra
				}
			}
			caracter = getch(); // vuelve a leer el siguiente caracter
		}
		cout << "\n";
		Personal objNew(objEncontrado.getCodPer(), nomApe, dni, sue, codTipPer, usuario, contrasenia);
		bool estado = objPersonalController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			objPersonalController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarPersonal()
{
	int cod;
	title();
	cout << "\t   ELIMINANDO PERSONAL\n";
	cout << "\t-------------------------\n\n";
	cout << "Ingrese codigo a eliminar: ";
	cin >> cod;
	Personal objEliminar = objPersonalController->buscar(cod);
	if (objEliminar.getUser() != "Error")
	{
		objPersonalController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		objPersonalController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}

// TIPO PERSONAL
void MenuDeTipoDePersonal()
{
	int opt;
	do
	{	
		title();
		cout << "\t   OPCIONES DEL TIPO DE PERSONAL\n";
		cout << "\t-----------------------------------\n\n";
		cout << "[1] Add un tipo de personal\n";
		cout << "[2] Buscar tipo de personal\n";
		cout << "[3] Listar tipo de personal\n";
		cout << "[4] Modificar tipo de personal\n";
		cout << "[5] Eliminar\n";
		cout << "[6] Atras\n";
		cout << "Ingrese una opcion: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addTipoPersonal();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarTipoPersonal();
			system("pause");
			system("cls");
			break;
		case 3:
			listarTipoPersonal();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarTipoPersonal();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarTipoPersonal();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la ventana anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-5].\n";
		}
	} while (opt != 6);
}
void addTipoPersonal()
{
	title();
	int codTip;
	string tipoPer;
	string bandera;
	do
	{
		codTip = tipController->getCorrelativo();
		cout << "CODIGO  (" << codTip << ")\n";
		cin.ignore();
		cout << "Ingrese Tipo de Personal:";
		getline(cin, tipoPer);
		transform(tipoPer.begin(), tipoPer.end(), tipoPer.begin(), ::toupper);
		cout << "Continuar(S/s):";
		cin >> bandera;
		/*Creando el objeto de tipo Usuario*/
		TipoPersonal objTip(codTip, tipoPer); 
		// Agregando el objeto al arreglo
		tipController->add(objTip);
		// grabar en archivo
		tipController->grabarEnArchivo(objTip);
		system("cls");
	} while (bandera == "S" || bandera == "s");
}
void buscarTipoPersonal()
{
	title();
	int cod;
	cout << "Ingrese codigo a buscar: ";
	cin >> cod;
	TipoPersonal objEncontrado = tipController->buscar(cod);
	if (objEncontrado.getNomTip() != "Error")
	{
		cout << "Tipo de personal encontrado\n";
		cout << "Tipo de personal:" << objEncontrado.getNomTip() << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}

}
void listarTipoPersonal()
{	
	title();
	tipController->listar2();
}
void modificarTipoPersonal()
{	
	title();
	int cod;
	cout << "Ingrese codigo a modificar: ";
	cin >> cod;
	TipoPersonal objEncontrado = tipController->buscar(cod);
	if (objEncontrado.getNomTip() != "Error")
	{
		cout << "Tipo de personal encontrado\n";
		cout << "Tipo de personal:" << objEncontrado.getNomTip() << endl;
		cin.ignore();
		// Modificacion
		string nomTip;
		cout << "Ingresar tipo de personal: ";
		getline(cin, nomTip);
		transform(nomTip.begin(), nomTip.end(), nomTip.begin(), ::toupper);
		TipoPersonal objNew(objEncontrado.getCodTip(), nomTip);
		bool estado = tipController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			tipController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarTipoPersonal()
{
	title();
	int cod;
	cout << "Ingrese codigo a eliminar:";
	cin >> cod;
	TipoPersonal objEliminar = tipController->buscar(cod);
	if (objEliminar.getNomTip() != "Error")
	{
		tipController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		tipController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}

}
// PRODUCTO
void MenuDeProductos()
{
	int opt;
	do
	{
		title();
		cout << "\t   MANTENIMIENTO DE PRODUCTOS\n";
		cout << "\t--------------------------------\n";
		cout << "[1] Add producto\n";
		cout << "[2] Buscar producto\n";
		cout << "[3] Listar producto\n";
		cout << "[4] Modificar producto\n";
		cout << "[5] Eliminar producto\n";
		cout << "[6] Volver atras\n";
		cout << "Ingresa una opcion correcta[1 - 6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addProducto();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarProducto();
			system("pause");
			system("cls");
			break;
		case 3:
			listarProducto();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarProducto();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarProducto();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la ventana anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-5].\n";
		}
	} while (opt != 6);
}
void addProducto()
{
	string bandera;
	int codPro;
	string nom;
	float pre;
	int stock;
	int codCat;
	do
	{
		title();
		codPro = objProductoController->getCorrelativo();
		cout << "************(" << codPro << ")************\n";
		cin.ignore();
		cout << "Ingresar nombre del producto:";
		getline(cin, nom);
		transform(nom.begin(), nom.end(), nom.begin(), ::toupper);
		cout << "Ingresar precio del producto:";
		cin >> pre;
		cout << "Ingresar stock del producto:";
		cin >> stock;
		objCategoriaController->listar();
		cin >> codCat;
		cout << "Continuar(S/s):";
		cin >> bandera;
		/*Creando el objeto de tipo Usuario*/
		Producto objPro(codPro, nom, pre, stock, codCat);
		// Agregando el objeto al arreglo
		objProductoController->add(objPro);
		// grabar en archivo
		objProductoController->grabarEnArchivo(objPro);
	} while (bandera == "S" || bandera == "s");
}
void buscarProducto()
{
	int cod;
	title();
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Producto objEncontrado = objProductoController->buscar(cod);
	if (objEncontrado.getNomApePro() != "Error")
	{
		cout << "\tPRODUCTO ENCONTRADO\n";
		cout << "Nombre del producto: " << objEncontrado.getNomApePro() << endl;
		cout << "Precio: " << objEncontrado.getPrePro() << endl;
		cout << "Stock: " << objEncontrado.getStockPro() << endl;
		cout << "Categoria del producto: " << objCategoriaController->listarCategoria(objEncontrado) << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void modificarProducto()
{
	int cod;
	title();
	cout << "\t   MODIFICANDO PRODUCTO\n\n";
	cout << "\t--------------------------";
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	Producto objEncontrado = objProductoController->buscar(cod);
	if (objEncontrado.getNomApePro() != "Error")
	{
		cout << "\tPRODUCTO ENCONTRADO\n";
		cout << "Nombre del producto: " << objEncontrado.getNomApePro() << endl;
		cout << "Precio: " << objEncontrado.getPrePro() << endl;
		cout << "Stock :" << objEncontrado.getStockPro() << endl;
		cout << "Categoria del producto: " << objCategoriaController->listarCategoria(objEncontrado) << endl;
		cin.ignore();

		string nomPro;
		float precio;
		int stock;
		int codCat;
		cout << "\tMODIFICANDO CAMPOS...\n\n";
		cout << "Modificando nombre del producto...: ";
		getline(cin, nomPro);
		transform(nomPro.begin(), nomPro.end(), nomPro.begin(), ::toupper);
		cout << "Modificando precio del producto...: ";
		cin >> precio;
		cout << "Modificando stock del producto...: ";
		cin >> stock;
		objCategoriaController->listar();
		cin >> codCat;
		Producto objNew(objEncontrado.getCodPro(), nomPro, precio, stock, codCat);
		bool estado = objProductoController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			objProductoController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarProducto()
{
	int cod;
	cout << "Ingrese codigo a eliminar: ";
	cin >> cod;
	Producto objEliminar = objProductoController->buscar(cod);
	if (objEliminar.getNomApePro() != "Error")
	{
		objProductoController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		objProductoController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void listarProducto()
{	
	title();
	cout << "\t   LISTADO DE PRODUCTOS\n";
	cout << "\t--------------------------\n\n";
	objProductoController->listar();
}
// CATEGORIA
void MenuDeCategoria()
{
	int opt;
	do
	{
		title();
		cout << "\t   MEMU DE CATEGORIA DE PRODUCTOS\n";
		cout << "\t------------------------------------\n";
		cout << "[1] Add categoria\n";
		cout << "[2] Buscar categoria\n";
		cout << "[3] Listar categoria\n";
		cout << "[4] Modificar categoria\n";
		cout << "[5] Eliminar categoria\n";
		cout << "[6] Volver atras\n";
		cout << "Ingresa una opcion correcta[1 - 6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addCategoria();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarCategoria();
			system("pause");
			system("cls");
			break;
		case 3:
			listarCategoria();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarCategoria();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarCategoria();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la ventana anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-5].\n";
		}
	} while (opt != 6);
}
void addCategoria()
{
	int codCat;
	string nomCat;
	string bandera;
	do
	{
		title();
		codCat = objCategoriaController->getCorrelativo();
		cout << "************(" << codCat << ")************\n";
		cin.ignore();
		cout << "Ingrese la nueva categoria de producto:";
		getline(cin, nomCat);
		transform(nomCat.begin(), nomCat.end(), nomCat.begin(), ::toupper);
		cout << "Continuar(S/s):";
		cin >> bandera;
		/*Creando el objeto de tipo Usuario*/
		Categoria objCat(codCat, nomCat);
		// Agregando el objeto al arreglo
		objCategoriaController->add(objCat);
		// grabar en archivo
		objCategoriaController->grabarEnArchivo(objCat);
	} while (bandera == "S" || bandera == "s");
}
void buscarCategoria()
{
	int cod;
	title();
	cout << "\t   BUSCANDO CATEGORIA\n";
	cout << "\t------------------------\n";
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Categoria objEncontrado = objCategoriaController->buscar(cod);
	if (objEncontrado.getNomCat() != "Error")
	{
		cout << "Categoria encontrada\n";
		cout << "Categoria:" << objEncontrado.getNomCat() << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void listarCategoria()
{	
	int contador = 0;
	title();
	objCategoriaController->listar2();

}
void modificarCategoria()
{
	int cod;
	title();
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	Categoria objEncontrado = objCategoriaController->buscar(cod);
	if (objEncontrado.getNomCat() != "Error")
	{
		cout << "Categoria encontrada\n";
		cout << "Categoria:" << objEncontrado.getNomCat() << endl;
		cin.ignore();
		// Modificacion
		string nomCat;
		cout << "Ingresar categoria de producto:";
		getline(cin, nomCat);
		Categoria objNew(objEncontrado.getCodCategoria(), nomCat);
		bool estado = objCategoriaController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			objCategoriaController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarCategoria()
{
	int cod;
	title();
	cout << "Ingrese codigo a eliminar:";
	cin >> cod;
	Categoria objEliminar = objCategoriaController->buscar(cod);
	if (objEliminar.getNomCat() != "Error")
	{
		objCategoriaController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		objCategoriaController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void fechaYHoraBoleta()
{
	string resultado;
    time_t t;
    t = time(NULL);
    struct tm* fecha;
    fecha = localtime(&t);
    cout	<< "Fecha de Emision: " << fecha->tm_mday << "-" << fecha->tm_mon + 1 << "-" << fecha->tm_year + 1900 << "\t"
			<< "Hora: " << fecha->tm_hour << ":" << fecha->tm_min<< endl;

}
void MenuDeVenta()
{	
	string bandera, arg, busqPro, nombrePro;
	int cod, codVendedor, cantidad, codPro, optprod;
	float total = 0;
	title();
	fechaYHoraBoleta();
	cout << "\tVENTA ( " << objVentaController->getCorrelativoVenta() << " )" << endl;

	cout << "Codigo del cliente: ";
	cin >> cod;
	Cliente cli = objClienteController->buscarPorCodigoCliente(cod);
	cout << "DNI: " << cli.getDniCliente() << endl;
	cout << cli.getNombreCliente() << " " << setw(25) << left << cli.getApellidoCliente() << "DISTRITO: " << cli.getDireccionCliente() << endl;
	cout << "\n\n";

	codVendedor = objPersonalController->busquedaPersonal(users);
	Personal vendedor;
	vendedor = objPersonalController->buscar(codVendedor);
	cout << "VENDEDOR: " << setw(25) << left << vendedor.getNomApe() << "DNI: " << vendedor.getDni() << endl;
	cout << "\n";
	system("pause"); system("cls");

	do
	{	
		title();
		cout << "\t   GENERANDO VENTA\n";
		cout << "\t---------------------\n";

		cin.ignore();
		cout << "Buscar producto por nombre: ";
		getline(cin, busqPro); // espacio
		transform(busqPro.begin(), busqPro.end(), busqPro.begin(), ::toupper); //a mayusculas


		cout << setw(9) << left << "CODIGO" << setw(28) << left << "DESCRIPCION" <<"PRECIO\n\n"; 
		objProductoController->listarPorNombre(busqPro); // listar los productos
		
		cout << "\nCodigo del producto: ";
		cin >> codPro;
		Producto pro = objProductoController->buscar(codPro);

		system("cls");
		title();
		if (pro.getNomApePro() != "Error")
		{
			cout << "\n\t*** ANIADIENDO AL CARRITO ***\n\n";
			cout	<< "000" << setw(6) << left << pro.getCodPro() 
					<< setw(28) << left << pro.getNomApePro()
					<< setw(9) << left << pro.getPrePro() << endl;
		}
		else
		{
			cout << "NO SE ENCONTRO EL PRODUCTO\n"; break;
		}
		
		cout << "CANTIDAD: "; 
		cin >> cantidad;
		do
		{
			cout << "\t \tAGREGAR PRODUCTO	[1]\n";
			cout << "\t \tELIMINAR PRODUCTO	[2]\n";
			cout << "\t \tOpcion: ";
			cin >> optprod;
			cout << endl;
			if (optprod == 1)
			{
				DetalleVenta detalle;
				detalle.setCodVenta(objVentaController->getCorrelativoVenta());
				detalle.setDescripcion(pro.getNomApePro());
				detalle.setCodProducto(codPro);
				detalle.setCantidadProducto(cantidad);
				detalle.setPrecioVenta(pro.getPrePro());
				objDetalleVentaController->add(detalle);
				total += detalle.getSubTotal();
				objDetalleVentaController->listarProducto(detalle);
			}
			else if (optprod == 2)
			{
				cout << "PRODUCTO ELIMINADO CORRECTAMENTE\n";
			}
			else
			{
				cout << "Ingrese un numero correcto\n";
			}
			
		} while ((optprod != 1) && (optprod != 2));
		

		cout << "\nQuiere seguir comprando?(S/s): ";
		cin >> bandera;
		system("cls");
	} while (bandera == "S" || bandera == "s");

	objDetalleVentaController->grabarDetalleVenta();
	
	Venta venta;
	venta.setCodVenta(objVentaController->getCorrelativoVenta());
	venta.setCodCliente(cod);
	venta.setCodVendedor(codVendedor);
	venta.setFecha(arg);
	venta.setTotal(total);
	objVentaController->addVenta(venta);
	objVentaController->grabarArchivoVenta();

	title();
	cout << "\t******** BOLETA VENTA MAS ********\n";
	cout << setw(10) << right << ""; fechaYHoraBoleta();
	cout << "CORRELATIVO: " << venta.getCodVenta() << endl;
	cout << setw(13) << right << "DNI: " << cli.getDniCliente() << endl;
	cout << setw(13) << right << "CLIENTE: " << cli.getNombreCliente() << " " << cli.getApellidoCliente() << endl;
	cout << setw(13) << right << "VENDEDOR: " << vendedor.getNomApe() << endl << endl;
	cout	<< setw(6) << left << "COD" 
			<< setw(28) << left << "DESCRIPCION"
			<< setw(6) << left << "CANT" 
			<< setw(9) << left << "PREC U"
			<< "SUBTOTAL\n\n"; 
	for (int i = 0; i < objDetalleVentaController->rows(); i++)
	{
		cout	<< "000" << setw(3) << left << objDetalleVentaController->get(i).getCodProducto()
				<< setw(28) << left << objDetalleVentaController->get(i).getDescripcion()
				<< setw(6) << left << objDetalleVentaController->get(i).getCantidadProducto()
				<< setw(9) << left << objDetalleVentaController->get(i).getPrecioVenta()
				<< objDetalleVentaController->get(i).getSubTotal() << endl;
		cout << "---------------------------------------------------------\n\n";
	}
	cout << setw(49) << right << "IMPORTE TOTAL S/ : " << total << endl;
}
