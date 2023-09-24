#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include"matriz.h"

int main(int argc, char const *argv[])
{   
    Matriz mat;
    int i = 0;

    inicializa_matriz(&mat, 150, 4);
    
    // Abre o arquivo CSV para leitura
    FILE *arquivo = fopen("IrisDataset.csv", "r");

    //Um testezinho caso o arquivo estiver vazio
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Define um buffer para armazenar cada linha do arquivo
    char linha[151]; 

    //remove a primeira linha que só tem labbles
    fgets(linha, sizeof(linha), arquivo);

    // Loop para ler e processar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Função strtok para dividir a linha em campos
        char *token = strtok(linha, ",");
        for (int j = 0; j < 4; j++)
        {
            (&mat)->dados[i][j] = atof(token);
            token = strtok(NULL, ",");
        }
        i++;
    }

    // Fecha o arquivo quando parar de usar ele
    fclose(arquivo);

    mostra_matriz(mat);

    libera_matriz(&mat);

    return 0;
}
