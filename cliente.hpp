#ifndef CLIENTE
#define CLIENTE

#include "precio.hpp"

class Cliente
{

	protected:
			int numero;
	public:
			Cliente();
			Cliente(int _numero);
			void asignarNumero(int _numero);
			int obtenerNumero();
			
			~Cliente();
};

#endif
