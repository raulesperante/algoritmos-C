#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Nodo{
	Item dato;
	struct Nodo* adelante;
	struct Nodo* atras;
}Nodo;

Nodo* NuevoNodo(Item x);
Nodo* BuscarLista(Nodo** cabeza, Item destino);
void EliminarNodo(Nodo** cabeza, Item destino);
void InsertarNodoAlFinal(Nodo** cabeza, Item entrada);
void RecorrerListaAdelante(Nodo** cabeza);
Nodo* BuscarUltimoNodo(Nodo** cabeza);


int main() {
	
	Nodo* cabeza = NuevoNodo(1);
	InsertarNodoAlFinal(&cabeza, 2);
	InsertarNodoAlFinal(&cabeza, 3);
	InsertarNodoAlFinal(&cabeza, 4);
	InsertarNodoAlFinal(&cabeza, 5);
	
	RecorrerListaAdelante(&cabeza);
	
	puts("Eliminando nodo 4
		 \n");
	
	EliminarNodo(&cabeza, 4);
	
	RecorrerListaAdelante(&cabeza);
	
	return 0;
}

void EliminarNodo(Nodo** cabeza, Item destino){
	Nodo* nodo_a_eliminar = BuscarLista(cabeza, destino);
	
	if(nodo_a_eliminar != NULL){
		// Si es el primero
		if(nodo_a_eliminar->atras == NULL){
			*cabeza = nodo_a_eliminar->adelante;
			free(nodo_a_eliminar);
			// si es el ultimo
		}else if(nodo_a_eliminar->adelante == NULL){
			nodo_a_eliminar->atras->adelante = NULL;
			free(nodo_a_eliminar);
			
		}else{
			// Si es un nodo interior
			nodo_a_eliminar->atras->adelante = nodo_a_eliminar->adelante;
			nodo_a_eliminar->adelante->atras = nodo_a_eliminar->atras;
			free(nodo_a_eliminar);
		}
	}else{
		puts("Elemento no encontrado");
	}
}

Nodo* BuscarLista(Nodo** cabeza, Item destino){
	for(Nodo* indice = *cabeza; indice != NULL; indice = indice->adelante){
		if(destino == indice->dato) return indice;
	}
	return NULL;
}

Nodo* NuevoNodo(Item x){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = x;
	nuevoNodo->adelante = NULL;
	nuevoNodo->atras = NULL;
	return nuevoNodo;
}

void InsertarNodoAlFinal(Nodo** cabeza, Item entrada){
	Nodo* ultimo = BuscarUltimoNodo(cabeza);
	Nodo* nuevoUltimoNodo = NuevoNodo(entrada);
	ultimo->adelante = nuevoUltimoNodo;
	nuevoUltimoNodo->atras = ultimo;
}
	
void RecorrerListaAdelante(Nodo** cabeza){
	Nodo* actual = *cabeza;
	while(actual != NULL){
		printf("%d\n", actual->dato);
		actual = actual->adelante;
	}
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
