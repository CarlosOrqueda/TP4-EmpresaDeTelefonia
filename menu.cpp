#include "menu.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void Menu::mostrarMenu()
{
	int opcionElegida = 0;
	bool invalido = true;
	while (invalido)
	{
		cout << "[ MENU PRINCIPAL ]" << endl;
		cout << "1- Cargar Archivo de Clientes (.csv)." << endl;
		cout << "2- Dar Alta Cliente Nuevo." << endl;
		cout << "3- Listar Clientes." << endl;
		cout << "4- Buscar Cliente(POR NUM)." << endl;
		cout << "5- Eliminar Cliente(POR NUM)." << endl;
		cout << "6- SALIR" << endl;
		cout << "------------------" << endl;
		cout << "ELECCION: ";
		cin >> opcionElegida;
		if (opcionElegida > 0 && opcionElegida <= 5)
		{
			invalido = false;
			ingresarOpcion(opcionElegida);
		}
		else
			cout << "[Opcion Invalida]" << endl;
	}
}
void Menu::ejecutarOpcion(Abb *_arbol)
{
	switch (obtenerOpcion())
	{
	case 1:
	{
		leerArchivo(_arbol);
		break;
	}
	case 2:
	{
		darAlta(_arbol);
		break;
	}
	case 3:
	{
		listarClientes(_arbol);
		break;
	}
	case 4:
	{
		buscarCliente(_arbol);
		break;
	}
	case 5:
	{
		eliminarCliente(_arbol);
		break;
	}
	case 6:
	{
		salir = true;
		break;
	}
	default:
		break;
	}
	if (!salir)
	{
		cout << "Continuar? [SI: 0] | [NO: 1] " << endl;
		cin >> salir;
	}
}
void Menu::ingresarOpcion(int _opcion)
{
	this->opcion = _opcion;
}
int Menu::obtenerOpcion()
{
	return opcion;
}
bool Menu::obtenerSalir()
{
	return salir;
}

void Menu::leerArchivo(Abb *_arbol)
{
	string nombreArchivo;
	cout << "Ingrese el nombre del archivo (csv): ";
	cin >> nombreArchivo;

	ifstream archivoClientes(nombreArchivo);
	if (!archivoClientes.is_open())
	{
		cout << "ERROR Archivo Inexistente" << endl;
		return;
	}
	string numero, lineaNombres, nombre, ultimoNombre;
	while (archivoClientes.good())
	{
		getline(archivoClientes, numero, ',');
		getline(archivoClientes, lineaNombres);
		if (!lineaNombres.empty() && lineaNombres[lineaNombres.size() - 1] == '\r')
			lineaNombres.erase(lineaNombres.size() - 1);
		if (lineaNombres.find(',') != string::npos)
		{
			stringstream ss(lineaNombres);
			Familia *_familia = new Familia(numero);
			while (ss.good())
			{
				getline(ss, nombre, ',');
				string *nombreIntegrante = new string();
				*nombreIntegrante = nombre;
				_familia->agregarIntegrantes(nombreIntegrante);
				cout << nombre << endl;
			}
			_arbol->insertar(_familia);
		}
		else
		{
			Individuo *_individuo = new Individuo(numero, lineaNombres);
			_arbol->insertar(_individuo);
		}
	}
}

void Menu::darAlta(Abb *_arbol)
{
	string legajo;
	do
	{
		cout << "Ingrese un legajo: ";
		cin >> legajo;
	} while ((legajo.length() > 6) || (legajo.length() <= 0));
	int tipo = 0;
	cout << "Que Tipo de Cliente Desea Ingresar?" << endl;
	while ((tipo != 1) && (tipo != 2))
	{
		cout << "Individuo[1] - Familia[2]: " << endl;
		cin >> tipo;
	}
	size_t digitosSize = legajo.size();
	int digitos = static_cast<int>(digitosSize);
	int ceros = 8 - digitos;

	string numTelefono = legajo;
	for (int i = 0; i < ceros; i++)
		numTelefono = "0" + numTelefono;

	if (tipo == 1)
	{
		string nombre;
		cout << "Ingrese APELLIDO_NOMBRE: ";
		cin >> nombre;
		Individuo *_individuo = new Individuo(numTelefono, nombre);
		_arbol->insertar(_individuo);
	}
	else if (tipo == 2)
	{
		string continuar;
		Familia *_familia = new Familia(numTelefono);
		do
		{
			string *integrante = new string();
			cout << "Ingrese un miembro de tu familia APELLIDO_NOMBRE: ";
			cin >> *integrante;
			_familia->agregarIntegrantes(integrante);
			cout << "Desea seguir ingresando familiares?[si/no]:";
			cin >> continuar;
		} while (continuar == "si");

		_arbol->insertar(_familia);
	}
}

void Menu::listarClientes(Abb *_arbol)
{
	_arbol->inOrderMostrar();
}

void Menu::buscarCliente(Abb *_arbol)
{
	string numero;
	do
	{
		cout << "Ingresar el numero de 8 digitos del cliente buscado" << endl;
		cin >> numero;
	} while (numero.length() != 8);
	_arbol->postOrderBuscar(numero);
}

void Menu::eliminarCliente(Abb *_arbol)
{
	string numero;
	do
	{
		cout << "Ingresar el numero de 8 digitos del cliente buscado" << endl;
		cin >> numero;
	} while (numero.length() != 8);
	_arbol->eliminar(numero);
}
