#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;



/*
	@claves guardara un array de enteros
	@valores guardara un array de palabras
    como son arrays y no listas, debemos indicar la capacidad del array
*/
struct Diccionario{
	int* claves;
	char** valores;
	int cantElementos;
	int capacidad;
};

/*
	Inicializa un Diccionario
	Todas las claves serán -1 por defecto

*/
Diccionario* Crear(int capacidad){
	Diccionario* diccionario = new Diccionario;
	diccionario->cantElementos = 0;
	diccionario->capacidad = capacidad;
	diccionario->claves = new int[capacidad];
	diccionario->valores = new char*[capacidad];
	
	//Rellenar claves por defecto
	for(int i=0; i<capacidad; i++){
		diccionario->claves[i] = -1;
	}
	
	return diccionario;
}

void Agregar(Diccionario* diccionario, int clave, char* palabra){
	int claveLibre = 0;
	int i;
	for(i=0; i < diccionario->capacidad && diccionario->claves[i] != -1; i++){
		claveLibre = i;
		cout<<diccionario->claves[i]<<endl;
		cout<<i<<endl;
	}
	cout<<"Mi i: "<<i<<endl;
	cout<<"Clave libre: "<<claveLibre<<endl;
	if(i == diccionario->capacidad){
		cout<<"No hay lugar en el diccinario"<<endl;
		cout<<"Elimine un elemento"<<endl;
	}else{
		//Agregar al diccionario
		diccionario->claves[claveLibre] = clave;
		diccionario->valores[claveLibre] = new char[30];
		strcpy(diccionario->valores[claveLibre], palabra);
	}
}

	

int main() {

	Diccionario* diccionario = Crear(3);
	Agregar(diccionario, 1, (char*)"Uno");
	Agregar(diccionario, 2, (char*)"Dos");
	Agregar(diccionario, 3, (char*)"Tres");
//	Agregar(diccionario, 4, (char*)"Cuatro");
	//cout<<diccionario->valores[0]<<endl;

	
	
	
	return 0;
}

void EjemploArrayNumeros(){
	int* numeros = new int[3];
	numeros[0] = 1;
	numeros[1] = 2;
	cout<<numeros[0]<<endl;
	cout<<numeros[1]<<endl;
}

void EjemploArrayPalabras(){
	char* palabra1 = new char[30];
	char* palabra2 = new char[30];
	char* palabra3 = new char[30];
	
	
	char** palabras = new char*[3];
	
	strcpy(palabra1, "Juan");
	strcpy(palabra2, "Lucas");
	strcpy(palabra3, "Mateo");
	
	
	palabras[0] = palabra1;
	palabras[1] = palabra2;
	palabras[2] = palabra3;
	
	for(int i=0; i < 3; i++){
		cout<<palabras[i]<<endl;
		
	}
}
