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
string Familia::obtenerIntegrante(int _pos)
{
	return integrantes[_pos];
} 
double Familia::obtenerPrecioFinal()
{
	return precioBase = precioBase-(precioBase*0.35);
}

Familia::~Familia()
{
	
}
