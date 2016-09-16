/**
 * @file suma.c
 * @author Brizula M, Morera B
 * @date 19 Agosto 2016
 * @brief Este programa retorna la suma de los 'n' parametros ingresados. Se cuenta con la funcion main y la funcion suma
 */

#include "stdio.h"
#include "stdlib.h"

/**
 * @brief Funcion Suma
 *
 * Funcion recibe dos parametros y retorna un valor flotante.
 *
 * @param argc tipo entero, cantidad de elementos a sumar
 * @param argv lista de char, contiene los elementos a sumar, pueden ser enteros o tipos flotantes
 */

float suma(int argc, char** argv){
  float Result = 0.0;	/**< Resultado de la suma, al llamar la funcion suma.*/
  int i;	/**< Contador en el bucle.*/
  for (i=1; i < argc; i++) {
    Result = Result + atof(argv[i]); 
  }
  return Result;
}

/**
 * @brief Funcion main
 *
 * Funcion recibe dos parametros y retorna un valor flotante.
 *
 * @param argc Contiene el numero de argumentos que se han introducido
 * @param argv Array de punteros a caracteres
 */

int main(int argc, char** argv) {
  float Result = suma(argc, argv);
  printf("El resultado de la suma es: %f\n", Result);
  return 0;
}
