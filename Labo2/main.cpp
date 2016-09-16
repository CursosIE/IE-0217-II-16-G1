/**
 * @file main.cpp
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Main del proyecto.
 */

#include <cstdlib>
#include "figure.h"
#include "circulo.h"
#include "triangulo.h"
#include "cuadrado.h"

using namespace std;


/**	@brief Funcion Main.
 *
 * En esta funcion se crea objetos de las clases derivadas de la clase base Figura; objetos como: circulos, cuadrados y triangulos. Se hace uso de las funciones virtuales de cada objeto de su propia clase y ademas del uso de sobrecargas de operadores.
 * 
 */
int main(int argc, char** argv) {
	Circulo circ(12);
	Triangulo t(4, 4, 4);
	Cuadrado cuad(5);
	
	
	cout << "==========Circulo============" << endl;
	circ.area();
	circ.perimetro();
	cout << "==========Triangulo==========" << endl;
	t.area();
	t.perimetro();
	cout << "==========Cuadrado===========" << endl;
	cuad.area();
	cuad.perimetro();
	cout << "=============================" << endl;
	
	
	Cuadrado cuad2(5);
	cuad2.nombre = "Cuadrado 2";
	cuad2.color = "Azul";
	~ cuad2;
	! cuad2;
	
	Circulo circ2(2);
	circ2.nombre = "Circulo 2";
	circ2.color = "Amarillo";
	~ circ2;
	! circ2;

	return 0;

}