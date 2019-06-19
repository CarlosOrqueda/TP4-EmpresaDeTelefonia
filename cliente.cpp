#include "cliente.hpp"


void Cliente::asignarNumero(int _numero)
{
	numeroTelefono = _numero;
}
int Cliente::obtenerNumero()
{
	return numeroTelefono;
}
Cliente::~Cliente()
{
	
}
