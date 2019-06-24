#include "individuo.hpp"

Individuo::Individuo(string numero):Cliente(numero)
{
	nombre = "";
}

Individuo::Individuo(string numero,string nombre):Cliente(numero)
{
	asignarNombre(nombre);
}
void Individuo::asignarNombre(string _nombre)
{
	nombre = _nombre;
}
string Individuo::obtenerNombre()
{
	return nombre;
}
double Individuo::obtenerPrecioFinal()
{
	return precioBase = precioBase-(precioBase*0.1);
}
Individuo::~Individuo()
{
	
}
