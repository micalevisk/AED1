#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{    
  char nome[10];
  float preco;
} tipoProduto;

typedef  struct tipoNo{
  tipoProduto produto;
  struct tipoNo *prox;
} tipoNo;

typedef struct{        
  tipoNo *prim;
} tipoLista;



void criarLista(tipoLista *l) {
  l->prim = NULL;
}


void inserirNoInicioDaLista(tipoLista *l, tipoProduto elemento) { 
  tipoNo *novo = (tipoNo*) malloc(sizeof(tipoNo));
  
  novo->produto = elemento;
  novo->prox    = l->prim;
  l->prim       = novo;
}


void inserirNoFinalDaLista(tipoLista *l, tipoProduto elemento) {
  tipoNo *novo, *aux = l->prim;
  
  novo = (tipoNo*) malloc(sizeof(tipoNo));
  novo->produto = elemento;
  novo->prox    = NULL;

  if(!aux) l->prim = novo; // para lista vazia: o novo elemento sera o primeiro.
  else{
    while(aux->prox) aux = aux->prox;
    aux->prox = novo;
  }     
}


void mostrarElementosDaLista(tipoLista *L) {
  tipoNo* aux = L->prim;
  while(aux){
    printf(" nome: %s | preco: %.2f \n", aux->produto.nome, aux->produto.preco);
    aux = aux->prox;
  }
}


tipoNo* buscarElementoNaLista(tipoLista l, char nomeElemento[]){
  while(l.prim){
    if( !strcmp(l.prim->produto.nome, nomeElemento)  )
      return l.prim;
    
    l.prim = l.prim->prox;
  }  
  return NULL; // elemento NAO encontrado ou lista vazia.
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


void removerElementoDaPosicao(int k, tipoLista *l){   // atual 'anda' ate ser o elemento que sera removido .
  tipoNo *anterior = NULL, *atual = l->prim;

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
  // "atual" 'anda' ate ser o elemento que sera removido.
  // "anterior" sera o elemento anterior ao "atual".
  for(; (k>1) && (atual); k--){
    anterior = atual;
    atual    = atual->prox;
  }
  
  if((k>0) && (atual)){
    if(!anterior) l->prim = atual->prox; // Caso seja a remocao do primeiro elemento da lista.
    else   anterior->prox = atual->prox; // O proximo elemento anterior ao que sera removido
                                         // altera para o proximo do elemento que sera removido.
    free(atual);
  }
}


void removerElementoDaPosicao2(int k, tipoLista *l){
  tipoNo *anterior = l->prim, *proximo;

  if((k>0) && (anterior)){ 
    
    for(; (k>2) && (anterior->prox); k--) anterior = anterior->prox;
    proximo = anterior->prox;

    if(k==1){ 
      l->prim = proximo;
      free(anterior);
    }
    else if(proximo){ 
      anterior->prox = proximo->prox;
      free(proximo);      
    }

  }
}


void removerElementoDaPosicao3(int k, tipoLista *l){
  tipoNo *aux = l->prim; // anterior ao que sera removido.
  tipoNo *proximo;       // o que sera removido.

  for(; (aux) && (k > 2); aux = aux->prox) k--;

  if((aux) && (k>0) && (k<3)){
    proximo = (k == 1) ? aux : aux->prox;

    if(k == 1)         l->prim = aux->prox;
    else if(proximo) aux->prox = proximo->prox;

    free(proximo);    
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


int inverterListaEncadeada(tipoLista *p){
  tipoNo *aux  = p->prim;
  tipoNo *ultimo;     // ultimo  no.
  tipoNo *temp = aux; // fixando o primeiro.
  
  if(!(aux) || !(aux->prox)) return 0;
  for(ultimo = aux; ultimo->prox; ultimo = ultimo->prox); 
	
  p->prim = ultimo;

  do{

    for(aux = temp; aux->prox != ultimo; aux = aux->prox);
    ultimo->prox = aux;
    ultimo	 = aux;

  }while(aux != temp);
	
  ultimo->prox = NULL;

  return 1;
}

// Retorna 0 se nao houve erros na gravacao dos dados.
int gravarListaNumArquivo(tipoLista *p){
  tipoNo* aux = p->prim;
  FILE* arq;
  char diretorio[100];

  if(!aux) return 0;

  printf("<< Digite o caminho e nome do arquivo que armazenara os dados:\n");
  gets(diretorio);

  // Cria (se nao existir) e adiciona os dados:
  if( !(arq = fopen(diretorio, "a+b")) ){
    perror("\aAo criar/abrir o arquivo");
    return 1; 
  }

  for(; aux; aux = aux->prox) fwrite(&(aux->produto), sizeof(tipoProduto), 1, arq);
  fclose(arq);
  
  return 0;
}


// Retorna 0 se nao houve erro ao ler os dados do arquivo para a lista.
int lerListaDeUmArquivo(tipoLista *p){
  tipoNo* novo;
  tipoProduto pdr_buffer;
  FILE* arq;
  char diretorio[100];

  printf("<< Digite o caminho e nome do arquivo que armazena os dados da lista:\n");
  gets(diretorio);

  if( !(arq = fopen(diretorio, "rb")) ){
    perror("\aAo abrir o arquivo");
    return 1; 
  }

  p->prim = NULL;
  
  while(fread(&pdr_buffer, sizeof(tipoProduto), 1, arq)){
    novo = (tipoNo*) malloc(sizeof(tipoNo)); // Criando um novo no e inserindo no inicio da lista:
    novo->produto = pdr_buffer;
    novo->prox    = p->prim;
    p->prim       = novo;
  }

  fclose(arq);

  return 0;
}



int main() {

  tipoLista lista;
  criarLista(&lista);
  /*
  tipoProduto comida, limpeza, corpo;
  strcpy(comida.nome, "Banana");  comida.preco = 2.57;
  strcpy(limpeza.nome, "SabaoP"); limpeza.preco= 5.34;
  strcpy(corpo.nome, "Toalha");   corpo.preco  = 8.24;
  
  printf("\n>> Inserindo e Exibindo: \n");
  inserirNoFinalDaLista(&lista, comida);   // 5o Banana
  inserirNoFinalDaLista(&lista, limpeza);  // 6o SabaoP
  inserirNoInicioDaLista(&lista, corpo);   // 4o Toalha
  inserirNoInicioDaLista(&lista, limpeza); // 3o SabaoP
  inserirNoInicioDaLista(&lista, corpo);   // 2o Toalha
  inserirNoInicioDaLista(&lista, comida);  // 1o Banana
  mostrarElementosDaLista(&lista);
  printf("\n");
  
  gravarListaNumArquivo(&lista);
  */
  
  lerListaDeUmArquivo(&lista);
  
  mostrarElementosDaLista(&lista);
  printf("\n");
  
}
