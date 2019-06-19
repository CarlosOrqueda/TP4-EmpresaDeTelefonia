//
// Created by carlo on 17/06/2019.
//

#include "Abb.hpp"

Abb::Abb() {
    raiz = NULL;
}

bool Abb::estaVacio() {
    return raiz == NULL;
}

void Abb::insertarRaiz(Nodo<Cliente>* nuevaRaiz){
    raiz = nuevaRaiz;
}

Nodo<Cliente>* Abb::obtenerRaiz() {
    return raiz;
}

void Abb::insertar(Cliente *dato) {
    Nodo<Cliente>* raizAux = raiz;
    if (estaVacio()) {
        Nodo<Cliente>* nuevoCliente = new Nodo<Cliente>(dato);
        raiz = nuevoCliente;
    }else {
        if (dato->obtenerNumero() < raizAux->obtenerData()->obtenerNumero()){
            raiz->asignarPadre(raiz);
            raiz = raiz->obtenerizquierda();
        }else {
            raiz->asignarPadre(raiz);
            raiz = raiz->obtenerDerecha();
        }
        insertar(dato);
    }
    raiz = raizAux;
}

Nodo<Cliente>* Abb::buscar(Cliente *dato) {
    Nodo<Cliente>* raizAux = raiz;
    if(estaVacio())
        return NULL;
    else if(dato->obtenerNumero() == raiz->obtenerData()->obtenerNumero()){
        return raiz;
    }else{
        if(dato->obtenerNumero()<raizAux->obtenerData()->obtenerNumero()){
            raiz = raiz->obtenerizquierda();
        } else{
            raiz = raiz->obtenerDerecha();
        }
        buscar(dato);
    }
    raiz = raizAux;
    return NULL;
}

void Abb::borrar(Cliente *dato) {
    Nodo<Cliente>* nodoBuscado = buscar(dato);
    if (nodoBuscado == NULL || estaVacio())
        return;
    else
        eliminarNodo(nodoBuscado);
}

void Abb::eliminarNodo(Nodo<Cliente> *nodoBuscado) {
    if(nodoBuscado->obtenerizquierda() && nodoBuscado->obtenerDerecha()){
        Nodo<Cliente>* menor = minimo(nodoBuscado->obtenerDerecha());
        nodoBuscado->obtenerData()->asignarNumero(menor->obtenerData()->obtenerNumero());
        eliminarNodo(menor); //No estaria seguro que conecte con el padre
    }
    else if(nodoBuscado->obtenerizquierda()){
        reemplazar(nodoBuscado,nodoBuscado->obtenerizquierda());
        destruirNodo(nodoBuscado);
    }
    else if(nodoBuscado->obtenerDerecha()){
        reemplazar(nodoBuscado,nodoBuscado->obtenerDerecha());
        destruirNodo(nodoBuscado);
    } else{
        reemplazar(nodoBuscado,NULL);
        destruirNodo(nodoBuscado);
    }
}

void Abb::reemplazar(Nodo<Cliente>* nodo, Nodo<Cliente>* nuevoNodo){
    if (nodo->obtenerPadre()){
        if(nodo->obtenerData()->obtenerNumero()== nodo->obtenerPadre()->obtenerData()->obtenerNumero()){
            nodo->obtenerPadre()->asignarizquierda(nuevoNodo);
        }else if(nodo->obtenerData()->obtenerNumero() == nodo->obtenerPadre()->obtenerData()->obtenerNumero()){
            nodo->obtenerPadre()->asignarDerecha(nuevoNodo);
        }
    }
    nuevoNodo ->asignarPadre(nodo->obtenerPadre());
}

Nodo<Cliente>* Abb::minimo(Nodo<Cliente>* menor){
    if(estaVacio())
        return  NULL;
    if(raiz->obtenerizquierda()){
        menor = raiz;
        return minimo(menor->obtenerizquierda());
    } else{
        return menor;
    }
}

void Abb::destruirNodo(Nodo<Cliente>* nodo){
    nodo->asignarizquierda(NULL);
    nodo->asignarDerecha(NULL);
    delete nodo;

}
