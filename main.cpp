#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo del árbol 
 struct Nodo {
    int id;
    string nombre;
    string fechaNacimiento;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo* padre; // para rastrear ancestros
};
