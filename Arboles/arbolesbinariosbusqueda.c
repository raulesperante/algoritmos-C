#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Un nodo modelizará el número de legajo de un
	estudiante en una universidad
	y su nombre

*/

typedef struct Nodo{
	int legajo;
	char nombre[30];
	struct Nodo* hijo_izdo;
	struct Nodo* hijo_dcho;
}Nodo;

Nodo* CrearNodo(int legajo, char* nombre);
Nodo* buscar(Nodo** arbol, int buscado);
void insertar(Nodo** raiz, int legajo, char* nombre);
void eliminar(Nodo** raiz, int legajo);
void RecorrerEnPreOrden(Nodo** raiz);



int main() {
	
	Nodo* raiz = CrearNodo(40, "Cuarenta");
	insertar(&raiz, 20, "Veinte");
	insertar(&raiz, 50, "Cincuenta");
	insertar(&raiz, 10, "Diez");
	insertar(&raiz, 30, "Treinta");
	insertar(&raiz, 70, "Setenta");
	insertar(&raiz, 60, "Sesenta");
	insertar(&raiz, 45, "Cuarenta y cinco");
	insertar(&raiz, 55, "Cincueta y cinco");
	insertar(&raiz, 54, "Cincueta y cuatro");
	

	RecorrerEnPreOrden(&raiz);
	eliminar(&raiz, 60);
	printf("\n");
	RecorrerEnPreOrden(&raiz);
	
	return 0;
}

Nodo* CrearNodo(int legajo, char* nombre){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->legajo = legajo;
	nuevoNodo->hijo_dcho = NULL;
	nuevoNodo->hijo_izdo = NULL;
	strcpy(nuevoNodo->nombre, nombre);
	return nuevoNodo;
}

	
Nodo* buscar(Nodo** arbol, int buscado){
	Nodo* nodo = *arbol;
	Nodo** hijo_izdo = &(nodo->hijo_izdo);
	Nodo** hijo_dcho = &(nodo->hijo_dcho);
	if(!nodo){
		return 0;
	}else if(buscado == nodo->legajo){
		return nodo;
	}else if(buscado < nodo->legajo){
		return buscar(hijo_izdo, buscado);
	}else{
		return buscar(hijo_dcho, buscado);
	}
}

/*
	Inserta un nuevo alumno con su legajo y nombre
	en el árbol
*/
void insertar(Nodo** raiz, int legajo, char* nombre){
	if(!(*raiz)){
		*raiz = CrearNodo(legajo, nombre);
	}else if(legajo < (*raiz)->legajo){
		Nodo** hijo_izdo = &((*raiz)->hijo_izdo);
		insertar(hijo_izdo, legajo, nombre);
	}else{
		Nodo** hijo_dcho = &((*raiz)->hijo_dcho);
		insertar(hijo_dcho, legajo, nombre);
	}
}

/*
	No estoy seguro de la lógica de eliminar, hacer más pruebas
	con dos ramas
*/
	
void eliminar(Nodo** raiz, int legajo){
	if(!(*raiz)){
		printf("Registro con clave %d no se encuentra\n", legajo);
	}else if(legajo < (*raiz)->legajo){
		Nodo** hijo_izdo = &((*raiz)->hijo_izdo);
		eliminar(hijo_izdo, legajo);
	}else if(legajo > (*raiz)->legajo){
		Nodo** hijo_dcho = &((*raiz)->hijo_dcho);
		eliminar(hijo_dcho, legajo);
	}else /* Legajo encontrado */
	{
		Nodo* nodoAEliminar = (*raiz);
		if(nodoAEliminar->hijo_izdo == NULL){
			*raiz = nodoAEliminar->hijo_dcho;
		}else if(nodoAEliminar->hijo_dcho == NULL){
			*raiz = nodoAEliminar->hijo_izdo;
		}else /* El arbol tiene sus dos ramas */
		{
			// Reemplazar por la mayor de sus claves menoes
			Nodo* mayor = nodoAEliminar->hijo_izdo;
			Nodo* mayorClaveMenor = NULL;
			// Buscar la mayor clave menor
			while(mayor->hijo_dcho){
				mayorClaveMenor = mayor;
				mayor = mayorClaveMenor->hijo_dcho;
			}
			/* No hay hijo_dcho_mayor_clave_mayor, 
			   si lo hubiera sería mi mayorClaveMenor */
			Nodo* hijo_dcho_mayor_clave_menor = mayorClaveMenor->hijo_dcho;
			mayorClaveMenor->hijo_izdo = nodoAEliminar->hijo_izdo;
			mayorClaveMenor->hijo_dcho = nodoAEliminar->hijo_dcho;
			mayorClaveMenor->hijo_izdo->hijo_dcho = hijo_dcho_mayor_clave_menor;
			free(nodoAEliminar);
			
		}
	}
}
	

void RecorrerEnPreOrden(Nodo** raiz){
	if(*raiz){
		printf("%d ", (*raiz)->legajo);
		Nodo** hijo_izdo = &((*raiz)->hijo_izdo);
		Nodo** hijo_dcho = &((*raiz)->hijo_dcho);
		RecorrerEnPreOrden(hijo_izdo);
		RecorrerEnPreOrden(hijo_dcho);
	}
}
	
	
	
	
	
	
	
	
	
