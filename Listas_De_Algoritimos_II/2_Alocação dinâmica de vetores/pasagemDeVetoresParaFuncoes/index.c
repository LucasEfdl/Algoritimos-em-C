#include<stdio.h>
#include<stdlib.h>

/* Cálculo da média e da variância de 10 notas*/
float media(int n, float * v) {
  int i;
  float s = 0.0f;
  for(i = 0; i < n; i++){
    s += v[i];
  }
  return s/n;
}

float variancia(int n, float * v, float m) {
  int i;
  float s = 0.0f;
  for(i = 0; i < n; i++) {
    s += (v[i]-m)*(v[i]-m);
  }
  return s/n;
}


int main(void) {
  float med, var;
  int i, notas;
  printf("Informe a quantidade de notas:\n");
  scanf("%d", &notas);

  float * v = (float *) malloc(notas*sizeof(float));

  printf("Insira as notas do aluno:\n");
  for(i = 0; i < notas; i++){
    scanf("%f", &v[i]);
  }
  med = media(notas, v); //pq que não usa "&v"?
  var = variancia(notas, v, med); //pq que não usa "&v"?
  printf("Media = %.2f variancia = %.2f\n", med, var);
}