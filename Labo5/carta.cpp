/**
 * @file carta.cpp
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Implementacion Clase Carta.
 */


#include "carta.h"
/**	@brief Constructor default.
 *
 * Constructor vacio, no recibe parametros.
 * 
 */
Carta::Carta(){}
/**	@brief Constructor con un parametro.
 *
 * Constructor recibe un enteros.
 * @param valorCarta Entero que representa el valor de la carta.
 *
 */
Carta::Carta(int valorCarta){
  this->valorCarta = valorCarta;
}

Carta::~Carta(){}
