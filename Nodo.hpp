#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
using namespace std;

template <typename DatoNodo>
class Nodo{
		
		private:
		DatoNodo* data;
    	Nodo<DatoNodo>* izquierda;
		Nodo<DatoNodo>* derecha;
		Nodo<DatoNodo>* padre;

		public:

		Nodo(DatoNodo* data, Nodo<DatoNodo>* izquierda = NULL, Nodo<DatoNodo>* derecha = NULL, Nodo<DatoNodo>* padre = NULL){
			asignarData(data);
			asignarizquierda(izquierda);
			asignarDerecha(derecha);
			asignarPadre(padre);
		}
		DatoNodo* obtenerData(){
			return data;
		}
		Nodo<DatoNodo>* obtenerizquierda(){
			return izquierda;
		}
		Nodo<DatoNodo>* obtenerDerecha(){
			return derecha;
		}

		Nodo<DatoNodo>* obtenerPadre(){
            return padre;
        }

		void asignarData(DatoNodo* data){
			Nodo::data = data;
		}
		void asignarizquierda(Nodo<DatoNodo>* izquierda){
			Nodo::izquierda = izquierda;
		}
		void asignarDerecha(Nodo<DatoNodo>* derecha){
			Nodo::derecha = derecha;
		}

        void asignarPadre(Nodo<DatoNodo>* padre){
            Nodo::padre = padre;
		}
};
#endif