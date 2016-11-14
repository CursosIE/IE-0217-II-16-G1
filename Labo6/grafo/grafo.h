/**
 * @file grafo.h
 * @author Brizuela M, Morera B
 * @date 1 Noviembre 2016
 * @brief Header grafo.cpp
 */
void addVertex(char label);
void addEdge(int start,int end, int** adjMatrix);
void displayVertex(int vertexIndex);
int getAdjUnvisitedVertex(int vertexIndex, int** adjMatrix);
void depthFirstSearch(int** adjMatrix);
void breadthFirstSearch(int** adjMatrix);
