#include <iostream>
#include "Abb.hpp"
#include "individuo.hpp"
#include "familia.hpp"
using namespace std;

Abb::Abb() {
    raiz = NULL;
}

Nodo<Cliente>* Abb::obtenerRaiz(){
    return raiz;
}

void Abb::insertar(Nodo<Cliente>* arbol,Cliente* nuevoCliente) {
    if(!arbol) {
        arbol = new Nodo<Cliente>(nuevoCliente);
    }else{
        if(nuevoCliente->obtenerNumero() < raiz->obtenerDato()->obtenerNumero()){
            if(!arbol->obtenerIzquierda()) {
                Nodo<Cliente> *nuevoArbol = new Nodo<Cliente>(nuevoCliente);
                arbol->asignarIzquierda(nuevoArbol);
            }else
                insertar(arbol->obtenerIzquierda(),nuevoCliente);
        }else{
            if(!arbol->obtenerDerecha()){
                Nodo<Cliente>* nuevoArbol = new Nodo<Cliente>(nuevoCliente);
                arbol->asignarDerecha(nuevoArbol);
            }else
                insertar(arbol->obtenerDerecha(),nuevoCliente);
        }
    }
}

int Abb::obtenerAltura(Nodo<Cliente> *arbol) {
    if(!arbol)
        return 0;
    else
        return 1 + max(obtenerAltura(arbol->obtenerIzquierda()),obtenerAltura(arbol->obtenerDerecha()));
}

bool Abb::balanceado(Nodo<Cliente> *arbol) {
    if(!arbol)
        return false;
    int alturaIzquierda = obtenerAltura(arbol->obtenerIzquierda());
    int alturaDerecha = obtenerAltura(arbol->obtenerDerecha());
    if (abs(alturaIzquierda - alturaDerecha)>1)
        return false;
    return true;
}

Nodo<Cliente>* Abb::obtenerNodoMaximo() {
    if(!raiz)
        cout << "Arbol vacio" << endl;
    Nodo<Cliente>* arbol = raiz;
    while(arbol->obtenerDerecha())
        arbol = arbol->obtenerDerecha();
    return arbol;
}

Nodo<Cliente>* Abb::obtenerNodoMinimo() {
    if(!raiz) {
        cout << "Arbol vacio" << endl;
    }
    Nodo<Cliente>* arbol = raiz;
    while(arbol->obtenerIzquierda())
        arbol = arbol->obtenerIzquierda();
    return arbol;
}

void Abb::eliminarArbol(Nodo<Cliente>* arbol) {
    if(!arbol)
        return;
    Nodo<Cliente>* arbolBase = arbol;
    Nodo<Cliente>* arbolIzquierdo = arbol->obtenerIzquierda();
    Nodo<Cliente>* arbolDerecho = arbol->obtenerDerecha();
    delete(arbolBase);
    eliminarArbol(arbolIzquierdo);
    eliminarArbol(arbolDerecho);
}

void  Abb::inOrderMostrar(Nodo<Cliente> *arbol) {
    if(!arbol)
        return;
    inOrderMostrar(arbol->obtenerIzquierda());
    cout << "******************************************************************************************************";
    cout<<arbol->obtenerDato()->obtenerNumero()<<": ";
    obtenerNombreCliente();
    cout<<"El Precio final es: "<<arbol->obtenerDato()->obtenerPrecioFinal();
    inOrderMostrar(arbol->obtenerDerecha());
}
void Abb::preOrder(Nodo<Cliente>* arbol){
    if(!arbol)
        return;
    cout<<arbol->obtenerDato()->obtenerNumero()<<endl;
    postOrder(arbol->obtenerIzquierda());
    postOrder(arbol->obtenerDerecha());
}

void Abb::postOrder(Nodo<Cliente> *arbol) {
    if(!arbol)
        return;
    postOrder(arbol->obtenerIzquierda());
    postOrder(arbol->obtenerDerecha());
    cout<<arbol->obtenerDato()->obtenerNumero()<<endl;
}

void Abb::obtenerNombreCliente(Nodo<Cliente>* arbol){
    if(!arbol)
        return;
    Familia* clienteFamilia = dynamic_cast<Familia*> (arbol->obtenerDato());
    Individuo* clienteIndividuo = dynamic_cast<Individuo*> (arbol->obtenerDato());
    if(clienteFamilia)
        clienteFamilia->mostrarIntegrantes();
    if(clienteIndividuo)
        cout<<clienteIndividuo->obtenerNombre()<<endl;
}

