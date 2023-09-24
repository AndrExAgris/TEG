#include<stdio.h>
#include<stdlib.h>

#define NUM_OBSERVACOES 150

// Definição da estrutura de um vértice
typedef struct {
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
} Vertex;

double distancia_euclidiana_normalizada(Vertex v1, Vertex v2);
void add_aresta(int graph[NUM_OBSERVACOES][NUM_OBSERVACOES], Vertex vertices[], int v1, int v2);
void salva_grafo(int graph[NUM_OBSERVACOES][NUM_OBSERVACOES]);
