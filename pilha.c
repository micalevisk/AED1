#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  int valor;
  unsigned quantidade;
} tipoDado;

typedef struct no{
  tipoDado dado;
  struct no *prox;
} tipoNo;


typedef struct{
  tipoNo *topo;
} tipoPilha;



void criarPilha(tipoPilha *t){
  t->topo = NULL;
}


void inserirNaPilha(tipoPilha *t, tipoDado elemento){ // sempre no topo da pilha
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dado = elemento;

  aux->prox = t->topo;
  t->topo   = aux;
}


tipoNo* haElementosNaPilha(tipoPilha *t){
  return t->topo;
}


tipoDado removerDaPilha(tipoPilha *t){ // remove sempre o de cima (topo)
  tipoNo *aux   = t->topo;
  tipoDado temp = aux->dado;

  t->topo = aux->prox;
  free(aux);
  return temp;  
}


void mostrarElementosDaPilha(tipoPilha *t){
  tipoNo *aux = t->topo;

  while(aux){
    printf(" valor: %d | quantidade: %u \n", aux->dado.valor, aux->dado.quantidade);
    aux = aux->prox;
  }
}


tipoNo* buscarElementoNaPilha(tipoPilha *t, int elemento){  //buscar por 'valor'
  tipoNo *aux = t->topo;
  while(aux){
    if(aux->dado.valor == elemento) return aux;
    aux = aux->prox;
  }
  return NULL;
} 
