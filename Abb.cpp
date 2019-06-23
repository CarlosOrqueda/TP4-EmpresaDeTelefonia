#include <iostream>
#include "Abb.hpp"
#include "familia.hpp"
using namespace std;

Abb::Abb() {
    raiz = NULL;
}

Nodo* Abb::obtenerRaiz(){
    return raiz;
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

void  Abb::inOrderMostrar(Nodo *arbol) {
    if(!arbol)
        return;
    inOrderMostrar(arbol->obtenerIzquierda());
    cout << "******************************************************************************************************";
    cout<<arbol->obtenerData()->obtenerNumero()<<": ";
    obtenerNombreCliente();
    cout<<"El Precio final es: "<<arbol->obtenerData()->obtenerPrecioFinal();
    inOrderMostrar(arbol->obtenerDerecha());
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

void Abb::obtenerNombreCliente(Nodo* arbol){
    if(!arbol)
        return;
    Familia* clienteFamilia = dynamic_cast<Familia*> (arbol->obtenerData());
    Individuo* clienteIndividuo = dynamic_cast<Individuo*> (arbol->obtenerData());
    if(clienteFamilia)
        clienteFamilia->mostrarIntegrantes();
    if(clienteIndividuo)
        cout<<clienteIndividuo->obtenerNombre()<<endl;
}

Cliente* Abb::inOrderBuscar(Nodo* arbol, string numero){
    if(!arbol)
        cout << "No existe el cliente";
        return;
    inOrderBuscar(arbol->obtenerIzquierda(), numero);
    if(numero == arbol->obtenerData()->obtenerNumero())
        return arbol->obtenerData();
    inOrderBuscar(arbol->obtenerDerecha(), numero);
}

void Abb::eliminarNodo(Nodo* arbol)
{
    if(!arbol)
        return
    arbol->asignarDerecha(NULL);
    arbol->asignarIzquierda(NULL);
    delete arbol;
}

Abb::~Abb() {
    eliminarArbol();
}
