/**
 * @file triangulo.h
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Clase derivada de la clase base Figura.
 */

#ifndef TRIANGULO_H
#define TRIANGULO_H
#include <iostream>
#include <stdlib.h>
#include "figure.h"

using namespace std;


/**	@brief Clase derivada Triangulo.
 *
 * Posee 3 atributos propios, las 2 funciones virtuales de la clase base y ademas de la sobrecarga de 2 operadores.
 * 
 */
class Triangulo:public Figura{
public:
	Triangulo();
	Triangulo(double lado1, double lado2, double lado3);
	virtual ~Triangulo();

	double lado1;	/**< Lados de cualquier tipo de triangulo */
	double lado2;
	double lado3;

	void area();
	void perimetro();
	
	void operator ~ ();
	void operator ! ();
};


#endif /* TRIANGULO_H */