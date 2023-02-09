#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct funcionario{
  char nome[50];
  float salario;
  char cargo[20];
  int ID; 
}Funcionario;

void preencher_dados(Funcionario * funcionario, int qtdFuncionario){
	int i;
	for(int i = 0; i < qtdFuncionario; i++){
    printf("Digite o nome do %dº funcionario:\n", i + 1);
    scanf(" %[^\n]", funcionario[i].nome);
    printf("Digite o salario do %dº funcionario:\n", i + 1);
    scanf("%f", &funcionario[i].salario);
    printf("Digite o cargo do %dº funcionario:\n", i + 1);
    scanf(" %[^\n]", funcionario[i].cargo);
    printf("Digite o indentificador do %dº funcionario:\n", i + 1);
    scanf("%d", &funcionario[i].ID);
    printf("\n");
  }
}

void imprime_funcionario(Funcionario * funcionario, int qtdFuncionario) {
	int i;
  for(int i = 0; i < qtdFuncionario; i++){
	  printf("\n");
    printf("Nome: %s\nSalário: %.2f\nCargo: %s \nID: %d\n\n", funcionario[i].nome, funcionario[i].salario, funcionario[i].cargo, funcionario[i].ID);
  }
}

void altera_salario(Funcionario * funcionario, int qtdFuncionario) {
	int indice, index, novoSalario;
	printf("Informe o ID do funcionario que deseja alterar o salario: ");
	scanf("%d", &indice);
  for(index=0; index<qtdFuncionario; index++){
		if(funcionario[index].ID == indice){
      printf("Informe o novo salario desse funcionario: ");
	    scanf("%f", &funcionario[index].salario);
		}
	}
}

void maior_menor_salario(Funcionario * funcionario, int qtdFuncionario){
	int i;
	float maiorSalario = 0;
	float menorSalario = 99999;
	char maiorCargo[20], menorCargo[20];
	
	for(i=0; i<qtdFuncionario; i++) {
		if(funcionario[i].salario> maiorSalario){
			maiorSalario = funcionario[i].salario;
			strcpy(maiorCargo, funcionario[i].cargo);
		}
		if(funcionario[i].salario < menorSalario) {
			menorSalario = funcionario[i].salario;
			strcpy(menorCargo, funcionario[i].cargo);
		}
	}
	printf("\nFuncionario que mais recebe:\nSalario: %.2f\nCargo: %s\n", maiorSalario, maiorCargo);
	printf("\nFuncionario que menos recebe:\nSalario: %.2f\nCargo: %s\n", menorSalario, menorCargo);
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  int n, c;
  printf("Quantos funcionários deseja cadastra?\n");
  scanf("%d", &n);
  Funcionario *funcionario = (Funcionario *) malloc(n * sizeof(Funcionario));
	
	preencher_dados(funcionario, n);

  imprime_funcionario(funcionario, n);

  printf("Deseja alterar o salario de algum funcionario?\n");
  scanf("%d", &c);
  if(c == 1){
    altera_salario(funcionario, n);
	}
	maior_menor_salario(funcionario, n);
  free(funcionario);
}