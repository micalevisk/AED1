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
  tipoNo *temp;
  int maiorDado;
  
  if((aux1) && (aux2)){

    // 'aux1' define qual das listas devera ter todos os elementos maiores que a outra.
    aux1 = (aux1->dado > aux2->dado) ? aux1 : aux2;
    if(aux1 == aux2) aux2 = p1->prim;
    
    do{
      maiorDado = aux1->dado;
      
      // 'temp' percorre a lista apontada por 'aux2' a cada verificacao de um elemento de 'aux1'.
      for(temp = aux2; temp; temp = temp->prox)
	if( !(maiorDado > temp->dado) ) return 0;

      aux1 = aux1->prox;
    }while(aux1);
    
  } 

  return 1;
}



/// (2): VER SE A PRIMEIRA LISTA TEM APENAS VALORES MAIORES QUE A SEGUNDA LISTA.
int saoTodosMaiores(tipoLista A, tipoLista B){
  int menorA, maiorB; // Pois o menor de A deve ser maior que o maior de B.

  if((A.prim) && (B.prim)){
    for(menorA=A.prim->dado; A.prim; A.prim = A.prim->prox) if(A.prim->dado < menorA) menorA = A.prim->dado;
    for(maiorB=B.prim->dado; B.prim; B.prim = B.prim->prox) if(B.prim->dado > menorB) menorB = B.prim->dado;

    return (menorA > maiorB);
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

