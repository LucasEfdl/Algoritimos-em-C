#include<stdio.h>
#include<stdlib.h>

int main(void){
	int tamanho = 10;
	int *vet = (int*) malloc(tamanho * sizeof(int));
	if(vet == NULL){
		printf("Erro!");
		exit(1);
	}
	for(int i = 0; i < tamanho; i++){
		*(vet + i) = i;
		printf("%i\n", vet[i]);
	}
	
	free(vet);
	return(0);
}