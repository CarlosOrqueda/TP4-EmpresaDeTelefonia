#ifndef PRECIO
#define PRECIO
#include <iostream>
#include <string>
using namespace std;

class Precio
{

	protected:
			double precioBase;
			double descuento;
	public:
			Precio();
			Precio(double _precio,double _descuento);
			void asignarPrecioBase(double _precio);
			void asignarDescuento(double _descuento);
			double obtenerPrecioBase();
			double obtenerDescuento();
			double calcularPrecioFinal();
			~Precio();
};

#endif
