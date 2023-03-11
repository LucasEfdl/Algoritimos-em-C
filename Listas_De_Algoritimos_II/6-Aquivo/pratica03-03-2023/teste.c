#include <stdio.h>

int main(){
    FILE *fp;
    int c;

    fp = fopen("arquivo.txt", "w");
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fputc('A', fp);
    fclose(fp);
    fp = fopen("arquivo.txt", "r");
    c = fgetc(fp);
    printf("%c\n", c);
    fclose(fp);
    

    return 0;
}
