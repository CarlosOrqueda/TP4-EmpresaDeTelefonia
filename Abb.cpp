//
// Created by carlo on 17/06/2019.
//

#include <iostream>
#include "Abb.hpp"

using namespace std;


Abb::Abb() {
    izq = NULL;
    der = NULL;
    dato = NULL;

}

Abb::Abb(Cliente* dato) {
    this->dato = dato;
}

void Abb::insertar(Cliente* dato) {
    if(this->dato == NULL)
        this->dato = dato;
    else{
        if(this->dato->obtenerNumero() < dato->obtenerNumero()){
            if(izq==NULL) {
                Abb *nuevoArbol = new Abb(dato);
                izq = nuevoArbol;
            } else
                izq->insertar(dato);
        } else{
            if(der == NULL){
                Abb* nuevoArbol = new Abb(dato);
                der = nuevoArbol;
            }else
                der->insertar(dato);
        }
    }
}

void Abb::mostrarArbol(int cont) {
    if(dato == NULL)
        return;
    else{
        der->mostrarArbol(cont + 1);
        for(int i = 0 ; i < cont; i++){
            cout<<"   ";
        }
        cout<<dato->obtenerNumero()<<endl;
        der->mostrarArbol(cont+1);
    }
}

void Abb::eliminar(int numero) {
    if(this->dato == NULL)
        return;
    else if(numero < this->dato->obtenerNumero())
        izq->eliminar(numero);
    else if(numero > this->dato->obtenerNumero())
        der->eliminar(numero);
    else
        eliminarNodo();
}

void Abb::eliminarNodo() {
    if(izq && der) {
        Cliente *menor = der->minimo();
        setDato(menor);
        Abb* padre = buscarPadre(menor);
        if(padre->der->dato->obtenerNumero() == menor->obtenerNumero())
            padre->der->eliminarNodo();
        else
            padre->izq->eliminarNodo();
    }else if(izq)
        izq->reemplazar(izq->dato);
    else if(der)
        der->reemplazar(der->dato);
    else{
        reemplazar(NULL);
        delete dato;
    }

}

void Abb::reemplazar(Cliente* nuevoDato) {
    if(buscarPadre(dato)){
        Abb* padre = buscarPadre(dato);
        if(dato->obtenerNumero() == padre->izq->dato->obtenerNumero())
            padre->izq->setDato(nuevoDato);
        else if(dato->obtenerNumero() == padre->der->dato->obtenerNumero())
            padre->der->setDato(nuevoDato);
    }
    delete(dato);
    //FALTA CASO LIMITE DE RAIZ QUE NO TIENE PADRE



}

Abb* Abb::buscarPadre(Cliente *dato) {
    if(this->dato == NULL)
        return NULL;
    else{
        if(dato->obtenerNumero() == der->dato->obtenerNumero() || dato->obtenerNumero() == izq->dato->obtenerNumero())
            return this;
        else{
            if(dato->obtenerNumero() < this->dato->obtenerNumero())
                return izq->buscarPadre(dato);
            else
                return der->buscarPadre(dato);
        }
    }
}

Cliente* Abb::minimo() {
    if(dato == NULL)
        return  NULL;
    if(izq)
        return izq->minimo();
    else
        return dato;
}

bool Abb::existe(Cliente *dato) {
    if(this->dato == NULL)
        return false;
    else if(this->dato->obtenerNumero() == dato->obtenerNumero())
        return true;
    else if(dato->obtenerNumero() < this->dato->obtenerNumero())
        return this->izq->existe(dato);
    else
        return this->der->existe(dato);
}

void Abb::preOrdenEliminar() {
    if(dato==NULL)
        return;
    else{
        delete dato;
        izq->preOrdenEliminar();
        der->preOrdenEliminar();
    }
}

Abb::~Abb() {
    preOrdenEliminar();
}

Abb *Abb::getIzq() const {
    return izq;
}

void Abb::setIzq(Abb *izq) {
    Abb::izq = izq;
}

Abb *Abb::getDer() const {
    return der;
}

void Abb::setDer(Abb *der) {
    Abb::der = der;
}

Cliente *Abb::getDato() const {
    return dato;
}

void Abb::setDato(Cliente *dato) {
    Abb::dato = dato;
}
