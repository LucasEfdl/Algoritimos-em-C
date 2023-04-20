#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

typedef struct lista
{
    float info;
    struct lista * prox;
}Lista;

struct pilha
{
    Lista * first;
};

Pilha * pilha_cria(void){
    Pilha * p = (Pilha*) malloc(sizeof(Pilha));
    p->first = NULL;
    if(p == NULL){
        printf("Erro de alocação!");
        exit(1);
    }
    return p;
}

int pilha_vazia(Pilha * p){
    return(p->first == NULL);
}

void pilha_push(Pilha* p, float v){
    Lista * list = (Lista*) malloc(sizeof(Lista));
    if(list == NULL){
        printf("Erro de alocação!");
        exit(1);
    }

    list->info = v;
    list->prox = p->first;
    p->first = list;
}

float pilha_pop(Pilha * p){
    if(pilha_vazia(p)){
        printf("Não há elementos na pelha");
        exit(1);
    }

    Lista * t;
    float v;

    t = p->first;
    v = t->info;
    p->first = t->prox;
    free(t);

    return v;
}

void pilha_libera(Pilha * p){
    Lista* q = p->first;
    Lista* t;

    while (q != NULL)
    {
        t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

float topo(Pilha* p){
    Lista* t = (Lista*) malloc(sizeof(Lista));
    t = p->first;
    float v = t->info;
    return v; 
}

void imprime(Pilha* l){
    Lista* p;
    for(p = l->first; p != NULL; p=p->prox)
        printf(" Info = %.2 \n", p->info);
}

void concatena(Pilha* p1, Pilha* p2){
    Lista* aux = NULL;
    while(p2->first != NULL){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        if (novo == NULL)
        {
            printf("Erro na alocação de memoria!");
            exit(1);
        }

        novo->info = pilha_pop(p2);
        novo->prox = aux;
        aux = novo;   
    }

    while (aux != NULL)
    {
        pilha_push(p1, aux->info);
        aux = aux->prox;
    }
}

Pilha* copia_pilha(Pilha* l){
    Pilha* copia = pilha_cria();
    Lista* p; 
    for(p = l->first; p != NULL; p = p->prox){
        pilha_push(copia, p->info); 
    }
    return copia;
}

