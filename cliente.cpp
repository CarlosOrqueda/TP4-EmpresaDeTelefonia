#include "cliente.hpp"

Precio::Precio():Cliente()
{
	numero = 0;
}
Precio::Precio(double _precio,double _descuento):Cliente(int _numero)
{
	numero = _numero;
}
void Cliente::asignarNumero(int _numero)
{
	numero = _numero;
}
int Cliente::obtenerNumero()
{
	return numero;
}
Cliente::~Cliente()
{
	
}
