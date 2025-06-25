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


