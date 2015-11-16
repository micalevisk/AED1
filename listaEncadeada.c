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
  tipoNo *prim;
} tipoLista;



void criarLista(tipoLista *l) {
  l->prim = NULL;
}


void inserirNoInicioDaLista(tipoLista *l, tipoProduto elemento) { 
  tipoNo *novo;
  novo = (tipoNo*) malloc(sizeof(tipoNo));
  if(novo){             // alocacao realizada.
    novo->produto = elemento;
    novo->prox    = l->prim;
    l->prim     = novo;
  }
}


void inserirNoFinalDaLista(tipoLista *l, tipoProduto elemento) {
  tipoNo *novo, *aux = l->prim;
  novo = (tipoNo*) malloc(sizeof(tipoNo));
  
  if(novo){
    novo->produto = elemento;
    novo->prox    = NULL;

    if(!aux) l->prim = novo; // para lista vazia: o novo elemento será o cabeça
    else{
      while(aux->prox) aux = aux->prox;
      aux->prox = novo;
    }    
  }
}


void mostrarElementosDaLista(tipoLista *L) {
  tipoNo* aux = L->prim;
  while(aux){
    printf(" nome: %s | preco: %.2f \n", aux->produto.nome, aux->produto.preco);
    aux = aux->prox;
  }
}


tipoNo* buscarElementoNaLista(tipoLista l, char nomeElemento[]){ // (não otimizado)
  while(l.prim){
    if( !strcmp(l.prim->produto.nome, nomeElemento)  )
      return l.prim;
    
    l.prim = l.prim->prox;
  }  
  return NULL; // elemento NAO encontrado.
}


int removerElementoDaLista(tipoLista *L, char produto[]){
  tipoNo *anterior = NULL, *atual = L->prim;

  while(atual){
    if( !strcmp(atual->produto.nome, produto) ){
      if(!anterior) L->prim = atual->prox;
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
  tipoNo *anterior = NULL, *atual = l->prim;
  // atual 'anda' até ser o elemento que será removido ()
  for(; (k>0) && (atual); k--){
    if(k != 1){
      anterior = atual;
      atual    = atual->prox;
    }else{ 
      if(!anterior) l->prim = atual->prox;
      else     anterior->prox = atual->prox;
      free(atual);
    }
  }  
}


void removerElementoDaPosicao1(int k, tipoLista *l){
  tipoNo *anterior = NULL, *atual = l->prim;
  // "atual" 'anda' até ser o elemento que será removido.
  // "anterior" será o elemento anterior ao "atual".
  for(; (k>1) && (atual); k--){
    anterior = atual;
    atual    = atual->prox;
  }
  
  if((k>0) && (atual)){
    if(!anterior) l->prim = atual->prox; // Caso seja a remoção do primeiro elemento da lista.
    else   anterior->prox = atual->prox; // O próximo elemento anterior ao que será removido
                                         // altera para o próximo do elemento que será removido.
    free(atual);
  }
}


void concatenarListas(tipoLista *A, tipoLista *B){
  tipoNo *aux;
  if(B){
    aux = A->prim;
    if(!aux) A->prim = B->prim;
    else{
      while(aux->prox) aux = aux->prox;
      aux->prox = B->prim;
    }
    B->prim = NULL;    
  }
}


void apagarLista(tipoLista *l){
  while(l->prim)
    removerElementoDaPosicao(1, l);  
}



int main() {
  srand(time(NULL));

  tipoLista lista;
  criarLista(&lista);

  tipoProduto comida, limpeza, corpo;
  strcpy(comida.nome, "Banana");  comida.preco = 2.57;
  strcpy(limpeza.nome, "SabaoP"); limpeza.preco= 5.34;
  strcpy(corpo.nome, "Toalha");   corpo.preco  = 8.24;

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
  while(lista.prim){
    printf(">> Posicao do elemento a remover: ");
    scanf("%d",&pos);
    removerElementoDaPosicao(pos, &lista);

    printf("\n>> Lista Atualizada: \n");
    (lista.prim) ? mostrarElementosDaLista(&lista): printf("<vazia>\n");
  }
  printf("\n");

}
