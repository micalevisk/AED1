#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

typedef  struct tipoNo {
  int val;
  struct tipoNo *prox;
} tipoNo;


void criarLista(tipoNo **p ) {
  *p = NULL;
}

void inserirNoInicio(tipoNo **p, int valor) { 
  tipoNo *aux;
  aux = (tipoNo*) malloc(sizeof(tipoNo));
  if(aux){             // alocacao realizada.
    aux->val = valor;
    aux->prox = *p;
    *p = aux;
  }
}

void inserirNoFinal(tipoNo **p, int valor) { 
  tipoNo *novoNo, *aux = *p;
  
  novoNo = (tipoNo*) malloc(sizeof(tipoNo));
  if(novoNo){             // alocacao realizada.
    novoNo->val  = valor;
    novoNo->prox = NULL;  // pois serah o ultimo da lista.

    if(!*p) *p = novoNo;  // para lista vazia.
    else{                 // para lista nao vazia.
      while(aux->prox)	aux = aux->prox;
      aux->prox = novoNo; 
    }       
  }
}

void mostrarElementosLista(tipoNo *p) {
  while(p) {
    printf("%d ",p->val);
    p = p->prox;
  }
  printf("\n");
}


int buscarElementoNaLista(tipoNo *p, int elemento){
  while(p){
    if(elemento == p->val) return 1; // elemento encontrado.
    p = p->prox;
  }
  return 0; // elemento NAO encontrado.
}



int removerElemento(tipoNo **p, int elemento){
  tipoNo *pp = *p;
  tipoNo *aux = NULL;
  
  while(pp){

    if(!aux){
      if(pp->val == elemento){
	*p = pp->prox;
	free(pp);
	return 1;
      }
    }

    aux = pp->prox;    
    if(aux){
      if(aux->val == elemento){
	pp->prox = aux->prox;
	free(aux);
	return 1;
      } 
    }
    pp = aux;
  }
  
  return 0; // nao encontrou o elemento
}

// TO FIX:
int removerElemento2(tipoNo **prim, int elemento){
  tipoNo *aux = NULL;
  tipoNo *p   = *prim;

  while(p){

    if(elemento == p->val){
      if(aux == NULL) *prim = p->prox;
      else             aux->prox = p->prox;
      free(p);
      return 1; // elemento removido
    }          
    aux = p;
    p = p->prox;
  }
  return 0; // nao encontrou o elemento
}




int main() {
  srand(time(NULL));

  tipoNo *prim;
  criarLista(&prim);

  int fim=1;
  int numero;
/* rand()%12 */
  for(numero=0; numero < 5; numero++) // criar lista com 5 elementos
    inserirNoFinal(&prim, numero); // 0 a 11

  /* 
     while(fim){
     printf(">> Digite um numero para inserir: ");
     scanf("%d",&numero);
     inserirNoInicio(&prim, numero);

     printf(">> Deseja inserir um valor na lista? (0 = nao): ");
     scanf("%d",&fim);
     }
  */

  printf(">> Lista criada: ");
  mostrarElementosLista(prim);

  printf(">> Digite o valor do elemento que quer remover: ");
  scanf("%d",&numero);
  removerElemento(&prim, numero);

  printf("\n>> Lista alterada: ");
  mostrarElementosLista(prim);
   
  /*
  printf("\n>> Qual valor deseja buscar na lista?: ");
  scanf("%d",&numero);

  (buscarElementoNaLista(prim, numero)) ? printf(">> Valor encontrado\n") :
                                          printf(">> Valor nao encontrado\n");
  */
}
