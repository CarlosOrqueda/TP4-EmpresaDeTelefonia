#include <iostream>
#include "Abb.hpp"


using namespace std;

Abb::Abb() {
    raiz = NULL;
}

void Abb::insertar(Nodo* arbol,Cliente* nuevoCliente) {
    if(!arbol) {
        arbol = new Nodo(nuevoCliente);
        raiz = arbol;
    }else{
        if(nuevoCliente->obtenerNumero() < raiz->obtenerData()->obtenerNumero()){
            if(!arbol->obtenerIzquierda()) {
                Nodo *nuevoArbol = new Nodo(nuevoCliente);
                arbol->asignarIzquierda(nuevoArbol);
            }else
                insertar(arbol->obtenerIzquierda(),nuevoCliente);
        }else{
            if(!arbol->obtenerDerecha()){
                Nodo* nuevoArbol = new Nodo(nuevoCliente);
                arbol->asignarDerecha(nuevoArbol);
            }else
                insertar(arbol->obtenerDerecha(),nuevoCliente);
        }
    }
}

int Abb::obtenerAltura(Nodo *arbol) {
    if(!arbol)
        return 0;
    else
        return 1 + max(obtenerAltura(arbol->obtenerIzquierda()),obtenerAltura(arbol->obtenerDerecha()));
}

bool Abb::balanceado(Nodo *arbol) {
    if(!arbol)
        return false;
    int alturaIzquierda = obtenerAltura(arbol->obtenerIzquierda());
    int alturaDerecha = obtenerAltura(arbol->obtenerDerecha());
    if (abs(alturaIzquierda - alturaDerecha)>1)
        return false;
    return true;
}

Nodo* Abb::obtenerNodoMaximo() {
    if(!raiz) {
        cout << "Arbol vacio" << endl;
    }
    Nodo* arbol = raiz;
    while(arbol->obtenerDerecha())
        arbol = arbol->obtenerDerecha();
    return arbol;
}

Nodo* Abb::obtenerNodoMinimo() {
    if(!raiz) {
        cout << "Arbol vacio" << endl;
    }
    Nodo* arbol = raiz;
    while(arbol->obtenerIzquierda())
        arbol = arbol->obtenerIzquierda();
    return arbol;
}

void Abb::eliminarArbol(Nodo* arbol) {
    if(!arbol)
        return;
    Nodo* arbolBase = arbol;
    Nodo* arbolIzquierdo = arbol->obtenerIzquierda();
    Nodo* arbolDerecho = arbol->obtenerDerecha();
    delete(arbolBase);
    eliminarArbol(arbolIzquierdo);
    eliminarArbol(arbolDerecho);
}

void  Abb::inOrder(Nodo *arbol) {
    if(!arbol)
        return;
    inOrder(arbol->obtenerIzquierda());
    cout<<arbol->obtenerData()->obtenerNumero()<<endl;
    inOrder(arbol->obtenerDerecha());
}

void Abb::preOrder(Nodo *arbol) {
    if(!arbol)
        return;
    cout<<arbol->obtenerData()->obtenerNumero()<<endl;
    postOrder(arbol->obtenerIzquierda());
    postOrder(arbol->obtenerDerecha());
}

void Abb::postOrder(Nodo *arbol) {
    if(!arbol)
        return;
    postOrder(arbol->obtenerIzquierda());
    postOrder(arbol->obtenerDerecha());
    cout<<arbol->obtenerData()->obtenerNumero()<<endl;
}

Abb::~Abb() {
    eliminarArbol();
}
