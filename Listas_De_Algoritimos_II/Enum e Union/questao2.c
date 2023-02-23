#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//Explicação
typedef union tipo{
	char Alimento[20];
	char Bebida[15];
	char Eletronico[20];
}Tipo;

typedef struct produto{
	char nome[50];
	float preco;
	Tipo tipo;
}Produto;


int main(void) {
	
	setlocale(LC_ALL, "Portuguese");
	Produto produto;
	printf("Digite os dados do pruto.\n");
	printf("Nome: ");
	scanf(" %[^\n]s", produto.nome);
	printf("Digite o preco: ");
	scanf("%f", &produto.preco);
	printf("Tipo:");
	scanf(" %[^\n]s", produto.tipo.Bebida);
	printf("Produto informado\n");
	
	printf("Nome: %s\nPreço: %.2f\nTipo: %s", produto.nome, produto.preco, produto.tipo.Alimento);

	return(0);
}
