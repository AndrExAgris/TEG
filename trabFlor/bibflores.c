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

void salva_arquivo_arestas(int quantidade, Aresta lista[quantidade]){
	FILE *file = fopen("Lista_Adjacencias.txt", "w");
    if (file == NULL) {
        perror("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(file, "%d\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%d, %d\n", lista[i].verticea, lista[i].verticeb); 
    }
}

void salva_arquivo_cluster(int quantidade, Aresta lista[quantidade]){
	FILE *file = fopen("Cluster.txt", "w");
    if (file == NULL) {
        perror("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(file, "%d\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%d, %d\n", lista[i].verticea, lista[i].verticeb); 
    }
}

