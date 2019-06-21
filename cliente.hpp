#ifndef CLIENTE
#define CLIENTE

#include "abonable.hpp"

class Cliente : protected Abonable
{

	protected:
			int numeroTelefono;
	public:
            Cliente(int _numero);
			void asignarNumero(int _numero);
			void definirPrecioFinal();
			int obtenerNumero();
			
			~Cliente();
};

#endif
