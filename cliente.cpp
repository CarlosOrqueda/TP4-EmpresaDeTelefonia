#include "cliente.hpp"

Cliente::Cliente():Precio()
{
	numero = 0;
}
Cliente::Cliente(double _precio,double _descuento,int _numero):Precio(_precio,_descuento)
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
/*Cliente::~Cliente()
{
	
}*/
