/**
 * @file polinomio.h
 * @author Brizuela M, Morera B
 * @date 23 Septiembre 2016
 * @brief Clase Polinomio.
 */

#ifndef POLINOMIO_H
#define POLINOMIO_H

/**	@brief Clase Polinomio
 *
 * Clase posee dos constructores, uno que no posee parametros y otro que recibe dos parametros; ademas un destructor.
 * 
 */
class Polinomio{
public:
   int dimension;
   double* polinomio;
	Polinomio();
	Polinomio(double* polinomio, int dimension);
	virtual ~Polinomio();
	
/**	@brief Sobrecarga de operadores.
 *
 * Los operadores a sobrecargar son las cuatro operaciones basicas algebraicas mas un operador de muestra de informacion.
 * 
 */
	Polinomio operator+(const Polinomio &OtroPolinomio);
	Polinomio operator-(const Polinomio &OtroPolinomio);
	Polinomio operator*(const Polinomio &OtroPolinomio);
	Polinomio operator/(const Polinomio &OtroPolinomio);
        void operator~();
	friend std::ostream& operator<<(std::ostream &out,const Polinomio &OtroPolinomio);

};

#endif /* POLINOMIO_H */

