#ifndef CLIENTE
#define CLIENTE

#include "abonable.hpp"

class Cliente : protected Abonable
{

	protected:
			string numeroTelefono;
	public:
            Cliente(string _numero);
			void asignarNumero(string _numero);
			void definirPrecioFinal();
			string obtenerNumero();
			double obtenerPrecioFinal();
			
			virtual ~Cliente();
};

#endif
