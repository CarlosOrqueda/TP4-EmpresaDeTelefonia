#ifndef ABB_HPP
#define ABB_HPP
#include <iostream>
using namespace std;
#include "Nodo.hpp"

template <typename DatoABB>
class Abb{

	private:

	DatoABB* dato;
	Nodo<DatoABB>* raiz;

	public:

	//Constructor del Arbol binario de busqueda
	Abb();

	/*
	* No puede insertar la misma clave.
	*/
	void insertar(DatoABB* dato);

	/*
	* Elimina el dato cuya clave coincide con la enviada.
	*/
	void borrar(DatoABB* dato);

	/*
	* Busca un dato en el arbol.
	* El parametro dato se utiliza para comparar con los otros datas del arbol.
	* Debe estar inicializado como para poder utilizar la función de comparación.
	* Devuelve el dato encontrado o NULL si no lo encuentra.
	*/
	DatoABB* buscar(DatoABB* dato);

	/*
	* Determina si el árbol está vacío. 
	* Devuelve true si lo está, false en caso contrario.
	*/
	bool estaVacio();

	/*
	* Destruye el arbol liberando la memoria reservada por este y todos sus nodos y hojas.
	* Adicionalmente invoca el destructor con cada dato presente en el arbol.
	*/
	~Abb();

};

template <typename DatoABB>
Abb<DatoABB>::Abb(){

}
template <typename DatoABB>
Abb<DatoABB>::~Abb(){

}

template <typename DatoABB>
void Abb<DatoABB>::insertar(DatoABB* dato){

}

template <typename DatoABB>
void Abb<DatoABB>::borrar(DatoABB* dato){

}

template <typename DatoABB>
DatoABB* Abb<DatoABB>::buscar(DatoABB* dato){

}

template <typename DatoABB>
bool Abb<DatoABB>::estaVacio(){

	return true;
}


#endif