/**
 * @file main.cpp
 * @author Brizuela M, Morera B
 * @date 21 Octubre 2016
 * @brief Main del proyecto. Implementación del algoritmo kruskal.
 */

#include "kruskal.h"
#include <stdlib.h>     /*atoi*/
#include <iostream>
#include <cstring>

using namespace std;

/**	@brief Funcion Main.
 *
 * Se presenta dos opciones en primer instancia, el Manual de Uso del programa y
 * el utilizar el algoritmo.
 *
 */
int main(int argc, char** argv){

  if( strcmp( argv[1], "-h") == 0 ){
    cout << "\n\n            MANUAL DE USO DE KRUSKAL\n";
    cout << "******Correr programa:\n";
    cout << "Parametros: Numero de vertices del grafo y pesos de las aristas.\n";
    cout << "Para conocer el orden al ingresar los pesos, tomar en cuenta la matriz de adyacencia (ejemplo con 4 vertices):\n\n";
    cout << "./correrKruskal [cantidad vertices del grafo] [peso1] .... [pesoN]\n";
    cout << "Vertices:         A    B   C   D\n";
    cout << "               A  x    x   x   x\n";
    cout << "               B  34   x   x   x\n";
    cout << "               C  46   11  x   x\n";
    cout << "               D  23   12  89  x\n";
    cout << "\n\n";
    cout << "Donde el primer peso '34' es el peso de la arista que conecta los verices 'A' y 'B'.\n";
    cout << "Los parametros se ingresan de la siguiente manera: ./correrGrafico 4 34 46 11 23 12 89\n\n";
  }
  /**	@brief Correr Kruskal.
 *
 * Se debe crear un puntero doble el cual va a ser utilizado en al matriz de adyacencia;
 * se llama al método Kruskal ingresando sus respectivos paramentros.
 *
 */
  else{
    int **ptrMatrizAdyacente = new int*[atoi(argv[1])];
    for(int i = 0; i < atoi(argv[1]); i++){
      ptrMatrizAdyacente[i] = new int[atoi(argv[1])];
    }

    /**
    * kruskal(int cantVertices, int cantArista, char** argv, int** ptrMatrizAdyacente)
    */
    kruskal(atoi(argv[1]), argc - 2, argv, ptrMatrizAdyacente);

    for (int i = 0; i < atoi(argv[1]); i++){
      delete[] ptrMatrizAdyacente[i];
    }
    delete[] ptrMatrizAdyacente;
  }
  return 0;
}
