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
    double limiar = 0.2;


    // Abre o iris_dataset CSV para leitura
    FILE *iris_dataset = fopen("IrisDataset.csv", "r");
    if (iris_dataset == NULL) 
    {
        perror("Erro ao abrir o iris_dataset");
        return 1;
    }

    //tira linha de labels do iris_dataset
    char str[128];
    fgets(str, sizeof(str), iris_dataset);

    // Le os dados do arquivo CSV
    for (int i = 0; i < NUM_OCORRENCIAS; i++) 
    {
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
        for (int j = i+1; j < NUM_OCORRENCIAS; j++)
        {
            double var_auxiliar = distancia_euclidiana(dados_csv[i], dados_csv[j]);
            mat_distancias[i][j] = var_auxiliar;
            mat_distancias[j][i] = var_auxiliar;

            //maximo e minimo para normalizacao
            if (max < var_auxiliar)
            {
                max = var_auxiliar;
            }
            else if (min > var_auxiliar)
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

    //caracteriza por distancia
    int florA[150], florB[150];
    double maxDist = 0;
    int elemento1, elemento2;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = i+1; j < NUM_OCORRENCIAS; j++)
        {
            if (mat_distancias[i][j] > maxDist)//acha a maior distancia entre os nos
            {
                maxDist = mat_distancias[i][j];
                elemento1 = i;
                elemento2 = j;
            }    
        }
        florA[i] = -1;//preenchendo com -1 para usar -1 como filtro
        florB[i] = -1;
    }
    int  quantA = 0, quantB = 0, quantC = 0;
    florA[0] = elemento1;//elementos mais distantes são os primeiros de cada lista
    florB[0] = elemento2;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        if (i != florA[0] && i != florB[0]){//preenche as listas por proximidade
            if (mat_distancias[i][florA[0]] < mat_distancias[i][florB[0]])
            {
                quantA+=1;
                florA[quantA] = i;
            }
            else
            {
                quantB+=1;
                florB[quantB] = i;
            }
        }  
    }   
    //da sort nas listas pela distancia
    for (int i = 0; i < quantA; i++) 
    {
        for (int j = 0; j < quantA - i; j++) 
        {
            if (mat_distancias[florA[j]][florA[0]] > mat_distancias[florA[j+1]][florA[0]]) 
            {
                int temp = florA[j];
                florA[j]= florA[j +1];
                florA[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < quantB; i++)
        {
        for (int j = 0; j < quantB - i; j++) 
        {
            if (mat_distancias[florB[j]][florB[0]] > mat_distancias[florB[j+1]][florB[0]]) 
            {
                int temp = florB[j];
                florB[j]= florB[j +1];
                florB[j+1] = temp;
            }
        }
    }

    int clusterA[50], clusterB[50], clusterC[50];
    int qclustA = 0, qclustB = 0, qclustC = 0;
    for (int i = 0; i <= quantA; i++) //cria os clusters
    {
        if (qclustA < 50)
        {
            clusterA[i] = florA[i];
            qclustA += 1;
        }
        else
        {
            clusterC[qclustC] = florA[i];
            qclustC += 1;
        } 
    }
    for (int i = 0; i <= quantB; i++)
    {
        if (qclustB < 50)
        {
            clusterB[i] = florB[i];
            qclustB += 1;
        }
        else
        {
            clusterC[qclustC] = florB[i];
            qclustC += 1;
        } 
    }

    // Inicializar o grafo com zeros
    int grafo[NUM_OCORRENCIAS][NUM_OCORRENCIAS] = {0};
    //cria a matriz de adjacencias
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = 0; j < NUM_OCORRENCIAS; j++)
        {
            if (mat_distancias[i][j] <= (limiar))
            {
                grafo[i][j] +=1;
            }   
        }
    }

    // Inicializar o grafo clusterizado? com zeros
    int grafocluster[NUM_OCORRENCIAS][NUM_OCORRENCIAS] = {0};
    //cria a matriz de adjacencias
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = 0; j < NUM_OCORRENCIAS; j++)
        {
            if (mat_distancias[i][j] <= (limiar))
            {   
                int countA = 0, countB = 0, countC = 0;
                for (int k = 0; k < 50; k++)
                {
                    if(clusterA[k] == i || clusterA[k] == j) 
                    {
                        countA += 1;
                    }
                    if(clusterB[k] == i || clusterB[k] == j) 
                    {
                        countB += 1;
                    }
                    if(clusterC[k] == i || clusterC[k] == j) 
                    {
                        countC += 1;
                    }
                }
                if(countA == 2 || countB == 2 || countC == 2)
                {
                    grafocluster[i][j] +=1;
                } 
            }   
        }
    }

    //conta quantas arestas tem o grafo
    int num_arestas_grafo = 0;
    int nos_grafo = 0;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        int aux = 0;
        for (int j = i+1; j < NUM_OCORRENCIAS; j++)
        {
            if (grafo[i][j] != 0)
            {
                num_arestas_grafo += 1;
                aux +=1;  
            }
        }
        if (aux != 0){
            nos_grafo += 1;
        }
    }

    //cria um vetor e armazena a lista de adjacencias
    Aresta arestas_grafo[num_arestas_grafo];
    int aux=0;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = i+1; j < NUM_OCORRENCIAS; j++)
        {
            if (grafo[i][j] != 0)
            {
                arestas_grafo[aux].verticea = i;
                arestas_grafo[aux].verticeb = j;
                aux += 1;
            }
        }
    }

    salva_arquivo_arestas(num_arestas_grafo, arestas_grafo);

    //conta quantas arestas tem grafocluster
    int num_arestas_cluster = 0;
    int nos_cluster = 0;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        int auxb = 0;
        for (int j = i+1; j < NUM_OCORRENCIAS; j++)
        {
            if (grafocluster[i][j] != 0)
            {
                num_arestas_cluster += 1;
                auxb +=1;  
            }
        }
        if (auxb != 0){
            nos_cluster += 1;
        }
    }

    //cria um vetor e armazena a lista de adjacencias
    Aresta arestas_cluster[num_arestas_cluster];
    int auxb=0;
    for (int i = 0; i < NUM_OCORRENCIAS; i++)
    {
        for (int j = i+1; j < NUM_OCORRENCIAS; j++)
        {
            if (grafocluster[i][j] != 0)
            {
                arestas_cluster[auxb].verticea = i;
                arestas_cluster[auxb].verticeb = j;
                auxb += 1;
            }
        }
    }

    salva_arquivo_cluster(num_arestas_cluster, arestas_cluster);

    int VerdAA = 0, FalAB = 0, FalAC = 0;
    int FalBA = 0, VerdBB = 0, FalBC = 0;
    int FalCA = 0, FalCB = 0, VerdCC = 0;


    for (int i = 0; i < 50; i++)
    {
        if (clusterA[i] < 50) VerdAA +=1;
        if (clusterA[i] >= 50 && clusterA[i] < 100) FalAB +=1;
        if (clusterA[i] >= 100) FalAC +=1;
        if (clusterB[i] < 50) FalCA +=1;
        if (clusterB[i] >= 50 && clusterB[i] < 100) FalCB +=1;
        if (clusterB[i] >= 100) VerdCC +=1;
        if (clusterC[i] < 50) FalBA +=1;
        if (clusterC[i] >= 50 && clusterC[i] < 100) VerdBB +=1;
        if (clusterC[i] >= 100) FalBC +=1;
    }
    
    printf("x A B C\n");
    printf("A %d %d %d\n", VerdAA, FalAB, FalAC);
    printf("B %d %d %d\n", FalBA, VerdBB, FalBC);
    printf("C %d %d %d\n", FalCA, FalCB, VerdCC);
    
    return 0;
}

