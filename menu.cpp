#include "menu.hpp"
#include <iostream>
using namespace std;

void Menu::mostrarMenu()
{
	int opcionElegida = 0;
	bool invalido = true;
	while (invalido)
	{
		cout <<"[ MENU PRINCIPAL ]" << endl;
		cout<<"1- Cargar Archivo de Clientes (.csv)."<<endl;
		cout<<"2- Dar Alta Cliente Nuevo."<<endl;
		cout<<"3- Listar Clientes."<<endl;
		cout<<"4- Buscar Cliente(POR NUM)."<<endl;
		cout<<"5- SALIR"<<endl;
		cout <<"------------------" << endl;
		cout<<"ELECCION: ";
		cin >> opcionElegida;
		if(opcionElegida > 0 && opcionElegida <= 5)
		{
			invalido = false;
			ingresarOpcion(opcionElegida);
		}
		else
			cout<<"[Opcion Invalida]"<<endl;
	}
}
void Menu::ejecutarOpcion(Abb* _arbol)
{
	switch (obtenerOpcion())
	{
		case 1:
		{
			//cargarArchivo();
			break;
		}
		case 2:
		{
			//darAlta();
			break;
		}
		case 3:
		{
			//listarClientes();
			break;
		}
		case 4:
		{
			//buscarCliente();
			cout<<"1- Calcular Precio Final por Abonar."<<endl;
			cout<<"2- Dar de Baja al Cliente."<<endl;
			break;
		}	
		case 5:
		{
			salir = true;
			break;
		}
		default:
			break;
	}
	if(!salir)
	{
		cout << "Continuar? [SI: 0] | [NO: 1] "<<endl;
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



void Menu::cargarArchivo()
{
	/*string nombreArchivo;
	cout << "Inserte Nombre Archivo: ";
	cin >> nombreArchivo;

	ifstream listaTrabajadores(nombreArchivo);
	if (!listaTrabajadores.is_open())
	{
		cout << "ERROR Archivo inexistente" << endl;
	}
	else
	{
		int legajoInt = 0;
		double sueldoDbl = 0;
		int llegadasTardesInt, ausenciasInt, diasTrabajadosInt, hsCatedraInt, hsDescontadasInt;

		string tipo, legajo, apellidoNombre, sueldo;
		string llegadasTardes, ausencias;
		string diasTrabajados;
		string hsCatedra, hsDescontadas;

		while (listaTrabajadores.good())
		{
			getline(listaTrabajadores, tipo, '\t');
			if (tipo == "E")
			{
				getline(listaTrabajadores, legajo, '\t');
				getline(listaTrabajadores, apellidoNombre, '\t');
				getline(listaTrabajadores, sueldo, '\t');
				getline(listaTrabajadores, llegadasTardes, '\t');
				getline(listaTrabajadores, ausencias, '\n');

				legajoInt = stoi(legajo);
				if (existeLegajo(listaTr, legajoInt) == -1)
				{
					sueldoDbl = stod(sueldo);
					llegadasTardesInt = stoi(llegadasTardes);
					ausenciasInt = stoi(ausencias);
					Empleado *empleadoNuevo = new Empleado(legajoInt, apellidoNombre, sueldoDbl, llegadasTardesInt, ausenciasInt);
					listaTr->agregar(empleadoNuevo);
				}
			}
			else if (tipo == "J")
			{
				getline(listaTrabajadores, legajo, '\t');
				getline(listaTrabajadores, apellidoNombre, '\t');
				getline(listaTrabajadores, sueldo, '\t');
				getline(listaTrabajadores, diasTrabajados, '\n');

				legajoInt = stoi(legajo);
				if (existeLegajo(listaTr, legajoInt) == -1)
				{
					sueldoDbl = stod(sueldo);
					diasTrabajadosInt = stoi(diasTrabajados);
					Jornalero *jornaleroNuevo = new Jornalero(legajoInt, apellidoNombre, sueldoDbl, diasTrabajadosInt);
					listaTr->agregar(jornaleroNuevo);
				}
			}
			else if (tipo == "C")
			{
				getline(listaTrabajadores, legajo, '\t');
				getline(listaTrabajadores, apellidoNombre, '\t');
				getline(listaTrabajadores, sueldo, '\t');
				getline(listaTrabajadores, hsCatedra, '\t');
				getline(listaTrabajadores, hsDescontadas, '\n');

				legajoInt = stoi(legajo);
				if (existeLegajo(listaTr, legajoInt) == -1)
				{
					sueldoDbl = stod(sueldo);
					hsCatedraInt = stoi(hsCatedra);
					hsDescontadasInt = stoi(hsDescontadas);
					Consultor *consultorNuevo = new Consultor(legajoInt, apellidoNombre, sueldoDbl, hsCatedraInt, hsDescontadasInt);
					listaTr->agregar(consultorNuevo);
				}
			}
		}
	}*/
}

void Menu::darAlta()
{
}
void Menu::listarClientes()
{
}
void Menu::buscarCliente()
{
}
