#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Elemento{
	Item dato;
	struct Elemento* siguiente;
	
}Nodo;

void InsertarCabezaLista(Nodo** cabeza, Item entrada);
Nodo* NuevoNodo(Item x);
void InsertarUltimoLista(Nodo** ultimo, Item entrada);

int main() {
	
	// Puntero a puntero
	int num = 100;
	int* ptrNum = &num;
	int** ptrptrNum = &ptrNum; // Guarda la direccion de memoria de un puntero
	
/*	Nodo* cabeza = NuevoNodo(2);*/
/*	printf("%d\n", cabeza->dato);*/
/*	InsertarCabezaLista(&cabeza, 1);*/
/*	printf("%d", cabeza->dato);*/
	
	Nodo* ultimo = NuevoNodo(24);
	InsertarUltimoLista(&ultimo, 25);
	printf("%d\n", ultimo->siguiente->dato);


	return 0;
}

// Necesito pasar la dirección de memoria de un puntero
// por eso se pasa así: Nodo**
// Nodo** cabeza, recibe la dirección de memoria de un puntero Nodo
void InsertarCabezaLista(Nodo** cabeza, Item entrada){
	Nodo* nuevo = NuevoNodo(entrada);
	nuevo->siguiente = *cabeza;
	*cabeza = nuevo;
}
	


/* 
	Pasar el último elemento de una lista
*/
void InsertarUltimoLista(Nodo** ultimo, Item entrada){
	Nodo* nuevoUltimo = NuevoNodo(entrada);
	(*ultimo)->siguiente = nuevoUltimo;
}

Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

/*
	Recorrer toda la lista hasta encontrar un puntero que apunte a null,
	ahí agrego mi ultimo puntero
*/
	
