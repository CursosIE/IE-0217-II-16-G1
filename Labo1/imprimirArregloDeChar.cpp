/**
 * @file imprimirArregloDeChar.cpp
 * @author Brizuela M, Morera B
 * @date 2 Septiembre 2016
 * @brief Este programa traduce una cadena ARN a AA
 */

#include <iostream>
#include <cstring>
#include <stdlib.h> 

/**
 * @brief Prototipo de las funciones
 *
 * Se presentan los prototipos de las funciones; misma estructura que en la declaracion, mostrando su tipo y tipo de parametros.
 */
int main(int argc, char **argv);
int imprimirArregloDeChar(int n, char *array);

using namespace std;


/**
 * @brief Funcion imprimirArregloDeChar
 *
 * Funcion encargada de parsear o seleccionar la cantidad deseada de caracteres del string ingresado; si la cantidad que se requiere imprimir es mayor a la longitud del string, se maneja como un error.
 *
 * @param n tipo entero, cantidad de elementos a imprimir del char pointer.
 * @param array char*, string del cual se imprime parcial o completamente.
 */
int imprimirArregloDeChar(int n, char *array){
	int lenArray = strlen(array);
	if( lenArray < n ){
		cout << "No se pueden imprimir los " << n << " caracteres deseados. El caracter posee " << lenArray << "." << endl;
	}
	else{
		char *ptrImprimir = new char[n];
		for(int i = 0; i < n; i++){
			*(ptrImprimir + i) = array[i];
		}
		cout << ptrImprimir << endl;
		delete ptrImprimir;
	}
	return 0;
}



/**
 * @brief Funcion main
 *
 * Funcion recibe dos parámetros.
 *
 * @param argc Contiene el numero de argumentos que se han introducido.
 * @param argv Array de punteros a caracteres.
 */
int main(int argc, char **argv){
	int nParam = atoi(argv[1]);
	imprimirArregloDeChar(nParam, argv[2]);
	return 0;
}
