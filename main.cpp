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

