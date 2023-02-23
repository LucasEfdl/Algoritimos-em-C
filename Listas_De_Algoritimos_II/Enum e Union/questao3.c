#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef enum mes{
	JANEIRO, 
	FEVEREIRO, 
	MARCO, 
	ABRIL, 
	MAIO,
	JUNHO, 
	JULHO, 
	AGOSTO, 
	SETEMBRO,
	OUTUBRO, 
	NOVEMBRO,
	DEZEMBRO
}Mes;

typedef struct data{
	int dia;
	int ano;
	Mes mes;
}Data;


int main(void) {
	
	setlocale(LC_ALL, "Portugues");
	Data data;
	printf("Dia: ");
	scanf("%d", &data.dia);
	printf("Digite o mes: ");
	scanf("%d", (int *)&data.mes);
	printf("Ano:");
	scanf("%d", &data.ano);
	
	printf("Data informada\n");
	
	data.mes <= OUTUBRO?printf("%d/0%d/%d", data.dia, data.mes, data.ano):printf("%d/%d/%d", data.dia, data.mes, data.ano);
	
	return(0);
}
