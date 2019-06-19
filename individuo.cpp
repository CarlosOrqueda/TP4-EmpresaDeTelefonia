#include "individuo.hpp"

Individuo::Individuo():Cliente()
{
	nombre = "";
}
Individuo::Individuo(string nombre, int numero)
{
	this->asignarNombre(nombre);
	this->asignarNumero(numero);

}
Individuo::Individuo(string nombre)
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
