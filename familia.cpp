#include "familia.hpp"

Familia::Familia(int numero) :Cliente(numero)
{
	integrantes[10] = {""};
	tope = 0;
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
