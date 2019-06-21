#ifndef ABB_H
#define ABB_H

#include "cliente.hpp"

class Abb {

private:
    Abb *izq;
    Abb *der;
    Cliente *dato;
    //Buscar implementacion de arbol binario de busqueda xd
public:
    Abb();

    Abb(Cliente *dato);

    void insertar(Cliente* dato);

    void mostrarArbol(int cont = 0);

    bool existe(Cliente *dato);

    void eliminar(int numero);

    void eliminarNodo();

    Cliente* minimo();

    void reemplazar(Cliente* nuevoDato);

    Abb* buscarPadre(Cliente* dato);

    Abb *getIzq() const;

    void setIzq(Abb *izq);

    Abb *getDer() const;

    void setDer(Abb *der);

    Cliente *getDato() const;

    void setDato(Cliente *dato);

    void preOrdenEliminar();

    ~Abb();
};
#endif //ABB_H