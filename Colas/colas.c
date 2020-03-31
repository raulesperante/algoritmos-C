#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	Creación de cola vacía
	Verificar cola vacía
	Insertar al final
	Eliminar datos en la cabeza
*/

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* siguiente;
}Nodo;

typedef struct{
	Nodo* frente;
	Nodo* fin;
}Cola;

Nodo* CrearNodo(Item dato);
void CrearCola(Cola** cola);
bool ColaVacia(Cola** cola);
void Insertar(Cola** cola, Item dato);
Item Eliminar(Cola** cola);
Item DevolverFrenteCola(Cola** cola);
	

int main() {
	
	
	return 0;
}

void CrearCola(Cola** cola){
	(*cola)->frente = (*cola)->fin = NULL;
}
	
Nodo* CrearNodo(Item dato){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

/*
	Devuelve true si la cola está vacía,
	de lo contario devuelve false
*/
bool ColaVacia(Cola** cola){
	return (*cola)->frente == NULL;
	
}

void Insertar(Cola** cola, Item dato){
	Nodo* nuevoNodo = CrearNodo(dato);
	
	if(ColaVacia(cola)){
		(*cola)->frente = nuevoNodo;
	}else{
		(*cola)->fin->siguiente = nuevoNodo;
	}
}
	
/*
	Elimina y devuelve el primer elemento
	Si hay un error, sale con -1
*/
Item Eliminar(Cola** cola){
	if(!ColaVacia(cola)){
		Nodo* nodoAEliminar = (*cola)->frente;
		Item valorAEliminar = (*cola)->frente->dato;
		(*cola)->frente = (*cola)->frente->siguiente;
		free(nodoAEliminar);
		return valorAEliminar;
	}else{
		puts("Error cometido al eliminar de una cola vacía");
		exit(1);
	}
}

Item DevolverFrenteCola(Cola** cola){
	if(ColaVacia(cola)){
		puts("Error: cola vacía");
		exit(1);
	}
	return (*cola)->frente->dato;
}

/*
	Elimina y libera todos los nodos de la cola
*/
void BorrarCola(Cola** cola){
	for(;(*cola)->frente != NULL; ){
		Nodo* nodoAEliminar = (*cola)->frente;
		(*cola)->frente = (*cola)->frente->siguiente;
		free(nodoAEliminar);
	}
}










