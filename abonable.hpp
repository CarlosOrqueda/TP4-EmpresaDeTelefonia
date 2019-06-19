#ifndef ABONABLE_HPP
#define ABONABLE_HPP
#include <iostream>
#include <string>
using namespace std;

class Abonable
{
	protected:
		double precioBase;
	public:
		virtual void pagarMontoFinal() = 0;
		virtual void aplicarDescuento(double precio);
};

#endif