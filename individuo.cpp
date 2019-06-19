#include "individuo.hpp"

Individuo::Individuo():Cliente()
{
	nombre = "";
}
Individuo::Individuo(double _precio,double _descuento,int _numero, string _nombre):Cliente(_precio,_descuento,_numero)
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
/*Individuo::~Individuo()
{
	
}*/
