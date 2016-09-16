/**
 * @file figure.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Implementacion de la clase Figura.
 */

#include "iostream"
#include "figure.h"
#include "circulo.h"
#include <stdlib.h>

using namespace std;



/**	@brief Constructores y destructor.
 *
 * Se muestra los 2 constructores que posee la clase Figura, una que recibe parametros atributos y la otra vacia. Al final el destructor.
 * 
 */
Figura::Figura(){

}

Figura::Figura(string nombre, string color){
	this->nombre = nombre;
	this->color = color;
}

Figura::~Figura(){

}


/**	@brief Metodos virtuales.
 *
 * Se implementan los metodos generales virtuales.
 * 
 */
void Figura::area(){
	cout << "Area de una figura geometrica."<< endl;
}

void Figura::perimetro(){
	cout << "Perimetro de una figura geometrica."<< endl;
}

