#include "cliente.hpp"

Cliente::Cliente(int _numero) {
    numeroTelefono = _numero;
}


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
