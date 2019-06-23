#ifndef ABONABLE_HPP
#define ABONABLE_HPP
#include <iostream>
#include <string>
using namespace std;

class Abonable
{
	protected:
		double precioBase = 323.44;
		double precioFinal;
	public:
		virtual void definirPrecioFinal() = 0;
};

#endif