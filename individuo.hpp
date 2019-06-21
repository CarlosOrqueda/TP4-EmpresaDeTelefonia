#ifndef INDIVIDUO
#define INDIVIDUO

#include "cliente.hpp"

class Individuo: public Cliente
{
	private:
			string nombre;
	public:
			Individuo(int nuemero);
			Individuo(int numero, string _nombre);
			void asignarNombre(string _nombre);
			string obtenerNombre();
			
			double obtenerPrecioFinal();
			
			~Individuo();
};
// 10% descuento
#endif
