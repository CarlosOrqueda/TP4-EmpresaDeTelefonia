#include "familia.hpp"

Familia::Familia():Cliente()
{
	integrantes[10] = {""};	
	tope = 0;

}
void Familia::agregarIntegrante(string _nombre)
{
	if(tope < 10){
		integrantes[tope] = _nombre;
		tope++;
	}else {
		cout<< "Maximo de integrantes por familia, superado\n";
	}
	
}
void Familia::mostrarIntegrantes()
{
	for(string integrante: integrantes){
		cout << integrante + ", ";
	}
}
Familia::~Familia()
{
	
}