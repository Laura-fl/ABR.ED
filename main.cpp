#include<iostream>
using namespace std;

struct persona{
	nodo* raiz;
	string nombre;
	int edad;
	persona* izq;
	persona* der;
};

nodo* nuevapersona(string nombre, int edad) {
	persona* nueva = new persona();
	nueva->nombre = nombre;
	nueva->edad = edad;
	nueva->izq = NULL;
	nueva->der = NULL;

	return nueva;
}
