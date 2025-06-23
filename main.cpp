#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    Persona* izq;
    Persona* der;
};

//crear persona 
