#ifndef ABB_H
#define ABB_H

#include "cliente.hpp"
#include "Nodo.hpp"

class Abb {

private:
<<<<<<< HEAD
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
=======
    Nodo<Cliente>* raiz;
    
    void insertar(Nodo<Cliente>* _arbol, Cliente* _nuevoCliente);
    int obtenerAltura(Nodo<Cliente>* _arbol);
    bool balanceado(Nodo<Cliente>* _arbol);
    void eliminarArbol(Nodo<Cliente>* _arbol);
    void inOrderMostrar(Nodo<Cliente>* _arbol);
    void inOrderBuscar(Nodo<Cliente>* _arbol, string _numero);
    void inOrderEliminar(Nodo<Cliente>* _arbol, string _numero);
    void preOrder(Nodo<Cliente>* _arbol);
    void postOrder(Nodo<Cliente>* _arbol);
    void obtenerNombreCliente(Nodo<Cliente>* _arbol);
    void eliminarNodo(Nodo<Cliente>* _nodoEliminar);
    void eliminar(Nodo<Cliente>* _arbol,string _numero);
    Nodo<Cliente>* nodoMinimo(Nodo<Cliente>* _nodo);
    void destruirNodo(Nodo<Cliente>* _nodo);
>>>>>>> 4ce374b9e18f0895784416d2b0a18b7af181c343

public:
    Abb();

<<<<<<< HEAD
    Nodo* obtenerRaiz();

    void insertar(Cliente* nuevoCliente){insertar(raiz,nuevoCliente);}
=======
    Nodo<Cliente>* obtenerRaiz();

    void insertar(Cliente* _nuevoCliente){insertar(raiz,_nuevoCliente);}
>>>>>>> 4ce374b9e18f0895784416d2b0a18b7af181c343

    int obtenerAltura(){return obtenerAltura(raiz);}

    bool balanceado(){return balanceado(raiz);}

    Nodo<Cliente>* obtenerNodoMaximo();

    Nodo<Cliente>* obtenerNodoMinimo();

    void eliminarArbol(){eliminarArbol(raiz);}

    void inOrderMostrar(){inOrderMostrar(raiz);}

<<<<<<< HEAD
    void inOrderBuscar(string numero){inOrderBuscar(raiz,numero);}

    void inOrderEliminar(string numero){inOrderEliminar(raiz,numero);}
=======
    void inOrderBuscar(string _numero){inOrderBuscar(raiz,_numero);}

    void inOrderEliminar(string _numero){inOrderEliminar(raiz,_numero);}
>>>>>>> 4ce374b9e18f0895784416d2b0a18b7af181c343

    void preOrder(){preOrder(raiz);}

    void postOrder(){postOrder(raiz);}

    void obtenerNombreCliente(){obtenerNombreCliente(raiz);}

<<<<<<< HEAD
    void eliminar(string numero){eliminar(raiz,numero);}

    void reemplazar(Nodo* arbol, Nodo* nodo, Nodo* nuevoNodo);
=======
    void eliminar(string _numero){eliminar(raiz,_numero);}

    void reemplazar(Nodo<Cliente>* _arbol, Nodo<Cliente>* _nodo, Nodo<Cliente>* _nuevoNodo);
>>>>>>> 4ce374b9e18f0895784416d2b0a18b7af181c343

    ~Abb();
};
#endif //ABB_H
