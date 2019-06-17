#include "cliente.hpp"

Cliente::Cliente()
{
	numero = 0;
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
