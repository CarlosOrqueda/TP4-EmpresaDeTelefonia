#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
using namespace std;

template <typename DatoNodo>
class Nodo{
		
		private:
		DatoNodo* data;
    	Nodo<DatoNodo>* izquierda, derecha;

		public:

		Nodo(DatoNodo* data, Nodo<DatoNodo>* izquierda = NULL, Nodo<DatoNodo>* derecha = NULL){
			this->asignarData(data);
			this->asignarizquierda(izquierda);
			this->asignarDerecha(derecha);
		}
		DatoNodo obtenerData(){
			return this->DatoNodo;
		}
		Nodo<DatoNodo>* obtenerizquierda(){
			return this->izquierda;
		}
		Nodo<DatoNodo>* obtenerDerecha(){
			return this->derecha;
		}
		void asignarData(DatoNodo* data){
			this->data = data;
		}
		void asignarizquierda(Nodo<DatoNodo>* izquierda){
			this->izquierda = izquierda;
		}
		void asignarDerecha(Nodo<DatoNodo>* derecha){
			this->derecha = derecha;
		}
};
#endif