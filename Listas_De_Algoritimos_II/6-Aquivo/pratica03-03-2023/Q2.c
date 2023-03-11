#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE * arquivo_entrada, * arquivo_saida;
    int vetor[10], bigValor, litValor;
    float somatorio = 0;
    char linha[100];
    int i = 0;

    arquivo_entrada = fopen("entrada_q2.txt", "rt");
    if(arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    } 

    arquivo_saida = fopen("saida_q2.txt", "wt");
    if(arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    while (fgets(linha,100,arquivo_entrada) != NULL)
    {
        sscanf(linha, "%d ", &vetor[i]);
        somatorio += vetor[i]; 
        i++;
    }
    litValor = vetor[0];
    bigValor = vetor[0];

    for(i = 0; i < 10; i++)
    {
        if(vetor[i] <= litValor){
            litValor = vetor[i];
        }
        if(vetor[i] >= bigValor){
            bigValor = vetor[i];
        }
    }

    fprintf(arquivo_saida, " Menor elemento: %d\n Maior elemento: %d\n Media: %f", litValor, bigValor, somatorio/10);
    
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}