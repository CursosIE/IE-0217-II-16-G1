/**
 * @file metodoGradiente.cpp
 * @author Brizuela M, Morera B, Rojas A.
 * @date 26 Noviembre 2016
 * @brief Funciones implementadas.
 */

#include <iostream>
#include <stdlib.h>   /*atof*/
#include <math.h>     /*pow*/
#include <fstream>
#include <cstdlib>
#include "metodoGradiente.h"

using namespace std;

/**	@brief Funcion derivarPolinomios
 *
 * Deriva funciones tipo polinomios de orden "n". No retorna algun tipo, guarda los cambios en un puntero tipo float.
 * @param derPolI Puntero float donde se guarda la derivada del polinomio I
 * @param derPolII Puntero float donde se guarda la derivada del polinomio II
 * @param polinomioI Puntero float con los coeficientes del polinomio I
 * @param polinomioII Puntero float con los coeficientes del polinomio II
 * @parm ordenPol Entero del orden de los polinomios a derivar.
 */
void derivarPolinomios(float* derPolI, float* derPolII, float* polinomioI, float* polinomioII, int ordenPol){
  for (int valor = 0; valor < ordenPol; valor++) {
    derPolI[valor] = (valor + 1)*polinomioI[valor + 1];
    derPolII[valor] = (valor + 1)*polinomioII[valor + 1];
  }
}

/**	@brief Funcion obtenerDirDescenso
 *
 * Funcion dedicada a obtener el punto de avance, el punto X_k+1. No retorna ningun tipo de dato, guarda el cambio en un puntero float
 * @parm ordenPol Entero del orden de los polinomios a derivar.
 * @param dirDescenso Puntero float donde se guarda el siguiente punto de avance, el punto de descenso
 * @param ptInicio Puntero float que posee el punto de la funcion donde se encuentra actualmente, es el punto X_k
 * @param derPolI Puntero float con los coeficientes de la derivada de la funcion I
 * @param derPolII Puntero float con los coeficientes de la derivada de la funcion II
 */
void obtenerDirDescenso(int ordenPol, float* dirDescenso, float* ptInicio, float* derPolI, float* derPolII){
  //Se inicia con una direccion de cero
  dirDescenso[0] = 0.0;
  dirDescenso[1] = 0.0;
  for (int x = 0; x < ordenPol-1; x++) {
    dirDescenso[0] += pow(ptInicio[0],x)*derPolI[x];
    dirDescenso[1] += pow(ptInicio[1],x)*derPolII[x];
  }
  //Se multiplica por un negativo
  dirDescenso[0] = -1*dirDescenso[0];
  dirDescenso[1] = -1*dirDescenso[1];
}

/**	@brief Funcion metodoGradiente
 *
 * Funcion que implementa el metodo de Gauss, obtencion del punto de solucion de la funcion, el punto minimo. Retorna un puntero float con la solucion encontrada.
 * @param polinomioI Puntero float con los coeficientes del polinomio I
 * @param polinomioII Puntero float con los coeficientes del polinomio II
 * @parm ordenPol Entero del orden de los polinomios a derivar.
 * @param ptInicio Puntero float que posee el punto de la funcion donde se encuentra actualmente, es el punto X_k
 * @param maxIter Entero de la maxima cantidad de iteraciones permitidas.
 * @param ptMinimo Puntero float con la solucion real de la funcion dada, el punto minimo de la funcion.
 */
float* metodoGradiente(float* polinomioI, float* polinomioII, int ordenPol, float* ptInicio, int maxIter, float* ptMinimo){
  int iter = 0;
  bool minEncontrado = false;
  float pasoDescenso = 0.0;
  float *derPolI = new float[ordenPol - 1];
  float *derPolII = new float[ordenPol - 1];
  float *dirDescenso = new float[2];
  float *dirDescensoTest = new float[2];
  float *ptPasoInicio = new float[2];

  /**Se deriva los polinomios
  */
  derivarPolinomios(derPolI, derPolII, polinomioI, polinomioII, ordenPol);

  ofstream puntos;
  puntos.open("puntos.txt"); /*!< Se genera el archivo con los puntos a ser graficados junto a la funcion objetivo. */

  float xgraf,ygraf,z;

  while( iter != maxIter && !minEncontrado) {
    iter++;

    /**  Se obtienen los puntos "x", "y" y "z" para ser ingresados en el archivo de texto puntos.txt 
     *   a partir del cual se va a generar la grafica de los mismos.
     */
    z = 0.0;
    for(int i=0;i<ordenPol;i++){
        z = z + polinomioI[i]*pow(ptInicio[0],i);
    }
    for(int i=0;i<ordenPol;i++){
        z = z + polinomioII[i]*pow(ptInicio[1],i);
    }

    xgraf = ptInicio[0];
    ygraf = ptInicio[1];

    /**Se obtiene el punto a descender, los valores se guardan en el puntero dirDescenso
    */
    obtenerDirDescenso(ordenPol, dirDescenso, ptInicio, derPolI, derPolII);

    pasoDescenso += 0.1;
    /**Se realiza un paso
    */
    ptPasoInicio[0] = ptInicio[0] + pasoDescenso*dirDescenso[0];    //X_k+1
    ptPasoInicio[1] = ptInicio[1] + pasoDescenso*dirDescenso[1];
    ptInicio[0] = ptPasoInicio[0];
    ptInicio[1] = ptPasoInicio[1];

    /**Se comprueba que la pendiente sea cero
    */
    obtenerDirDescenso(ordenPol, dirDescensoTest, ptInicio, derPolI, derPolII);
    if ( dirDescensoTest[0] == 0.0 && dirDescensoTest[1] == 0.0 ){
      minEncontrado = true;
      cout << "Condicion parada: pendiente cero" << endl;
      cout << "Cantidad de iteraciones: " << iter << endl;
    }else{
      puntos << xgraf << " " << ygraf << " " << z << endl; /*!< Se ingresan los resultados en formato "x y z" al archivo puntos.txt */
    }
  }

  if (!minEncontrado) {
    cout << "Condicion parada: maxima iteracion" << endl;
  }
  puntos.close();

  /**Se guarda el resultado del punto fianl en formato "x y z" en el archivo puntoFinal.txt
    */
  ofstream puntoFinal;
  puntoFinal.open("puntoFinal.txt");
  puntoFinal << xgraf << " " << ygraf << " " << z << endl;
  puntoFinal.close();

  cout << "Punto Solucion ABSOLUTO: " << ptMinimo[0] << ", " << ptMinimo[1] << endl;
  cout << "Punto Solucion ENCONTRADO: " << ptPasoInicio[0] << ", " << ptPasoInicio[1] << endl;
  cout << "Diferencia entre los puntos: " << sqrt(pow(ptMinimo[0]-ptPasoInicio[0],2) + pow(ptMinimo[1]-ptPasoInicio[1],2)) << endl;
  delete derPolI;
  delete derPolII;
  delete dirDescenso;
  delete dirDescensoTest;

  return ptPasoInicio;
}

