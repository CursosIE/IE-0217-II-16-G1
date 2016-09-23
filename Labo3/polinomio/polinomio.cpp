/**
 * @file polinomio.cpp
 * @author Brizuela M, Morera B
 * @date 23 Septiembre 2016
 * @brief Implementacion de la clase Polinomio.
 */

#include <stdlib.h>
#include <iostream>
#include "polinomio.h"

using namespace std;

/**	@brief Constructor default.
 *
 * Constructor vacio, no recibe parametros.
 * 
 */

Polinomio::Polinomio(){

}

/**	@brief Constructor con parametros.
 *
 * Constructor recibe dos parámetros, un double* y un entero.
 * @param polinomio Double* de la dirección del arreglo con los coeficientes del polinomio.
 * @param dimension Entero que representa la dimensión del arreglo polinomio.
 *
 */
Polinomio::Polinomio(double* polinomio, int dimension){
    
    this->dimension = dimension;
    this->polinomio = new double[dimension];
    for(int i = 0; i < dimension; i++){
        this->polinomio[i] = polinomio[i];
    }

}

/**	@brief Destructor.
 *
 * Destructor vacio.
 * 
 */
Polinomio::~Polinomio(){

}


/**	@brief Implementacion de la sobrecarga de operadores.
 *
 * Se implementan la sobrecarga de cada operador antes declarados en polinomio.h.
 *
 */

ostream& operator<<(ostream &out, const Polinomio &OtroPolinomio){
          
    for (int i = 0; i< OtroPolinomio.dimension; i++){
        cout << " " << OtroPolinomio.polinomio[i] <<"x^"<< OtroPolinomio.dimension-1-i<< " +";
    }
    cout << " 0" << endl<< "\0";
    
    return out;

}


void Polinomio::operator~(){
    for (int i = 0; i< this->dimension; i++){
        cout << " " << this->polinomio[i] <<"x^"<< this->dimension-1-i;
    }
    cout << endl<< endl;
    

}
Polinomio Polinomio::operator+(const Polinomio &OtroPolinomio){
    int D1 = OtroPolinomio.dimension;
    int D2 = this->dimension;
    int new_dimension;
    if (D2>D1){
        new_dimension = D2;
    }
    else{
        new_dimension = D1;
    }
    
    double result[new_dimension];

    if (D2 > D1){
        for (int j = 0; j < D2 ; j++){
            result[j] = this->polinomio[j];
        }
        for (int i = 0; i<D1; i++ ){
            result[(D2-D1)+i] += OtroPolinomio.polinomio[i];
        }
    }
    else{
        for (int j = 0; j < D1 ; j++){
            result[j] = OtroPolinomio.polinomio[j];
        }
        for (int i = 0; i<D2; i++ ){
            result[(D1-D2)+i] += this->polinomio[i];
        }
        for (int y=0; y< D1; y++){
        }
    }

    return Polinomio(result, new_dimension);
}


Polinomio Polinomio::operator-(const Polinomio &OtroPolinomio){
    int D2 = OtroPolinomio.dimension;
    int D1 = this->dimension;
    int new_dimension;
    if (D2>D1){
        new_dimension = D2;
    }
    else{
        new_dimension = D1;
    }
    
    double result[new_dimension];

    if (D2 > D1){
        for (int j = 0; j < D2 ; j++){
            result[j] = OtroPolinomio.polinomio[j];
            
        }
        for (int i = 0; i<D1; i++ ){
            result[(D2-D1)+i] -= this->polinomio[i];
        }
    }
    else{
        for (int j = 0; j < D1 ; j++){
            result[j] = (-1)*this->polinomio[j];
        }
        for (int i = 0; i<D2; i++ ){
            result[(D1-D2)+i] += OtroPolinomio.polinomio[i];
        }
        for (int y=0; y< D1; y++){
        }
    }

    return Polinomio(result, new_dimension);
}



Polinomio Polinomio::operator*(const Polinomio &OtroPolinomio){
    int new_dimension = this->dimension + OtroPolinomio.dimension-1;
    double result[new_dimension];
    for (int i = 0; i<new_dimension; i++){
        result[i] = 0;
    }
    int x = 0;
    for (int i = 0; i<this->dimension; i++ ){
        for (int j = 0; j< OtroPolinomio.dimension; j++){
            result[j+x] = result[j+x] + this->polinomio[i] * OtroPolinomio.polinomio[j];
        }
        x++;
    }
    return Polinomio(result, new_dimension);
}



Polinomio Polinomio::operator/(const Polinomio &OtroPolinomio){
    
    int new_dim = this->dimension - OtroPolinomio.dimension+1;
    if (new_dim <0){
        double result[1] = {0};
        return Polinomio(result, 1);
    }
    double result[new_dim];
    for (int j = 0; j< new_dim; j++){
        double var = this->polinomio[j]/OtroPolinomio.polinomio[0];
        result[j] = var;
        for (int i = 0; i< dimension; i++){
            this->polinomio[j+i] = this->polinomio[j+i]-var*OtroPolinomio.polinomio[i];
        }
    }
    return Polinomio(result, new_dim);
}

