#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"

class Familia: public Cliente
{
	private:
			int tope;
			string integrantes[10];
	public:
			Familia();
			void agregarIntegrante(string _nombre);
			void mostrarIntegrantes();
			
			~Familia();
};

#endif