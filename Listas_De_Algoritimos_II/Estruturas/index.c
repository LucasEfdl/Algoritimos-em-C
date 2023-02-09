#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct funcionario{
    char nome[50];
    float salario;
    char cargo[20];
}Funcionario;

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Quantos funcionários deseja cadastra?\n");
    scanf("%d", &n);
    Funcionario *funcionario = (Funcionario *) malloc(n * sizeof(Funcionario));

    /* Preenchendo o vetor funcionario 18-26 */
    for(int i = 0; i < n; i++){
        printf("Digite o nome do %dº funcionario:\n", i + 1);
        scanf(" %[^\n]", funcionario[i].nome);
        printf("Digite o salario do %dº funcionario:\n", i + 1);
        scanf("%f", &funcionario[i].salario);
        printf("Digite o cargo do %dº funcionario:\n", i + 1);
        scanf(" %[^\n]", funcionario[i].cargo);
        printf("\n");
    }

    /* Exibindo o vetor funcionario */
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("Nome: %s | Salário: %.2f | Cargo: %s \n", funcionario[i].nome, funcionario[i].salario, funcionario[i].cargo);
    }

    free(funcionario);
}