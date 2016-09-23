/**
 * @file matriz.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Implementacion de la clase Matriz.
 */
#include <stdlib.h>
#include <iostream>
#include "matriz.h"

using namespace std;


/**	@brief Constructor default.
 *
 * Constructor vacio, no recibe parametros.
 * 
 */
Matriz::Matriz(){

}

/**	@brief Constructor con parametros.
 *
 * Constructor recive dos enteros y un puntero doble.
 * @param cantFila Entero que representa la cantidad de filas de la matriz.
 * @param cantColumna Entero que representa la cantidad de columnas de la matriz.
 * @param datosMatriz Puntero doble/arrego de 2D, con los datos de la matriz.
 *
 */
Matriz::Matriz(int cantFila, int cantColumna, double **datosMatriz){
	this->cantFila = cantFila;
	this->cantColumna = cantColumna;
	this->datosMatriz = datosMatriz;
	
	for(int i = 0; i < this->cantFila; i++){
		for(int j = 0; j < this->cantColumna; j++){
			this->datosMatriz[i][j] = datosMatriz[i][j];
		}
	}
}

/**	@brief Destructor.
 *
 * Destructor vacio.
 * 
 */
Matriz::~Matriz(){

}


/**	@brief Implementacion de la sobrecarga de operadores.
 *
 * Se implementan la sobrecarga de cada operador antes declarados en matriz.h.
 *
 */
Matriz Matriz::operator+(const Matriz &OtraMatriz){
	if(this->cantFila == OtraMatriz.cantFila && this->cantColumna == OtraMatriz.cantColumna){

		double **ptrDatosNuevaMatriz = new double*[this->cantFila];
		for(int i = 0; i < this->cantFila; i++){
			ptrDatosNuevaMatriz[i] = new double[this->cantColumna];
		}
	
		for(int i = 0; i < this->cantFila; i++){
			for(int j = 0; j < this->cantColumna; j++){
				ptrDatosNuevaMatriz[i][j] = this->datosMatriz[i][j] + OtraMatriz.datosMatriz[i][j];
			}
		}
		
		Matriz MatrizResult(this->cantFila, this->cantColumna, ptrDatosNuevaMatriz);
		return MatrizResult;
	}
	else{
		cout << "Error en la dimension de matrices, no se puede SUMAR" << endl;
	}
	Matriz matrizVacia;
	return matrizVacia;
}

Matriz Matriz::operator-(const Matriz &OtraMatriz){
	if(this->cantFila == OtraMatriz.cantFila && this->cantColumna == OtraMatriz.cantColumna){

		double **ptrDatosNuevaMatriz = new double*[this->cantFila];
		for(int i = 0; i < this->cantFila; i++){
			ptrDatosNuevaMatriz[i] = new double[this->cantColumna];
		}
	
		for(int i = 0; i < this->cantFila; i++){
			for(int j = 0; j < this->cantColumna; j++){
				ptrDatosNuevaMatriz[i][j] = this->datosMatriz[i][j] - OtraMatriz.datosMatriz[i][j];
			}
		}
		
		Matriz MatrizResult(this->cantFila, this->cantColumna, ptrDatosNuevaMatriz);
		return MatrizResult;
	}
	else{
		cout << "Error en la dimension de matrices, no se puede RESTAR" << endl;
	}
	Matriz matrizVacia;
	return matrizVacia;
}

Matriz Matriz::operator*(const Matriz &OtraMatriz){
	if(this->cantFila == OtraMatriz.cantFila && this->cantColumna == OtraMatriz.cantColumna){

		double **ptrDatosNuevaMatriz = new double*[this->cantFila];
		for(int x = 0; x < this->cantFila; x++){
			ptrDatosNuevaMatriz[x] = new double[this->cantColumna];
		}
		
		for(int g = 0; g < this->cantFila; g++){
			for(int f = 0; f < OtraMatriz.cantColumna; f++){
				ptrDatosNuevaMatriz[g][f] = 0.0;
			}
		}
	
		for(int i = 0; i < this->cantFila; i++){
			for(int j = 0; j < OtraMatriz.cantColumna; j++){
				for(int k = 1; k < this->cantColumna; k++){
					ptrDatosNuevaMatriz[i][j] += this->datosMatriz[i][k] * OtraMatriz.datosMatriz[k][j];
				}
			}
		}
		
		Matriz MatrizResult(this->cantFila, this->cantColumna, ptrDatosNuevaMatriz);
		return MatrizResult;
	}
	else{
		cout << "Error en la dimension de matrices, no se puede MULTIPLICAR" << endl;
	}
	Matriz matrizVacia;
	return matrizVacia;
}

Matriz Matriz::operator/(const Matriz &OtraMatriz){
	cout << "Tomar en cuanta que esta division no es matricial..." << endl;
	cout << "Solo se esta dividiendo entrada por entrada...\n" << endl;
	if(this->cantFila == OtraMatriz.cantFila && this->cantColumna == OtraMatriz.cantColumna){

		double **ptrDatosNuevaMatriz = new double*[this->cantFila];
		for(int i = 0; i < this->cantFila; i++){
			ptrDatosNuevaMatriz[i] = new double[this->cantColumna];
		}
	
		for(int i = 0; i < this->cantFila; i++){
			for(int j = 0; j < this->cantColumna; j++){
				ptrDatosNuevaMatriz[i][j] = this->datosMatriz[i][j] / OtraMatriz.datosMatriz[i][j];
			}
		}
		
		Matriz MatrizResult(this->cantFila, this->cantColumna, ptrDatosNuevaMatriz);
		return MatrizResult;
	}
	else{
		cout << "Error en la dimension de matrices, no se puede DIVIDIR" << endl;
	}
	Matriz matrizVacia;
	return matrizVacia;
}

void Matriz::operator~(){
	cout<<"**Imprimiendo Matriz**\n";
	for(int i = 0; i < this->cantFila; i++){
		for(int j = 0; j < this->cantColumna; j++){
			cout << "  " << this->datosMatriz[i][j];
		}
		cout<<"\n";
	}
	cout << "**********************" << endl;
}

ostream& operator<<(ostream &out, const Matriz &OtraMatriz){
	cout << "*****Datos Matriz*****" << endl;
	cout << "Cantidad Filas: " << OtraMatriz.cantFila << endl;
	cout << "Cantidad Columnas: " << OtraMatriz.cantColumna << endl;
	cout << "Entradas: " << endl;
	cout << "\n" << endl;
	
	for(int i = 0; i < OtraMatriz.cantFila; i++){
		for(int j = 0; j < OtraMatriz.cantColumna; j++){
			cout << "A[" << i << "][" << j << "]= " << OtraMatriz.datosMatriz[i][j] << endl;
		}
	}
	cout << "**********************" << endl;
	return out;
}
