#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
  *area = (3 * pow(l, 2) * sqrt(3)) / 2;
  *perimetro = 6 * l;
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  float lado, area, p;
  printf("Digite o lado desse Hexagono:\n");
  scanf("%f", &lado);
  calcula_hexagono(lado, &area, &p);
  printf("A area do hexadono de lado %.1f é igual a %.2f e o seu perimetro é %.2f", lado, area, p);
  return(0);

}