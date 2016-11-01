/**
 * @file carta.h
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Clase Carta.
 */

#ifndef Carta_H
#define Carta_H

/**	@brief Clase Carta
 *
 * Clase posee dos constructores, uno que no posee parametros y otro que recibe como parametro el valor de la carta asignada; ademas un destructor.
 *
 */
class Carta{
public:

    Carta();
    Carta(int valorCarta);
    virtual ~Carta();

    int valorCarta;
};
#endif /* Carta_H */