void Abb::inOrderBuscar(Nodo<Cliente>* arbol, string numero){
    if(!arbol)
        return;
    inOrderBuscar(arbol->obtenerIzquierda(), numero);
    if(numero == arbol->obtenerDato()->obtenerNumero())
    {
        cout<<arbol->obtenerDato()->obtenerNumero()<<endl;
		Familia* clienteFamilia = dynamic_cast<Familia*> (arbol->obtenerDato());
    	Individuo* clienteIndividuo = dynamic_cast<Individuo*> (arbol->obtenerDato());
    	if(clienteFamilia)
        	clienteFamilia->mostrarIntegrantes();
    	if(clienteIndividuo){
        	cout<<clienteIndividuo->obtenerNombre()<<endl;
		}
		cout<<(arbol->obtenerDato()->obtenerPrecioFinal())<<endl;
    }    
    inOrderBuscar(arbol->obtenerDerecha(), numero);
}

void Abb::inOrderEliminar(Nodo<Cliente>* arbol, string numero){
    if(!arbol)
        return;
    inOrderEliminar(arbol->obtenerIzquierda(), numero);
    if(numero == arbol->obtenerDato()->obtenerNumero())
        eliminar(numero);
    inOrderEliminar(arbol->obtenerDerecha(), numero);
}

