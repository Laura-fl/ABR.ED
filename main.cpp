#include <iostream>
#include <string>
using namespace std;


struct Persona {
    string nombre;
    int edad;
    int id;
    Persona* izq;
    Persona* der;
};
//===============funciones del arbol================================//

// Máximo número de nodos permitidos para el arreglo estático
const int MAX = 100;
Persona* arreglo[MAX];
int total = 0;

// Crear nueva persona
Persona* nuevaPersona(string nombre, int edad, int id) {
    Persona* nueva = new Persona();
    nueva->nombre = nombre;
    nueva->edad = edad;
    nueva->id = id;
    nueva->izq = NULL;
    nueva->der = NULL;
    return nueva;
}

// Insertar en el árbol
Persona* insertar(Persona* raiz, string nombre, int edad, int id) {
    if (raiz == NULL)
        return nuevaPersona(nombre, edad, id);
    if (edad < raiz->edad)
        raiz->izq = insertar(raiz->izq, nombre, edad, id);
    else
        raiz->der = insertar(raiz->der, nombre, edad, id);
    return raiz;
}

// Contar dígitos del ID
int contarDigitos(int n) {
    if (n == 0) return 1;
    int c = 0;
    while (n != 0) {
        c++;
        n /= 10;
    }
    return c;
}

//============================generacion y recorridos del arbol=====================//
// Mostrar por generación
void mostrarPorGeneracion(Persona* raiz, int gen) {
    if (raiz == NULL) return;
    mostrarPorGeneracion(raiz->izq, gen);
    if (contarDigitos(raiz->id) == gen)
        cout << raiz->nombre << " (" << raiz->edad << ") ";
    mostrarPorGeneracion(raiz->der, gen);
}
// Mostrar todas las generaciones
void mostrarTodasGeneraciones(Persona* raiz, int maxGen) {
    for (int i = 1; i <= maxGen; i++) {
        cout << i << "ra generacion: ";
        mostrarPorGeneracion(raiz, i);
        cout << endl;
    }
}
// Recorridos
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

//===========================================eliminacion de nodos y funciones auxiliares=========================================//
//buscar el minimo (sucesor)
Persona* minimo(Persona* nodo) {
    while (nodo && nodo->izq != NULL)
        nodo = nodo->izq;
    return nodo;
}

// Eliminar persona por nombre
Persona* eliminar(Persona* raiz, string nombre) {
    if (raiz == NULL) return NULL;

    if (nombre < raiz->nombre)
        raiz->izq = eliminar(raiz->izq, nombre);
    else if (nombre > raiz->nombre)
        raiz->der = eliminar(raiz->der, nombre);
    else {
        if (raiz->izq == NULL) {
            Persona* temp = raiz->der;
            delete raiz;
            return temp;
        }
        else if (raiz->der == NULL) {
            Persona* temp = raiz->izq;
            delete raiz;
            return temp;
        }

        Persona* temp = minimo(raiz->der);
        raiz->nombre = temp->nombre;
        raiz->edad = temp->edad;
        raiz->id = temp->id;
        raiz->der = eliminar(raiz->der, temp->nombre);
    }
    return raiz;
}

//============================ Balanceo del árbol=================================//



//=======================================menu interactivo============================//


void mostrarMenu() {
    cout << "\n=== MENU ===\n";
    cout << "1. Insertar persona (por consola)\n";
    cout << "2. Eliminar persona\n";
    cout << "3. Mostrar arbol en orden (por edad)\n";
    cout << "4. Mostrar generaciones (por id)\n";
    cout << "5. Recorridos (pre, in, pos)\n";
    cout << "6. Balancear arbol\n";
    cout << "0. Salir\n";
    cout << "Seleccion: ";
}

// Programa principal
int main() {
    Persona* raiz = NULL;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            string nombre;
            int edad, id;
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cout << "ID (#digitos = #generacion): ";
            cin >> id;
            raiz = insertar(raiz, nombre, edad, id);
            break;
        }
        case 2: {
            string nombre;
            cout << "Nombre a eliminar: ";
            getline(cin, nombre);
            raiz = eliminar(raiz, nombre);
            break;
        }
        case 3:
            cout << "\n--- Arbol en orden (por edad) ---\n";
            inorden(raiz);
            break;
        case 4:
            cout << "\n--- Mostrar generaciones ---\n";
            mostrarTodasGeneraciones(raiz, 4);
            break;
        case 5:
            cout << "--- Recorridos ---\n";
            cout << "Preorden:\n";
            preorden(raiz);
            cout << "Inorden:\n";
            inorden(raiz);
            cout << "Posorden:\n";
            posorden(raiz);
            break;
        case 6:
            cout << "--- Balanceando el arbol ---\n";
            raiz = balancearArbol(raiz);
            cout << "Árbol balanceado correctamente.\n";
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
