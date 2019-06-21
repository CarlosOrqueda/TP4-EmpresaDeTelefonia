#include "individuo.hpp"

Individuo::Individuo(int numero):Cliente(numero)
{
	nombre = "";
}

Individuo::Individuo(int numero,string nombre):Cliente(numero)
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
Individuo::~Individuo()
{
	
}
double Individuo::obtenerPrecioFinal()
{
	return precioBase-(precioBase*0.1);
}
