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

Lista_adjacencias *cabeca = NULL;
Lista_adjacencias *corrente = NULL;

Lista_adjacencias * cria_lista(Lista_adjacencias *list, int va, int vb){
	//aloca memoria
	Lista_adjacencias *list = (Lista_adjacencias*) malloc(sizeof(struct Lista_adjacencias*));
	if(list == NULL)
	{	
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	//cria primeiro elemento da lista
	list->verticea = va;
	list->verticeb = vb;
	list->pointer = NULL;

	return list;
}

Lista_adjacencias * adicionar_lista(Lista_adjacencias *list, int a, int b){
	//se estiver vazia cria a lista
	if(cabeca == NULL)
	{
		return cria_lista(&list, a, b);
	}

	//aloca em memoria
	Lista_adjacencias *list = (Lista_adjacencias*) malloc(sizeof(struct Lista_adjacencias*));

	// verifica se houve falha na alocação de memória
	if(list == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	list->verticea = a;
	list->verticeb = b;
	list->pointer = NULL;

	corrente->pointer = list;
	corrente = list;

	return list;
}

// função que imprime a lista
void imprimir_lista(){
	// variável ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "cabeca"
	Lista_adjacencias *aux = cabeca;

	// enquanto "aux" for diferente de NULL
	while(aux != NULL)
	{
		// imprime o valor
		printf("%d, %d\n", aux->verticea, aux->verticeb);
		// aponta para o próximo elemento da lista
		aux = aux->pointer;
	}
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