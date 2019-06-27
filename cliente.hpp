#ifndef CLIENTE
#define CLIENTE

#include "abonable.hpp"

class Cliente : public Abonable
{

protected:
	string numeroTelefono;

public:
	//CONSTRUCTOR
	Cliente(string _numero);
	//SETTERS/GETTERS
	void asignarNumero(string _numero);
	string obtenerNumero();
	//DESTRUCTOR
	virtual ~Cliente();
};

#endif
