#ifndef CLIENTE
#define CLIENTE

#include "precio.hpp"

class Cliente : public Precio
{

	protected:
			int numero;
	public:
			Cliente();
			Cliente(double _precio,double _descuento,int _numero);
			void asignarNumero(int _numero);
			int obtenerNumero();
			
			~Cliente();
};

#endif
