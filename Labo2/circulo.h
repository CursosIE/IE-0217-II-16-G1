/**
 * @file circulo.h
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Clase derivada de la clase base Figura.
 */
 
#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
#include <stdlib.h>
#include "figure.h"

using namespace std;


/**	@brief Clase derivada Circulo.
 *
 * Posee 1 unico atributo propio, las 2 funciones virtuales de la clase base y ademas de la sobrecarga de 2 operadores.
 * 
 */
class Circulo:public Figura{
public:
	Circulo();
	Circulo(double radio);
	virtual ~Circulo();

	double radio;

	void area();
	void perimetro();
	
	void operator ~ ();
	void operator ! ();
};


#endif /* CIRCULO_H */