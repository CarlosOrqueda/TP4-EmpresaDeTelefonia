#include "familia.hpp"

Familia::Familia(string numero) :Cliente(numero)
{
	integrantes[10] = {""};
	tope = 0;
}
Familia::Familia(string numero,string _nombres[],int _tam) :Cliente(numero)
{
	for(int i = 0; i < _tam; i++)
	{
		integrantes[i] = _nombres[i];
	}
}
void Familia::agregarIntegrante(string _nombre[],int _tam)
{
	int recorrer = 0;
	while((tope < 10)&&(recorrer < _tam))
	{
		integrantes[tope] = _nombre[recorrer];
		tope++;
		recorrer++;
	}
}
void Familia::mostrarIntegrantes()
{
	for(string integrante: integrantes)
	{
		cout << integrante + ", ";
	}
}

double Familia::obtenerPrecioFinal()
{
	return precioBase-(precioBase*0.35);
}

Familia::~Familia()
{
	
}
