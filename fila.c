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


void inserirNaFila(tipoFila *p, tipoDado elemento){ // insere sempre no final.
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dado = elemento;
  aux->prox = NULL;
  
  if(!p->prim) p->prim = aux; // para fila vazia.
  else    p->ult->prox = aux;

  p->ult = aux;
}


tipoNo* haElementosNaFila(tipoFila *p){
  return p->prim;
}


tipoDado removerDaFila(tipoFila *p){ // remove sempre o que esta na vez (primeiro)[fila nao vazia].
  tipoNo *aux   = p->prim;
  tipoDado temp = aux->dado;

  if(!aux->prox) p->ult = NULL; // verifica se a fila tem apenas 1 elemento.
  p->prim = aux->prox;
  free(aux);

  return temp;
}


void mostrarElementosDaFila(tipoFila *p){
  tipoNo *aux = p->prim;

  while(aux){
    printf(" valor: %d | quantidade: %u \n", aux->dado.valor, aux->dado.quantidade);
    aux = aux->prox;
  }
}


tipoNo* buscarElementoNaFila(tipoFila *p, int elemento){  //buscar por 'valor'.
  tipoNo *aux = p->prim;
  while(aux){
    if(aux->dado.valor == elemento) return aux;
    aux = aux->prox;
  }
  return NULL;  
} 


int inverterFila(tipoFila *p){
  tipoNo *aux  = p->prim; // Para percorrer a lista.
  tipoNo *temp = p->prim; // Para fixar o primeiro 'original'.
  tipoNo *neo  = p->ult;  // Novo nó que é 'inserido' na fila.

  if((!aux) || (aux == neo)) return 0; // Fila vazia ou com apenas 1 nó.

  do{
    
    for(aux = temp; aux->prox != neo; aux = aux->prox); // "aux" é o nó anterior ao "neo".
    neo->prox = aux;
    neo = aux;
    
  }while(aux != temp);
	
  neo->prox = NULL;
  
  p->prim = p->ult;
  p->ult  = neo;
 
  return 1;
}
