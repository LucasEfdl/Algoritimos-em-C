#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_VAGAS 4
#define MAX_TURMAS 2

typedef struct aluno
{
  int mat;
  char nome[80];
  float notas[3];
  float media;
} Aluno;
typedef struct turma
{
  char id;
  int vagas;
  Aluno *alunos[MAX_VAGAS];
} Turma;
Turma *turmas[MAX_TURMAS]; // declarando a struct com 2 vagas

int valida_turma(Turma **turmax)
{ // função auxiliar
  if (turmas[0] == NULL)
  {
    printf("Nao ha turmas disponiveis!\n");
    return 1;
  }
}

Turma *cria_turma(char ID)
{ // case 1
  int i;
  printf("\nCriando nova turma...");
  Turma *turmax = (Turma *)malloc(sizeof(Turma));
  if (turmax == NULL)
  {
    printf("Erro de memoria!");
    exit(1);
  }
  turmax->id = ID;
  turmax->vagas = MAX_VAGAS;
  for (i = 0; i < MAX_VAGAS; i++)
  {
    turmax->alunos[i] = NULL;
  }
  printf("\nTurma '%c' criada com sucesso!\n\n", ID);
  return turmax;
}

void listar_turmas(Turma **turmax)
{ // case 2
  int i;
  for (i = 0; i < MAX_TURMAS; i++)
  {
    if (turmax[i] != NULL)
    {
      printf("Turma %c - %d vagas disponiveis\n\n", turmax[i]->id, turmax[i]->vagas);
    }
  }
}

void matricular_aluno(Turma *turma, char *nome, int mat)
{ // case 3
  int i, n;
  turma->vagas -= 1;
  for (i = 0; i < MAX_VAGAS; i++)
  {
    if (turma->alunos[i] == NULL)
    {
      turma->alunos[i] = (Aluno *)malloc(sizeof(Aluno));
      for (n = 0; n < 3; n++)
      {
        turma->alunos[i]->notas[n] = 0;
      }
      turma->alunos[i]->mat = mat;
      strcpy(turma->alunos[i]->nome, nome);
      break;
    }
  }
}

void lancar_notas(Turma *turmax)
{ // case 4
  int i, n;
  float contMedia;
  for (i = 0; i < MAX_VAGAS; i++)
  {
    contMedia = 0;
    if (turmax->alunos[i] != NULL && turmax->alunos[i]->notas[0] == 0)
    {
      printf("Recebendo as notas da turma: %c\n", turmax->id);
      printf("Aluno: %s\n", turmax->alunos[i]->nome);
      for (n = 0; n < 3; n++)
      {
        printf("Digite a %dº nota: ", n + 1);
        scanf("%f", &turmax->alunos[i]->notas[n]);
        contMedia += turmax->alunos[i]->notas[n];
      }
      turmax->alunos[i]->media = contMedia / 3;
    }
  }
}

void imprime_turmas(Turma *turmax)
{ // case 5
  int i;
  printf("Imprindo os alunos da turma: %c\n", turmax->id);
  for (i = 0; i < MAX_VAGAS; i++)
  {
    if (turmax->alunos[0] == NULL)
    {
      printf("Não há alunos cadastrados nesta turma\n");
      break;
    }

    else if (turmax->alunos[i] != NULL)
    {
      printf("Aluno: %s || Matricula: %d || Media: %.1f\n\n", turmax->alunos[i]->nome, turmax->alunos[i]->mat, turmax->alunos[i]->media);
    }
  }
}

void buscar_turmas(Turma **turmax, char ID, int index)
{ // case 6
  int i;
  for (i = 0; i < index; i++)
  {
    if (turmax[i]->id == ID)
    {
      printf("Informações da turma:\nTurma %c - %d vagas disponiveis\n\n", turmax[i]->id, turmax[i]->vagas);
    }
  }
}
int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  int op, mat, index = 0, i, j, c;
  char ID, nome[50];
  printf("\n\tBem-vindo ao Programa de Gerenciamento de Turmas!\n\tEste programa gerencia as turmas ofertadas, fornecendo as\n\tfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n\tAutor: Lucas Emanuel Freire de Lima   Versão só Deus sabe.");
  do
  {
    printf("MENU:\n\n1 Criar turma\n2 Listar turmas\n3 Matricular aluno\n4 Lancar notas\n5 Listar alunos\n6 Buscar turma\n7 sair\n\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      if (index >= MAX_TURMAS)
      {
        printf("Não é possivel cadastra uma nova turma!\n");
        break;
      }
      printf("Informe um ID para a sua turma: ");
      scanf(" %[^\n]s", &ID);
      turmas[index] = cria_turma(ID);
      index++;
      break;
    case 2:
      printf("Listando turmas...\n");
      c = valida_turma(turmas);
      if (c == 1)
      {
        break;
      }
      listar_turmas(turmas);
      break;
    case 3:
      c = valida_turma(turmas);
      if (c == 1)
      {
        break;
      }
      printf("Digite o ID da turma que deseja cadastrar esse aluno:\n");
      scanf(" %[^\n]s", &ID);
      printf("Digite a matricula do aluno que deseja cadastrar:\n");
      scanf("%d", &mat);
      printf("Digite o nome do aluno que deseja cadastrar:\n");
      scanf(" %[^\n]s", nome);
      for (i = 0; i < MAX_TURMAS; i++)
      {
        if (turmas[i]->vagas == 0)
        {
          printf("Não ha vagas nesta turma!\n");
          break;
        }
        else if (turmas[i]->id == ID)
        {
          matricular_aluno(turmas[i], nome, mat);
          printf("Aluno matriculado com sucesso!\n\n");
          break;
        }
        else
        {
          printf("Não existe nenhuma turma com esse ID cadastrada!\n");
          break;
        }
      }
      break;
    case 4:
      c = valida_turma(turmas);
      if (c == 1)
      {
        break;
      }
      printf("Digite o ID da turma que deseja lacar as notas: ");
      scanf(" %[^\n]s", &ID);
      for (i = 0; i < MAX_TURMAS; i++)
      {
        if (turmas[i]->id == ID)
        {
          lancar_notas(turmas[i]);
          printf("Notas lancadas com sucesso!\n");
          break;
        }
        else
        {
          printf("Não existe nenhuma truam com esse ID cadastrada!\n");
          break;
        }
      }
    case 5:
      c = valida_turma(turmas);
      if (c == 1)
      {
        break;
      }
      printf("Digite o ID da turma que deseja exiv=bir os alunos: ");
      scanf(" %[^\n]s", &ID);
      for (i = 0; i < MAX_TURMAS; i++)
      {
        if (turmas[i]->id == ID)
        {
          imprime_turmas(turmas[i]);
          break;
        }
        else
        {
          printf("Não existe nenhuma turma com esse ID cadastrada!\n");
          break;
        }
      }
      break;
    case 6:
      c = valida_turma(turmas);
      if (c == 1)
      {
        break;
      }
      printf("Digite o ID da turma que deseja pesquisar: ");
      scanf(" %[^\n]s", &ID);
      buscar_turmas(turmas, ID, index);
      break;
    default:
      break;
    }
  } while (op != 7);
  printf("Encerrando o programa.");
  // Liberando a alocação de memoria
  for (i = 0; i < MAX_TURMAS; i++)
  {
    for (j = 0; j < MAX_VAGAS; j++)
    {
      free(turmas[i]->alunos[j]);
    }
    free(turmas[i]);
  }
  free(turmas);
  return (0);
}