#ifndef INDIVIDUO
#define INDIVIDUO

#include "cliente.hpp"

class Individuo: public Cliente
{
	private:
			string nombre;
	public:
			Individuo();
			Individuo(double _precio,double _descuento,int _numero, string _nombre);
			void asignarNombre(string _nombre);
			string obtenerNombre();
			
			~Individuo();
};

#endif
