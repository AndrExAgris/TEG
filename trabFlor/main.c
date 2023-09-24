#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include"matriz.h"

int main(int argc, char const *argv[])
{
    
    // Abre o arquivo CSV para leitura
    FILE *arquivo = fopen("IrisDataset.csv", "r");

    //Um testezinho caso o arquivo estiver vazio
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Define um buffer para armazenar cada linha do arquivo
    char linha[151]; 

    // Loop para ler e processar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Função strtok para dividir a linha em campos
        char *token = strtok(linha, ",");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    // Fecha o arquivo quando parar de usar ele
    fclose(arquivo);

    return 0;
}
