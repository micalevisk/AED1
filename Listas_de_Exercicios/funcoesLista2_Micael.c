// ALUNO    : Micael Levi L. C.
// MATRÍCULA: 21554923
// TURMA    : CB01
// CORREÇÃO : 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipo em comum entre as questões.
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

void inserirNaPilha(tipoPilha *t, tipoDados elemento){ // Insere no topo (= início numa lista simplesmente encadeada).
  tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dados = elemento;

  aux->prox = t->topo;
  t->topo   = aux;
}

tipoDados removerDaPilha(tipoPilha *t){ // Admitindo uma pilha nunca vazia.
  tipoNo *aux    = t->topo;
  tipoDados temp = aux->dados;

  temp = aux->dados;

  t->topo = aux->prox;
  free(aux);

  return temp; // Retorna os dados do elemento removido.
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

tipoDados removerDaListaCircular(tipoListaCircular *a){ // Admitindo uma lista nunca vazia.
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
	return 1; // Encontrou o novo 'atual' e ele é diferente do 'atual' antigo.
      }
      aux = aux->prox;
    }while(aux != temp);
  }

  return 0; // Não foi atualizado.
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

  if(!t->topo){ // A pilha deve estar vazia.
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
    
  // 'atual' "anda" ate ser o elemento que sera removido.
  // 'anterior' será o elemento anterior ao 'atual'.
  for(; (k>1) && (atual); k--){
    anterior = atual;
    atual    = atual->prox;
  }

  if((k>0) && (atual)){
    if(!anterior) p->prim = atual->prox; // Caso seja a remoção do primeiro elemento da lista.
    else   anterior->prox = atual->prox; // O próximo elemento de 'anterior' altera para o próximo do elemento que será removido.
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
  tipoNoSimples *aux = p->primeiro, *fixado = aux, *aux2;  // 3 ponteiros.
  unsigned nElementos=0, limite, iSimetrico, i=1;         // 4 inteiros sem sinal.

  if((!aux) || (!aux->prox)) return 0;

  for(; aux; nElementos++, aux = aux->prox);  // Contando o número de elementos da lista.

  limite = nElementos/2;                      // Posição do último elemento da primeira metade.
  (nElementos % 2 == 0) ? (iSimetrico=limite+1) : (iSimetrico=limite+2);

  for(aux=fixado; i != iSimetrico; aux=aux->prox, i++);
  aux2 = aux;                                 // Fixando o primeiro elemento da segunda metade da lista.

  do{
    for(aux=aux2; aux; aux=aux->prox)
      if(aux->valor == fixado->valor) break; // Sair do laço for.

    if(!aux) return 0;

    fixado = fixado->prox;
    limite--;
  }while(limite>0);

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
  unsigned i=0;

  for(; p->prim; i++){
    aux  = p->prim;
    v[i] = *aux;

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
// Troca o valor da variável 'a' para 'b' e vice-versa.
void trocar(tipoDados* a, tipoDados* b){
  tipoDados aux = *a;
  *a = *b;
  *b = aux;
}

// Ordenação por Inserção pelo campo 'nome'.
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
  int i=inicio-1;          // Posição do menor elemento.
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
    int p = particionar(v, inicio, fim);    // Posição do elemento divisor.

    // Para "vetor" do lado esquerdo da posição 'p'.
    tamanho = (p-1 - inicio+1); // Tamanho do vetor formado pelos elementos do lado esquerdo de 'p'.
    if(tamanho >= 10) quickSortInterno(v, inicio, p-1);
    else              insertionSort(v, inicio, p-1);

    // Para "vetor" do lado direito da posição 'p'.
    tamanho = (fim - p+1);      // Tamanho do vetor formado pelos elementos do lado direito de 'p'.
    if(tamanho >= 10) quickSortInterno(v, p+1, fim);
    else              insertionSort(v, p+1, fim);
  }
}

void quickInsertionSort(int v[], int n){
  quickSortInterno(v, 0, n-1);
}



/// (11)
void intercalar(tipoDados v[], tipoDados vaux[], int inicio, int fim, int meio){
  int i = inicio;
  int j = meio+1;
  int k = inicio;

  while((i <= meio) && (j <= fim)){
    if(strcmp(v[i].nome, v[j].nome) < 0){ // Se v[i] vem antes de v[j] no alfabeto.
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
    mergeSortInterno(v, vaux, inicio, meio); // Ordenar primeira metade.
    mergeSortInterno(v, vaux, meio+1, fim);  // Ordenar segunda metade.
    intercalar(v, vaux, inicio, fim, meio);  // Intercalar as metades ordenadas.
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

// Trocar os valores de 'a' com 'b' e vice-versa.
void trocar(tipoDados* a, tipoDados* b){
	tipoDados aux = *a;
	*a = *b;
	*b = aux;
}

// Define o último como pivô e coloca os elementos menores que ele no seu lado esquerdo.
int particionar(tipoDados v[], int inicio, int fim){
	int pivot = v[fim].id; 
	int i = inicio-1; 	
	int j = inicio;

	for(; j <= fim-1; j++){
		if(v[j].id <= pivot){
			i++; 								
			if(i != j) trocar(&v[i], &v[j]); 
		}
	}

	trocar(&v[i+1], &v[fim]); 

	return (i + 1); // Posição em que o pivô ficou.
}

// Ordenar por quickSortvetor no intervalo [inicio;fim] 
void quickSortInterno(tipoDados v[], int inicio, int fim){
	if(fim > inicio){
		int p = particionar(v, inicio, fim);		
		quickSortInterno(v, inicio, p-1);
		quickSortInterno(v, p+1, fim); 
	}
}

// Determinar o vetor onde 'p' fica entre elementos maiores e menores que ele.
void quickSortParcial(tipoDados v[], int inicio, int fim, int k){	
	if(fim > inicio){
		int p = particionar(v, inicio, fim);
		int tamanhoEsquerdo = p; // Tamanho do "vetor" do lado esquerdo de 'p'.
		
		if(tamanhoEsquerdo == 0) quickSortParcial(v, p, fim, k);
		else if(tamanhoEsquerdo+1 > k) quickSortParcial(v, 0, p-1, k);
		else if(tamanhoEsquerdo+1 < k) quickSortParcial(v, 0, p+1, k);
		else if(tamanhoEsquerdo+1 == k) quickSortInterno(v, 0, p);   	
	}
}

void quickSort(tipoDados v[], int n, int k){
    if(k>0 && k<n){
        quickSortParcial(v, 0, n-1, k);
        int i=0;
        printf("\n>> Os %d primeiros (em ordem crescente): ",k);
        for(; i < k; i++) v[i];
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


float* gerarVetorComRegistros(tipoListaBinaria *p){
  tipoArquivoBinario *aux;
  float *vetor = NULL;
  unsigned nElementosValidos=0, i=0;

  // 1 - Contar a quantidade de elementos da lista que entrarão no vetor:
  for(aux=p->primeiro; aux; aux=aux->prox)
    if(aux->registro.alfa > 2.3) nElementosValidos++;

  if(nElementosValidos){
    // 2 - Reverservar um espaço para o vetor:
    vetor = (float*) malloc(sizeof(float)*(nElementosValidos+1));

    // 3 - Inserir os elementos no vetor:
    for(aux=p->primeiro; aux; aux=aux->prox)
      if(aux->registro.alfa > 2.3){
	vetor[i] = aux->registro.alfa;
	i++;
      }
  }

  return vetor; // Endereço do primeiro elemento do vetor.
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

  if((!atual) || (!atual->prox)) return 1; // Se a lista estiver vazia ou tem 1 elemento então é estritamente crescente.

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




/// (18) - [TEÓRICA] Função "inserir" Corrigida (foram feitas 3 alterações):
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
