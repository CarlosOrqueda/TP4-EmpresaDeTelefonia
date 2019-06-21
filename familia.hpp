#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"

class Familia: public Cliente
{
	private:
			int tope;
			string integrantes[10];
	public:
			Familia(int numero);
			void agregarIntegrante(string _nombre[],int _tam);
			void mostrarIntegrantes();
			
			double obtenerPrecioFinal();
			
			~Familia();
};

#endif
// 35% descuento