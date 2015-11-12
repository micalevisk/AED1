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
    printf("%d, ",p->val);
    p = p->prox;
  }
  printf("\n");
}


tipoNo* buscarElemento(tipoNo *p, int elemento){
  while(p){
    if(elemento == p->val) return p; // elemento encontrado.
    p = p->prox;
  }
  return NULL; // elemento NAO encontrado.
}


int removerElemento(tipoNo **prim, int elemento){
  tipoNo *anterior = NULL;
  tipoNo *atual    = *prim;

  while(atual){
    if((atual->val) == elemento){
      if(!anterior) *prim  = atual->prox;
      else  anterior->prox = atual->prox;
      
      free(atual);
      return 1;
    }          
    anterior = atual;
    atual    = atual->prox;
  }
  return 0; // nao encontrou o elemento
}



void removerElementoDaPosicao(unsigned k, tipoNo **prim){
  tipoNo *anterior = NULL;
  tipoNo *atual = *prim;

  for(; atual; k--){
    if(k == 1){
      if(!anterior) *prim = atual->prox;
      else anterior->prox = atual->prox;

      free(atual);
      break;
    }
    anterior = atual;
    atual    = atual->prox;
  }  
}




int main() {
  srand(time(NULL));

  tipoNo *prim;
  criarLista(&prim);

  int fim=1;
  int numero;
  
  for(numero=0; numero < 5; numero++) // criar lista com 5 elementos
    inserirNoFinal(&prim, rand()%12); // 0 a 11
  
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
  
  while(prim){
    printf(">> Digite o valor do elemento que quer remover: ");
    scanf("%d",&numero);
    removerElemento(&prim, numero);
 
    printf("\n>> Lista alterada: ");
    mostrarElementosLista(prim);
  }
  
  /*
  printf("\n>> Qual valor deseja buscar na lista?: ");
  scanf("%d",&numero);

  (buscarElemento(prim, numero)) ? printf(">> Valor encontrado\n") :
                                   printf(">> Valor nao encontrado\n");
  */
}
