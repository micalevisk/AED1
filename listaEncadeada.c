#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int val;
  struct No *prox;
}tipoNo;

void criarListaDinamica(tipoNo **p){
  *p = NULL;
}

void inserirNaLista(tipoNo **p, int valor){
  tipoNo *nova = (tipoNo*) malloc(sizeof(tipoNo));
  nova->val = valor;

  nova->prox = p->prox;
  p->prox    = nova;
}
