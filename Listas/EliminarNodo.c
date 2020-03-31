#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>// Booleanos

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* siguiente;
}Nodo;

Nodo* NuevoNodo(Item x);
void eliminarNodo(Nodo** cabeza, Item entrada);


int main() {
	
	return 0;
}

void eliminarNodo(Nodo** cabeza, Item entrada){
	Nodo* actual = *cabeza;
	Nodo* anterior = NULL;
	bool encontrado = false;
	// Bucle de búsqueda
	while(actual != NULL && !encontrado){
		encontrado = actual->dato == entrada;
		if(!encontrado){
			anterior = actual;
			actual = actual->siguiente;
		}
	}
	if(actual != NULL){
		if(actual == *cabeza){
			*cabeza = actual->siguiente;
		}else{
			anterior->siguiente = actual->siguiente;
		}
		free(actual);
	}
}

Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}
