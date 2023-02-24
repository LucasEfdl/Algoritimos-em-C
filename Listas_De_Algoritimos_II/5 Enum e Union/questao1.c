#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef enum genero{
	masculino,
	feminino
}Genero;

typedef struct pessoa{
	char nome[50];
	int idade;
	Genero genero;
}Pessoa;


int main(void) {
	
	setlocale(LC_ALL, "Portugues");
	Pessoa pessoa;
	printf("Digite os dados da pessoa.\n");
	printf("Nome: ");
	scanf(" %[^\n]", pessoa.nome);
	printf("Digite a idade: ");
	scanf("%d", &pessoa.idade);
	printf("0 - Masculino\n1 - Feminino\n");
	scanf("%d", (int*)&pessoa.genero);
	
	printf("Pessoa informada\n");
	
	if(pessoa.genero == masculino){
		printf("Nome: %s\nIdade: %d\nGenero: Masculino", pessoa.nome, pessoa.idade);
	}
	if(pessoa.genero == feminino){
		printf("Nome: %s\nIdade: %d\nGenero: Feminino", pessoa.nome, pessoa.idade);
	}
	
	
	return(0);
}
