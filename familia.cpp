#include "familia.hpp"

Familia::Familia():Cliente()
{
	tope = 0;
	integrantes[tope] = "";
}
Familia::Familia(double _precio,double _descuento,int _numero, int _tope, string _integrantes):Cliente(_precio,_descuento,_numero)
{
	tope = 0;
	integrantes[tope] = "";
}
void Familia::agregarIntegrante(int _tope, string _nombre)
{
	integrantes[tope] = "";
}
string Familia::obtenerIntegrantes()
{
	return NULL;
}
/*Familia::~Familia()
{
	
}*/

