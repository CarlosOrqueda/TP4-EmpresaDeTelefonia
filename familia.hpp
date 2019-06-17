#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"

class Familia: public Cliente
{
	private:
			string* integrantes;
	public:
			Familia();
			
			void agregarIntegrante(string _nombre);
			string* obtenerIntegrantes();
			
			~Familia();
};

#endif
