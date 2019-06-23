#ifndef INDIVIDUO
#define INDIVIDUO

#include "cliente.hpp"

class Individuo: public Cliente
{
	private:
			string nombre;
	public:
			Individuo(string numero);
			Individuo(string numero, string _nombre);
			void asignarNombre(string _nombre);
			string obtenerNombre();
			void definirPrecioFinal();
			double obtenerPrecioFinal();
			
			~Individuo();
};
// 10% descuento
#endif
