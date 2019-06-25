#include "menu.hpp"
#include <iostream>
#include <string>
#include <istream>
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
		cout<<"5- Eliminar Cliente(POR NUM)."<<endl;
		cout<<"6- SALIR"<<endl;
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
			//leerArchivo(_arbol);
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



 /* void Menu::leerArchivo(Abb* _arbol)
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
		int cantidad = 0;	//CANTIDAD INTEGRANTES (1 -> Individuo, sino, Familia)
		unsigned int end = 4294967295;
		string numero;	//NUM. TEL.
		string nombre;	//INDIVIDUO
		string nombres;	//STRING DE DONDE SE EXTRAERAN LAS SUBSTR
		Lista<size_t>* listaPosiciones = new Lista<size_t>;
		Lista<string>* listaIntegrantes = new Lista<string>;
		
		while (listaClientes.good())
		{
			if(getline(listaClientes,numero,','))	//OBTENER NUMERO
			{
				cout<<numero<<": ";
				if(getline(listaClientes,nombres,'\n'))	//OBTENER NOMBRES TODOS EN UN SOLO STRING
				{
					string buscado = ",";
					size_t* Prposicion = (nombres.find(buscado);
					
					if(*Prposicion != end ) //FAMILIA
					{
						listaPosiciones->agregar(Prposicion); //PRIMERA COMA
						cantidad = 1;
						cout<<cantidad<<"["<<*(listaPosiciones->consultar(cantidad))<<"]";
						size_t* last = Prposicion;
						
						
						//ACA EL PROBLEMA
						while(*last != end) //OBTENER RESTO POSICIONES
						{
							size_t* posicion = new size_t(nombres.find(buscado,last + 1));
							last = (*posicion);
							if(*last != end)
							{
								listaPosiciones->agregar(posicion);
								cout<<cantidad<<"["<<*(listaPosiciones->consultar(cantidad))<<"]";
								cantidad++;
							}
						}
					}
					
					if(cantidad == 0) //INDIVIDUO
					{
						nombre = nombres;
						cout<<nombre;
					}
					else //FAMILIA
					{
						for(int j = 1; j <= cantidad; j++)
						{
							if(j == 1)
							{
								string aux = nombres.substr(0, *(listaPosiciones->consultar(j)) );
								listaIntegrantes->agregar(&aux); //Primero
							}
							else
							{
								if(j == cantidad)
								{
									string aux = nombres.substr(*(listaPosiciones->consultar(j))); //Ultimo
									listaIntegrantes->agregar(&aux);
									cout<<*(listaIntegrantes->consultar(j));
								}
								else
								{
									string aux = nombres.substr( *(listaPosiciones->consultar(j)),
																 *(listaPosiciones->consultar(j+1)) - *(listaPosiciones->consultar(j)));
									listaIntegrantes->agregar(&aux);
									cout<<*(listaIntegrantes->consultar(j));
								}
							}
						}
					}
					cout<<endl;
				}
			}
		}
	}
}
*/
void Menu::darAlta(Abb* _arbol)
{
	string legajo;
	do{
		cout<<"Ingrese un legajo: ";
		cin>>legajo;
	}while(legajo.length() != 6);
	int tipo = 0;
	cout<<"Que Tipo de Cliente Desea Ingresar?"<<endl;
	while((tipo != 1)&&(tipo != 2))
	{
		cout<<"Individuo[1] - Familia[2]: "<<endl;
		cin>>tipo;
	}
	string numTelefono = "00"+legajo;
	if(tipo == 1)
	{
		string nombre;
		cout<<"Ingrese APELLIDO_NOMBRE: ";
		cin>>nombre;
		Individuo* _individuo = new Individuo(numTelefono,nombre);
		_arbol->insertar(_individuo);
	}
	else if(tipo == 2)
	{
		string continuar;
		Familia* _familia = new Familia(numTelefono);
		do{
			string* integrante = new string();
			cout << "Ingrese un miembro de tu familia APELLIDO_NOMBRE: ";
			cin >> *integrante;
			_familia->agregarIntegrantes(integrante);
			cout<<"Desea seguir ingresando familiares?[si/no]:";
			cin>>continuar;
		}while(continuar == "si");

		_arbol->insertar(_familia);
	}
}

void Menu::listarClientes(Abb* _arbol)
{
	_arbol->inOrderMostrar();
}

void Menu::buscarCliente(Abb* _arbol)
{
	string numero;
	do{
	cout << "Ingresar el numero de 8 digitos del cliente buscado" << endl;
	cin >> numero;
	}while(numero.length() != 8);
	_arbol->inOrderBuscar(numero);
}

void Menu::eliminarCliente(Abb* _arbol)
{
	string numero;
	do{
	cout << "Ingresar el numero de 8 digitos del cliente buscado" << endl;
	cin >> numero;
	}while(numero.length() != 8);
	_arbol->eliminar(numero);
}
