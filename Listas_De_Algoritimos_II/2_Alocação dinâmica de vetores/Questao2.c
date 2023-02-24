#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int main(void) {
  setlocale(LC_ALL, "Portuguese");
  int qtdQuest, i, j, qtdAlunos, aprovados = 0;
  float pontosPorQuest, nota, porcAprovados;


  printf("Quantas questoes tem a prova?\n");
  scanf("%d", &qtdQuest);
  pontosPorQuest = 10/qtdQuest;


  //declarando e preenchendo o gabarito da prova
  char * gabaritoProva = (char *) malloc(qtdQuest*sizeof(char));
  printf("Digite o gabarito da prova (a, b, c, d):\n");
  for ( i = 0; i < qtdQuest; i++){
    scanf(" %c", &gabaritoProva[i]);
  }


  //Alocando o espaço dos alunos e suas respostas
  printf("Quantos alunos fizeram a prova:\n");
  scanf("%d", &qtdAlunos);
  char ** respostas = (char **) malloc(qtdAlunos*sizeof(char*));
  for (i = 0; i < qtdAlunos; i++){
    respostas[i] = (char *) malloc(qtdQuest*sizeof(char));
  }
  

  //capturando as respostados dos alunos e comparando as respostas
  for (i = 0; i < qtdAlunos; i++){
    int acerto = 0;
    printf("Digite as respostado do %dª aluno:\n", i+1);
    for (j = 0; j<qtdQuest; j++){
      scanf(" %c", &respostas[i][j]);
      if(respostas[i][j] == gabaritoProva[j]){
        acerto++;
      }
    }
    nota = pontosPorQuest * acerto;
    if(nota >= 6){
      aprovados++;
    }
    printf("A nota do %dª aluno foi: %.1f\n", i+1, nota);
  }
  
  //Calculado a porcentagem de alunos aprovados
  porcAprovados = (aprovados/qtdAlunos)*100;
  printf("A porcentagem de alunos aprovados foi de: %.1f%%", porcAprovados);


  //Liberando o espaço alocado dinamicamente
  free(gabaritoProva);
  for (i = 0; i < qtdAlunos; i++)
  {
    free(respostas[i]);
  }
  free(respostas);
  
  
}