//
//  parcial2_resolucao.c
//  Created by Micael Levi on 02/12/15.
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
int numeroDeElementosDaLista(tipoLista *p){
  tipoNo *aux = p->prim;
  int nElementos=0;

  for(; aux; aux = aux->prox) nElementos++;
  return nElementos;
}



/// (2): VER SE UMA LISTA TEM APENAS ELEMENTOS COM 'dado's MAIORES QUE A OUTRA LISTA.
int saoTodosMaiores(tipoLista *p1, tipoLista *p2){
  tipoNo *aux1 = p1->prim;
  tipoNo *aux2 = p2->prim;
  tipoNo *temp, *fixo;
  int maiorDado;
  
  if((aux1) && (aux2)){

    // 'aux1' define qual das listas devera ter todos os elementos maiores que a outra.
    aux1 = (aux1->dado > aux2->dado) ? aux1 : aux2;
    if(aux1 == aux2) aux2 = p1->prim;
    
    fixo = aux2; // Fixando o primeiro da lista que, em tese, tem elementos menores que a outra.
    do{
      maiorDado = aux1->dado;
      
      // 'temp' percorre a lista apontada por 'aux2' a cada verificacao de um elemento de 'aux1'.
      for(temp = fixo; temp; temp = temp->prox)
	if( !(maiorDado > temp->dado) ) return 0;

      aux1 = aux1->prox;
      aux2 = aux2->prox;
    }while((aux1) && (aux2));
    
  } 

  return 1;
}



/// (3): VER SE DUAS LISTAS SAO IDENTICAS.
int saoIdenticas(tipoLista *p1, tipoLista *p2){
  tipoNo *aux1 = p1->prim;
  tipoNo *aux2 = p2->prim;

  while( (aux1) && (aux2)){
    if(aux1->dado != aux2->dado) return 0;
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }

  return (!(aux1) && !(aux2));
}



/// (4): CORRIGIR FUNCAO DE INSERCAO ORDENADA.

