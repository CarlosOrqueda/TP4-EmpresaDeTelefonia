#include "cliente.hpp"

Cliente::Cliente()
{
	numero = 0;
	descuento = 0;
}
void Cliente::asignarNumero(int _numero)
{
	numero = _numero;
}
int Cliente::obtenerNumero()
{
	return numero;
}
void Cliente::asignarDescuento(double _descuento)
{
	decuento = _descuento;
}
double Cliente::obtenerDescuento()
{
	return descuento;
}
Cliente::~Cliente()
{
	
}
