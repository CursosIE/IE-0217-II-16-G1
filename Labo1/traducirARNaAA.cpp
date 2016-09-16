/**
 * @file traducirARNaAA.cpp
 * @author Brizuela M, Morera B
 * @date 2 Septiembre 2016
 * @brief Este programa traduce una cadena ARN a AA
 */

#include <iostream>
#include <string.h>

using namespace std;

int traducirARNaAA(int argc, char *ARN);
int main(int argc, char **argv);
int verificarCodon(char** ARN, int size);

/**
 * @brief Funcion traducirARNaAA
 *
 * Funcion encargada de traducir la secuencia ARN a AA.
 *
 * @param argc tipo entero, cantidad de elementos.
 * @param ARN char*, que contiene un conjunto de tres bases nitrogenadas (A, G, C, U).
 * @return Aminoácido correspondiente al ARN recibido.
 */

int traducirARNaAA(int argc, char *ARN){
	char AA;
	switch(ARN[0]){
		case 'U':
			switch(ARN[1]){
				case 'U':
					switch(ARN[2]){
						case 'U':
							AA = 'F';
							return AA;
						case 'C':
							AA = 'F';
							return AA;
						case 'A':
							AA = 'L';
							return AA;
						case 'G':
							AA = 'L';
							return AA;
					}
				case 'C':
					AA = 'S';
					return AA;
				case 'A':
					switch(ARN[2]){
						case 'U':
							AA = 'Y';
							return AA;
						case 'C':
							AA = 'Y';
							return AA;
					}
				case 'G':
					switch(ARN[2]){
						case 'U':
							AA = 'C';
							return AA;
						case 'C':
							AA = 'C';
							return AA;
						case 'G':
							AA = 'W';
							return AA;
					}
			}
		case 'C':
			switch(ARN[1]){
				case 'U':
					AA = 'L';
					return AA;
				case 'C':
					AA = 'P';
					return AA;
				case 'A':
					switch(ARN[2]){
						case 'U':
							AA = 'H';
							return AA;
						case 'C':
							AA = 'H';
							return AA;
						case 'A':
							AA = 'Q';
							return AA;
						case 'G':
							AA = 'Q';
							return AA;
					}
				case 'G':
					AA = 'R';
					return AA;
			}
		case 'A':
			switch(ARN[1]){
				case 'U':
					switch(ARN[2]){
						case 'U':
							AA = 'I';
							return AA;
						case 'C':
							AA = 'I';
							return AA;
						case 'A':
							AA = 'I';
							return AA;
						case 'G':
							AA = 'M';
							return AA;
					}
				case 'C':
					AA = 'T';
					return AA;
				case 'A':
					switch(ARN[2]){
						case 'U':
							AA = 'N';
							return AA;
						case 'C':
							AA = 'N';
							return AA;
						case 'A':
							AA = 'K';
							return AA;
						case 'G':
							AA = 'K';
							return AA;
					}
				case 'G':
					switch(ARN[2]){
						case 'U':
							AA = 'S';
							return AA;
						case 'C':
							AA = 'S';
							return AA;
						case 'A':
							AA = 'R';
							return AA;
						case 'G':
							AA = 'R';
							return AA;
					}
			}
		case 'G':
			switch(ARN[1]){
				case 'U':
					AA = 'V';
					return AA;
				case 'C':
					AA = 'A';
					return AA;
				case 'A':
					switch(ARN[2]){
						case 'U':
							AA = 'D';
							return AA;
						case 'C':
							AA = 'D';
							return AA;
						case 'A':
							AA = 'R';
							return AA;
						case 'G':
							AA = 'R';
							return AA;
					}
				case 'G':
					AA = 'G';
					return AA;
			}
	}
	AA = 'E';
	return AA;
}

/**
 * @brief Funcion verificarCodon
 *
 * Funcion encargada de verificar si la secuencia inicia y termina con codones de parada.
 *
 * @param ARN tipo char**, contiene la secuencia ARN total.
 * @param size tipo entero, contiene el tamaño de la secuencia.
 * @return retorna cero si cumple la condicion de codones de parada, de lo contrario retorna uno.
 */

int verificarCodon(char** ARN, int size){
	int first = 0;
	int last = 0;
	if (ARN[1][0] == 'U'){
		if (ARN[1][1] == 'A' || ARN[1][1] == 'G'){
			if (ARN[1][2] == 'A'){
				first = 1;
			}
		}
		if (ARN[1][1] == 'A' && ARN[1][2] == 'G'){
			first = 1;
		}
	}
	if (ARN[1][size-3] == 'U'){
		if (ARN[1][size-2] == 'A' || ARN[1][size-2] == 'G'){
			if (ARN[1][size-1] == 'A'){
				last = 1;
			}
		}
		if (ARN[1][size-2] == 'A' && ARN[1][size-1] == 'G'){
			last = 1;
		}
	}
	if (first == 1 && last == 1){
		return 0;
	}
	return 1;
}

/**
 * @brief Funcion main
 *
 * Funcion recibe dos parámetros.
 *
 * @param argc Contiene el numero de argumentos que se han introducido.
 * @param argv Array de punteros a caracteres.
 */

int main(int argc, char **argv){

	char resultMoment;
	int count = 0;
	int total = strlen(argv[1])-5;
	int AAtotal = strlen(argv[1])/3;
	char *ptrARNaAA = new char[AAtotal];
	char parseado[3];
	int codones = verificarCodon(argv, strlen(argv[1]));

	if (codones == 1){
		cout << "ERROR: Se debe iniciar y terminar en un codón de parada" << endl;	
		delete ptrARNaAA;
		return 0;
	}
	for(int i = 3; i < total; i = i+3){
		parseado[0] = argv[1][i];
		parseado[1] = argv[1][i+1];
		parseado[2] = argv[1][i+2];
		resultMoment = traducirARNaAA(argc, parseado);
		if (resultMoment == 'E'){
			cout << "ERROR: Secuencia incorrecta o codón de parada dentro de la secuencia" << endl;
			return 0;
		}
		ptrARNaAA[count] = resultMoment;
		count++;
	}
	cout << "|" << ptrARNaAA << "|" << endl;
	delete ptrARNaAA;
	return 0;
}
