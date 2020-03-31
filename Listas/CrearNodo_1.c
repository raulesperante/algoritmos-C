#include <stdio.h>
#include <stdlib.h>

struct Elemento{
	int dato;
	struct Elemento* siguiente;
};

typedef struct Elemento Nodo;

Nodo* CrearNodo(int x, Nodo* enlace){
	Nodo* p;
	p = (Nodo*)malloc(sizeof(Nodo));
	p->dato = x;
	p->siguiente = enlace;
	return p;
}


int main() {
	
	Nodo* Primero = CrearNodo(11, NULL);
	
	
	return 0;
}

