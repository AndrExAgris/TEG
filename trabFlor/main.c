#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<math.h>
#include"bibflores.h"


int main(int argc, char const *argv[])
{   
    Vertice dados_csv[NUM_OCORRENCIAS];
    double mat_distancias[NUM_OCORRENCIAS][NUM_OCORRENCIAS];
    double max=0, min=2048;

    // Abre o iris_dataset CSV para leitura
    FILE *iris_dataset = fopen("IrisDataset.csv", "r");
    if (iris_dataset == NULL) {
        perror("Erro ao abrir o iris_dataset");
        return 1;
    }

    //tira linha de labels do iris_dataset
    char str[128];
    fgets(str, sizeof(str), iris_dataset);

    // Le os dados do arquivo CSV
    for (int i = 0; i < NUM_OCORRENCIAS; i++) {
        fscanf(iris_dataset, "%s", str );
        char *pt;
        pt = strtok(str, ",");
        dados_csv[i].petal_length = atof(pt);
        pt = strtok (NULL, ",");
        dados_csv[i].petal_width = atof(pt);
        pt = strtok (NULL, ",");
        dados_csv[i].sepal_length = atof(pt);
        pt = strtok (NULL, ",");
        dados_csv[i].sepal_width = atof(pt);
    }
    fclose(iris_dataset);

    //preenche a matriz de distancias
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = i; j < NUM_OCORRENCIAS; j++)
        {
            double var_auxiliar = distancia_euclidiana(dados_csv[i], dados_csv[j]);
            mat_distancias[i][j] = var_auxiliar;
            mat_distancias[j][i] = var_auxiliar;

            //maximo e minimo para normalizacao
            if (max < var_auxiliar)
            {
                max = var_auxiliar;
            }else if (min > var_auxiliar)
            {
                min = var_auxiliar;
            }
        }
    }

    //normaliza a matriz de distancias
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = 0; j < NUM_OCORRENCIAS; j++)
        {
            mat_distancias[i][j] = (mat_distancias[i][j] - min ) / (max-min);
        }
        
    }
    
    // Inicializar o grafo com zeros
    int grafo[NUM_OCORRENCIAS][NUM_OCORRENCIAS] = {0};
    

    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = 0; j < NUM_OCORRENCIAS; j++)
        {
            if (mat_distancias[i][j] <= (0.3))
            {
                grafo[i][j] +=1;
            }   
        }
    }


    Lista_adjacencias lista;

    int num_vertices = 0;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = i; j < NUM_OCORRENCIAS; j++)
        {
            if (grafo[i][j] != 0)
            {
                num_vertices += 1;
                printf("%d, %d\n", i, j);
                adicionar_lista(&lista, i, j);

                
            }
        }
    }
    printf ("numero de vertices é %d\n", num_vertices);
    




    /*print matrizz pra verificação
    for(int i = 0 ; i < NUM_OCORRENCIAS ; i++ ){
		for(int j = 0 ; j < NUM_OCORRENCIAS ; j++ ){
		    printf("%4d ", grafo[i][j]);
		}
  	    printf("\n");
	}
	printf("\n");
    */
    return 0;
}

