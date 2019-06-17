#include "precio.hpp"

Precio::Precio()
{
	
}
Precio::Precio(double _precio,double _descuento)
{
	precio = _precio;
	descuento = _descuento;
}
void Precio::asignarPrecioBase(double _precio)
{
	precio = _precio;
}
void Precio::asignarDescuento(double _descuento)
{
	descuento = _descuento;
}
double Precio::obtenerPrecioBase()
{
	return _precio;
}
double Precio::obtenerDescuento()
{
	return _descuento;
}
double Precio::calcularPrecioFinal()
{
	return (precio-(precio*descuento));
}
Precio::~Precio()
{
	
}
