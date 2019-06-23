#ifndef CLIENTE
#define CLIENTE

#include "abonable.hpp"

class Cliente : public Abonable
{

	protected:
			string numeroTelefono;
	public:
            Cliente(string _numero);
			void asignarNumero(string _numero);
			string obtenerNumero();
			
			virtual ~Cliente();
};

#endif