/** @brief Funcion graficar
 *
 *  Funcion se dedica a generar las salidas graficas. Los parametros corresponden al orden de los polinomios que conforman la funcion, el punto inicial en coordenadas (x,y), el punto final en coordenadas (x,y), y los parametros originales ingresados junto con el programa al ejecutarlo, mediante los parametros argc y el vector argv. Ejecuta el archivo .gnp generado con harramienta GNUPlot llamada desde C++ con el comando "system".
 *
 * @param ordenPolinomio Entero con el orden de los polinomio que conforman la funcion.
 * @param xi Float correpondiente a la coordenada x del punto inicial.
 * @param yi Float correpondiente a la coordenada y del punto inicial.
 * @param xf Float correpondiente a la coordenada x del punto final obtenido por el metodo gradiente.
 * @param yf Float correpondiente a la coordenada y del punto final obtenido por el metodo gradiente.
 * @param argc Entero con el numero de parametros ingresados originalmente al ejecutar el progama.
 * @param argv Puntero al arreglo con los parametros ingresados originalmente al ejecutar el programa. De aqui se toman los coeficientes de los polinomios que generan la funcion objetivo.
 */
void graficar(int ordenPolinomio, float xi, float yi, float xf, float yf, int argc, char const *argv[]){
  float limsupx,liminfx,limsupy,liminfy;

  /**  Se obtienen los extremos de graficacion para GNUPlot de acuerdo a los resultados obtenidos de manera que la perspectiva de los mismos 
   *   sea eficiente. Para esto se consideran el punto inicial ingresado por el usuario y el punto final devuelto por el metodo gradiente.
   */
  if (xi > xf){
    limsupx = xi+1;
    liminfx = xf-1;
  }
  else{
    limsupx = xf+1;
    liminfx = xi-1;
  }

  if (yi > yf){
    limsupy = yi+1;
    liminfy = yf-1;
  }
  else{
    limsupy = yf+1;
    liminfy = yi-1;
  }

  /**  Se configura el archivo .gnp de acuerdo a los limites de graficacion para que grafique los puntos obtenidos en cada iteracion por el
   *   metodo gradiente, el punto final y la funcion objetivo. Ademas se obtiene el resultado en una imagen gnp.
   */
  ofstream out;
  out.open("salida.gnp");
  out<<"f(x,y)=";
  for(int i=0;i<ordenPolinomio;i++){
    int este = atof(argv[i+2]);
    out<<este<<"*x**"<<i<<"+";
  }
  for(int i=0;i<ordenPolinomio;i++){
    int este = atof(argv[i+2+ordenPolinomio]);
    out<<este<<"*y**"<<i<<"+";
  }
  out<<"0;"<<endl;

  out << "splot [" << liminfx << ":" << limsupx << "][" << liminfy << ":" << limsupy << "] f(x,y), 'puntos.txt' w p lt 7 ps 1, 'puntoFinal.txt' w p lt 20 ps 1;" //20
  << " \n pause mouse \n pause mouse \n pause mouse \n pause mouse \n pause mouse"
  << " \n pause mouse \n pause mouse \n pause mouse \n pause mouse \n pause mouse"
  << " \n pause mouse \n pause mouse \n pause mouse \n pause mouse \n pause mouse"
  << " \n pause mouse \n pause mouse \n pause mouse \n pause mouse \n pause mouse"<<endl;
  out<<"set term png"<<endl;
  out<<"set output 'salida.png'"<<endl;
  out<<"replot"<<endl;
  system("gnuplot salida.gnp"); /*!< Para llamar a la herramienta GNUPlot se utiliza el comando system */
  out.close();
}
