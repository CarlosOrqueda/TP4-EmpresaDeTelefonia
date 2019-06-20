#ifndef CLIENTE
#define CLIENTE

#include "abonable.hpp"

class Cliente : public Abonable
{

	protected:
			int numeroTelefono;
	public:
            Cliente(int _numero);
			void asignarNumero(int _numero);
			int obtenerNumero();
			
			~Cliente();
};

#endif