void Abb::eliminarNodo(Nodo<Cliente>* nodoEliminar)
{
    if(nodoEliminar->obtenerDerecha() && nodoEliminar->obtenerIzquierda())
    {
        Nodo<Cliente>* nodoMenor = nodoMinimo(nodoEliminar->obtenerDerecha());
        nodoEliminar->asignarDato(nodoMenor->obtenerDato());
        eliminarNodo(nodoMenor);
    }
    else if(nodoEliminar->obtenerIzquierda())
    {
        reemplazar(raiz,nodoEliminar,nodoEliminar->obtenerIzquierda());
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->obtenerDerecha())
    {
        reemplazar(raiz,nodoEliminar,nodoEliminar->obtenerDerecha());
        destruirNodo(nodoEliminar);
    }
    else {
        reemplazar(raiz,nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
}

void Abb::eliminar(Nodo<Cliente>* arbol, string numero)
{
    if(!arbol)
        return;
    else if(numero < arbol->obtenerDato()->obtenerNumero())
            eliminar(arbol->obtenerIzquierda(),numero);
    else if(numero > arbol->obtenerDato()->obtenerNumero())
            eliminar(arbol->obtenerDerecha(),numero);
    else
        eliminarNodo(arbol);
}

void Abb::reemplazar(Nodo<Cliente>* arbol, Nodo<Cliente>* nodoEliminar, Nodo<Cliente>* nodoHijoDeEliminar)
{
    if(!arbol)
        return;
    reemplazar(arbol->obtenerIzquierda(),nodoEliminar, nodoHijoDeEliminar);
    if(arbol->obtenerIzquierda() == nodoEliminar || arbol -> obtenerDerecha() == nodoEliminar)
    {
        if(nodoEliminar->obtenerDato()->obtenerNumero() == arbol->obtenerIzquierda()->obtenerDato()->obtenerNumero())
            arbol->asignarIzquierda(nodoHijoDeEliminar);
        else if(nodoEliminar->obtenerDato()->obtenerNumero() == arbol->obtenerDerecha()->obtenerDato()->obtenerNumero())
            arbol->asignarDerecha(nodoHijoDeEliminar);
    }
    reemplazar(arbol->obtenerDerecha(),nodoEliminar,nodoHijoDeEliminar);
}

Nodo<Cliente>* Abb::nodoMinimo(Nodo<Cliente>* nodo)
{
    if(!nodo)
        return NULL;
    if(nodo->obtenerIzquierda())
        return nodoMinimo(nodo->obtenerIzquierda());
    else
        return nodo;
}

void Abb::destruirNodo(Nodo<Cliente>* nodo)
{
    nodo->asignarDerecha(NULL);
    nodo->asignarIzquierda(NULL);
    delete nodo;
}

void Abb::obtenerNombreCliente(Nodo<Cliente>* arbol){
    if(!arbol)
        return;
    Familia* clienteFamilia = dynamic_cast<Familia*> (arbol->obtenerDato());
    Individuo* clienteIndividuo = dynamic_cast<Individuo*> (arbol->obtenerDato());
    if(clienteFamilia)
        clienteFamilia->mostrarIntegrantes();
    if(clienteIndividuo)
        cout<<clienteIndividuo->obtenerNombre()<<endl;
}

void Abb::inOrderBuscar(Nodo<Cliente>* arbol, string numero){
    if(!arbol)
        return;
    inOrderBuscar(arbol->obtenerIzquierda(), numero);
    if(numero == arbol->obtenerDato()->obtenerNumero())
    {
        cout<<arbol->obtenerDato()->obtenerNumero()<<endl;
		Familia* clienteFamilia = dynamic_cast<Familia*> (arbol->obtenerDato());
    	Individuo* clienteIndividuo = dynamic_cast<Individuo*> (arbol->obtenerDato());
    	if(clienteFamilia)
        	clienteFamilia->mostrarIntegrantes();
    	if(clienteIndividuo){
        	cout<<clienteIndividuo->obtenerNombre()<<endl;
		}
		cout<<arbol->obtenerDato()->obtenerPrecioFinal()<<endl;
    }    
    inOrderBuscar(arbol->obtenerDerecha(), numero);
}

void Abb::inOrderEliminar(Nodo<Cliente>* arbol, string numero){
    if(!arbol)
        return;
    inOrderEliminar(arbol->obtenerIzquierda(), numero);
    if(numero == arbol->obtenerDato()->obtenerNumero())
        eliminar(numero);
    inOrderEliminar(arbol->obtenerDerecha(), numero);
}

void Abb::eliminarNodo(Nodo<Cliente>* nodoEliminar)
{
    if(nodoEliminar->obtenerDerecha() && nodoEliminar->obtenerIzquierda())
    {
        Nodo<Cliente>* nodoMenor = nodoMinimo(nodoEliminar->obtenerDerecha());
        nodoEliminar->asignarDato(nodoMenor->obtenerDato());
        eliminarNodo(nodoMenor);
    }
    else if(nodoEliminar->obtenerIzquierda())
    {
        reemplazar(raiz,nodoEliminar,nodoEliminar->obtenerIzquierda());
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->obtenerDerecha())
    {
        reemplazar(raiz,nodoEliminar,nodoEliminar->obtenerDerecha());
        destruirNodo(nodoEliminar);
    }
    else {
        reemplazar(raiz,nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
}

void Abb::eliminar(Nodo<Cliente>* arbol, string numero)
{
    if(!arbol)
        return;
    else if(numero < arbol->obtenerDato()->obtenerNumero())
            eliminar(arbol->obtenerIzquierda(),numero);
    else if(numero > arbol->obtenerDato()->obtenerNumero())
            eliminar(arbol->obtenerDerecha(),numero);
    else
        eliminarNodo(arbol);
}

void Abb::reemplazar(Nodo<Cliente>* arbol, Nodo<Cliente>* nodoEliminar, Nodo<Cliente>* nodoHijoDeEliminar)
{
    if(!arbol)
        return;
    reemplazar(arbol->obtenerIzquierda(),nodoEliminar, nodoHijoDeEliminar);
    if(arbol->obtenerIzquierda() == nodoEliminar || arbol -> obtenerDerecha() == nodoEliminar)
    {
        if(nodoEliminar->obtenerDato()->obtenerNumero() == arbol->obtenerIzquierda()->obtenerDato()->obtenerNumero())
            arbol->asignarIzquierda(nodoHijoDeEliminar);
        else if(nodoEliminar->obtenerDato()->obtenerNumero() == arbol->obtenerDerecha()->obtenerDato()->obtenerNumero())
            arbol->asignarDerecha(nodoHijoDeEliminar);
    }
    reemplazar(arbol->obtenerDerecha(),nodoEliminar,nodoHijoDeEliminar);
}

Nodo<Cliente>* Abb::nodoMinimo(Nodo<Cliente>* nodo)
{
    if(!nodo)
        return NULL;
    if(nodo->obtenerIzquierda())
        return nodoMinimo(nodo->obtenerIzquierda());
    else
        return nodo;
}

void Abb::destruirNodo(Nodo<Cliente>* nodo)
{
    nodo->asignarDerecha(NULL);
    nodo->asignarIzquierda(NULL);
    delete nodo;
}

Abb::~Abb() {
    eliminarArbol();
}