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
			cargarArchivo(_arbol);
			break;
		}
		case 2:
		{
			darAlta(_arbol);
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



void Menu::cargarArchivo(Abb* _arbol)
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
		string numero;
		
		int i = 0;
		string listaNombres;
		int posiciones[5];
		string nombre;//INDV
		string nombres[5];//FLIA
		
		while (listaClientes.good())
		{
			i = 0;
			if(getline(listaClientes,numero,','))	//OBTENER NUMERO
			{
				if(getline(listaClientes,listaNombres,'\n'))	//OBTENER NOMBRES
				{
					i++;
					string busco = ",";
					size_t pos = listaNombres.find(busco);
					while( pos != std::string::npos) //OBTENER POSICIONES
					{
						posiciones[i] = pos;
						pos = listaNombres.find(busco, pos + busco.size());
						i++;
					}
					if(i == 1) //INDIVIDUO
					{
						nombre = listaNombres.substr(0,posiciones[1]);
					}
					else //FAMILIA
					{
						for(int j = 0; j < i; j++) //OBTENER SUBSTRINGS
						{
							if(j == 0)
								nombres[j] = listaNombres.substr(0,posiciones[j+1]); //Primero
							else
							{
								if(j == i-1)
									nombres[j] = listaNombres.substr(posiciones[j]+1); //Ultimo
								else
									nombres[j] = listaNombres.substr(posiciones[j]+1, (posiciones[j+1])-(posiciones[j]+1) );
							}
						}
					}
				}
				if(i == 1)
				{
					Individuo* _individuo = new Individuo(numero,nombre);
					_arbol->insertar(_individuo);
				}
				else
				{
					Familia* _familia = new Familia(numero,nombres,i);
					_arbol->insertar(_familia);
				}
			}
		}
	}
}

void Menu::darAlta(Abb* _arbol)
{
	string legajo;
	cout<<"Ingrese un legajo: ";
	cin>>legajo;
	
	int tipo = 0;
	cout<<"Que Tipo de Cliente Desea Ingresar?"<<endl;
	while((tipo != 1)&&(tipo != 2))
	{
		cout<<"Individuo[1] - Familia[2]: "<<endl;
		cin>>tipo;
	}
	
	string ceros = "";
	int cant = 8-(legajo.size());
	for(int i = 0; i<cant; i++)
	{
		ceros = ceros+"0";
	}
	
	string numTel = ceros+legajo;
	
	if(tipo == 1)
	{
		string nombre;
		cout<<"Ingrese APELLIDO_NOMBRE: ";
		cin>>nombre;
		Individuo* _individuo = new Individuo(numTel,nombre);
		_arbol->insertar(_individuo);
	}
	else if(tipo == 2)
	{
		bool valido = false;
		int cant = 0;
		while(!valido)
		{
			cout<<"Ingrese la cantidad de Integrantes(MIN 1/MAX 10): ";
			cin>>cant;
			valido = ((cant>0)&&(cant<=10));
		}
		string famNombres[10];
		
		for(int i = 0; i<cant; i++)
		{
			cout<<"Ingrese APELLIDO_NOMBRE: ";
			cin>>famNombres[i];
		}
		Familia* _familia = new Familia(numTel,famNombres,cant);
		_arbol->insertar(_familia);
	}
}
void Menu::listarClientes(Abb* _arbol)
{
	/*cout<<numero<<": ";
	if(i == 1)
		cout<<nombre<<" ";
	else
		for(int j = 0; j < i; j++)
			cout<<nombres[j]<<" ";
	cout<<endl;*/
}
void Menu::buscarCliente(Abb* _arbol)
{
}
