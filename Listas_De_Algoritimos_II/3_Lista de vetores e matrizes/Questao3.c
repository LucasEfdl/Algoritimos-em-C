#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	//matriz de frutas 10-20
	int qntFrutas, linha, maiorString = 0;
	printf("Digite a quantidade de frutas:\n");
	scanf("%d", &qntFrutas);
	char ** frutas = (char**) malloc(qntFrutas * sizeof(char*));
	if(frutas == NULL){
		printf("Erro de memória");
		exit(1);
	}

	//verificação das linhas da atriz
	for(linha = 0; linha < qntFrutas; linha++){
		frutas[linha] = (char*) malloc(50 * sizeof(char));
		if(frutas[linha] == NULL){
		printf("Erro de memória");
		exit(1);
	}
	}

	
	//vetor de precos
	float * preco = (float*) malloc(qntFrutas * sizeof(float));
	if(preco==NULL){
		exit(1);
	}
	for(linha = 0; linha < qntFrutas; linha ++){
		printf("Informe a %iº fruta: \n", linha + 1);
		scanf(" %[^\n]s", frutas[linha]);
		printf("Informe o preço da %iº fruta: \n", linha + 1);
		scanf("%f", &preco[linha]);
	}
	
	//Interando sobre os vetores da fruta para achar a aior string
	for (linha = 0; linha < qntFrutas; linha++){
			if(strlen(frutas[linha]) > maiorString){
				maiorString = strlen(frutas[linha]);
			}
	}
	
  	//Realocação da matriz de frutas
 	 for(linha = 0; linha < qntFrutas; linha++){
		frutas = (char**) realloc(frutas,maiorString * sizeof(char));
		if(frutas == NULL){
		printf("Erro de memória");
		exit(1);	
		}
	}

  	//liberando o espaço da memoria 
	for(linha=0; linha<qntFrutas; linha++){
		free(frutas[linha]);
	}
	free(frutas);
	free(preco);
}