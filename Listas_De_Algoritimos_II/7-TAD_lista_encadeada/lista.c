#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct lista
{
  int info;
  struct lista *prox;
};

/* Função de criação: retorna uma lista vazia */
Lista *lst_cria(void)
{
  return NULL;
}

/* Inserção no inicio: retorna a lista atualizada */
Lista *lst_insere(Lista *l, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

/* Função imprime: imprime valores dos elementos */
void lst_imprime(Lista *l)
{
  Lista *p; /* Variavel auxiliar para percorer a lista */
  for (p = l; p != NULL; p = p->prox)
    printf("Info = %d\n", p->info);
}

/* Função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia(Lista *l)
{
  if (l == NULL)
    return 1;
  else
    return 0;
}

/* Função busca: busca um elemento na lista */
Lista *lst_busca(Lista *l, int v)
{
  Lista *p;
  for (p = l; p != NULL; p = p->prox)
  {
    if (p->info == v)
      return p;
  }
  return NULL;
}

/* Função retira: retira elemtno da lista */
Lista *lst_retira(Lista *l, int v)
{
  Lista *ant = NULL;
  Lista *p = l;

  /* Procura elemento na lista, quardandoi o anterior */
  while (p != NULL && p->info != v)
  {
    ant = p;
    p = p->prox;
  }

  /* Verifica se achou o elemento */
  if (p == NULL)
  {
    return l; /* Não achou retorna a lista original */
  }

  /* Rerira elemento */
  if (ant == NULL)
  {
    /* Retira elemtno do inicio */
    l = p->prox;
  }
  else
  {
    /* Retira elemtno do meio */
    ant->prox = p->prox;
  }
  free(p);
  return l;
}

/* Função libera: liberta elementos alocados */
void lst_libera(Lista *l)
{
  Lista *p = l;
  while (p != NULL)
  {
    /* Guarda referencia p/ próx. elemento */
    Lista *t = p->prox;
    /* Libera a memória apontada por p */
    free(p);
    /* Faz p apontar para o proximo */
    p = t;
  }
}

/* Função insere ordenado: insere elementos em ordem */
Lista *lst_insere_ordenado(Lista *l, int v)
{
  Lista *novo;
  Lista *ant = NULL;
  Lista *p = l;

  /* Procura posição da inserção */
  while (p != NULL && p->info < v)
  {
    ant = p;
    p = p->prox;
  }

  /* Cria novo elemtno */
  novo = (Lista *)malloc(sizeof(Lista));
  novo->info = v;

  /* Encadeia elemento */
  if (ant == NULL)
  { /* Insere no início */
    novo->prox = l;
    l = novo;
  }
  else
  { /* Insere no meio da lista */
    novo->prox = ant->prox;
    ant->prox = novo;
  }

  return l;
}
