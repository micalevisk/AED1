// ALUNO    : Micael Levi L. C.
// MATRÍCULA: 21554923
// TURMA    : CB01
// CORREÇÃO : 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoDados{
  char nome[20];
  char endereco[40];
  int id;
}tipoDados;



/// (1)
typedef struct tipoNo{
  tipoDados dados;
  struct tipoNo *prox;
}tipoNo;
typedef struct{
  tipoNo* topo;
}tipoPilha;


void criarPilha(tipoPilha *t){
  t->topo = NULL;
}

void inserirNaPilha(tipoPilha *t, tipoDados elemento){
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dados = elemento;

  aux->prox = t->topo;
  t->topo   = aux;
}

tipoDados removerDaPilha(tipoPilha *t){ 
  tipoNo *aux    = t->topo;
  tipoDados temp = aux->dados;

  temp = aux->dados;

  t->topo = aux->prox;
  free(aux);

  return temp; 
}



/// (2)
typedef struct tipoNo{
  tipoDados dados;
  struct tipoNo *prox;
}tipoNo;
typedef struct{
  tipoNo *prim;
  tipoNo *ult;
}tipoFila;


void criarFila(tipoFila *p){
  p->prim = NULL;
  p->ult  = NULL;
}

void inserirNaFila(tipoFila *p, tipoDados elemento){ // Insere no final.
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dados = elemento;
  aux->prox  = NULL;

  if(!p->prim) p->prim = aux;
  else    p->ult->prox = aux;
  p->ult = aux;
}

tipoDados removerDaFila(tipoFila *p){ // Admitindo uma fila nunca vazia.
  tipoNo   *aux  = p->prim;
  tipoDados temp = aux->dados;

  if(!aux->prox) p->ult = NULL;
  p->prim = aux->prox;
  free(aux);

  return temp;
}



/// (3)
typedef struct tipoNo{
  tipoDados dados;
  struct tipoNo *prox;
}tipoNo;
typedef struct{
  tipoNo *atual;
}tipoListaCircular;


void criarListaCircular(tipoListaCircular *a){
  a->atual = NULL;
}

void inserirNaListaCircular(tipoListaCircular *a, tipoDados elemento){
  tipoNo *aux  = (tipoNo*) malloc(sizeof(tipoNo));
  tipoNo *temp = a->atual;
  aux->dados   = elemento;

  if(!temp) a->atual = aux;
  else     aux->prox = temp->prox;

  a->atual->prox = aux;
}

tipoDados removerDaListaCircular(tipoListaCircular *a){ 
  tipoNo *aux     = a->atual;
  tipoNo *proximo = aux->prox;
  tipoDados temp  = proximo->dados;

  if(aux == proximo) a->atual = NULL;
  else              aux->prox = proximo->prox;

  free(proximo);
  return temp;
}

int atualizarAtualDaListaCircular(tipoListaCircular *a, int idNovo){
  tipoNo *aux  = a->atual;
  tipoNo *temp = aux;

  if(aux){
    aux = aux->prox;
    do{
      if((aux->dados.id) == idNovo){
	a->atual = aux;
	return 1;
      }
      aux = aux->prox;
    }while(aux != temp);
  }

  return 0;
}



/// (4)
typedef struct tipoNo{
  tipoDados dados;
  struct tipoNo *prox;
}tipoNo;


unsigned elementosIguaisA(int K, tipoListaCircular *a){
  unsigned vezes=0;
  tipoNo *aux = a->atual;
  tipoNo *temp= aux;

  if(aux){
    do{
      if((aux->dados.id) == K) vezes++;
      aux = aux->prox;
    }while(aux != temp);
  }
  return vezes;
}



/// (5)
typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
}tipoNo;
typedef struct{
  tipoNo *topo;
}tipoPilha;


void inserirVetorNaPilha(tipoPilha *t, int v[], int k){
  int i = 0;
  tipoNo *aux;

  if(!t->topo){ 
    for(; i < k; i++){
      aux = (tipoNo*) malloc(sizeof(tipoNo));
      aux->dado = v[i];

      aux->prox = t->topo;
      t->topo   = aux;
    }
  }
}



/// (6)
typedef struct{
  tipoNo *prim;
}tipoListaEncadeada;


void removerElementoDaPosicao(int k, tipoListaEncadeada *p){
  tipoNo *anterior = NULL;
  tipoNo *atual    = p->prim;
    
  for(; (k>1) && (atual); k--){
    anterior = atual;
    atual    = atual->prox;
  }

  if((k>0) && (atual)){
    if(!anterior) p->prim = atual->prox; 
    else   anterior->prox = atual->prox;
    free(atual);
  }
}



/// (7)
typedef struct tipoNoSimples{
  int valor;
  struct tipoNoSimples *prox;
}tipoNoSimples;
typedef struct{
  tipoNoSimples *primeiro;
}tipoListaEncadeadaSimples;

