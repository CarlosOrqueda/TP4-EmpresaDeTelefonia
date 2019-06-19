#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"

class Familia: public Cliente
{
	private:
			int tope;
			string integrantes[10];
	public:
			Familia();
			Familia(double _precio,double _descuento,int _numero, int _tope, string _integrantes);
			
			void agregarIntegrante(int _tope, string _nombre);
			string obtenerIntegrantes();
			
			~Familia();
};

#endif
