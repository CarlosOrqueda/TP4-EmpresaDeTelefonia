#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"
#include "abonable.hpp"
class Familia: public Cliente
{
	private:
			int tope;
			string integrantes[10];
	public:
			Familia();
			void agregarIntegrante(string _nombre);
			void mostrarIntegrantes();
			void pagarMontoFinal();
			void aplicarDescuento(double& precio);
			
			~Familia();
};

#endif