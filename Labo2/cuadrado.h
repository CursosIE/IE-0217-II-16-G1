/**
 * @file cuadrado.h
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Clase derivada de la clase base Figura.
 */

#ifndef CUADRADO_H
#define CUADRADO_H
#include <iostream>
#include <stdlib.h>
#include "figure.h"

using namespace std;


/**	@brief Clase derivada Cuadrado.
 *
 * Posee 1 unico atributo propio, las 2 funciones virtuales de la clase base y ademas de la sobrecarga de 2 operadores.
 * 
 */
class Cuadrado:public Figura{
public:
	Cuadrado();
	Cuadrado(double lado);
	virtual ~Cuadrado();

	double lado;

	void area();
	void perimetro();

	void operator ~ ();
	void operator ! ();
};


#endif /* CUADRADO_H */