// ALUNO    : Micael Levi L. C.
// MATRÍCULA: 21554923
// TURMA    : CB01

#include <stdio.h>
#include "funcAuxiliares.h"
#include <string.h>
#include <math.h>
#define N 4

// 1
int fatorialDe(int n){
  int fatorial=1;
	
  while(n>0){
    fatorial *= n;
    n--;
  }
	
  return fatorial;
}


// 2
void modificarVetor(int v[], int n){
  int i=0;
	
  for( ; i < n; i++){
    if(v[i]<=0) v[i] = -2;                     // a
		
    else if(v[i] >= 1 && v[i] <= 5) v[i] = -1; // b
		
    else v[i] = 0;                             // c
  }
}


// 3
void inverterPosicoesVetor(int v[], int n){
  int i, j;
  int aux;
	
  for(i=0, j=n-1; i < j; i++, j--){
    aux  = v[i];
    v[i] = v[j];
    v[j] = aux;
  }
}


// 4
int textoVerdadeiro(char texto[]){
  int i=0, j;
  char palavra[4] = "FAM";

  for(; texto[i] != '\0' ; i++){
    if(texto[i] == 'U'){
      j=0;
      while( texto[i+1] == palavra[j] ){
	if(j==2) return 1; // verdadeiro
	j++;
	i++;
      }
    }
  }
  
  return 0; // falso
}


// 5
int estaEmOrdemCrescente(int v[], int n){
  int i=0;

  if( n > 1 ){
    while( v[i] <= v[i+1] ){
      if(i == n-2) // se for o penultimo elemento
	return 1;
      i++;
    }
  }

  return 0;
}


