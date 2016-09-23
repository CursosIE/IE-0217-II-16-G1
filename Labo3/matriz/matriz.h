/**
 * @file matriz.h
 * @author Brizuela M, Morera B
 * @date 20 Septiembre 2016
 * @brief Clase Matriz.
 */

#ifndef MATRIZ_H
#define MATRIZ_H


/**	@brief Clase Matriz
 *
 * Clase posee dos constructores, uno que no posee parametros y otro que recibe dos parametros enteros y un puntero doble; ademas un destructor.
 * 
 */
class Matriz{
public:
	Matriz();
	Matriz(int cantFila, int cantColumna, double **datosMatriz);
	virtual ~Matriz();

	int cantFila;
	int cantColumna;
	double **datosMatriz;


/**	@brief Sobrecarga de operadores.
 *
 * Los operadores a sobrecargar son las cuatro operaciones basicas algebraicas mas un operador de muestra de informacion.
 * 
 */
	Matriz operator+(const Matriz &OtraMatriz);
	Matriz operator-(const Matriz &OtraMatriz);
	Matriz operator*(const Matriz &OtraMatriz);
	Matriz operator/(const Matriz &OtraMatriz);
	void operator~();
	friend std::ostream& operator<<(std::ostream &out,const Matriz &OtraMatriz);
};
#endif /* MATRIZ_H */
