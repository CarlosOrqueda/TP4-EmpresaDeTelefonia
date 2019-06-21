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

void Cliente::definirPrecioFinal()
{
	/*Este es el metodo abstracto puro que se define en individuo y 
	familia con sus descuentos respectivos*/ 
}

Cliente::~Cliente()
{
	
}
