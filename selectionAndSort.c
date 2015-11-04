/* SIMULADORES:
http://nicholasandre.com.br/sorting/
http://algorithms.openmymind.net/
*/

// ORDENAÇÃO POR SELEÇÃO: ; 
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
  for(; v[i] != chave; i++);
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
    
    else if(v[meio] > chave) fim = meio -1;
    
    else return meio;
  }
  
  return -1;
}



// ORDENAÇÃO POR INSERÇÃO: 
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



// QUICKSORT:
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
      
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
            	
    }while(i <= j);
   
    if(inicio < j) particionar(v, inicio, j);
    if(i < fim)    particionar(v, i, fim);
  }
}

void quickSort(int v[], int n){
  particionar(v, 0, n-1);
}


// MERGE SORT:
// melhor: O(n.log n)   | pior: O(n.log n)
void mergeSort(){}




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


				/* written with GNU Emacs editor */
