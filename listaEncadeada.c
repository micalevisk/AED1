#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int val;
  struct No *prox;
}tipoNo;


void criarLista(tipoNo **prim){
  *prim = NULL;
}

void inserirNaLista(tipoNo **prim, int valor){
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->val = valor;

  aux->prox = *prim;
  *prim     = aux;
}

int valorDoPrimeiro(tipoNo *prim){
  if(prim) return prim->val; // prim != NULL
  return 0;
}

void mostrarLista(tipoNo *prim){
  tipoNo *aux = prim;

  while(aux != NULL){
    printf("%d, ",aux->val);
    aux = aux->prox;    
  }
  printf("\n");
}




int main(){

  tipoNo *primeiro;
  
  criarLista(&primeiro);
  
  inserirNaLista(&primeiro, 1);
  inserirNaLista(&primeiro, 2);
  inserirNaLista(&primeiro, 3);
  
  mostrarLista(primeiro); // 3, 2, 1,
}
