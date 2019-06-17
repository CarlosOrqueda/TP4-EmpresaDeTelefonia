#include "cliente.hpp"

Cliente::Cliente():Individuo()
{
	nombre = "";
}
Cliente::Cliente(int _numero):Individuo(string _nombre)
{
	nombre = _nombre;
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
