#include <stdio.h>
#include <stdlib.h>
#define TOPE 7

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* siguiente;
}Nodo;

Nodo* NuevoNodo(Item x);
Nodo* BuscarLista(Nodo** cabeza, Item destino);
void InsertarCabezaLista(Nodo** cabeza, Item entrada);
void TestArrayEnteros();
void ArrayDeEnteros(int lista[], int tope);

int main() {
	
	Nodo* cabeza = NuevoNodo(4);
	InsertarCabezaLista(&cabeza, 3);
	InsertarCabezaLista(&cabeza, 2);
	InsertarCabezaLista(&cabeza, 1);
	
	Nodo* nodoDos = BuscarLista(&cabeza, 1);
	//printf("%d\n", nodoDos != NULL ? nodoDos->dato : 0);
	
	return 0;
}

void InsertarCabezaLista(Nodo** cabeza, Item entrada){
	Nodo* nuevo = NuevoNodo(entrada);
	nuevo->siguiente = *cabeza;
	*cabeza = nuevo;
}
	
Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}
	
Nodo* BuscarLista(Nodo** cabeza, Item destino){
	for(Nodo* indice = *cabeza; indice != NULL; indice = indice->siguiente){
		if(destino == indice->dato) return indice;
	}
	return NULL;
}

void TestArrayEnteros(){
	int numers[TOPE] = {1,2,3,4,5,6,7};
	ArrayDeEnteros(numers, TOPE);
}
	
void ArrayDeEnteros(int lista[], int tope){
	for(int i = 0; i < tope; i++){
		printf("%d ", lista[i]);
	}
}
