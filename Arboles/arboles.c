#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct Nodo{
	Item dato;
	struct Nodo* hijo_izdo;
	struct Nodo* hijo_dcho;
};

typedef struct Nodo Hoja;
typedef Hoja* ArbolBinario;
ArbolBinario CrearHoja(Item dato);
void EjemploCrearArbol();
void ArbolDeEjemplo();
void RecorrerEnPreOrden(ArbolBinario* arbol);
void EjemploRecorridoPreOrden();
void RecorrerEnOrden(ArbolBinario* arbol);
void EjemploRecorridoEnOrden();
void RecorrerEnPostOrden(ArbolBinario* arbol);
int Profundidad(ArbolBinario* arbol);
void BorrarArbolEntero(ArbolBinario* arbol);


int main() {
	
	return 0;
}

void EjemploProfundidad(){
	puts("Arbol de entrada:\n1 2 3 4 5 6 7\n");
	
	ArbolBinario raiz = CrearHoja(1);
	raiz->hijo_izdo = CrearHoja(2);
	raiz->hijo_dcho = CrearHoja(3);
	
	ArbolBinario raizDos = raiz->hijo_izdo;
	ArbolBinario raizTres = raiz->hijo_dcho;
	
	raizDos->hijo_izdo = CrearHoja(4);
	raizDos->hijo_dcho = CrearHoja(5);
	
	raizTres->hijo_izdo = CrearHoja(6);
	raizTres->hijo_dcho = CrearHoja(7);
	
	int profundidad = Profundidad(&raiz);
	
	printf("La profundidad del árbol es: %d\n", profundidad);
	
}

void EjemploRecorridoEnPostOrden(){
	puts("Arbol de entrada:\n1 2 3 4 5 6 7\n");
	
	ArbolBinario raiz = CrearHoja(1);
	raiz->hijo_izdo = CrearHoja(2);
	raiz->hijo_dcho = CrearHoja(3);
	
	ArbolBinario raizDos = raiz->hijo_izdo;
	ArbolBinario raizTres = raiz->hijo_dcho;
	
	raizDos->hijo_izdo = CrearHoja(4);
	raizDos->hijo_dcho = CrearHoja(5);
	
	raizTres->hijo_izdo = CrearHoja(6);
	raizTres->hijo_dcho = CrearHoja(7);
	
	RecorrerEnPostOrden(&raiz);
	
	puts("\nEl recorrido en Preorden debe ser:\n");
	puts("4 5 2 6 7 3 1\n");
}

void EjemploRecorridoEnOrden(){
	puts("Arbol de entrada:\n1 2 3 4 5 6 7\n");
	
	ArbolBinario raiz = CrearHoja(1);
	raiz->hijo_izdo = CrearHoja(2);
	raiz->hijo_dcho = CrearHoja(3);
	
	ArbolBinario raizDos = raiz->hijo_izdo;
	ArbolBinario raizTres = raiz->hijo_dcho;
	
	raizDos->hijo_izdo = CrearHoja(4);
	raizDos->hijo_dcho = CrearHoja(5);
	
	raizTres->hijo_izdo = CrearHoja(6);
	raizTres->hijo_dcho = CrearHoja(7);
	
	RecorrerEnOrden(&raiz);
	
	puts("\nEl recorrido en Preorden debe ser:\n");
	puts("4 2 5 1 6 3 7\n");
}

void EjemploRecorridoPreOrden(){
	puts("Arbol de entrada:\n1 2 3 4 5 6 7\n");
	
	ArbolBinario raiz = CrearHoja(1);
	raiz->hijo_izdo = CrearHoja(2);
	raiz->hijo_dcho = CrearHoja(3);
	
	ArbolBinario raizDos = raiz->hijo_izdo;
	ArbolBinario raizTres = raiz->hijo_dcho;
	
	raizDos->hijo_izdo = CrearHoja(4);
	raizDos->hijo_dcho = CrearHoja(5);
	
	raizTres->hijo_izdo = CrearHoja(6);
	raizTres->hijo_dcho = CrearHoja(7);
	
	RecorrerEnPreOrden(&raiz);
	
	puts("\nEl recorrido en Preorden debe ser:\n");
	puts("1 2 4 5 3 6 7\n");
	
}

