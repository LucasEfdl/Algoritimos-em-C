#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct pessoa
{
	char nome[50];
	float numeroDocumento;
	int idade;
} Pessoa;

void preencher_dados(Pessoa ** pessoa, int qtdPessoas)
{
	int i;
	for ( i = 0; i < qtdPessoas; i++)
	{
		printf("Digite o nome da %dº pessoa:\n", i + 1);
		scanf(" %[^\n]s", pessoa[i]->nome);
		printf("Digite o número do documento da %dº pessoa:\n", i + 1);
		scanf("%f", &pessoa[i]->numeroDocumento);
		printf("Digite a idade do %dº pessoa:\n", i + 1);
		scanf("%d", &pessoa[i]->idade);
		printf("\n");
	}
}

void imprime_pessoa(Pessoa **pessoa, int qtdPessoas)
{
	int i;
	for (int i = 0; i < qtdPessoas; i++)
	{
		printf("\n");
		printf("Nome: %s\nNúmero do docuemnto: %.0f\nIdade: %d\n\n", pessoa[i]->nome, pessoa[i]->numeroDocumento, pessoa[i]->idade);
	}
}

void altera_idade(Pessoa **pessoa, int qtdPessoas)
{
	float numberDocument;
	int i, novoSalario;
	printf("Informe o Número do documento da pessoa que deseja alterar a idade: ");
	scanf("%f", &numberDocument);
	for (i = 0; i < qtdPessoas; i++)
	{
		if (pessoa[i]->numeroDocumento == numberDocument)
		{
			printf("Informe a nova idade dessa pessoa: ");
			scanf("%d", &pessoa[i]->idade);
		}
	}
}

void maior_menor_idade(Pessoa **pessoa, int qtdPessoas)
{
	int i;
	int maiorIdade = 0;
	int menorIdade = 120;
	char pessoaVelha[20], pessoaNova[20];

	for (i = 0; i < qtdPessoas; i++)
	{
		if (pessoa[i]->idade > maiorIdade)
		{
			maiorIdade = pessoa[i]->idade;
			strcpy(pessoaVelha, pessoa[i]->nome);
		}
		if (pessoa[i]->idade < menorIdade)
		{
			menorIdade = pessoa[i]->idade;
			strcpy(pessoaNova, pessoa[i]->nome);
		}
	}
	printf("\nPessoa mais velha:\n%s\nPessoa mais nova:%s\n", pessoaVelha, pessoaNova);
}

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	int n, c;
	printf("Quantas pessoas deseja cadastra?\n");
	scanf("%d", &n);
	Pessoa **pessoa = (Pessoa **)malloc(n * sizeof(Pessoa *));

	preencher_dados(pessoa, n);

	imprime_pessoa(pessoa, n);

	printf("Deseja alterar a idade de alguma pessoa? (sim = 1, não = 0)\n");
	scanf("%d", &c);
	if (c == 1)
	{
		altera_idade(pessoa, n);
	}
	maior_menor_idade(pessoa, n);
	for (int i = 0; i < n; i++)
	{
		free(pessoa[i]);
	}
	free(pessoa);
}