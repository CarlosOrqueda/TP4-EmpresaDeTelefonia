#include <iostream>
using namespace std;
#include "individuo.hpp"
#include "familia.hpp"
#include "Abb.hpp"
int main()
{
	int dato;
	int termino = 0;
	Abb* nuevoArbol = new Abb();
	cout << "Mostrar opciones" << endl;
	cin >> dato;
	while(termino == 0){
		switch (dato)
		{
		case 1:
		{
			int numero;
			cout<<"ingresar numero"<<endl;
			cin>>numero;
			Cliente* nuevoCliente = new Cliente(numero);
			nuevoArbol->insertar(nuevoCliente);
			break;
		}
		case 2:
			nuevoArbol->mostrarArbol();
			break;

		case 3:{
			cout << "chau" << endl;
			termino = 1;
			break;
		}
		default:
			break;
		}
		cout << "continuar? 0/1 " << endl;
		cin >> termino; 
		cout << "elija opcion " << endl;
		cin >> dato;
	}
	return 0;
}
