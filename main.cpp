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

