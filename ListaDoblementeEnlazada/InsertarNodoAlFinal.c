#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* adelante;
	struct Nodo* atras;
}Nodo;

Nodo* NuevoNodo(Item x);
void InsertarCabezaLista(Nodo** cabeza, Item entrada);
void RecorrerListaAdelante(Nodo** cabeza);
void InsertarNodoAlFinal(Nodo** cabeza, Item entrada);
Nodo* BuscarUltimoNodo(Nodo** cabeza);


int main(int argc, char *argv[]) {
	
	Nodo* cabeza = NuevoNodo(1);
	
	InsertarNodoAlFinal(&cabeza, 2);
	InsertarNodoAlFinal(&cabeza, 3);
	InsertarNodoAlFinal(&cabeza, 4);
	
	RecorrerListaAdelante(&cabeza);
	
	return 0;
}

void InsertarNodoAlFinal(Nodo** cabeza, Item entrada){
	Nodo* ultimo = BuscarUltimoNodo(cabeza);
	Nodo* nuevoUltimoNodo = NuevoNodo(entrada);
	ultimo->adelante = nuevoUltimoNodo;
	nuevoUltimoNodo->atras = ultimo;
}

void InsertarCabezaLista(Nodo** cabeza, Item entrada){
	Nodo* nuevo = NuevoNodo(entrada);
	nuevo->adelante = *cabeza;
	nuevo->atras = NULL;
	(*cabeza)->atras = nuevo;
	*cabeza = nuevo;
}
	
Nodo* BuscarUltimoNodo(Nodo** cabeza){
	Nodo* actual = *cabeza;
	Nodo* anterior = NULL;
	while(actual != NULL){
		anterior = actual;
		actual = actual->adelante;
	}
	return anterior;
}

Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->adelante = NULL;
	nuevoNodo->atras = NULL;
	return nuevoNodo;
}
	
void RecorrerListaAdelante(Nodo** cabeza){
	Nodo* actual = *cabeza;
	while(actual != NULL){
		printf("%d\n", actual->dato);
		actual = actual->adelante;
	}
}

