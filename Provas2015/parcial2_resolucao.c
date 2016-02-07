//
//  parcial2_resolucao.c
//  Created by Micael Levi on 12/02/15.
//  Copyright (c) 2015 Micael Levi L. Cavalcante. All rights reserved
//

// ---------------- //
typedef struct no{
  int dado;
  struct no *prox;
}tipoNo;

typedef struct{
  tipoNo *prim;
}tipoLista;
// ---------------- //



/// (1): RETORNAR A QUANTIDADE DE ELEMENTOS QUE A LISTA POSSUI.
int numeroDeElementosDaLista(tipoLista p){
  int nElementos=0;

  for(; p.prim; p.prim = p.prim->prox) nElementos++;
  return nElementos;
}



/// (2): VER SE A PRIMEIRA LISTA TEM APENAS VALORES MAIORES QUE A SEGUNDA LISTA.
int saoTodosMaiores(tipoLista A, tipoLista B){
  tipoNo *auxB;
  int dado;

  if(!B.prim) return 1;
  
  while(A.prim){
    dadoA = A.prim->dado;
    
    for(auxB = B.prim; aux; aux = aux->prox)
      if( !(dadoA > auxB->dado ) ) return 0;

    A.prim = A.prim->prox;
  }

  return 1;
}



/// (3): VER SE DUAS LISTAS SAO IDENTICAS.
int saoIdenticas(tipoLista p1, tipoLista p2){
  while((p1.prim) && (p2.prim)){
    if(p1.prim->dado != p2.prim->dado) return 0;
    p1.prim = p1.prim->prox;
    p2.prim = p2.prim->prox;
  }

  return (!(p1.prim) && !(p2.prim));
}



/// (4): CORRIGIR FUNCAO DE INSERCAO ORDENADA.
void inserirOrdenado(tipoLista *L, int *d){
  tipoNo *aux, *aux2 = NULL;
  tipoNo *aux3 = L->prim;

  while((aux3) && (*d > aux3->dado)){
    aux2 = aux3;
    aux3 = aux3->prox;
  }

  aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dado = *d;
  aux->prox = aux3;
  
  if(aux2 != NULL) aux2->prox = aux;
  else                L->prim = aux;
}
