#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"
#include "individuo.hpp"
#include "lista.hpp"
class Familia : public Cliente
{
private:
	Lista<string> *listaIndividuos;

public:
	//Constructor
	Familia(string numero);
	//Muestra por pantalla los integrantes de la familia
	void mostrarIntegrantes();
	//Devuelve el precio final a pagar.
	double obtenerPrecioFinal();
	//Agrega un integrante nuevo.
	void agregarIntegrantes(string *_nombre);
	//Destructor
	~Familia();
};

#endif
// 35% descuento