void ArbolDeEjemplo(){
	ArbolBinario raiz = CrearHoja(1);
	raiz->hijo_izdo = CrearHoja(2);
	raiz->hijo_dcho = CrearHoja(3);
	
	ArbolBinario raizDos = raiz->hijo_izdo;
	ArbolBinario raizTres = raiz->hijo_dcho;
	
	raizDos->hijo_izdo = CrearHoja(4);
	raizDos->hijo_dcho = CrearHoja(5);
	
	raizTres->hijo_izdo = CrearHoja(6);
	raizTres->hijo_dcho = CrearHoja(7);
}

void EjemploCrearArbol(){
	ArbolBinario raiz = CrearHoja(1);
	raiz->hijo_izdo = CrearHoja(2);
	raiz->hijo_dcho = CrearHoja(3);
	
	printf("Raíz: %d\n", raiz->dato); 
	printf("Hijo izdo: %d\n", raiz->hijo_izdo->dato);
	printf("Hijo dcho: %d\n", raiz->hijo_dcho->dato);
	
	free(raiz->hijo_izdo);
	free(raiz->hijo_dcho);
	free(raiz);
}

ArbolBinario CrearHoja(Item dato){
	ArbolBinario hoja = (ArbolBinario)malloc(sizeof(Hoja));
	hoja->dato = dato;
	hoja->hijo_izdo = NULL;
	hoja->hijo_dcho = NULL;
	return hoja;
}

void RecorrerEnPreOrden(ArbolBinario* arbol){
	if(*arbol){
		printf("%d ", (*arbol)->dato);
		ArbolBinario* hijo_izdo = &((*arbol)->hijo_izdo);
		ArbolBinario* hijo_dcho = &((*arbol)->hijo_dcho);
		RecorrerEnPreOrden(hijo_izdo);
		RecorrerEnPreOrden(hijo_dcho);
	}
}
	
	
void RecorrerEnOrden(ArbolBinario* arbol){
	if(*arbol){
		ArbolBinario* hijo_izdo = &((*arbol)->hijo_izdo);
		ArbolBinario* hijo_dcho = &((*arbol)->hijo_dcho);
		
		RecorrerEnOrden(hijo_izdo);
		printf("%d ", (*arbol)->dato);
		RecorrerEnOrden(hijo_dcho);
	}
}	
	
void RecorrerEnPostOrden(ArbolBinario* arbol){
	if(*arbol){
		ArbolBinario* hijo_izdo = &((*arbol)->hijo_izdo);
		ArbolBinario* hijo_dcho = &((*arbol)->hijo_dcho);
		
		RecorrerEnPostOrden(hijo_izdo);
		RecorrerEnPostOrden(hijo_dcho);
		printf("%d ", (*arbol)->dato);
	}
}
	
void BorrarArbolEntero(ArbolBinario* arbol){
	if(*arbol){
		ArbolBinario* hijo_izdo = &((*arbol)->hijo_izdo);
		ArbolBinario* hijo_dcho = &((*arbol)->hijo_dcho);
		
		BorrarArbolEntero(hijo_izdo);
		BorrarArbolEntero(hijo_dcho);
		printf("Borrando nodo: %d\n", (*arbol)->dato);
		free(*arbol);
		*arbol = NULL;
	}
}

int Profundidad(ArbolBinario* arbol){
	if(*arbol){
		ArbolBinario* hijo_izdo = &((*arbol)->hijo_izdo);
		ArbolBinario* hijo_dcho = &((*arbol)->hijo_dcho);
		int profundidadIzdo = Profundidad(hijo_izdo);
		int profundidadDcho = Profundidad(hijo_dcho);
		if(profundidadIzdo > profundidadDcho){
			return profundidadIzdo + 1;
		}else{
			return profundidadDcho + 1;
		}
	}else{
		return 0;
	}
}
	
	
	
	
	
	
	

