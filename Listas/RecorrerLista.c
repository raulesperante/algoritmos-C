#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* siguiente;
}Nodo;

Nodo* NuevoNodo(Item x);

void RecorrerLista(Nodo** cabeza);
void InsertarCabezaLista(Nodo** cabeza, Item entrada);
Nodo* BuscarUltimoNodo(Nodo** cabeza);
void InsertarAlFinal(Nodo** cabeza, Item x);

int main() {
	
	Nodo* cabeza = NuevoNodo(1);
	InsertarCabezaLista(&cabeza, 2);	
	InsertarCabezaLista(&cabeza, 3);	
	InsertarCabezaLista(&cabeza, 4);	
	InsertarCabezaLista(&cabeza, 5);
	
	RecorrerLista(&cabeza);
	
	Nodo* ultimoNodo = BuscarUltimoNodo(&cabeza);
	printf("%d\n", ultimoNodo != NULL ? ultimoNodo->dato : -1);
	
	InsertarAlFinal(&cabeza, 0);
	
	Nodo* ultimoNodo = BuscarUltimoNodo(&cabeza);
	printf("%d\n", ultimoNodo != NULL ? ultimoNodo->dato : -1);
	
	return 0;
}

void RecorrerLista(Nodo** cabeza){
	Nodo* actual = *cabeza;
	while(actual != NULL){
		printf("%d\n", actual->dato);
		actual = actual->siguiente;
	}
}
	
void InsertarAlFinal(Nodo** cabeza, Item x){
	Nodo* ultimoNodo = BuscarUltimoNodo(cabeza);
	if(ultimoNodo != NULL){
		ultimoNodo->siguiente = NuevoNodo(x);
	}else{
		puts("No existe el puntero");
	}
}
	
Nodo* BuscarUltimoNodo(Nodo** cabeza){
	Nodo* actual = *cabeza;
	Nodo* anterior = NULL;
	while(actual != NULL){
		anterior = actual;
		actual = actual->siguiente;
	}
	return anterior;
}

Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

void InsertarCabezaLista(Nodo** cabeza, Item entrada){
	Nodo* nuevo = NuevoNodo(entrada);
	nuevo->siguiente = *cabeza;
	*cabeza = nuevo;
}
		
