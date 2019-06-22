#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
#include "cliente.hpp"

using namespace std;


class Nodo{
		
		private:
		Cliente* data;
    	Nodo* izquierda;
		Nodo* derecha;

		public:

		Nodo(Cliente* data, Nodo* izquierda = NULL, Nodo* derecha = NULL){
			asignarData(data);
			asignarIzquierda(izquierda);
			asignarDerecha(derecha);
		}
		Cliente* obtenerData(){
			return data;
		}
		Nodo* obtenerIzquierda(){
			return izquierda;
		}
		Nodo* obtenerDerecha(){
			return derecha;
		}
		void asignarData(Cliente* data){
			Nodo::data = data;
		}
		void asignarIzquierda(Nodo* izquierda){
			Nodo::izquierda = izquierda;
		}
		void asignarDerecha(Nodo* derecha){
			Nodo::derecha = derecha;
		}
};
#endif