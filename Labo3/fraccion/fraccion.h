/**
 * @file fraccion.h
 * @author Brizuela M, Morera B
 * @date 20 Septiembre 2016
 * @brief Clase Fraccion.
 */
#ifndef FRACCION_H
#define FRACCION_H

/**	@brief Clase Fraccion
 *
 * Clase posee dos constructores, uno que no posee parametros y otro que recibe dos parametros enteros; ademas un destructor.
 * 
 */
class Fraccion{
public:
	Fraccion();
	Fraccion(int num, int den);
	virtual ~Fraccion();
	
	int num;
	int den;

/**	@brief Sobrecarga de operadores.
 *
 * Los operadores a sobrecargar son las cuatro operaciones basicas algebraicas mas un operador de muestra de informacion.
 * 
 */
	Fraccion operator+(const Fraccion &OtraFraccion);
	Fraccion operator-(const Fraccion &OtraFraccion);
	Fraccion operator*(const Fraccion &OtraFraccion);
	Fraccion operator/(const Fraccion &OtraFraccion);
	void operator~();
	friend std::ostream& operator<<(std::ostream &out,const Fraccion &OtraFraccion);

};
#endif /* FRACCION_H */