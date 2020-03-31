#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* siguiente;
}Nodo;

Nodo* NuevoNodo(Item x);
void InsertarListaCircular(Nodo** cabeza, Item dato);

int main() {
	
	return 0;
}

// Insertar al comienzo
Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}
	
void InsertarListaCircular(Nodo** cabeza, Item dato){
	Nodo* nodoNuevo = NuevoNodo(dato);
	
	if(*cabeza != NULL){
		nodoNuevo->siguiente = (*cabeza)->siguiente;
		(*cabeza)->siguiente = nodoNuevo;
	}
	(*cabeza) = nodoNuevo;
}
	