int verSimetriaDaListaSimples(tipoListaEncadeadaSimples *p){
  tipoNoSimples *aux = p->primeiro, *fixado = aux, *aux2;	  
  unsigned nElementos=0, limite, iSimetrico;		          

  if((!aux) || (!aux->prox)) return 0;

  for(; aux; nElementos++, aux = aux->prox); 	

  limite = nElementos/2;						
  (nElementos % 2 == 0) ? (iSimetrico=limite+1) : (iSimetrico=limite+2);

  for(aux=fixado; iSimetrico > 1; aux=aux->prox, iSimetrico--);
  aux2 = aux;                                

  do{
    for(aux=aux2; aux; aux=aux->prox)
      if(aux->valor == fixado->valor) break; 

    if(!aux) return 0;

    fixado = fixado->prox;
    limite--;
  }while( limite>0 );

  return 1;
}



/// (8)
typedef struct tipoNo{
  tipoDados dados;
  struct tipoNo *prox;
}tipoNo;
typedef struct tipoLista{
  tipoNo *prim;
}tipoLista;


void transferirListaEncadeada(tipoLista *p, tipoNo v[]){
  tipoNo *aux;

  for(; p->prim; v++){
    aux  = p->prim;
    *v = *aux;

    p->prim = aux->prox;
    free(aux);
  }
}



/// (9)
typedef struct tipoNoSimples{
  char nome[50];
  struct tipoNoSimples *prox;
}tipoNoSimples;
typedef struct{
  tipoNoSimples *prim;
}tipoFila;


void mostrarElementosDaFilaInverso(tipoFila p){
  tipoNoSimples *aux = p.prim;
  if(aux){
    p.prim = aux->prox;
    mostrarElementosDaFilaInverso(p);
    printf(" nome: %s \n", aux->nome);
  }
}



/// (10)

void trocar(tipoDados* a, tipoDados* b){
  tipoDados aux = *a;
  *a = *b;
  *b = aux;
}

void insertionSort(tipoDados v[], int posInicial, int posFinal){
  int i, j;
  tipoDados pivot;

  for(i=posInicial; i <= posFinal; i++){
    pivot = v[i];

    for(j=i-1; (j >= 0) && (strcmp(v[j].nome, pivot.nome) > 0); j--)
      v[j+1] = v[j];

    v[j+1] = pivot;
  }
}


int particionar(tipoDados v[], int inicio, int fim){
  tipoDados pivot=v[fim];
  int i=inicio-1;     
  int j;

  for(j=inicio; j <= fim-1; j++){
    if(strcmp(v[j].nome, pivot.nome) <= 0){
      i++;
      if(i != j) trocar(&v[i], &v[j]);
    }
  }

  trocar(&v[i+1], &v[fim]);

  return (i + 1);
}

void quickSortInterno(tipoDados v[], int inicio, int fim){
  if(fim > inicio){
    int tamanho;
    int p = particionar(v, inicio, fim);   

    tamanho = (p-1 - inicio+1); 
    if(tamanho >= 10) quickSortInterno(v, inicio, p-1);
    else              insertionSort(v, inicio, p-1);

    tamanho = (fim - p+1);      
    if(tamanho >= 10) quickSortInterno(v, p+1, fim);
    else              insertionSort(v, p+1, fim);
  }
}

void quickInsertionSort(tipoDados v[], int n){
  quickSortInterno(v, 0, n-1);
}



/// (11)
void intercalar(tipoDados v[], tipoDados vaux[], int inicio, int fim, int meio){
  int i = inicio;
  int j = meio+1;
  int k = inicio;

  while((i <= meio) && (j <= fim)){
    if(strcmp(v[i].nome, v[j].nome) < 0){ 
      vaux[k] = v[i];
      i++;
    }
    else{
      vaux[k] = v[j];
      j++;
    }
    k++;
  }

  while(i <= meio){
    vaux[k] = v[i];
    i++;
    k++;
  }

  while(j <= fim){
    vaux[k] = v[j];
    j++;
    k++;
  }

  for(k=inicio; k<=fim; k++) v[k] = vaux[k];
}

void mergeSortInterno(tipoDados v[], tipoDados vaux[], int inicio, int fim){
  int meio;
  if(inicio < fim){
    meio = (inicio+fim)/2;
    mergeSortInterno(v, vaux, inicio, meio); 
    mergeSortInterno(v, vaux, meio+1, fim); 
    intercalar(v, vaux, inicio, fim, meio);  
  }
}

void mergeSortNomes(tipoDados v[], int n){
  tipoDados *vaux = (tipoDados*) malloc(sizeof(tipoDados)*n);
  mergeSortInterno(v, vaux, 0, n-1);
  free(vaux);
}



