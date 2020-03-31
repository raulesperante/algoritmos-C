#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* siguiente;
}Nodo;

Nodo* CrearNodo(Item dato);
Nodo* CrearPilaVacia();
bool EstaVacia(Nodo** pila);
Nodo* Cima(Nodo** pila);
void Insertar(Nodo** pila, Item dato);
Item Sacar(Nodo** pila);

int main() {
	
	Nodo* pila =  CrearPilaVacia();
	
	Nodo* uno = CrearNodo(1);
	pila = uno;
	
	Insertar(&pila, 2);
	Insertar(&pila, 3);
	
	int dato = Sacar(&pila);
	printf("%d\n", dato);
	dato = Sacar(&pila);
	printf("%d\n", dato);
	dato = Sacar(&pila);
	printf("%d\n", dato);
	dato = Sacar(&pila);
	
	free(pila);
	return 0;
}

Nodo* CrearPilaVacia(){
	Nodo* pila = NULL;
	return pila;
}

/*
	Devuelve true si la pila esta vacia, de lo contrario devuelve false
*/	
bool EstaVacia(Nodo** pila){
	if(*pila == NULL){
		return true;
	}
	return false;
}
	
Nodo* Cima(Nodo** pila){
	if(!EstaVacia(pila)){
		return *pila;
	}
}
	
Nodo* CrearNodo(Item dato){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
}
	
void Insertar(Nodo** pila, Item dato){
	Nodo* nuevoNodo = CrearNodo(dato);

	Nodo* aux = *pila;
	*pila = nuevoNodo;
	(*pila)->siguiente = aux;
}

Item Sacar(Nodo** pila){
	if(!EstaVacia(pila)){
		int dato = (*pila)->dato;
		
		Nodo* nodoAElimnar = Cima(pila);
		*pila = (*pila)->siguiente;
		free(nodoAElimnar);
		return dato;
	}
	puts("Pila vacia\n");
	return 0;
}
