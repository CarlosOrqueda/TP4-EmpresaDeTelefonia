#include "precio.hpp"

Precio::Precio()
{
	precioBase = 0;
	descuento = 0;
}
Precio::Precio(double _precio,double _descuento)
{
	precioBase = _precio;
	descuento = _descuento;
}
void Precio::asignarPrecioBase(double _precio)
{
	precioBase = _precio;
}
void Precio::asignarDescuento(double _descuento)
{
	descuento = _descuento;
}
double Precio::obtenerPrecioBase()
{
	return precioBase;
}
double Precio::obtenerDescuento()
{
	return descuento;
}
double Precio::calcularPrecioFinal()
{
	return (precioBase-(precioBase*descuento));
}
/*Precio::~Precio()
{
	
}*/
