#include <stdio.h>

// ORDENAÇÃO POR SELEÇÃO: O(n²)
void selectionSort(int v[], int n){
  int i=0,j, aux;
  int posMenor;
  
  for(; i < n - 1; i++){
    posMenor = i;

    for(j=i+1; j < n; j++){
      if(v[j] < v[posMenor])
	posMenor = j;
    }
    if( i != posMenor ){
      aux         = v[i];
      v[i]        = v[posMenor];
      v[posMenor] = aux;
    }
  }
}



// BUSCA SEQUENCIAL: O(n)
int linearSearch(int v[], int n, int chave){
  int i;
  v[n] = chave; //sentinela

  for(i=0; v[i]!=chave; i++);

  if(i < n) return i;
  else return -1;  
}



// BUSCA BINÁRIA: O(log2 n)
int binarySearch(int v[], int n, int chave){
  int inicio = 0, fim = n - 1;
  int meio;
  
  while(inicio <= fim){
    meio = (inicio+fim)/2;

    if(v[meio] < chave)
      inicio = meio + 1;
    
    else if(v[meio] > chave)
      fim = meio - 1;

    else
      return meio;    
  }
  return -1;
}



// ORDENAÇÃO POR INSERÇÃO: O(n²)
void insertionSort(int v[], int n){
  int i=1, j, pivot;

  for(; i < n; i++){
    pivot = v[i];
    j = i - 1;
    while((j >= 0) && (v[j] > pivot)){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = pivot;
  }
}


/* written with GNU Emacs */
