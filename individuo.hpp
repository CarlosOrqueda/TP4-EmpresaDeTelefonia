#ifndef INDIVIDUO
#define INDIVIDUO

#include "cliente.hpp"
#include "abonable.hpp"

class Individuo: public Cliente
{
	private:
			string nombre;
	public:
			Individuo();
			Individuo(string _nombre);
			Individuo(string _nombre,int numero);
			void asignarNombre(string _nombre);
			string obtenerNombre();
			void pagarMontoFinal();
			void aplicarDescuento(double& precio);
			
			~Individuo();
};

#endif