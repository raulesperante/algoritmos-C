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

int main(int argc, char *argv[]) {
	
	Nodo* cabeza = NuevoNodo(4);
	InsertarCabezaLista(&cabeza, 3);
	InsertarCabezaLista(&cabeza, 2);
	InsertarCabezaLista(&cabeza, 1);
	
	RecorrerListaAdelante(&cabeza);
	
	return 0;
}

void InsertarCabezaLista(Nodo** cabeza, Item entrada){
	Nodo* nuevo = NuevoNodo(entrada);
	nuevo->adelante = *cabeza;
	nuevo->atras = NULL;
	(*cabeza)->atras = nuevo;
	*cabeza = nuevo;
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

