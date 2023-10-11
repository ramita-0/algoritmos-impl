#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* anterior;
    Nodo* siguiente;
};

void agregar(Nodo*&, Nodo*&, int);
void recorrerDesdeInicio(Nodo*);
void recorrerDesdeFin(Nodo*);

// Implementacion de una lista doblemente enlazada, ordenada de manera ascendente.
int main() {
    // Los inicializo como nullptr porque sino hay problemas con el chequeo de NULLs cuando quiero agregar un 0 a mi lista
    Nodo* inicio = nullptr;
    Nodo* fin = nullptr;

    agregar(inicio, fin, 1);
    agregar(inicio, fin, 2);
    agregar(inicio, fin, 4);
    agregar(inicio, fin, 5);
    agregar(inicio, fin, 0);
    agregar(inicio, fin, 3);
    agregar(inicio, fin, 7);
    agregar(inicio, fin, -3);
    agregar(inicio, fin, 6);
    agregar(inicio, fin, -5);

    recorrerDesdeInicio(inicio);
    cout << endl;
    recorrerDesdeFin(fin);
    
    return 0;
}

void agregar(Nodo*& inicio, Nodo*& fin, int newDato) {
    // Tengo 0 nodos en la lista
    if (inicio == nullptr && fin == nullptr) { 
        inicio = new Nodo;
        inicio->dato = newDato;
        return;
    }
    
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = newDato;

    // Tengo 1 nodo en la lista
    if (fin == nullptr && newDato >= inicio->dato) { // newDato es mayor o igual al dato inicial
        fin = new Nodo;
        fin = nuevoNodo;
        inicio->siguiente = fin;
        fin->anterior = inicio;
        return;
    }
    if (fin == nullptr && newDato < inicio->dato) { // newDato es menor al dato inicial
        fin = new Nodo;
        fin = inicio;
        inicio = nuevoNodo;
        inicio->siguiente = fin;
        fin->anterior = inicio;
        return;
    }

    // Tengo 2 nodos como minimo en mi lista
    Nodo* i = inicio;
    while(i != NULL && i->dato < newDato) {
        i = i->siguiente;
    } 
    if (i == inicio) { // Estoy al principio de la lista
        inicio->anterior = nuevoNodo;
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
        return;
    }
    if (i == NULL) { // Tengo que insertar al final final de la lista
        fin->siguiente = nuevoNodo;
        nuevoNodo->anterior = fin;
        fin = nuevoNodo;
        return;
    }
    else { // Tengo que insertar entre dos nodos
        Nodo* anterior = i->anterior;
        nuevoNodo->anterior = anterior;
        nuevoNodo->siguiente = i;
        anterior->siguiente = nuevoNodo;
        i->anterior = nuevoNodo;
        return;
    }
}

void recorrerDesdeInicio(Nodo* inicio) {
    if(inicio == nullptr) return;
    
    Nodo* i = inicio;
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->siguiente;
    }
}

void recorrerDesdeFin(Nodo* fin) {
    if(fin == nullptr) return; // A lo mejor tengo un nodo solo, y no funcionaria correctamente esta funcion
    
    Nodo* i = fin;
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->anterior;
    }
}