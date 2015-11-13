#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

typedef struct{             // informações sobre o elemento
  char nome[10];
  float preco;
} tipoProduto;

typedef  struct tipoNo{     // elemento da lista
  tipoProduto produto;
  struct tipoNo *prox;
} tipoNo;

typedef struct{             // guarda o endereço do primeiro da lista
  tipoNo *cabeca;
} tipoLista;



void criarLista(tipoLista *l) {
  l->cabeca = NULL;
}


void inserirNoInicioDaLista(tipoLista *l, tipoProduto elemento) { 
  tipoNo *novo;
  novo = (tipoNo*) malloc(sizeof(tipoNo));
  if(novo){             // alocacao realizada.
    novo->produto = elemento;
    novo->prox    = l->cabeca;
    l->cabeca     = novo;
  }
}


void inserirNoFinalDaLista(tipoLista *l, tipoProduto elemento) {
  tipoNo *novo, *aux = l->cabeca;
  novo = (tipoNo*) malloc(sizeof(tipoNo));
  
  if(novo){

    novo->produto = elemento;
    novo->prox    = NULL;

    if(!aux) l->cabeca = novo; // para lista vazia: o novo elemento será o cabeça
    else{
      while(aux->prox) aux = aux->prox;
      aux->prox = novo;
    }    
  }
}


void mostrarElementosDaLista(tipoLista *L) {
  tipoNo* aux = L->cabeca;
  while(aux){
    printf(" nome: %s | preco: %.2f \n", aux->produto.nome, aux->produto.preco);
    aux = aux->prox;
  }
}


tipoNo* buscarElementoNaLista(tipoLista l, char nomeElemento[]){ // (não otimizado)
  while(l.cabeca){
    if( !strcmp(l.cabeca->produto.nome, nomeElemento)  )
      return l.cabeca;
    
    l.cabeca = l.cabeca->prox;
  }  
  return NULL; // elemento NAO encontrado.
}


int removerElementoDaLista(tipoLista *L, char produto[]){
  tipoNo *anterior = NULL, *atual = L->cabeca;

  while(atual){
    if( !strcmp(atual->produto.nome, produto) ){
      if(!anterior) L->cabeca = atual->prox;
      else  anterior->prox = atual->prox;
      free(atual);
      return 1;
    }

    anterior = atual;
    atual    = atual->prox;    
  }
  return 0; 
}


void removerElementoDaPosicao(int k, tipoLista *l){
  tipoNo *anterior = NULL, *atual = l->cabeca;
  // atual 'anda' até ser o elemento que será removido
  for(; (atual) && (k>0); k--){
    if(k != 1){
      anterior = atual;
      atual    = atual->prox;
    }else{ 
      if(!anterior) l->cabeca = atual->prox;
      else     anterior->prox = atual->prox;
      free(atual);
    }
  }  
}


void removerElementoDaPosicao2(int k, tipoLista *l){ 
  tipoNo *anterior = l->cabeca, *proximo = NULL;
  
  if((k == 1) && (anterior)){
    l->cabeca = anterior->prox;
    free(anterior);
  }
  else{ // anterior 'anda' até ser o elemento antes do que será removido (k=1)
    for(; (anterior->prox) && (k>2); k--) anterior = anterior->prox;
    if(anterior != l->cabeca){
      proximo        = anterior->prox;
      anterior->prox = proximo->prox;
      free(proximo);
    }
  }  
}





int main() {
  srand(time(NULL));

  tipoLista lista;
  criarLista(&lista);

  tipoProduto comida, limpeza, corpo;
  strcpy(comida.nome, "Banana");  comida.preco = 2.57;
  strcpy(limpeza.nome, "SabaoP"); limpeza.preco = 5.34;
  strcpy(corpo.nome, "Toalha");   corpo.preco = 8.24;

  printf("\n>> Inserindo e Exibindo: \n");
  inserirNoFinalDaLista(&lista, comida);   // 2o
  inserirNoFinalDaLista(&lista, limpeza);  // 3o
  inserirNoInicioDaLista(&lista, corpo);   // 1o
  mostrarElementosDaLista(&lista);
  printf("\n");

  printf("\n>> Buscando e Retornando Resultado: \n");
  tipoNo *elemento = buscarElementoNaLista(lista, "Toalha");
  if(elemento){
    printf(">> O produto foi encontrado!: \n");
    printf(" NOME: %s -- PRECO: %.2f\n", elemento->produto.nome, (*elemento).produto.preco);
  }
  else
    printf("\n>> O produto buscado nao foi encontrado! \n");

  
  printf("\n>> Removendo e Exibindo: \n");
  (removerElementoDaLista(&lista, "Banana")) ? mostrarElementosDaLista(&lista) :
                                               printf(">> Produto nao encontrado!");
  printf("\n");


  int pos;
  printf("\n>> Removendo da Posicao 'pos' e Exibindo: \n");
  while(lista.cabeca){
    printf(">> Posicao do elemento a remover: ");
    scanf("%d",&pos);
    removerElementoDaPosicao2(pos, &lista);

    printf("\n>> Lista Atualizada: \n");
    (lista.cabeca) ? mostrarElementosDaLista(&lista): printf("<vazia>\n");
  }
  printf("\n");
  

}