/// (12)
void particionar(tipoDados v[], int inicio, int fim){
  int pivot, i, j;
  tipoDados aux;

  if(fim - inicio > 0){
    i = inicio;
    j = fim;
    pivot = v[(i+j)/2].id;
    do{
      while(v[i].id < pivot) i++;
      while(v[j].id > pivot) j--;
      if(i <= j){
	aux  = v[i];
	v[i] = v[j];
	v[j] = aux;
	i++; j--;
      }
    }while(i <= j);

    if(inicio < j) particionar(v, inicio, j);
    if(i < fim)    particionar(v, i, fim);
  }
}

void quickSort(tipoDados v[], int n){
  particionar(v, 0, n-1);
}



/// (13)
void trocar(tipoDados* a, tipoDados* b){
  tipoDados aux = *a;
  *a = *b;
  *b = aux;
}

int particionar(tipoDados v[], int inicio, int fim){
  tipoDados pivot = v[fim];
  int i = inicio-1;
  int j = inicio;

  for(; j <= fim-1; j++){
    if(v[j].id <= pivot.id){
      i++;
      if(i != j) trocar(&v[i], &v[j]);
    }
  }

  trocar(&v[i+1], &v[fim]);

  return (i + 1);
}

void quickSortInterno(tipoDados v[], int inicio, int fim){
  if(fim > inicio){
    int p = particionar(v, inicio, fim);
    quickSortInterno(v, inicio, p-1);
    quickSortInterno(v, p+1, fim);
  }
}

void quickSortParcial(tipoDados v[], int inicio, int fim, int k){
  if(fim > inicio){
    int p = particionar(v, inicio, fim);

    if(p == 0)      quickSortParcial(v, p+1, fim, k);
    else if(p > k)  quickSortParcial(v, 0,   p-1, k);
    else if(p < k)  quickSortParcial(v, 0,   p+1, k);
    else if(p == k) quickSortInterno(v, 0, p-1);
  }
}

void quickSort(tipoDados v[], int n, int k){
  if(k < n){
    quickSortParcial(v, 0, n-1, k);
    int i;
    printf(">> Os k menores 'id' (em ordem) sao: ");
    for(i=0; i < k; i++) printf("%d, ", v[i].id);
  }
}



/// (14)
typedef struct{
  float alfa;
  char identificador[10];
}tipoRegistroBinario;
typedef struct tipoArquivoBinario{
  tipoRegistroBinario registro;
  struct tipoArquivoBinario *prox;
}tipoArquivoBinario;
typedef struct{
  tipoArquivoBinario *primeiro;
}tipoListaBinaria;


tipoRegistroBinario* gerarVetorComRegistros(tipoListaBinaria *p){
  tipoArquivoBinario *aux;
  tipoRegistroBinario *vetor = NULL;
  unsigned nElementosValidos=0, i=0;

  for(aux=p->primeiro; aux; aux=aux->prox)
    if(aux->registro.alfa > 2.3) nElementosValidos++;

  if(nElementosValidos){
    vetor = (tipoRegistroBinario*) malloc(sizeof(tipoRegistroBinario)*nElementosValidos);

    for(aux=p->primeiro; aux; aux=aux->prox)
      if(aux->registro.alfa > 2.3){
	vetor[i] = aux->registro;
	i++;
      }
  }

  return vetor;
}



/// (15)
typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
}tipoNo;
typedef struct tipoLista{
  tipoNo *prim;
}tipoLista;


int somaDosValoresNaLista(tipoLista *p){
  int soma=0;
  tipoNo *aux = p->prim;

  while(aux){
    soma += aux->dado;
    aux   = aux->prox;
  }
  return soma;
}



/// (16)
typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
}tipoNo;
typedef struct tipoLista{
  tipoNo *prim;
}tipoLista;


int estritamenteCrescente(tipoLista *p){
  int valAnterior;
  tipoNo *atual = p->prim;

  if((!atual) || (!atual->prox)) return 1;

  valAnterior = atual->dado;
  atual       = atual->prox;

  do{
    if( valAnterior >= (atual->dado)) return 0;
    valAnterior = atual->dado;
    atual = atual->prox;
  }while(atual);

  return 1;
}



/// (17)
typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
}tipoNo;
typedef struct tipoLista{
  tipoNo *prim;
}tipoLista;


void destruirListaEncadeada(tipoLista *l){
  tipoNo *aux;
  while(l->prim){
    aux     = l->prim;
    l->prim = aux->prox;
    free(aux);
  }
}




/// (18) 
typedef struct tipoNo{
  int dado;
  struct tipoNo *prox;
}tipoNo;
typedef struct tipoLista{
  tipoNo *prim;
}tipoLista;


void inserir(tipoLista *L, int d){
  tipoNo *aux;
  aux = (tipoNo*) malloc( sizeof(tipoNo) );
  aux->dado = d;
  aux->prox = L->prim;
  L->prim   = aux;
}

/* written with GNU Emacs editor */
