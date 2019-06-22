#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
using namespace std;
#include "individuo.hpp"
#include "familia.hpp"
#include "Abb.hpp"

class Menu
{
	private:
		int opcion;
		bool salir;
		
		void cargarArchivo(Abb* _arbol);
		void darAlta(Abb* _arbol);
		void listarClientes(Abb* _arbol);
		void buscarCliente(Abb* _arbol);

	public:
		void mostrarMenu();
		void ejecutarOpcion(Abb* _arbol);

		//Metodos setters/getters
		void ingresarOpcion(int);
		int obtenerOpcion();
		bool obtenerSalir();
};

#endif
