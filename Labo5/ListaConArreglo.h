/**
 * @file ListaConArreglo.h
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Clase ListaConArreglo.
 */


#ifndef LISTACONARREGLO_H
#define LISTACONARREGLO_H
#include <iostream>
#include "Lista.h"

/**	@brief Template ListaConArreglo
 *
 * Esta clase plantilla posee un constructor y un destructor. Ademas hereda de Lista.h
 * 
 */

template <typename typeList> class ListaConArreglo : public Lista<typeList> {
public:
  int tam;
  int ultimo;

  ListaConArreglo(){
      data = 0;
      tam = 0;
      ultimo = -1;
  }

  ListaConArreglo(const ListaConArreglo& orig){}

  ~ListaConArreglo(){
			delete data;
}

  ListaConArreglo(int N){
      this->data = new typeList[N];
      tam = N;
      ultimo = tam - 1;
  }

	/**	@brief Funciones de la plantilla
 	*
	* Implementacion de las funciones. agregar() añade un elemento a la lista, eliminarK(int e) retira el elemento "e", recuperar(int k) devuelve el valor en esa posicion 'k'.
	* 
	*/

  void agregar(typeList e){
      if (data == 0) {
          data = new typeList[1];
          tam = 1;
          ultimo = 0;
          data[0] = e;
      } else {
          if (ultimo == tam - 1) {
              typeList* temp = new typeList[tam * 2];
              for (int i = 0; i < tam; i++) {
                  temp[i] = data[i];
              }
              ultimo++;
              tam++;
              temp[ultimo] = e;
              //delete data; // ojo con los deletes
              data = temp;
          } else {
              ultimo++;
              tam++;
              data[ultimo] = e;
          }
      }
  }


  void eliminarK(int k){
      for (int i = k; i < tam - 1; i++) data[i] = data[i + 1];
      tam--;
      ultimo--;
  }


  typeList recuperar(int k){
      return data[k];
  }

  void agregarEnOrdenAscendente(typeList e){}

private:
    typeList* data; //almacenar los elementos
};

#endif /* LISTACONARREGLO_H */
