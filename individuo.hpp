#ifndef INDIVIDUO
#define INDIVIDUO

#include "cliente.hpp"

class Individuo: public Cliente
{
	private:
			string nombre;
	public:
			Individuo();
			Individuo(string _nombre);
			void asignarNombre(string _nombre);
			string obtenerNombre();
			
			~Individuo();
};

#endif
