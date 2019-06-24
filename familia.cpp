#include "familia.hpp"

Familia::Familia(string numero) :Cliente(numero)
{
	listaIndividuos = new Lista<string>();
}

void Familia::mostrarIntegrantes()
{
	int tamanio = listaIndividuos->obtenerTamanio();
	for (int i = 0; i < tamanio ; i++){
		string nombre = *(listaIndividuos->consultar(i));
		cout << nombre << " ";
	}
	cout << endl;
} 
double Familia::obtenerPrecioFinal()
{
	precioBase = precioBase-(precioBase*0.35);
	double precioFinal = precioBase*listaIndividuos->obtenerTamanio();
	return precioFinal;
}

void Familia::agregarIntegrantes(string* _nombre){
	listaIndividuos->agregar(_nombre);
}

Familia::~Familia()
{
	delete listaIndividuos;
}
