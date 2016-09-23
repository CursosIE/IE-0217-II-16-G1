/**
 * @file main.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Main del proyecto. Implementacion del template calculadora con las clases fraccion, polinomio y matriz.
 */
#include <cstdlib>
#include <iostream>

#include "fraccion.h"
#include "calculadora.h"
#include "matriz.h"
#include "polinomio.h"


using namespace std;

/**	@brief Funcion Main.
 *
 * En esta funcion se crea calculadoras de varias clases (Fraccion, Polinomio y Matriz), aplicando operaciones algebraicas con sobrecarga de operadores.
 * 
 */
int main(int argc, char** argv) {

	Calculadora<Fraccion> calc;    // el tipo de calculadora puede ser cualquier cosa, int o fracciones
	Fraccion frac1(7,2);
	Fraccion frac2(1,2);
	Fraccion result;
	result = calc.sub(frac1, frac2);
	calc.print(result);
	~frac1;

        Calculadora<Polinomio> calc_poli;
        double array[] = {1,2,1};
        double array1[] = {1,2,1};
        Polinomio polinomio1(array, 3);
        Polinomio polinomio2(array1,3);
        Polinomio Poliadd = calc_poli.add(polinomio1, polinomio2);
        Polinomio Polisub = calc_poli.sub(polinomio1, polinomio2);
        Polinomio Polimul = calc_poli.mul(polinomio1, polinomio2);
        Polinomio Polidiv = calc_poli.div(polinomio1, polinomio2);
        cout<< endl << "Polinomios" << endl;
        ~Poliadd;
        ~Polisub;
        calc_poli.print(Polimul);
        calc_poli.print(Polidiv);
       
	int fila = 2;
	int columna = 2; 
	
	double **ptrDatosMatriz = new double*[fila];
	for(int i = 0; i < fila; i++){
		ptrDatosMatriz[i] = new double[columna];
	}
	
	for(int j = 0; j < fila; j++){
		for(int k = 0; k < columna; k++){
			ptrDatosMatriz[j][k] = 2.0;
		}
	}
	
	Calculadora<Matriz> calc1;
	Matriz mat1(fila,columna,ptrDatosMatriz);
	Matriz mat2(fila,columna,ptrDatosMatriz);
	Matriz mat3;
	mat3 = calc1.mul(mat1, mat2);
	~mat3;
	
	calc1.print(mat3);



	for(int l = 0; l < 2; l++) delete[] ptrDatosMatriz[l];
	delete[] ptrDatosMatriz;
	return 0;
}
