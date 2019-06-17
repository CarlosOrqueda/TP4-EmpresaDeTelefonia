#include "cliente.hpp"

Cliente::Cliente():Individuo()
{
	nombre = "";
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
