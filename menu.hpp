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

	/*DAR ALTA
		 *PRE: Existe el arbol 
		  POST: Inserta un cliente nuevo*/
	void darAlta(Abb *_arbol);
	/*LISTAR
		 *PRE: Existe el arbol  
		  POST: Muestra todos los clientes por pantalla*/
	void listarClientes(Abb *_arbol);
	/*BUSCAR
		 *PRE: Existe el arbol  
		  POST: Devuelve los datos vinculados al numero ingresado*/
	void buscarCliente(Abb *_arbol);
	/*DAR BAJA
		 *PRE: Existe el cliente  
		  POST: Elimina a el cliente vinculado al numero ingresado*/
	void eliminarCliente(Abb *_arbol);

public:
	//MUESTRA LAS OPCIONES
	void mostrarMenu();
	/*CARGAR ARCHIVO
		 * PRE: Existe el archivo y tiene un formato valido.
		   POST: Da el alta a todos los clientes dentro del archivo*/
	void leerArchivo(Abb *_arbol);
	void ejecutarOpcion(Abb *_arbol);

	//Metodos setters/getters
	void ingresarOpcion(int);
	int obtenerOpcion();
	bool obtenerSalir();
};

#endif
