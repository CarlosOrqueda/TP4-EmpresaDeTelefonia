#ifndef NODOLista_HPP
#define NODOLista_HPP
#include <iostream>
using namespace std;
template <typename Dato>
class NodoLista
{
	private:
		Dato *dato;
		NodoLista *punteroSiguiente;

	public:
		//Constructor
		//POST: Crea un nodoLista con dato y puntero vacio
		NodoLista();
		//Constructor con parametro
		//POST: Crea un nodoLista con el el dato _dato y el puntero a NULL
		NodoLista(Dato *_dato);
		//Setea el dato
		//PRE: El nodoLista tiene que estar creado y _dato tiene que ser un dato valido
		//POST: El nodoLista queda con el dato _dato
		void asignarDato(Dato *_dato);
		//Setea el punteroSiguiente
		//PRE: nodoLista creado y punteroSiguiente valido
		//POST: el puntero siguiente apunta a un puntero
		void asignarSiguiente(NodoLista *_punteroSiguiente);
		//Obtener dato
		//PRE: nodoLista creado
		//POST: devuelve el dato que contiene el nodoLista
		Dato *obtenerDato();
		//Obtener punteroSiguiente
		//PRE: nodoLista creado
		//POST: devuelve el puntero al siguiente nodoLista, si es el ultimo devuelve NULL
		NodoLista *obtenerSiguiente();
};

//Constructor
template <typename Dato>
NodoLista<Dato>::NodoLista()
{
	dato = NULL;
	punteroSiguiente = NULL;
}
// Constructor con parametro
template <typename Dato>
NodoLista<Dato>::NodoLista(Dato *_dato)
{
	dato = _dato;
	punteroSiguiente = NULL;
}
//Asignar dato
template <typename Dato>
void NodoLista<Dato>::asignarDato(Dato *_dato)
{
	dato = _dato;
}
//Asignar puntero al siguiente
template <typename Dato>
void NodoLista<Dato>::asignarSiguiente(NodoLista *_punteroSiguiente)
{
	punteroSiguiente = _punteroSiguiente;
}
//Obtener dato
template <typename Dato>
Dato *NodoLista<Dato>::obtenerDato()
{
	return dato;
}
//Obtener puntero al siguiente nodoLista
template <typename Dato>
NodoLista<Dato> *NodoLista<Dato>::obtenerSiguiente()
{
	return punteroSiguiente;
}
#endif
