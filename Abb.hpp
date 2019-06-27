#ifndef ABB_H
#define ABB_H

#include "cliente.hpp"
#include "Nodo.hpp"

class Abb
{

private:
    Nodo<Cliente> *raiz;
    //pre: recibe un arbol y un nuevo dato tipo cliente
    void insertar(Nodo<Cliente> *_arbol, Cliente *_nuevoCliente);
    //Recibe un arbol y lo recorre eliminando nodos. Se utiliza en el destructor del arbol
    void eliminarArbol(Nodo<Cliente> *_arbol);
    //Recorre y muestra los datos del arbol
    void inOrderMostrar(Nodo<Cliente> *_arbol);
    //Recorre el arbol y muestra el cliente comparando numeros
    void postOrderBuscar(Nodo<Cliente> *_arbol, string _numero);
    //Compara casos y aplica el metodo correcto para eliminar y mantener balanceado el arbol y luego llama a destruirNodo
    void eliminarNodo(Nodo<Cliente> *_nodoEliminar);
    //Recorre el arbol comparando por numero hasta encontrar el nodo a eliminar y luego llama a eliminarNodo
    void eliminar(Nodo<Cliente> *_arbol, string _numero);
    //Busca el menor de los mayores en el caso de que el nodo a eliminar tenga dos hijos
    Nodo<Cliente> *nodoMinimo(Nodo<Cliente> *_nodo);
    //Asigan Null a los hijos y libera la memoria que utilizaba el nodo
    void destruirNodo(Nodo<Cliente> *_nodo);
    //Asigna el hijo del nodo a eliminar, al padre del mismo. Se utiliza cuando dicho nodo tienen un solo nodo
    void reemplazar(Nodo<Cliente> *arbol, Nodo<Cliente> *nodoEliminar, Nodo<Cliente> *nodoHijoDeEliminar);

public:
    //Llamamos a las funciones privadas para pasarle la raiz como parametro

    //COnstructor
    Abb();

    Nodo<Cliente> *obtenerRaiz();

    void insertar(Cliente *_nuevoCliente) { insertar(raiz, _nuevoCliente); }

    void eliminarArbol() { eliminarArbol(raiz); }

    void inOrderMostrar() { inOrderMostrar(raiz); }

    void postOrderBuscar(string _numero) { postOrderBuscar(raiz, _numero); }

    void obtenerNombreCliente(Nodo<Cliente> *arbol);

    void eliminar(string _numero) { eliminar(raiz, _numero); }

    void reemplazar(Nodo<Cliente> *nodoEliminar, Nodo<Cliente> *nodoHijoDeEliminar) { reemplazar(raiz, nodoEliminar, nodoHijoDeEliminar); }

    //Destructor
    ~Abb();
};
#endif //ABB_H
