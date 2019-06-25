#ifndef ABB_H
#define ABB_H

#include "cliente.hpp"
#include "Nodo.hpp"

class Abb {

private:
    Nodo<Cliente>* raiz;
    
    void insertar(Nodo<Cliente>* _arbol, Cliente* _nuevoCliente);
    int obtenerAltura(Nodo<Cliente>* _arbol);
    bool balanceado(Nodo<Cliente>* _arbol);
    void eliminarArbol(Nodo<Cliente>* _arbol);
    void inOrderMostrar(Nodo<Cliente>* _arbol);
    void inOrderBuscar(Nodo<Cliente>* _arbol, string _numero);
    void preOrder(Nodo<Cliente>* _arbol);
    void postOrder(Nodo<Cliente>* _arbol);
    void eliminarNodo(Nodo<Cliente>* _nodoEliminar);
    void eliminar(Nodo<Cliente>* _arbol,string _numero);
    Nodo<Cliente>* nodoMinimo(Nodo<Cliente>* _nodo);
    void destruirNodo(Nodo<Cliente>* _nodo);
    void reemplazar(Nodo<Cliente>* arbol, Nodo<Cliente>* nodoEliminar, Nodo<Cliente>* nodoHijoDeEliminar);

public:
    Abb();

    Nodo<Cliente>* obtenerRaiz();

    void insertar(Cliente* _nuevoCliente){insertar(raiz,_nuevoCliente);}

    int obtenerAltura(){return obtenerAltura(raiz);}

    bool balanceado(){return balanceado(raiz);}

    Nodo<Cliente>* obtenerNodoMaximo();

    Nodo<Cliente>* obtenerNodoMinimo();

    void eliminarArbol(){eliminarArbol(raiz);}

    void inOrderMostrar(){inOrderMostrar(raiz);}

    void inOrderBuscar(string _numero){inOrderBuscar(raiz,_numero);}

    void preOrder(){preOrder(raiz);}

    void postOrder(){postOrder(raiz);}

    void obtenerNombreCliente(Nodo<Cliente>* arbol);

    void eliminar(string _numero){eliminar(raiz,_numero);}

    void reemplazar(Nodo<Cliente>* nodoEliminar, Nodo<Cliente>* nodoHijoDeEliminar){reemplazar(raiz, nodoEliminar, nodoHijoDeEliminar);}

    ~Abb();
};
#endif //ABB_H
