#ifndef CLIENTE
#define CLIENTE
#include <iostream>
#include <string>
using namespace std;

class Cliente
{

	protected:
			int numero;
			double descuento;
	public:
			Cliente();
			
			void asignarNumero(int _numero);
			int obtenerNumero();
			
			void asignarDescuento(double _descuento);
			double obtenerDescuento();
			
			~Cliente();
};

#endif
