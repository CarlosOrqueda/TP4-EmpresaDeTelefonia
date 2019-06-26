#ifndef FAMILIA
#define FAMILIA

#include "cliente.hpp"
#include "individuo.hpp"
#include "lista.hpp"
class Familia: public Cliente
{
	private:
			Lista<string>* listaIndividuos; 
	public:
			Familia(string numero);
			
			void mostrarIntegrantes();
			
			double obtenerPrecioFinal();

			void agregarIntegrantes(string* _nombre); // usen esto con el cargarArchivo Recibe un PUNTERO a un string 
			
			~Familia();
};

#endif
// 35% descuento
