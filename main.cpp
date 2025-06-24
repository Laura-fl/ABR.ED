#include<iostream>
#include<string>
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

// Insertar ordenado (ABB por nombre)
Persona* insertar(Persona* raiz, string nombre, int edad) {
    if (raiz == NULL)
        return nuevaPersona(nombre, edad);
    if (nombre < raiz->nombre)
        raiz->izq = insertar(raiz->izq, nombre, edad);
    else
        raiz->der = insertar(raiz->der, nombre, edad);
    return raiz;
}

// Mostrar en orden (inorden)
void inorden(Persona* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        cout << "Nombre: " << raiz->nombre << ", Edad: " << raiz->edad << endl;
        inorden(raiz->der);
    }
}
