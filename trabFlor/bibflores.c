#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include"bibflores.h"

double distancia_euclidiana(Vertice v1, Vertice v2) {
    double sum = 0.0;
    sum += (v1.sepal_length - v2.sepal_length) * (v1.sepal_length - v2.sepal_length);
    sum += (v1.sepal_width - v2.sepal_width) * (v1.sepal_width - v2.sepal_width);
    sum += (v1.petal_length - v2.petal_length) * (v1.petal_length - v2.petal_length);
    sum += (v1.petal_width - v2.petal_width) * (v1.petal_width - v2.petal_width);
    return sqrt(sum);
}

/*

// Função para salvar o grafo em um arquivo TXT
void salva_grafo(int graph[NUM_OCORRENCIAS][NUM_OCORRENCIAS]) {
    FILE *file = fopen("graph.txt", "w");
    if (file == NULL) {
        perror("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(file, "%d\n", NUM_OCORRENCIAS);
    for (int i = 0; i < NUM_OCORRENCIAS; i++) {
        for (int j = i + 1; j < NUM_OCORRENCIAS; j++) {
            if (graph[i][j] == 1) {
                fprintf(file, "%d,%d\n", i + 1, j + 1); // +1 para ajustar para 1-based indexing
            }
        }
    }

    fclose(file);
}

*/