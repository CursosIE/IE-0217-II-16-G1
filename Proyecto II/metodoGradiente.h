/**
 * @file metodoGradiente.h
 * @author Brizuela M, Morera B, Rojas A.
 * @date 26 Noviembre 2016
 * @brief Headers
 */
void derivarPolinomios(float* derPolI, float* derPolII, float* polinomioI, float* polinomioII, int ordenPol);
void obtenerDirDescenso(int ordenPol, float* dirDescenso, float* ptInicio, float* derPolI, float* derPolII);
float* metodoGradiente(float* polinomioI, float* polinomioII, int ordenPol, float* ptInicio, int maxIter, float* ptMinimo);
void graficar(int ordenPolinomio, float xi, float yi, float xf, float yf, int argc, char const *argv[]);
