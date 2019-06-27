#ifndef Nodo_HPP
#define Nodo_HPP

#include <iostream>
#include "cliente.hpp"

using namespace std;
template <typename Dato>

class Nodo
{
private:
	Dato *dato;
	Nodo *izquierda;
	Nodo *derecha;

public:
	//CONSTRUCTORES
	Nodo<Dato>();
	Nodo<Dato>(Dato *_dato);
	Nodo<Dato>(Dato *_dato, Nodo *_izquierda, Nodo *_derecha);
	//SETTERS/GETTERS
	void asignarDato(Dato *_dato);
	void asignarIzquierda(Nodo *izquierda);
	void asignarDerecha(Nodo *derecha);
	Dato *obtenerDato();
	Nodo *obtenerIzquierda();
	Nodo *obtenerDerecha();
};

//Constructor
template <typename Dato>
Nodo<Dato>::Nodo()
{
	dato = NULL;
	izquierda = NULL;
	derecha = NULL;
}
template <typename Dato>
Nodo<Dato>::Nodo(Dato *_dato)
{
	dato = _dato;
	izquierda = NULL;
	derecha = NULL;
}
template <typename Dato>
Nodo<Dato>::Nodo(Dato *_dato, Nodo *_izquierda, Nodo *_derecha)
{
	dato = _dato;
	izquierda = _izquierda;
	derecha = _derecha;
}

//Asignar
template <typename Dato>
void Nodo<Dato>::asignarDato(Dato *_dato)
{
	dato = _dato;
}
template <typename Dato>
void Nodo<Dato>::asignarIzquierda(Nodo<Dato> *_izquierda)
{
	izquierda = _izquierda;
}
template <typename Dato>
void Nodo<Dato>::asignarDerecha(Nodo<Dato> *_derecha)
{
	derecha = _derecha;
}

//Obtener
template <typename Dato>
Dato *Nodo<Dato>::obtenerDato()
{
	return dato;
}
template <typename Dato>
Nodo<Dato> *Nodo<Dato>::obtenerIzquierda()
{
	return izquierda;
}
template <typename Dato>
Nodo<Dato> *Nodo<Dato>::obtenerDerecha()
{
	return derecha;
}
#endif
