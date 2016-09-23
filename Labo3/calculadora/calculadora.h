/**
 * @file calculadora.h
 * @author Brizuela M, Morera B
 * @date 20 Septiembre 2016
 * @brief Plantilla calculadora.
 */

#ifndef CALCULADORA_H
#define CALCULADORA_H


#include <iostream>
#include <stdlib.h>

using namespace std;


/**	@brief Template Calculadora
 *
 * Esta clase plantilla posee un constructor y un destructor, ambos vacio que no reciben parametros.
 * 
 */
template <typename data>
class Calculadora{
public:
	Calculadora(){
	
	}
	
	virtual ~Calculadora(){
	
	}
	
	/**	@brief Funciones de la plantilla
 	*
	* Implementacion de las funciones que retornan un tipo "data", donde en la mayoria revibe como parametros dos objetos tipo "data", uno constante y el otro no.
	* 
	*/
	data add(data &d1, const data &d2){
		return (d1 + d2);
	}

	data sub(data &d1, const data &d2){
		return (d1 - d2);
	}
	
	data mul(data &d1, const data &d2){
		return (d1 * d2);
	}
	
	data div(data &d1, const data &d2){
		return (d1 / d2);
	}
	
	void print(const data &d1){
		cout << "Print :" << d1 << endl;
	}
};
#endif /* CALCULADORA_H */
