/**
 * @file suma.cpp
 * @author Brizula M, Morera B
 * @date 19 Agosto 2016
 * @brief Este programa retorna la suma de los 'n' parametros ingresados. Se cuenta con la funcion main y la funcion suma
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

/**	@brief Funcion Suma
 *
 * Funcion recibe dos parametros y retorna un valor flotante.
 *
 *	@param argc tipo entero, cantidad de elementos a sumar
 *	@param argv lista de char, contiene los elementos a sumar
 */
 
float suma(int argc,char** argv){
  float Result = 0.0;	/**< Resultado total de la sumatoria a retornar */
  int i;				/**< Contador de los parametros aceptados */
  for (i=1; i < argc; i++) {
    float number = atof(argv[i]);
    Result = Result + number;
  }
  return Result;
}


/** 
 * @brief Funcion main
 * @param argc cantidad de parametros recibidos
 * @argv array de los parametros
 */

int main(int argc, char** argv) {
  float Result = suma(argc, argv);	/**< Valor a retornar, sumatoria de los parametros */
  std::cout<<"El resultado de la suma es "<<Result<<std::endl;
  return 0;
}


