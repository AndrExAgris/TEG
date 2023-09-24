#include<stdio.h>
#include<stdlib.h>
#include"grafos.h"

#define LIMITE_QUADRADO (0.3 * 0.3)

// Função para calcular a distância euclideana normalizada ao quadrado entre dois vértices
double distancia_euclidiana_normalizada(Vertex v1, Vertex v2) {
    double sum = 0.0;
    sum += (v1.sepal_length - v2.sepal_length) * (v1.sepal_length - v2.sepal_length);
    sum += (v1.sepal_width - v2.sepal_width) * (v1.sepal_width - v2.sepal_width);
    sum += (v1.petal_length - v2.petal_length) * (v1.petal_length - v2.petal_length);
    sum += (v1.petal_width - v2.petal_width) * (v1.petal_width - v2.petal_width);
    return sum;
}

// Função para adicionar uma aresta ao grafo se a distância euclideana normalizada ao quadrado for menor ou igual ao limiar ao quadrado
void add_aresta(int graph[NUM_OBSERVACOES][NUM_OBSERVACOES], Vertex vertices[], int v1, int v2) {
    double distance_square = distancia_euclidiana_normalizada(vertices[v1], vertices[v2]);
    if (distance_square <= LIMITE_QUADRADO) {
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

// Função para salvar o grafo em um arquivo TXT
void salva_grafo(int graph[NUM_OBSERVACOES][NUM_OBSERVACOES]) {
    FILE *file = fopen("graph.txt", "w");
    if (file == NULL) {
        perror("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(file, "%d\n", NUM_OBSERVACOES);

    // Percorre todos os vértices
    for (int i = 0; i < NUM_OBSERVACOES; i++) {
        fprintf(file, "%d: ", i + 1); // +1 para ajustar para 1-based indexing

        // Percorre todas as conexões do vértice atual
        for (int j = 0; j < NUM_OBSERVACOES; j++) {
            if (graph[i][j] == 1) {
                fprintf(file, "%d, ", j + 1); // +1 para ajustar para 1-based indexing
            }
        }

        fprintf(file, "\n");
    }

    fclose(file);
}
