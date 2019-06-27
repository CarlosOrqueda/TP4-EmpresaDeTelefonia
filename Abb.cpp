#include <iostream>
#include "Abb.hpp"
#include "individuo.hpp"
#include "familia.hpp"
using namespace std;

Abb::Abb()
{
    raiz = NULL;
}

Nodo<Cliente> *Abb::obtenerRaiz()
{
    return raiz;
}

void Abb::insertar(Nodo<Cliente> *arbol, Cliente *nuevoCliente)
{
    if (arbol == nullptr)
    {
        raiz = new Nodo<Cliente>(nuevoCliente);
    }
    else
    {
        if (nuevoCliente->obtenerNumero() < arbol->obtenerDato()->obtenerNumero())
        {
            if (arbol->obtenerIzquierda() == nullptr)
            {
                Nodo<Cliente> *nuevoArbol = new Nodo<Cliente>(nuevoCliente);
                arbol->asignarIzquierda(nuevoArbol);
            }
            else
                insertar(arbol->obtenerIzquierda(), nuevoCliente);
        }
        else if (nuevoCliente->obtenerNumero() > arbol->obtenerDato()->obtenerNumero())
        {
            if (arbol->obtenerDerecha() == nullptr)
            {
                Nodo<Cliente> *nuevoArbol = new Nodo<Cliente>(nuevoCliente);
                arbol->asignarDerecha(nuevoArbol);
            }
            else
                insertar(arbol->obtenerDerecha(), nuevoCliente);
        }
    }
}

void Abb::eliminarArbol(Nodo<Cliente> *arbol)
{
    if (!arbol)
        return;
    Nodo<Cliente> *arbolBase = arbol;
    Nodo<Cliente> *arbolIzquierdo = arbol->obtenerIzquierda();
    Nodo<Cliente> *arbolDerecho = arbol->obtenerDerecha();
    delete (arbolBase);
    eliminarArbol(arbolIzquierdo);
    eliminarArbol(arbolDerecho);
}

void Abb::inOrderMostrar(Nodo<Cliente> *arbol)
{
    if (!arbol || raiz->obtenerDato() == nullptr) // esto se fija si el dato de raiz es nullo
        return;
    inOrderMostrar(arbol->obtenerIzquierda());
    cout << "******************************************************************************************************" << endl;
    cout << arbol->obtenerDato()->obtenerNumero() << ": " << endl;
    obtenerNombreCliente(arbol);
    cout << "El Precio final es: " << arbol->obtenerDato()->obtenerPrecioFinal() << endl;
    inOrderMostrar(arbol->obtenerDerecha());
}

void Abb::postOrderBuscar(Nodo<Cliente> *arbol, string numero)
{
    if (arbol == nullptr || raiz->obtenerDato() == nullptr)
        return;
    postOrderBuscar(arbol->obtenerIzquierda(), numero);
    postOrderBuscar(arbol->obtenerDerecha(), numero);
    if (numero == arbol->obtenerDato()->obtenerNumero())
    {
        cout << arbol->obtenerDato()->obtenerNumero() << endl;
        Familia *clienteFamilia = dynamic_cast<Familia *>(arbol->obtenerDato());
        Individuo *clienteIndividuo = dynamic_cast<Individuo *>(arbol->obtenerDato());
        if (clienteFamilia)
            clienteFamilia->mostrarIntegrantes();
        if (clienteIndividuo)
        {
            cout << clienteIndividuo->obtenerNombre() << endl;
        }
        cout << (arbol->obtenerDato()->obtenerPrecioFinal()) << endl;
    }
}

void Abb::obtenerNombreCliente(Nodo<Cliente> *arbol)
{
    if (!arbol)
        return;
    Familia *clienteFamilia = dynamic_cast<Familia *>(arbol->obtenerDato());
    Individuo *clienteIndividuo = dynamic_cast<Individuo *>(arbol->obtenerDato());
    if (clienteFamilia)
        clienteFamilia->mostrarIntegrantes();
    if (clienteIndividuo)
        cout << clienteIndividuo->obtenerNombre() << endl;
}

void Abb::eliminarNodo(Nodo<Cliente> *nodoEliminar)
{
    if (nodoEliminar->obtenerDerecha() && nodoEliminar->obtenerIzquierda())
    {
        Nodo<Cliente> *nodoMenor = nodoMinimo(nodoEliminar->obtenerDerecha());
        nodoEliminar->asignarDato(nodoMenor->obtenerDato());
        eliminarNodo(nodoMenor);
    }
    else if (nodoEliminar->obtenerIzquierda())
    {
        reemplazar(nodoEliminar, nodoEliminar->obtenerIzquierda());
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->obtenerDerecha())
    {
        reemplazar(nodoEliminar, nodoEliminar->obtenerDerecha());
        destruirNodo(nodoEliminar);
    }
    else
    {
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

void Abb::eliminar(Nodo<Cliente> *arbol, string numero)
{
    if (!arbol)
        return;
    else if (numero < arbol->obtenerDato()->obtenerNumero())
        eliminar(arbol->obtenerIzquierda(), numero);
    else if (numero > arbol->obtenerDato()->obtenerNumero())
        eliminar(arbol->obtenerDerecha(), numero);
    else
        eliminarNodo(arbol);
}

void Abb::reemplazar(Nodo<Cliente> *arbol, Nodo<Cliente> *nodoEliminar, Nodo<Cliente> *nodoHijoDeEliminar)
{
    if (!arbol)
        return;
    reemplazar(arbol->obtenerIzquierda(), nodoEliminar, nodoHijoDeEliminar);
    if (arbol->obtenerIzquierda() == nodoEliminar || arbol->obtenerDerecha() == nodoEliminar)
    {
        if (nodoEliminar->obtenerDato()->obtenerNumero() == arbol->obtenerIzquierda()->obtenerDato()->obtenerNumero())
            arbol->asignarIzquierda(nodoHijoDeEliminar);
        else if (nodoEliminar->obtenerDato()->obtenerNumero() == arbol->obtenerDerecha()->obtenerDato()->obtenerNumero())
            arbol->asignarDerecha(nodoHijoDeEliminar);
    }
    reemplazar(arbol->obtenerDerecha(), nodoEliminar, nodoHijoDeEliminar);
}

Nodo<Cliente> *Abb::nodoMinimo(Nodo<Cliente> *nodo)
{
    if (!nodo)
        return NULL;
    if (nodo->obtenerIzquierda())
        return nodoMinimo(nodo->obtenerIzquierda());
    else
        return nodo;
}

void Abb::destruirNodo(Nodo<Cliente> *nodo)
{
    nodo->asignarDerecha(NULL);
    nodo->asignarIzquierda(NULL);
    delete nodo;
}

Abb::~Abb()
{
    eliminarArbol();
}
