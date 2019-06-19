#ifndef CLIENTE
#define CLIENTE

#include "abonable.hpp"

class Cliente : public Abonable
{

	protected:
			int numeroTelefono;
	public:
			void asignarNumero(int _numero);
			int obtenerNumero();
			
			~Cliente();
};

#endif
