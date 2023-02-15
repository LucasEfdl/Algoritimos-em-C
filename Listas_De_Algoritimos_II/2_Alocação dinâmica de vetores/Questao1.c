#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(void){
  setlocale(LC_ALL, "Portuguese");
  int n, i;
  float qtd_mulheres = 0, qtd_homens = 0, likeGirl = 0, likeMan = 0;
  float porFem, porMac;
  printf("Quantas pessoas participaram da pesquisa?\n");
  scanf("%i", &n);
  char *sexo, *opniao;
  sexo = (char*) malloc(n * sizeof(char)); 
  opniao = (char*) malloc(n * sizeof(char)); 

  //Preenchendo os vetores
  for (i = 0; i < n; i++)
  {
    printf(" 'M' se for homem, 'F' se for mulher\n'G' para gostei, 'N' para não gostei.\n");
    printf("Digite o sexo e a opnião da %iº pessoa (M/F e G/N)\n", i + 1);
    scanf(" %[^\n]s", &sexo[i]);
    scanf(" %[^\n]s",&opniao[i]);
  }

  //Separando a quantidade de mulheres que gostaram da pesquisa e homens que não gostaram da pesquisa
  for (i = 0; i < n; i++)
  {
    if(sexo[i] == 'F' && opniao[i] == 'G')
    {
      likeGirl++;
    }
    else if(sexo[i] == 'M' && opniao[i] == 'N')
    {
      likeMan++;
    }
  }
  
  //dividindo os entrevistados em homens e muçheres para calcular a pocentagem.
  for(i=0; i<n; i++){
    if(sexo[i] == 'F')
    {
      qtd_mulheres++;
    }
    if(sexo[i] == 'M')
    {
      qtd_homens++;
    }
  }

  porFem = (likeGirl/qtd_mulheres)*100;
  porMac = (likeMan/qtd_homens)*100;
  
  printf("%.1f%% das mulheres gostaram desse produto.\n", porFem); 
  printf("%.1f%% dos homens não gostaram desse produto.", porMac); 

  free(sexo);
  free(opniao);
  return(0);
}