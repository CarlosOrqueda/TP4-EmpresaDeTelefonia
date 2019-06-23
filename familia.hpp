#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"
#include "individuo.hpp"
const int MAX_INDIVIDUOS = 10;
class Familia: public Cliente
{
	private:
			int tope;
			Individuo* integrantes[MAX_INDIVIDUOS];
	public:
			Familia(string numero);
			Familia(string numero,string _nombres[],int _tam);
			void mostrarIntegrantes();
			
			void definirPrecioFinal();
			double obtenerPrecioFinal();
			
			~Familia();
};

#endif
// 35% descuento
