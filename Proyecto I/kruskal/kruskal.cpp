/**
 * @file kruskal.cpp
 * @author Brizuela M, Morera B
 * @date 21 Octubre 2016
 * @brief Implementacion de la clase Polinomio.
 */

#include <algorithm>    /*sort: O( N*log2 (N) )*/
#include <iostream>
#include <cstdlib>     /*atoi*/
#include <cstdio>
#include "kruskal.h"
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

/** @brief Método createGraph
 * Método dedicado a representar el grafo con una matriz de adyacencia
 * @param char** argv Arreglo de los pesos entre los vertices del grafo.
 * @param int** matrizAdyacencia Puntero doble para crear la matriz cuadrada.
*/
void createGraph(char** argv, int** matrizAdyacencia){
  int peso = 2;
  for(int fila = 1; fila < atoi(argv[1]); fila++){
    for(int columna = 0; columna < fila; columna++){
        matrizAdyacencia[fila][columna] = atoi(argv[peso]);
        peso++;
    }
  }
  for(int fila = 0; fila < atoi(argv[1]); fila++){
    matrizAdyacencia[fila][fila] = 0;
    for(int columna = fila + 1; columna < atoi(argv[1]); columna++){
        matrizAdyacencia[fila][columna] = 0;
    }
  }
}

/**	@brief Método verticeInicio
 *
 * El objetivo de este Método es encontrar el vertice de inicio de una arista especifica.
 * Por convencion, las aristas inician con el vértice fila de la matriz.
 * @param int pesoBuscado Arista a buscar su punto de inicio.
 * @param int** matrizAdyacencia Matriz que representa le grafo.
 * @param int ordenMatriz Orden de la matriz de adyacencia.
 *
 */
int verticeInicio(int pesoBuscado, int** matrizAdyacencia, int ordenMatriz){
  for(int fila = 1; fila < ordenMatriz; fila++){
    for(int columna = 0; columna < fila; columna++){
      if (matrizAdyacencia[fila][columna] == pesoBuscado) return fila; }
  }
  return 0;
}

/**	@brief Método verticeFinal
 *
 * El objetivo de este Método es encontrar el vertice donde terminauna arista especifica.
 * Por convencion, las aristas terminan con el vértice columna de la matriz.
 * @param int pesoBuscado Arista a buscar su punto final.
 * @param int** matrizAdyacencia Matriz que representa le grafo.
 * @param int ordenMatriz Orden de la matriz de adyacencia.
 *
 */
int verticeFinal(int pesoBuscado, int** matrizAdyacencia, int ordenMatriz){
  for(int fila = 1; fila < ordenMatriz; fila++){
    for(int columna = 0; columna < fila; columna++){
      if (matrizAdyacencia[fila][columna] == pesoBuscado){
        matrizAdyacencia[fila][columna] = 0;
        return columna;
      }
    }
  }
  return 0;
}

/**	@brief Método MakeSet
 *
 * Método que inicializa la estructura conjuntos disjuntos. Nombra el vértice padre
 * de cada vertice como él mismo.
 * @param int numVertices Cantidad de vertices en el grafo.
 * @param int padre[] Arreglo donde indica el padre de cada vertice.
 *
 */
void MakeSet(int numVertices, int padre[]) {
  for(int vertice = 0; vertice < numVertices; ++vertice) padre[vertice] = vertice;
}

/**	@brief Método Find
 *
 * Método recursivo, encuentra el padre de un vértice.
 * @param int vertice Vertice a encontrar el padre.
 * @param int padre[] Arreglo que indica el padre de cada vértice.
 *
 */
int Find(int vertice, int padre[]){
  if(vertice == padre[vertice]) return vertice;
  else return Find(padre[vertice], padre);
  return 0;
}

/**	@brief Método sameConjunt
 *
 * Verifica si dos vértices pertencen a un mismo conjunto. Recibe dos int y un
 * int[] y retorna un bool. Hace uso del método Find.
 * @param int verticePrimero Primer vértice a comprobar.
 * @param int verticeSegundo Segundo vértice a comprobar, contra el primero.
 * @param int padre[] Arreglo que indica el padre de cada vértice.
 *
 */
bool sameConjunt(int verticePrimero, int verticeSegundo, int padre[]){
  if(Find(verticePrimero, padre) == Find(verticeSegundo, padre)) return true;
  return false;
}

/**	@brief Método Union
 *
 * Encargado de unir dos conjuntos de vértices. Hace uso del método Find para
 * unir los padres del conjunto.
 * @param int verticePrimero Primer vértice a unir.
 * @param int verticeSegundo Segundo vértice a unir con el primero.
 * @param int padre[] Arreglo que indica el padre de cada vértice.
 *
 */
