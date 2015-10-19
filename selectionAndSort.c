#include <stdio.h>

// ORDENAÇÃO POR SELEÇÃO:
// melhor: O(n²)   | pior: O(n²)
void selectionSort(int v[], int n){
  int i=0;
  int j, posMenor, aux;

  for(; i<n; i++){
    posMenor = i;

    for(j=i+1; j < n; j++)
      if(v[j] < v[posMenor])
	posMenor = j;
		
    if(i != posMenor){
      aux 	  = v[i];
      v[i]	  = v[posMenor];
      v[posMenor] = aux;
    }
  }
}

// BUSCA SEQUENCIAL/LINEAR:
// melhor: O(1)    | pior: O(n)
int linearSearch(int chave, int v[], int n){
  int i=0;
  v[n] = chave;

  for(; v[i] != chave; i++);
  if(i < n) return i;
  return -1;
}


// BUSCA BINÁRIA:
// melhor: O(1)   | pior: O(log n) = log2 n
int binarySearch(int chave, int v[], int n){
  int inicio=0, fim = n-1;
  int meio;

  while(inicio <= fim){
    meio = (inicio+fim)/2;

    if(v[meio] < chave) inicio = meio+1;
    
    else if(v[meio] > chave) fim = meio -1
    
    else return meio;
  }
  
  return -1;
}


// ORDENAÇÃO POR INSERÇÃO:
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

// QUICK SORT:
// melhor: O(n.log n)   | pior: O(n²)





/* written with GNU Emacs editor */
