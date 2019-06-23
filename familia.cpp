#include "familia.hpp"

Familia::Familia(string numero) :Cliente(numero)
{
	integrantes[10] = NULL;
	tope = 0;
}
Familia::Familia(string numero,string _nombres[],int _tam) :Cliente(numero)
{
	tope = _tam;
	for(int i = 0; i < tope; i++)
	{
		Individuo* individuo = new Individuo(_nombres[i]);
		integrantes[i] = individuo;
	}
}

void Familia::mostrarIntegrantes()
{
	for(int i = 0; i < tope; i++)
	{
		cout << integrantes[i]->obtenerNombre() << " ";
	}
	cout<<endl;
} 

double Familia::obtenerPrecioFinal()
{
	return precioFinal;
}

void Familia::definirPrecioFinal()
{
	precioFinal = precioBase-(precioBase*0.35);
}

Familia::~Familia()
{
	
}
