#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include"matriz.h"
#include"grafos.h"

#define NUM_OBSERVACOES 150
#define NUM_ATRIBUTOS 4

int main(int argc, char const *argv[])
{   
    Matriz inicial, distancias;
    Vertex vertices[NUM_OBSERVACOES];

    inicializa_matriz(&inicial, NUM_OBSERVACOES, NUM_ATRIBUTOS);
    
    // Abre o iris_dataset CSV para leitura
    FILE *iris_dataset = fopen("IrisDataset.csv", "r");

    //Um testezinho caso o iris_dataset estiver vazio
    if (iris_dataset == NULL) {
        perror("Erro ao abrir o iris_dataset");
        return 1;
    }

    // Define um buffer para armazenar cada linha do iris_dataset
    char linha[256]; 

    //remove a primeira linha que só tem labbles
    fgets(linha, sizeof(linha), iris_dataset);

    // Loop para ler e processar cada linha do iris_dataset
    int i = 0;
    while (fgets(linha, sizeof(linha), iris_dataset)) {
        // Função strtok para dividir a linha em campos
        char *token = strtok(linha, ",");
        for (int j = 0; j < NUM_ATRIBUTOS; j++)
        {
            (&inicial)->dados[i][j] = atof(token);
            token = strtok(NULL, ",");
        }
        i++;
    }

    // Fecha o iris_dataset quando parar de usar ele
    fclose(iris_dataset);

    // Inicializar o grafo com zeros
    int graph[NUM_OBSERVACOES][NUM_OBSERVACOES] = {0};

    // Criar as arestas com base na distância euclideana normalizada ao quadrado
    for (int i = 0; i < NUM_OBSERVACOES; i++) {
        for (int j = i + 1; j < NUM_OBSERVACOES; j++) {
            add_aresta(graph, vertices, i, j);
        }
    }

    // Salvar o grafo em um arquivo TXT
    salva_grafo(graph);


    libera_matriz(&inicial);

    return 0;
}
