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
	string nombreArchivo;
	cout << "Inserte Nombre Archivo: ";
	cin >> nombreArchivo;

	ifstream listaClientes(nombreArchivo);
	if (!listaClientes.is_open())
	{
		cout << "ERROR Archivo inexistente" << endl;
	}
	else
	{
		int i = 0;
		int numero = 0;
		string nombre[5];
		
		while (listaClientes.good())
		{
			getline(listaClientes,numero,',');
			cout<< numero;
			while(getline(listaClientes,nombre[i],','))
			{
				cout<<" *"<<nombre[i]<<endl;
				i++;
			}
		}
	}
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
