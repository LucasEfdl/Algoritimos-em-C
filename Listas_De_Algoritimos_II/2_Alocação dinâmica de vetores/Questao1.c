#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(void){
  setlocale(LC_ALL, "Portuguese");
  int n;
  float porFem = 0, porMac = 0;
  printf("Quantas pessoas participaram da pesquisa?");
  scanf("%i", &n);
  char *sexo, *opniao;
  sexo = (char*) malloc(n * sizeof(char)); 
  opniao = (char*) malloc(n * sizeof(char)); 

  for (int i = 0; i < n; i++){
    printf("Digite o sexo e a opnião da %iº pessoa (M/F e G/NG)\n", i + 1);
    scanf(" %c %c", &sexo[i], &opniao[i]);
    if(sexo[i] == 'F' && opniao[i] == 'G'){
      porFem++;
    }
    else if(sexo[i] == 'M' && opniao[i] == 'NG'){
      porMac++;
    }
  }

  porFem /= 100;
  porMac /= 100;

  printf("%f%% das mulheres gostaram desse produto.", porFem); 
  printf("%f%% dos homens não gostaram desse produto.", porMac); 

  free(sexo);
  free(opniao);
  return(0);
}