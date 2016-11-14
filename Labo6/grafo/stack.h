/**
 * @file queue.h
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Clase Stack.
 */

#ifndef Stack_H
#define Stack_H

#include <iostream>
#include <stdlib.h>
#include "Lista.h"

using namespace std;

/**	@brief Template Stack
 *
 * Esta clase plantilla posee un constructor y un destructor. Posee un puntero a un objeto de tipo Lista y reimplementa ciertos metodos de Lista.h
 *
 */

template <typename typeStack> class Stack{
public:
	Stack(){}

	ListaConArreglo<typeStack>* pilaConArreglo;		//Puntero a objeto tipo Lista

	virtual ~Stack(){
		delete pilaConArreglo;
	}

/**
 * @brief Funcion push
 *
 * Funcion para agregar elementos en una cola, funciona igual que en una lista cualquiera.
 *
 * @param number tipo typeStack, es el elemento que se desea agregar.
 */

	void push(typeStack number){
		pilaConArreglo->agregar(number);
	}

/**
 * @brief Funcion pop
 *
 * Funcion para eliminar elementos en una pila, siempre se debe retirar el ultimo que se agrego.
 *
 */

  void pop(){
		int ultimoStack = pilaConArreglo->ultimo;
		typeStack elemetPop = pilaConArreglo->recuperar(ultimoStack);
		pilaConArreglo->eliminarK(ultimoStack);
  }

	typeStack peek(){
		int ultimoStack = pilaConArreglo->ultimo;
		typeStack elemetPop = pilaConArreglo->recuperar(ultimoStack);
		return elemetPop;
	}

/**
 * @brief Funcion size
 *
 * Funcion para que devuelve el tamaño o la cantidad de elementos que hay en la pila.
 *
 */

	int size(){
		return pilaConArreglo->tam;
  }

/**
 * @brief Funcion isEmpty
 *
 * Funcion que dice si la pila está vacia.
 *
 */

  bool isStackEmpty(){
		if (pilaConArreglo->tam == 0) return true;
		else return false;
  }


  void clear(){
		int sizeStack = size();
		for (int element = 0; element < sizeStack; element++) {
			pilaConArreglo->eliminarK(0);
		}
  }

  void Delete(){
		pilaConArreglo->~ListaConArreglo();
	};
};
#endif /* Stack_H */
