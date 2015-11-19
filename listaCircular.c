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
  tipoNo *atual;	
} tipoListaCircular;


void criarListaCircular(tipoListaCircular *a){
  a->atual = NULL;
}


void inserirNaListaCircular(tipoListaCircular *a, tipoDado elemento){ // insere depois do 'atual'
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  tipoNo *temp = a->atual;

  if(aux){
    aux->dado = elemento;
    if(!temp) a->atual = aux; // lista vazia
    aux->prox = a->atual->prox;
    a->atual->prox = aux;    
  }
}


tipoNo* haElementosNaListaCircular(tipoListaCircular *a){
  return a->atual;
}


// [lista nunca vazia]
tipoDado removerDaListaCircular(tipoListaCircular *a){ // remove o sucessor de 'atual'
  tipoNo *aux    = a->atual;
  tipoNo *proximo= aux->prox;;
  tipoDado temp  = proximo->dado;

  // para lista de 1 elemento
  if(aux == proximo) a->atual = NULL;

  // para lista com mais de 1 elemento
  else aux->prox = proximo->prox;
  free(proximo);

  return temp;
}


void mostrarElementosDaListaCircular(tipoListaCircular *a){
  tipoNo *aux = a->atual;
  tipoNo *temp= aux;
  
  if(aux){
    do{
      printf(" valor: %d | quantidade: %u \n", aux->dado.valor, aux->dado.quantidade);
      aux = aux->prox;
    }while(aux != temp);
  }
}


int main(){

  tipoListaCircular lista;
  tipoDado d1, d2, d3;
  d1.valor = 1;      d2.valor = 2;      d3.valor = 3;
  d1.quantidade = 1; d2.quantidade = 2; d3.quantidade = 3;

  criarListaCircular(&lista);

  printf("\n>> Ha elementos? ");
  (haElementosNaListaCircular(&lista)) ? printf(" SIM\n") : printf(" NAO\n");

  printf("\n>> Inserindo elemtos: \n");
  inserirNaListaCircular(&lista, d1); // atual
  inserirNaListaCircular(&lista, d2);
  inserirNaListaCircular(&lista, d3);
  inserirNaListaCircular(&lista, d3);
	
  printf("\n>> Mostrando elementos: \n");
  mostrarElementosDaListaCircular(&lista);
  
  int loop=0;
  while(loop>=0){
    scanf("%d", &loop);
    printf("\n>> Removendo o proximo de atual e mostrando: \n");
    if(haElementosNaListaCircular(&lista)) removerDaListaCircular(&lista);
    else printf("\n <vazia> \n");
    mostrarElementosDaListaCircular(&lista);
  }
  
}
