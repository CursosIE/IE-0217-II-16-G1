/**
 * @file fraccion.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Implementacion de la clase Fraccion.
 */
#include <stdlib.h>
#include <iostream>
#include "fraccion.h"



using namespace std;


/**	@brief Constructor default.
 *
 * Constructor vacio, no recibe parametros.
 * 
 */
Fraccion::Fraccion(){

}

/**	@brief Constructor con parametros.
 *
 * Constructor recive dos enteros.
 * @param num Entero que representa el numerador de la fraccion.
 * @param den Entero que representa el denominador de la fraccion.
 *
 */
Fraccion::Fraccion(int num, int den){
	this->num = num;
	this->den = den;
}

/**	@brief Destructor.
 *
 * Destructor vacio.
 * 
 */
Fraccion::~Fraccion(){

}

/**	@brief Implementacion de la sobrecarga de operadores.
 *
 * Se implementan la sobrecarga de cada operador antes declarados en matriz.h.
 *
 */
Fraccion Fraccion::operator+(const Fraccion &OtraFraccion){
	int num2 = OtraFraccion.num;
	int den2 = OtraFraccion.den;
	if(this->den == den2){
		int numResult =  this->num + num2;
		int denResult =  this->den;
		Fraccion Result(numResult, denResult);
		return Result;
	}
	else{
		int num2 = OtraFraccion.num;
		int den2 = OtraFraccion.den;

		int numResult =  this->num * den2 + this->den * num2;
		int denResult =  this->den * den2;
		Fraccion Result(numResult, denResult);
		return Result;
	}	
}


Fraccion Fraccion::operator-(const Fraccion &OtraFraccion){
	int num2 = OtraFraccion.num;
	int den2 = OtraFraccion.den;
	if(this->den == den2){
		int numResult =  this->num - num2;
		int denResult =  this->den;
		Fraccion Result(numResult, denResult);
		return Result;
	}
	else{
		int num2 = OtraFraccion.num;
		int den2 = OtraFraccion.den;

		int numResult =  this->num * den2 - this->den * num2;
		int denResult =  this->den * den2;
		Fraccion Result(numResult, denResult);
		return Result;
	}
}

Fraccion Fraccion::operator*(const Fraccion &OtraFraccion){
	int num2 = OtraFraccion.num;
	int den2 = OtraFraccion.den;
	
	int numResult = this->num * num2;
	int denResult = this->den * den2;
	Fraccion Result(numResult, denResult);
	return Result;
}

Fraccion Fraccion::operator/(const Fraccion &OtraFraccion){
	int num2 = OtraFraccion.num;
	int den2 = OtraFraccion.den;
	
	int numResult = this->num * den2;
	int denResult = this->den * num2;
	Fraccion Result(numResult, denResult);
	return Result;
}

void Fraccion::operator~(){
	cout << "Fraccion: " << this->num << "/" << this->den << endl;
}

ostream& operator<<(ostream &out, const Fraccion &OtraFraccion){
	out << "(" << OtraFraccion.num << "/" << OtraFraccion.den << ")";
	return out;
}
