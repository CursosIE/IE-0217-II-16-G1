/**
 * @file cuadrado.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Implementacion de la clase derivada Cuadrado.
 */

#include "cuadrado.h"

using namespace std;



/**	@brief Constructores y destructor.
 *
 * Se muestra los 2 constructores que posee la clase Cuadrado, una que recibe parametros atributos y la otra vacia. Al final el destructor.
 * 
 */
Cuadrado::Cuadrado(){

}

Cuadrado::Cuadrado(double lado){
	this->lado = lado;
}

Cuadrado::~Cuadrado(){

}



/**	@brief Implementacion de los metodos (virtuales).
 *
 * Se implementa los metodos para los calculos de areas y perimetros de objetos cuadrados.
 * 
 */
void Cuadrado::area(){
	double result = this->lado*this->lado;
	cout << "Area: " << result << endl;
}

void Cuadrado::perimetro(){
	double result = 4*this->lado;
	cout << "Perimetro: " << result << endl;
}



/**	@brief Sobrecarga de operadores
 *
 * La primer sobrecarga es dediada a mostrar el desgloce de datos, entiendasen los atributos del objeto; mientras que la segunda sobrecarga es encargada de mostrar los resultados del area y perimetro respectivamente.
 * 
 */
void Cuadrado::operator ~ (){
	cout << "\n\n=======================" << endl;
	cout << "****Desgloce de datos: Cuadrado****" << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Color: " << this->color << endl;
	cout << "Lado: " << this->lado << endl;
	cout << "=======================" << endl;
}


void Cuadrado::operator ! (){
	cout << "\n\n=======================" << endl;
	cout << "****Desgloce de calculos: Cuadrado****" << endl;
	area();
	perimetro();
	cout << "=======================" << endl;
}

