#include <stdio.h>
#include <stdlib.h>

int main(void){
    int m, n;
    printf("Digite o numero de linhas e colunas da matriz:");
    scanf("%d %d", &m, &n);
    if(m < 1 || n > 1000){
        printf("Entrada invalida.");
    }
    else
    {
        char **matriz = (char**) malloc(m * sizeof(char*));
        if(matriz == NULL){
            exit(1);
        }

        for(int i = 0; i < m; i++){
            matriz[i] = (char*) malloc(n * sizeof(char*));
            if(matriz[i] == NULL){
                exit(1);
            }
        }

        printf("Preencha o mapa:\n");
        for(int i = 0; i < m; i++){
            scanf(" %[^\n]s", matriz[i]);
        }

        printf("Mapa:\n");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                printf("%c\t", matriz[i][j]);
            }
            printf("\n");
        }

        /* For que verifica o meio da matriz */
        int qtdCostas = 0;
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(matriz[i][j] == '#'){

                    if(matriz[i][j-1] == '.'){
                        qtdCostas++;
                        /* break; */
                    }
                    else if(matriz[i][j+1] == '.'){
                        qtdCostas++;
                        /* break; */
                    }
                    else if(matriz[i-1][j] == '.'){
                        qtdCostas++;
                        /* break; */
                    }
                    else if(matriz[i+1][j] == '.'){
                        qtdCostas++;
                        /* break; */
                    }
                }
                
            }
        }

        /* Verifica a prieira linha e coluna da matriz */
        for(int i = 0; i < 1; i++){
            for(int j = 0; j < 1; j++){
                if(matriz[i][j] == '#'){
                    if(matriz[i][j+1] == '.'){
                        qtdCostas++;
                        /* break; */
                    } 
                    else if(matriz[i+1][j] == '.'){
                        qtdCostas++;
                        /* break; */
                    }

                }
            }        
        }

        /* Verifica a ultima linha e coluna da matriz */
            for(int j = 0; j < n; j++){
                if(matriz[m-1][j] == '#'){
                    if(matriz[m-1][j-1] == '.'){
                        qtdCostas++;
                        /* break; */
                    } 
                    else if(matriz[m-1][j+1] == '.'){
                        qtdCostas++;
                        /* break; */
                    }
                }
               
            }        

        printf("%d", qtdCostas);
        for(int i = 0; i < m; i++){
        free(matriz[i]);
        }
    free(matriz);
    }
}