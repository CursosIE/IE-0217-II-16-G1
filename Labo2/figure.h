/**
 * @file figure.h
 * @author Brizuela M, Morera B
 * @date 11 Septiembre 2016
 * @brief Se presenta la clase base de figuras geometricas.
 */

#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <stdlib.h>

using namespace std;


/**
 * @brief Clase Figura
 *
 * Clase base, posee como solamente 2 atributos: nombre y color; ademas de 2 funciones virtuales, las cuales son area y perimetro.
 * Esta clase tiene 2 constructores, uno vacio (no recibe parametros) por default y el otro el caul recibe los atributos de las figuras en general.
 */
class Figura{
public:
	Figura(); /**< Constructor default */
	Figura(string nombre, string color);
	virtual ~Figura();

	string nombre; /**< Atributo */
	string color;

	virtual void area(); /**< Metodo virtual */
	virtual void perimetro();
};


#endif /* FIGURE_H */