/**
 * @file circulo.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Implementacion de la clase derivada Circulo.
 */

#include "circulo.h"

using namespace std;


/**	@brief Constructores y destructor.
 *
 * Se muestra los 2 constructores que posee la clase Circulo, una que recibe parametros atributos y la otra vacia. Al final el destructor.
 * 
 */
Circulo::Circulo(){

}

Circulo::Circulo(double radio){
	this->radio = radio;
}

Circulo::~Circulo(){

}



/**	@brief Implementacion de los metodos (virtuales).
 *
 * Se implementa los metodos para los calculos de areas y perimetros de objetos circulares.
 * 
 */
void Circulo::area(){
	double result = this->radio*this->radio*3.14;
	cout << "Area: " << result << endl;
}

void Circulo::perimetro(){
	double result = 2*3.14*this->radio;
	cout << "Perimetro: " << result << endl;
}



/**	@brief Sobrecarga de operadores
 *
 * La primer sobrecarga es dediada a mostrar el desgloce de datos, entiendasen los atributos del objeto; mientras que la segunda sobrecarga es encargada de mostrar los resultados del area y perimetro respectivamente.
 * 
 */
void Circulo::operator ~ (){
	cout << "\n\n=======================" << endl;
	cout << "****Desgloce de datos: Circulo****" << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Color: " << this->color << endl;
	cout << "Lado: " << this->radio << endl;
	cout << "=======================" << endl;
}


void Circulo::operator ! (){
	cout << "\n\n=======================" << endl;
	cout << "****Desgloce de calculos: Circulo****" << endl;
	area();
	perimetro();
	cout << "=======================" << endl;
}