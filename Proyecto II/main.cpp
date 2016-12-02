/**
 * @file main.cpp
 * @author Brizuela M, Morera B, Rojas A.
 * @date 26 Noviembre 2016
 * @brief Main del Proyecto
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>   /**atof*/
#include "metodoGradiente.h"

using namespace std;

/**	@brief Funcion main
 *
 * Funcion main.
 * @param argc Entero de la cantidad de parametros recividos por linea de comandos
 * @param argv Puntero doble que contiene los parametros recividos por linea de comandos
 */
int main(int argc, char const *argv[]) {

  int ordenPolinomio = atof(argv[1]) + 1;

  float *ptrPolinomioI = new float[ordenPolinomio];
  float *ptrPolinomioII = new float[ordenPolinomio];
  int contadorPriPol = 2;
  int contadorSegPol = 0;
  float *ptInicio = new float[2];
  float *ptMinimo = new float[2];
  int maxK;

  for (int valor = 0; valor < ordenPolinomio; valor++) {
    ptrPolinomioI[valor] = atof(argv[valor + 2]);
    contadorPriPol++;
  }

  for (int valor = contadorPriPol; valor < contadorPriPol + ordenPolinomio; valor++) {
    ptrPolinomioII[contadorSegPol] = atof(argv[valor]);
    contadorSegPol++;
  }

  ptInicio[0] = atof(argv[contadorPriPol + ordenPolinomio]);
  ptInicio[1] = atof(argv[contadorPriPol + ordenPolinomio + 1]);
  maxK = atof(argv[contadorPriPol + ordenPolinomio + 2]) - 1;
  ptMinimo[0] = atof(argv[contadorPriPol + ordenPolinomio + 3]);
  ptMinimo[1] = atof(argv[contadorPriPol + ordenPolinomio + 4]);

  float xinicialgraf = ptInicio[0];
  float yinicialgraf = ptInicio[1];

  clock_t t_ini, t_fin;
  t_ini = clock();

  float* puntosFinales = metodoGradiente(ptrPolinomioI, ptrPolinomioII, ordenPolinomio, ptInicio, maxK, ptMinimo);

  t_fin = clock();

  double secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  cout << "\n\n" << endl;
  cout << "Tiempo Ejecucion Metodo Gradiente: " << secs*1000 << " milisegundos" << endl;
  cout << "\n\n" << endl;

  delete ptrPolinomioI;
  delete ptrPolinomioII;
  delete ptInicio;
  delete ptMinimo;

  graficar(ordenPolinomio, xinicialgraf, yinicialgraf, puntosFinales[0], puntosFinales[1], argc, argv);

  return 0;
}
