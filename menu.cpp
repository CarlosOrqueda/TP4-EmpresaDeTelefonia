#include "menu.hpp"
#include <iostream>
#include <string>
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
			/*buscarCliente(_arbol);
			cout<<"1- Calcular Precio Final por Abonar."<<endl;
			cout<<"2- Dar de Baja al Cliente."<<endl;*/
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



 void Menu::leerArchivo(Abb* _arbol)
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
		Familia* _familia = new Familia(numero);//FAMILIA
		string* integranteActual = new string();
		
		while (listaClientes.good())
		{
			getline(listaClientes,numero,','); //NUMERO
			getline(listaClientes,integranteActual,'\n');
		
			}
				
		}
	}
}
/*i = 1;
			if(getline(listaClientes,numero,','))	//OBTENER NUMERO
			{
				if(getline(listaClientes,listaNombres,'\n'))	//OBTENER NOMBRES
				{
					string busco = ",";
					size_t pos = listaNombres.find(busco);
					while( pos != std::string::npos) //OBTENER POSICIONES
					{
						posiciones[i] = pos;
						pos = listaNombres.find(busco, pos + 1);
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
									nombres[j] = listaNombres.substr(posiciones[j]+1, (posiciones[j+1])-(posiciones[j]+1));
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
					for (int z = 0; z < nombres.; z++)
					{
						
					}
					
				}
			} */
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
		string* integrante = new string();
		string continuar;
		Familia* _familia = new Familia(numTelefono);
		do{
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
