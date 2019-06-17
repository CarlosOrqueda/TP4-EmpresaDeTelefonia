#ifndef ABB_HPP
#define ABB_HPP
#include <iostream>
using namespace std;
#include "Nodo.hpp"
#include "cliente.hpp"


class Abb{

	private:
	Nodo<Cliente>* raiz;

	public:

	//Constructor del Arbol binario de busqueda
	Abb();

	/*
	* No puede insertar la misma clave.
	*/
	void insertar(Cliente* dato);

	/*
	* Elimina el dato cuya clave coincide con la enviada.
	*/
	void borrar(Cliente* dato);

	void eliminarNodo(Nodo<Cliente>* nodoBuscado);

	Nodo<Cliente>* minimo(Nodo<Cliente>* menor);

    void reemplazar(Nodo<Cliente>* nodo, Nodo<Cliente>* nuevoNodo);

    void destruirNodo(Nodo<Cliente>* nodo);

	/*
	* Busca un dato en el arbol.
	* El parametro dato se utiliza para comparar con los otros datas del arbol.
	* Debe estar inicializado como para poder utilizar la función de comparación.
	* Devuelve el dato encontrado o NULL si no lo encuentra.
	*/
	Nodo<Cliente>* buscar(Cliente* dato);

	/*
	* Determina si el árbol está vacío. 
	* Devuelve true si lo está, false en caso contrario.
	*/
	bool estaVacio();

	void insertarRaiz(Nodo<Cliente>* nuevaRaiz);

	Nodo<Cliente>* obtenerRaiz();

	/*
	* Destruye el arbol liberando la memoria reservada por este y todos sus nodos y hojas.
	* Adicionalmente invoca el destructor con cada dato presente en el arbol.
	*/
	~Abb();
};
#endif