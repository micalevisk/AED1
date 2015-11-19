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
  tipoNo* prim;
  tipoNo* ult;
} tipoFila;


void criarFila(tipoFila *p){
  p->prim = NULL;
  p->ult  = NULL;
}


void inserirNaFila(tipoFila *p, tipoDado elemento){ // insere sempre no final
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dado = elemento;
  aux->prox = NULL;
  
  if(!p->prim) p->prim = aux; // para fila vazia
  else    p->ult->prox = aux;

  p->ult = aux;
}


tipoNo* haElementosNaFila(tipoFila *p){
  return p->prim;
}


tipoDado* removerDaFila(tipoFila *p){ // remove sempre o que esta na vez (primeiro)[fila nao vazia]
  tipoNo *aux   = p->prim;
  tipoDado temp = aux->dado;

  p->prim = aux->prox;
  free(aux);

  if(!p->prim) p->ult = NULL; // verifica se a fila tinha apenas 1 elemento
  return temp;
}


void mostrarElementosDaFila(tipoFila *p){
  tipoNo *aux = p->prim;

  while(aux){
    printf(" valor: %d | quantidade: %u \n", aux->dado.valor, aux->dado.quantidade);
    aux = aux->prox;
  }
}


//tipoNo* buscarElementoNaFila(tipoFila *p, tipoDado elemento){}  //buscar por 'valor'
