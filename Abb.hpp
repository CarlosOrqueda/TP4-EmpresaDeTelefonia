#ifndef ABB_H
#define ABB_H

#include "cliente.hpp"
#include "Nodo.hpp"

class Abb {

private:
    Nodo* raiz;
    //Buscar implementacion de arbol binario de busqueda xd
    void insertar(Nodo* arbol, Cliente* nuevoCliente);
    int obtenerAltura(Nodo* arbol);
    bool balanceado(Nodo* arbol);
    void eliminarArbol(Nodo* arbol);
    void inOrderMostrar(Nodo* arbol);
    void inOrderBuscar(Nodo* arbol, string numero);
    void inOrderEliminar(Nodo* arbol, string numero);
    void preOrder(Nodo* arbol);
    void postOrder(Nodo* arbol);
    void obtenerNombreCliente(Nodo* arbol);
    void eliminarNodo(Nodo* nodoEliminar);
    void eliminar(Nodo* arbol,string numero);
    Nodo* nodoMinimo(Nodo* nodo);
    void destruirNodo(Nodo* nodo);

public:
    Abb();

    Nodo* obtenerRaiz();

    void insertar(Cliente* nuevoCliente){insertar(raiz,nuevoCliente);}

    int obtenerAltura(){return obtenerAltura(raiz);}

    bool balanceado(){return balanceado(raiz);}

    Nodo* obtenerNodoMaximo();

    Nodo* obtenerNodoMinimo();

    void eliminarArbol(){eliminarArbol(raiz);}

    void inOrderMostrar(){inOrderMostrar(raiz);}

    void inOrderBuscar(string numero){inOrderBuscar(raiz,numero);}

    void inOrderEliminar(string numero){inOrderEliminar(raiz,numero);}

    void preOrder(){preOrder(raiz);}

    void postOrder(){postOrder(raiz);}

    void obtenerNombreCliente(){obtenerNombreCliente(raiz);}

    void eliminar(string numero){eliminar(raiz,numero);}

    void reemplazar(Nodo* arbol, Nodo* nodo, Nodo* nuevoNodo);

    ~Abb();
};
#endif //ABB_H