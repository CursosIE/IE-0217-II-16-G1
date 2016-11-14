/**
 * @file grafo.cpp
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Metodos de grafo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "Lista.h"
#include "ListaConArreglo.h"
#include "stack.h"
#include "queue.h"
#include "grafo.h"

using namespace std;

#define MAX 5


/**	@brief Se implementa los verices como struct.
 *
 * Estos contienn un label y visited.
 *
 */
struct Vertex {
   char label;
   bool visited;
};

/**
 * Array de vertices
 *
 */
struct Vertex* lstVertices[MAX];
int vertexCount = 0;

/**	@brief Funcion addVertex
 *
 * Agrega un vertice en la lista de vertices
 *
 */
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;
   vertex->visited = false;
   lstVertices[vertexCount++] = vertex;
}

/**	@brief Funcion addEdge
 *
 * Define que vertices se conectan por medio de aristas.
 * El grafo se implementa en este metodo, por medio de una matriz de adyacencia.
 *
 */
void addEdge(int start,int end, int** adjMatrix) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

/**	@brief Funcion displayVertex
 *
 * Muestra el vertice.
 *
 */
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}


/**	@brief Funcion getAdjUnvisitedVertex
 *
 * Obtiene la posicion del verice que no ha sido visitado.
 *
 */
int getAdjUnvisitedVertex(int vertexIndex, int** adjMatrix) {
   for(int i = 0; i<vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }
   return -1;
}


/**	@brief Funcion depthFistSearch
 *
 * Realiza la busqueda por profundidad. Se vale de la matriz de adyacencia.
 *
 */
void depthFirstSearch(int** adjMatrix) {
  ListaConArreglo<int>* c = new ListaConArreglo<int>(MAX);
  Stack<int>* stack = new Stack<int>();
  stack->pilaConArreglo = c;
   //mark first node as visited
   lstVertices[0]->visited = true;

   displayVertex(0);
   stack->push(0);

   while(!stack->isStackEmpty()) {
      int unvisitedVertex = getAdjUnvisitedVertex(stack->peek(), adjMatrix);
      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         stack->pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         stack->push(unvisitedVertex);
      }
   }
   for(int i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }
   stack->Delete();
}

/**	@brief Funcion depthFistSearch
 *
 * Realiza la busqueda por ancho. Se vale de la matriz de adyacencia.
 *
 */
void breadthFirstSearch(int** adjMatrix) {
  ListaConArreglo<int>* c = new ListaConArreglo<int>(MAX);
  Queue<int>* queue = new Queue<int>();
  queue->queueArray = c;
   //mark first node as visited
   lstVertices[0]->visited = true;
   displayVertex(0);
   queue->insert(0);
   int unvisitedVertex;

   while(!queue->isQueueEmpty()) {
      int tempVertex = queue->removeData();
      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex, adjMatrix)) != -1) {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         queue->insert(unvisitedVertex);
      }
   }
   for(int i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   }
   queue->Delete();
}
