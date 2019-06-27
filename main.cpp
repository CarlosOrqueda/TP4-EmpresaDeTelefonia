#include <iostream>
using namespace std;
#include "menu.hpp"

int main()
{
	Abb *nuevoArbol = new Abb;
	Menu mainMenu;

	while (!(mainMenu.obtenerSalir()))
	{
		mainMenu.mostrarMenu();
		mainMenu.ejecutarOpcion(nuevoArbol);
	}

	delete nuevoArbol;

	return 0;
}
