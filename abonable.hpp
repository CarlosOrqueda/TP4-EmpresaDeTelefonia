#ifndef ABONABLE_HPP
#define ABONABLE_HPP
#include <iostream>
#include <string>
using namespace std;

class Abonable
{
	protected:
		double precioBase = 323.44;
	public:
		virtual void aplicarDescuento(double& precio) = 0;
		virtual void pagarMontoFinal() = 0;
};

#endif