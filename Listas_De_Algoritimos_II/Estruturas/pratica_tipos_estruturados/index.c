#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define MAX_VAGAS 30
#define MAX_TURMAS 2

//struct alunos
typedef struct aluno
{
  int mat;
  char nome[80];
  float notas[3];
  float media;
} Aluno;

//struct turmas
typedef struct turma
{
  char id;
  int vagas;
  Aluno * alunos[MAX_VAGAS];
}Turma;

//Declarando a struct turma com 2 vagas
Turma* turmas[MAX_TURMAS];

Turma* cria_turma(char ID){
  int i;
  printf("\nCriando nova turma...");
  Turma * turmax = (Turma*) malloc(sizeof(Turma));
  if (turmax == NULL)
  {
    printf("Erro de memoria!");
    exit (1);
  }
  turmax->id = ID;
  turmax->vagas = MAX_VAGAS;
  for(i=0; i<MAX_VAGAS; i++){
    turmax->alunos[i] = NULL;
  }
  printf("\nTurma '%c' criada com sucesso!\n\n", ID);
  return turmax;
}

void matricular_aluno(Turma * turma, char * nome, int mat){
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

void lancar_notas(Turma * turmax){
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
        printf("Digite a %dº nota: ", n+1);
        scanf("%f", &turmax->alunos[i]->notas[n]);
        contMedia += turmax->alunos[i]->notas[n];
      }
      turmax->alunos[i]->media = contMedia / 3;
    }
  }
}

void imprime_turmas(Turma * turmax){
  int i;
  printf("Imprindo os alunos da turma: %c\n", turmax->id);
  for (i = 0; i < MAX_VAGAS; i++)
  {
    if (turmax->alunos[i] != NULL)
    {
      printf("Aluno: %s || Matricula: %d || Media: %.1f", turmax->alunos[i]->nome, turmax->alunos[i]->mat, turmax->alunos[i]->media);
    }
  }
}

int main(void){
  setlocale(LC_ALL, "Portuguese");
  int op, index = 0, i;
  int mat;
  char ID, nome[50];

  do
  {
    printf("MENU:\n\n1 Criar turma\n2 Listar turmas\n3 Matricular aluno\n4 Lancar notas\n5 Listar alunos\n6 Sair\n\n");
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
      /* Função de exibir turmas ja esta no case dois ;-; */
      printf("Listando turmas...\n");
      if (turmas[0] == NULL)
      {
        printf("Nao ha turmas disponiveis!\n");
        break;
      }
      for (i = 0; i <= MAX_TURMAS; i++)
      {
        printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
        if (i == MAX_TURMAS)
        {
          break;
        } 
      }
    case 3:
      printf("Digite o ID da turma que deseja cadastrar esse aluno:\n");
      scanf(" %[^\n]s", &ID);
      printf("Digite a matricula do aluno que deseja cadastrar:\n");
      scanf("%d", &mat);      
      printf("Digite o nome do aluno que deseja cadastrar:\n");
      scanf(" %[^\n]s", nome);

      for (i = 0; i <= index; i++)
      { 
        if (i == index)
        {
          printf("Nenhuma turma foi cadastrada!");
          break;
        }
        else if (turmas[i]->vagas == 0)
        {
          printf("Não ha vagas nesta turma!\n");
          break;
        }
        else if (turmas[i]->id == ID)
        {
          matricular_aluno(turmas[i], nome, mat);
          printf("Aluno matriculado com sucesso!\n");
          break;
        } else{
          printf("Não existe nenhuma truam com esse ID cadastrada!\n");
          break;
        }
        break;
      }
      case 4:
        if (turmas[0] == NULL)
        {
          printf("Nao ha turmas disponiveis!\n");
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
          } else{
            printf("Não existe nenhuma truam com esse ID cadastrada!\n");
            break;
          }
        }
      case 5:
        if (turmas[0] == NULL)
        {
          printf("Nao ha turmas disponiveis!\n");
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
          } else{
            printf("Não existe nenhuma turma com esse ID cadastrada!\n");
            break;
          }
        }
        break;
      default:
      break;
    }
  } while (op != 6);
  printf("Encerrando o programa.");

  /* //Liberando a alocação de memoria DUVIDA!!
  for (i = 0; i < MAX_VAGAS; i++)
  {
    free(turmas->alunos[i]);
  } 
  free(turmas->alunos);
  for (i = 0; i < MAX_TURMAS; i++)
  {
    free(turmas[i]);
  }
  free(turmas);
   */
  return (0);
}