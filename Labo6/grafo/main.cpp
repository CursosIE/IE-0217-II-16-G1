/**
 * @file main.cpp
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Main Laboratorio 6.
 */

#include <iostream>
#include "Lista.h"
#include "ListaConArreglo.h"
#include "stack.h"
#include "queue.h"
#include "grafo.h"

using namespace std;
#define MAX 5

/**	@brief Implementacion del grafo
 *
 * Se implementa el grafo por medio de una matriz de adyacencia, por medio de un puntero doble.
 *
 */
int main() {
  int **adjMatrix = new int*[MAX];
  for(int i = 0; i < MAX; i++){
    adjMatrix[i] = new int[MAX];
  }
/**
 *Se agregan vertices y se definen las aristas.
 */
   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4

   addEdge(0, 1, adjMatrix);    // S - A
   addEdge(0, 2, adjMatrix);    // S - B
   addEdge(0, 3, adjMatrix);    // S - C
   addEdge(1, 4, adjMatrix);    // A - D
   addEdge(2, 4, adjMatrix);    // B - D
   addEdge(3, 4, adjMatrix);    // C - D

/**
 *Se realizan las busquedas.
 */
   printf("Depth First Search: ");
   depthFirstSearch(adjMatrix);
   cout << "\n" << endl;

   printf("\nBreadth First Search: ");
   breadthFirstSearch(adjMatrix);
   cout << "\n" << endl;


   for (int i = 0; i < MAX; i++){
     delete[] adjMatrix[i];
   }
   delete[] adjMatrix;
   return 0;
}
