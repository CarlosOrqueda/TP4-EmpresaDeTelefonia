#include "cliente.hpp"

Cliente::Cliente(string _numero) {
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

void Cliente::definirPrecioFinal()
{
	/*Este es el metodo abstracto puro que se define en individuo y 
	familia con sus descuentos respectivos*/ 
}

Cliente::~Cliente()
{
	
}
