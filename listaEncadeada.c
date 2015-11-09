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

void inserirNaLista(tipoNo **p, int valor) {
  tipoNo *aux;
  aux = (tipoNo*) malloc(sizeof(tipoNo));
  
  aux->val = valor;
  aux->prox = *p;
  *p = aux;
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
    if(elemento == p->val) return 1; // elemento encontrado
    p = p->prox;
  }
  return 0; // elemento NAO encontrado
}



int removerElemento(tipoNo *p, int elemento){
  tipoNo *aux;

  while(p){
    aux = p->prox;
    if(elemento == aux->val){
      p->prox = aux->prox;
      free(aux);
      return 1; // elemento removido
    }
    p = p->prox;
  }
  return 0; // nao encontrou o elemento
}


int removerElemento2(tipoNo **prim, int elemento){
  tipoNo *aux = NULL;
  tipoNo *p   = *prim;

  while(p){

    if(elemento == p->val){
      if(aux == NULL) *prim = p->prox;
      else             aux->prox = p->prox;
        free(p);
      }      
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

  for(numero=0; numero < 5; numero++) // criar lista com 5 elementos
    inserirNaLista(&prim, rand()%12); // 0 a 11

/* 
  while(fim){
    printf(">> Digite um numero para inserir: ");
    scanf("%d",&numero);
    inserirNaLista(&prim, numero);

    printf(">> Deseja inserir um valor na lista? (0 = nao): ");
    scanf("%d",&fim);
  }
*/

  mostrarElementosLista(prim);
  mostrarElementosLista(prim->prox->prox); // mostrar a partir do 3o elemento

  printf("\n>> Qual valor deseja buscar na lista?: ");
  scanf("%d",&numero);

  (buscarElementoNaLista(prim, numero)) ? printf(">> Valor encontrado\n") : printf(">> Valor nao encontrado\n");

}