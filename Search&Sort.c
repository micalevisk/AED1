/* SIMULADORES:
http://nicholasandre.com.br/sorting/
http://algorithms.openmymind.net/
*/

// ORDENAÇÃO POR SELEÇÃO: [ESTÁVEL NESSE CASO]
// melhor: O(n²)   | pior: O(n²)
void selectionSort(int v[], int n){
  int i=0;
  int j, posMenor, aux;

  for(; i<n; i++){
    posMenor = i;

    for(j=i+1; j < n; j++)
      if(v[j] < v[posMenor]) posMenor = j;
		
    if(i != posMenor){
      aux 	  = v[i];
      v[i]	  = v[posMenor];
      v[posMenor] = aux;
    }
  }
}



// BUSCA SEQUENCIAL/LINEAR: 
// ideal= se a chave estiver na posição 0 do vetor | pior= se não existir ou for o último.
// melhor: O(1)    | pior: O(n)
int linearSearch(int chave, int v[], int n){
  int i=0;
  
  for(; i < n; i++){
    if(v[i] == chave) return i;
    else if(v[i] > chave) return -1; // *VERIFICAÇÃO IDEAL PARA VETOR EM ORDEM CRESCENTE
  }
  
  // OTIMIZAÇÃO PARA VETOR NÃO ORDENADO:
  /*
  v[n] = chave;
  for(i=0; v[i] != chave; i++);
  if(i < n) return i;
  */
  
  return -1;
}



// BUSCA BINÁRIA:
// Se uma busca num vetor de tamanho N faz T iterações, então num vetor 8N fará apenas 3+T iterações (2³ = 8)
// ideal= se a chave estiver na posição central do vetor | pior= a chave não está no vetor
// melhor: O(1)   | pior: O(log n) = log2 n
int binarySearch(int chave, int v[], int n){
  int inicio=0, fim = n-1;
  int meio;

  while(inicio <= fim){
    meio = (inicio+fim)/2;

    if(v[meio] < chave) inicio = meio+1;
    
    else if(v[meio] > chave) fim = meio-1;
    
    else return meio;
  }
  
  return -1;
}



// ORDENAÇÃO POR INSERÇÃO: [ESTÁVEL]
// ideal= para vetores quase ordenados | pior= se o vetor estiver em ordem decrescente. 
// melhor: O(n)   | pior: O(n²)
void insertionSort(int v[], int n){
  int i=1;
  int j, pivot;

  for(; i<n; i++){
    pivot = v[i];
    j = i-1;
    
    while( (j >= 0) && (v[j] > pivot) ){
      v[j+1] = v[j];
      j--;
    }
    
    v[j+1] = pivot;
  }    
}



// ORDENAÇÃO POR QUICKSORT: [INSTÁVEL]
// melhor: O(n.log n)   | pior: O(n²)
void particionar(int v[], int inicio, int fim){
  int pivot, aux, i, j;

  if(fim - inicio > 0){
    i = inicio;            
    j = fim;           
    pivot = v[(i+j)/2];
    do{
      while(v[i] < pivot) i++;
      while(v[j] > pivot) j--;
      if(i <= j){
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
	i++;
	j--;
      }
    }while(i <= j);
   
    if(inicio < j) particionar(v, inicio, j);
    if(i < fim)    particionar(v, i, fim);
  }
}

void quickSort(int v[], int n){
  particionar(v, 0, n-1);
}



// ORDENAÇÃO POR INTERCALAÇÃO: [ESTÁVEL]
// melhor: O(n.log n)   | pior: O(n.log n)
#include <stdlib.h>

void intercalar(int v[], int vaux[], int inicio, int fim, int meio) {
  int i, j,k;

  k = inicio;
  i = inicio;
  j = meio+1;

  while((i <= meio) && (j <= fim)){
    if(v[i] < v[j]) {
      vaux[k] = v[i];
      i++;
    }
    else{
      vaux[k]= v[j];
      j++;
    }
    k++;
  }

  while(i<=meio){
    vaux[k] = v[i];
    i++; 
    k++;
  }

  while(j <= fim){
    vaux[k]= v[j];
    j++;
    k++;
  }
  for(k = inicio; k <=fim; k++)
    v[k]=vaux[k];
}

void mergeSortInterno(int v[], int vaux[], int inicio, int fim) {
  int meio;
  if(inicio < fim) {
    meio = (inicio+fim)/2;
    mergeSortInterno(v,vaux,inicio, meio);
    mergeSortInterno(v,vaux, meio+1,fim);
    intercalar(v,vaux,inicio,fim,meio);
  }
}
    
void mergeSort(int v[], int n) {
  int *vaux;

  vaux = (int*) malloc(sizeof(int)*n);
  mergeSortInterno(v,vaux,0,n-1);
  free(vaux);
}

/* ----------------------------ARQUIVOS--------------------------------- */

// Dado um arquivo binário com dados do tipo tipoDadosDeCadastro.
typedef struct{
  char nome[20];
  char endereco[30];
}tipoDadosDeCadastro;

// BUSCA SEQUENCIAL EM ARQUIVO BINÁRIO:
// melhor: O(1)   | pior: O(n)
int linearSearch_file(FILE *fp, const char chave[], tipoDadosDeCadastro *result){
  tipoDadosDeCadastro buffer;
  rewind(fp);

  while((fread(&buffer, sizeof(tipoDadosDeCadastro), 1, fp)==1 ))
    if(!strcmp(chave, buffer.nome)){
      *result = buffer;
      return 1;      
    }

  return 0;  
}
    


// BUSCA BINÁRIA EM ARQUIVO BINÁRIO:
// melhor: O(1)   | pior: O(log n)
int binarySearch_file(FILE* fp, const char chave[], tipoDadosDeCadastro *result){
  tipoDadosDeCadastro aux;
  int inicio = 0, meio, fim=-1;
  
  rewind(fp);
  while(fread(&aux, sizeof(tipoDadosDeCadastro), 1, fp)==1) fim++;

  rewind(fp);
  while(inico <= fim){
    meio = (inicio+fim)/2;

    fseek(fp, meio * sizeof(tipoDadosDeCadastro), SEEK_SET); // Indo para o registro do meio.
    fread(&aux, sizeof(tipoDadosDeCadastro), 1, fp);         // Lendo para 'aux' o registro do meio.

    if(strcmp(chave, aux.nome) > 0)     inicio = meio+1;
    else if(strcmp(chave, aux.nome < 0))fim    = meio-1;
    else{
      *result = aux;
      return 1;      
    }    
  }
  return 0;
}





/*******************************************************
	Array Sorting Algorithms:
  BEST:				|   WORST:
- Quicksort      O(nlog n)	| - Quicksort	   O(n²)
- Merge Sort     O(nlog n)	| - Merge Sort	   O(nlog n)
- Insertion Sort O(n)		| - Insertion Sort O(n²)
- Selection Sort O(n²)		| - Selection Sort O(n²)

	Array Search Algorithms:
  BEST:				|   WORST:
- Linear Search  O(1) 		| - Binary Search  O(log n)
- Binary Search  O(1)		| - Linear Search  O(n)

*******************************************************/

/*
               Insertion  |   Quick  |  Merge
Random        :  3.6      |    2.5   |   2.9
Nearly Sorted :  0.8      |    5.8   |   2.9
Reversed      :  5.3      |    6.0   |   3.0
Few Unique    :  3.1      |    2.8   |   3.0
Sorted & Small:  0.2      |    0.9   |   0.7

*/


				/* written with GNU Emacs editor */
