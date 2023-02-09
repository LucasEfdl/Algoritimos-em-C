#include<stdio.h>
#include<stdlib.h>

float ** criaMatrizFloat(int linhas, int colunas){
	float ** matriz = (float**) malloc(linhas * sizeof(float*));//Pq tem um *?
	int linha;
	for(linha = 0; linha < linhas; linha++){
		matriz[linha] = (float*) malloc(colunas * sizeof(float));//pq não tem *?
	}
	return matriz;
}

void limpaFuncao(float ** matriz, int linhas){
	for(int i = 0; i < linhas; i++){
		free(matriz[i]);
	}
	free(matriz);
}

int main(){
	int l, c;
	float **matriz1;
	printf("digite as linhas:\n");
	scanf("%i", &l);
	printf("digite as colunas:\n");
	scanf("%i", & c);
	matriz1 = criaMatrizFloat(l, c);
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			matriz1[i][j] = (i * 3 + j);
		}
	}
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("\t%.f ", matriz1[i][j]);
		}
		printf("\n");
	}
	limpaFuncao(matriz1, l);
	return(0);
}