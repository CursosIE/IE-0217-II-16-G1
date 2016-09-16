/**
 * @file triangulo.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Implementacion de la clase derivada Triangulo.
 */

#include "triangulo.h"
#include <cmath>

using namespace std;



/**	@brief Constructores y destructor.
 *
 * Se muestra los 2 constructores que posee la clase Triangulo, una que recibe parametros atributos y la otra vacia. Al final el destructor.
 * 
 */
Triangulo::Triangulo(){

}

Triangulo::Triangulo(double lado1, double lado2, double lado3){
	this->lado1 = lado1;
	this->lado2 = lado2;
	this->lado3 = lado3;

}

Triangulo::~Triangulo(){

}



/**	@brief Implementacion de los metodos (virtuales).
 *
 * Se implementa los metodos para los calculos de areas y perimetros de objetos triangulares.
 * 
 */
void Triangulo::area(){
	/*Obtencion del semiperimetro*/
	double s = (this->lado1+this->lado2+this->lado3)*0.5;
	double altura = ((2)/(this->lado1))*sqrt(s*(s-this->lado1)*(s-this->lado2)*(s-this->lado3));
	double base = this->lado1;
	double result = base*altura*0.5;
	cout << "Area: " << result << endl;
}

void Triangulo::perimetro(){
	double result = this->lado1 + this->lado2 + this->lado3;
	cout << "Perimetro: " << result << endl;
}



/**	@brief Sobrecarga de operadores
 *
 * La primer sobrecarga es dediada a mostrar el desgloce de datos, entiendasen los atributos del objeto; mientras que la segunda sobrecarga es encargada de mostrar los resultados del area y perimetro respectivamente.
 * 
 */
void Triangulo::operator ~ (){
	cout << "\n\n=======================" << endl;
	cout << "****Desgloce de datos: Triangulo****" << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Color: " << this->color << endl;
	cout << "Lado1: " << this->lado1 << endl;
	cout << "Lado2: " << this->lado2 << endl;
	cout << "Lado3: " << this->lado3 << endl;		
	cout << "=======================" << endl;
}


void Triangulo::operator ! (){
	cout << "\n\n=======================" << endl;
	cout << "****Desgloce de calculos: Triangulo****" << endl;
	area();
	perimetro();
	cout << "=======================" << endl;
}