void Union(int verticePrimero, int verticeSegundo, int padre[]){
  int verticePrimeroRaiz = Find(verticePrimero, padre);
  int verticeSegundoRaiz = Find(verticeSegundo, padre);
  padre[verticePrimeroRaiz] = verticeSegundoRaiz;
}

/**	@brief Método itoa
 *
 * Convierte un valor tipo int a uno tipo char. Este metodo no es requerido para
 * emplear el algoritmo, sólo
 * @param int n Valor a convertir.
 *
 */
string itoa(int n){
  stringstream ss;
  string s;
  ss << n;
  ss >> s;
  return s;
}

/**	@brief Método kruskal
 *
 * Método del algoritmo kruskal.
 * @param int cantVertices Cantidad de vertices del grafo.
 * @param int cantArista Cantidad de aristas entre los vértices del grafo.
 * @param int** matrizAdyacencia Puntero a la matriz de adyacencia.
 * @param char** argv Arreglo de los pesos del grafo.
 */
int kruskal(int cantVertices, int cantArista, char** argv, int** matrizAdyacencia){
  ofstream fs("kruskal/confTxt/pesosKruskal.txt");
  clock_t t_ini, t_fin;
  createGraph(argv, matrizAdyacencia);
  t_ini = clock();   /*La medición del tiempo de ejecución inicia en este punto*/

  /**
   * Se crean arreglos para inicializar la estructura union-find y demas variables
   */
  int padreVertice[cantVertices], aristaActual, verticeEntrada, verticeSalida;
  int aristasNoNulas = 0;
  int countPesoArista = 0;
  int countDireccionArbol = 0;
  int countAristasArbolMinimo = 0;

  for(int i = 0; i < cantArista; i++){
    if(atoi(argv[2 + i]) != 0) aristasNoNulas++;  /*Se cuentan las aristas validas*/
  }

  /**
   * Se crean arreglos sólo tomando en cuenta las aristas, entiendase se desprecian
   * los valores nulos de la matriz de adyacencia.
   */
  int pesosAristas[aristasNoNulas];
  int arbolExpansionMinima[aristasNoNulas];
  int direccionArbol[2*aristasNoNulas];

  for (int i = 0; i < cantArista; i++) {
    if (atoi(argv[2 + i]) != 0) {
      pesosAristas[countPesoArista] = atoi(argv[2 + i]);
      countPesoArista++;
    }
  }

  sort(pesosAristas, pesosAristas + aristasNoNulas);
  MakeSet(cantVertices, padreVertice);

  /**Para cada arista E que une los vertices U y V
   */
  for (int arista = 0; arista < aristasNoNulas; arista++) {
    aristaActual = pesosAristas[arista];
    if(aristaActual == 0) continue;
    /**Puntos U y V
     */
    verticeEntrada = verticeInicio(aristaActual, matrizAdyacencia, atoi(argv[1]));
    verticeSalida = verticeFinal(aristaActual, matrizAdyacencia, atoi(argv[1]));
    /**Si los puntos U y V no estan en la misma componente, evitar ciclos cerrados
     */
    if (not sameConjunt(verticeEntrada, verticeSalida, padreVertice)) {
      /**Agregar arista E al MST y se realiza la union de U y V
       */
      arbolExpansionMinima[arista] = aristaActual;
      countAristasArbolMinimo++;
      direccionArbol[countDireccionArbol] = verticeEntrada;
      direccionArbol[countDireccionArbol + 1] = verticeSalida;
      countDireccionArbol = countDireccionArbol + 2;
      Union(verticeEntrada, verticeSalida, padreVertice);
    }
    /**Para que no halla datos aleatorios si una arista no es tomada en cuenta
     */
    else arbolExpansionMinima[arista] = 0;
  }
	t_fin = clock();   /*La medición del tiempo de ejecución termina en este punto*/

  /** Se preparan las salidas tanto en la terminal como escrito en un
  * archivo para la interfaz grafica.
  */
  for(int i = 0; i<aristasNoNulas; i++){
    fs << itoa(arbolExpansionMinima[i]);
    fs << " ";
  }
  fs.close();

  int countPrintDirArb = 0;
  cout << "\n\n" << endl;
  cout << "       *************************************************" << endl;
  cout << "       *               Trayectoria Mínima:             *" << endl;
  cout << "       *************************************************" << endl;
  for(int i = 0; i < aristasNoNulas; i++){
    if(arbolExpansionMinima[i] != 0){
      cout << "          Vértice " << direccionArbol[countPrintDirArb] << " --> " << "Vértice " << direccionArbol[countPrintDirArb+1] << " : Peso arista " << arbolExpansionMinima[i] <<endl;
      countPrintDirArb = countPrintDirArb + 2;
    }
  }
  cout << "       *************************************************" << endl;

  double secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  cout << "Tiempo Ejecucion Kruskal: " << secs*1000 << " milisegundos" << endl;
  cout << "\n\n" << endl;

  return 0;
}
