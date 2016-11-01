/**
 * @file Lista.h
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Clase Lista.
 */

#ifndef LISTA_H
#define LISTA_H

/**	@brief Template Lista
 *
 * Esta clase plantilla posee un constructor y un destructor y varios metodos.
 * 
 */

template <typename typeList> class Lista { //lista de typeLists
public:
    Lista(){}
    Lista(const Lista& orig){}
    virtual ~Lista(){}

    virtual void agregar(typeList e) = 0;
    virtual void agregarEnOrdenAscendente(typeList e) = 0;
    virtual void eliminarK(int k) = 0;

    virtual typeList recuperar(int k) = 0;
};
#endif /* LISTA_H */
