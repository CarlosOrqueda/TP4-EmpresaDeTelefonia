#ifndef INDIVIDUO
#define INDIVIDUO

#include "cliente.hpp"

class Individuo : public Cliente
{
private:
	string nombre;

public:
	//Constructores
	Individuo(string numero);
	Individuo(string numero, string _nombre);
	//Setters/Getters
	void asignarNombre(string _nombre);
	string obtenerNombre();
	//Devuelve el precio final a pagar.
	double obtenerPrecioFinal();
	//Destructor
	~Individuo();
};
// 10% descuento
#endif
