#include <iostream> 
#include <string>
using namespace std;

//funciones base del arbol 
struct Persona {
    string nombre;
    int edad;
    int id;
    Persona* izq;
    Persona* der;
};

Persona* nuevaPersona(string nombre, int edad, int id) {
    Persona* nueva = new Persona();
    nueva->nombre = nombre;
    nueva->edad = edad;
    nueva->id = id;
    nueva->izq = NULL;
    nueva->der = NULL;
    return nueva;
}
Persona* insertar(Persona* raiz, string nombre, int edad, int id) {
    if (raiz == NULL)
        return nuevaPersona(nombre, edad, id);
    if (edad < raiz->edad)
        raiz->izq = insertar(raiz->izq, nombre, edad, id);
    else
        raiz->der = insertar(raiz->der, nombre, edad, id);
    return raiz;
}
int contarDigitos(int n) {
    if (n == 0) return 1;
    int c = 0;
    while (n != 0) {
        c++;
        n /= 10;
    }
    return c;
}
//generacion y recorridos del arbol
void mostrarPorGeneracion(Persona* raiz, int gen) {
    if (raiz == NULL) return;
    mostrarPorGeneracion(raiz->izq, gen);
    if (contarDigitos(raiz->id) == gen)
        cout << raiz->nombre << " (" << raiz->edad << ") ";
    mostrarPorGeneracion(raiz->der, gen);
}
void mostrarTodasGeneraciones(Persona* raiz, int maxGen) {
    for (int i = 1; i <= maxGen; i++) {
        cout << i << "ra generacion: ";
        mostrarPorGeneracion(raiz, i);
        cout << endl;
    }
}
void inorden(Persona* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        cout << "Nombre: " << raiz->nombre << ", Edad: " << raiz->edad << ", ID: " << raiz->id << endl;
        inorden(raiz->der);
    }
}
void preorden(Persona* raiz) {
    if (raiz != NULL) {
        cout << "Nombre: " << raiz->nombre << ", Edad: " << raiz->edad << endl;
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
void posorden(Persona* raiz) {
    if (raiz != NULL) {
        posorden(raiz->izq);
        posorden(raiz->der);
        cout << "Nombre: " << raiz->nombre << ", Edad: " << raiz->edad << endl;
    }
}
