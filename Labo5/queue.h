/**
 * @file queue.h
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Clase Queue.
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdlib.h>
#include "Lista.h"


using namespace std;

/**	@brief Template Queue
 *
 * Esta clase plantilla posee un constructor y un destructor. Posee un puntero a un objeto de tipo Lista y reimplementa ciertos metodos de Lista.h
 * 
 */

template <typename type> class Queue{
public:
	Queue(){}

	virtual ~Queue(){
		delete queueArray;
	}

	ListaConArreglo<type>* queueArray;		//Puntero a objeto tipo Lista

/**
 * @brief Funcion enQueue
 *
 * Funcion para agregar elementos en una cola, funciona igual que en una lista cualquiera.
 *
 * @param number tipo type, es el elemento que se desea agregar.
 */

	void enQueue(type number){
		queueArray->agregar(number);
	}

/**
 * @brief Funcion deQueue
 *
 * Funcion para eliminar elementos en una cola, siempre se debe retirar el primero que se agrego.
 *
 */

  void deQueue(){
		int first = 0;
		queueArray->eliminarK(first);
  }

/**
 * @brief Funcion size
 *
 * Funcion para que devuelve el tamaño o la cantidad de elementos que hay en la cola.
 *
 */


  int size(){
    return queueArray->tam;
  }

/**
 * @brief Funcion isEmpty
 *
 * Funcion que dice si la cola está vacia.
 *
 */

  bool isEmpty(){
    if (size() == 0){
	   return 1;
	 }
	 else return 0;
  }

  type New(){ 
		return 0;
  }

  void clear(){
		int sizeQueue = size();
		for (int element = 0; element < sizeQueue; element++) {
			queueArray->eliminarK(0);
		}
  }


  void Delete(){
		queueArray->~ListaConArreglo();
	};
};
#endif /* Stack_H */




