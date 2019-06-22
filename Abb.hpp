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
    void inOrder(Nodo* arbol);
    void preOrder(Nodo* arbol);
    void postOrder(Nodo* arbol);
public:
    Abb();

    void insertar(Cliente* nuevoCliente){insertar(raiz,nuevoCliente);}

    int obtenerAltura(){return obtenerAltura(raiz);}

    bool balanceado(){return balanceado(raiz);}

    Nodo* obtenerNodoMaximo();

    Nodo* obtenerNodoMinimo();

    void eliminarArbol(){eliminarArbol(raiz);}

    void inOrder(){inOrder(raiz);}

    void preOrder(){preOrder(raiz);}

    void postOrder(){postOrder(raiz);}

    ~Abb();
};
#endif //ABB_H