//6
void insertionSort(int v[], int n){
  int i = 1, j;
  int pivot;

  while( i < n ){
    pivot = v[i];
    j = i - 1;

    while( (j >= 0) && (v[j] > pivot) ){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = pivot;
    i++;
  }
}


// 7
int somaDosQuadradosDe(int inteiroN){
  int acumulador=0;
	
  while(inteiroN > 0){
    acumulador += inteiroN * inteiroN;
    inteiroN--;
  }
  return acumulador;
}


// 8
int letraNoNome(char nome[], char letra){
  int i;
  int vezesQueAparece = 0;
  char letraMinuscula, letraMaiuscula;
	
  if((letra > 64) && (letra < 91)) letraMinuscula = letra + 32; // se for uma letra maíuscula, torna ela minúscula (ao somar com 32)
  letraMinuscula = letraMinuscula-32;
	
  for(i=0; nome[i] != '\0'; i++){
    if( nome[i] == letraMinuscula || nome[i] == letraMaiuscula )
      vezesQueAparece++;
  }

  return vezesQueAparece;
}


// 9
int palindromo(char nome[]){
  int tamanho = strlen(nome);
  int i=0, j=tamanho-1;

  for(; i < j; i++, j--){
    if(nome[i] != nome[j]) // se não for palíndromo
      return 0;
  }

  return tamanho; // se tiver apenas o caracter nulo, tamanho == 0 -> falso
  // senão, tamanho != 0 -> verdadeiro
}


// 10
int verSeRepete_binarySearch(int x, int v[], int n){
  int i=0;
  int inicio=0, fim = n-1, meio;

  while( inicio <= fim ){
    meio = (inicio + fim)/2;

    if(v[meio] < x)
      inicio = meio + 1;
    else if(v[meio] > x)
      fim = meio - 1;
    else{
      return ((v[meio+1] != x) && (v[meio-1] != x));
      // se for true -> a chave não se repete (considerando um vetor ordenado crescente/decrescente).
      // onde o próximo/anterior elemento deverá ser diferente de x caso este não se repita.
    }
  }

  return 0; // 'falso' caso a chave não exista no vetor.
}


// 11
void substituirElementos(int v[], int n, int delta){
  int i=0;
  for(; i<n; i++)
    v[i] -= delta;
}


//12
void substituirElementos2(int v[], int n){
  int i, aux, aux2;

  if(n>1){
    aux = v[0];

    for(i=1; i<n; i++){
      aux2 = v[i] - aux;
      aux  = v[i];
      v[i] = aux2;
    }
  }
}


// 13
void inverterSubstituicoes(int v[], int n){
  int i=1;
  for(; i<n; i++ )
    v[i] += v[i-1];
}


/* 14 -
a) R: 40, 12, 3
b) R: 40, 90, 50, 55

/// Resolução:
/// { 3, 12, 20, 25, 40, 50, 55, 90, 95, 99 } | n = 10
/// a) Buscando a Chave '4'
/// inicio = 0 | fim = 9 | meio := (0+9)/2 = 4 ---> v[4] = 40 > chave : fim    = meio - 1
/// inicio = 0 | fim = 3 | meio := (0+3)/2 = 1 ---> v[1] = 12 > chave : fim    = meio - 1
/// inicio = 0 | fim = 0 | meio := (0+0)/2 = 0 ---> v[0] = 3  < chave : inicio = meio + 1
/// inicio > fim --> retorna -1

/// b) Buscando a Chave '55'
/// inicio = 0 | fim = 9 | meio := (0+9)/2 = 4 ---> v[4] = 40 < chave : inicio = meio + 1
/// inicio = 5 | fim = 9 | meio := (5+9)/2 = 7 ---> v[7] = 90 > chave : fim    = meio - 1
/// inicio = 5 | fim = 6 | meio := (5+6)/2 = 5 ---> v[5] = 50 < chave : inicio = meio + 1
/// inicio = 6 | fim = 6 | meio := (6+6)/2 = 6 ---> v[6] = 55 == chave: retorna meio
/// --> retorna 6
*/


// 15
int matrizQuadrada(int matriz[][N], int K){
  int i, j;
  int vezesQueAparece=0;

  for(i=0; i < N ; i++){
    for(j=0; j < N; j++){
      if(matriz[i][j] == K) vezesQueAparece++;
      if (vezesQueAparece > 4) return 0; // como é maior que 4 vezes, retorna 0 (=false)
    }
  }

  return (vezesQueAparece == 4); // se for exatamente 4, retorna 1 (=true)
}


// 16
int maiorElementoDaMatrizQuadrada(int matriz[][N]){
  int i=0, j;
  int maior = matriz[0][0];
	
  for(; i < N; i++){
    for(j=0; j < N; j++){
      if(matriz[i][j] > maior)
	maior = matriz[i][j];
    }
  }
  return maior;
}


// 17
int somaDiagonalSecundaria(int matriz[][N]){
  int i, j;
  int soma = 0;
	
  for(i=0,j=N-1; i < N; i++, j--)
    soma += matriz[i][j];
	
  return soma;
}


// 18
float desvioPadraoDe(int v[], int n[]){
  /*
    1 - obter media geral
    2 - subtrair cada elemento da media geral, elevar ao quadrado e soma-los
    3 - variancia = dividir resultado anterior pelo numero de elementos
    4 - desvio padrao = raiz quadrada da variancia.
  */

  int i;
  int somaDosQuadradosDasDifrencas=0;
  float mediaGeral, variancia;
  int nElementos = n; // numero de elementos.
	
  // definindo media geral.
  for(i=0; i<n; i++)
    mediaGeral += (float)v[i] * (1 / (float)nElementos);
	
  // subtraindo cada elemento pela mediaGeral, elevando ao quadrado e somando tudo.
  for(i=0; i<n; i++)
    somaDosQuadradosDasDifrencas += pow((v[i] - mediaGeral), 2) ;
	
  // media dos quadrados das diferencas.
  variancia = somaDosQuadradosDasDifrencas / nElementos;
	
  return sqrt(variancia); // desvio padrao
}
