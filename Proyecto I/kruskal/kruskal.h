void createGraph(char** argv, int** matrizAdyacencia);
void imprimirGrafo(int ordenMatriz, int** matrizAdyacencia);
int verticeFinal(int pesoBuscado, int** matrizAdyacencia, int ordenMatriz);
int verticeInicial(int pesoBuscado, int** matrizAdyacencia, int ordenMatriz);
void MakeSet(int numVertices, int padre[]);
int Find(int vertice, int padre[]);
bool sameTree(int verticePrimero, int verticeSegundo, int padre[]);
void Union(int verticePrimero, int verticeSegundo, int padre[]);
int kruskal(int cantVertices, int cantArista, char** argv, int** ptrMatrizAdyacente);
