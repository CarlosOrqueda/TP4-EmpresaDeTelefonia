#include "cliente.hpp"

Cliente::Cliente(string _numero)
{
    numeroTelefono = _numero;
}


void Cliente::asignarNumero(string _numero)
{
	numeroTelefono = _numero;
}
string Cliente::obtenerNumero()
{
	return numeroTelefono;
}

Cliente::~Cliente()
{
	
}
