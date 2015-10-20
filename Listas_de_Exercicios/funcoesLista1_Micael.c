// ALUNO    : Micael Levi L. C.
// MATRÍCULA: 21554923
// TURMA    : CB01
/* Correção: Mikael Souza 18/10/15 */

#include <stdio.h>
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
  int i=0, limite = strlen(texto) - 3;
    
  for(; i < limite; i++){
        
    if(texto[i] == 'U'){
      if( (texto[i+1] == 'F') && (texto[i+2] == 'A') && (texto[i+3] == 'M') )
	return 1;
    }
  }
  return 0;
}


// 5
int verSeEstaEmOrdemCrescente(int v[], int n){
  int i=0;
    
  if( n > 1 ){
    while( v[i] <= v[i+1] ){
      if(i == n-2)
	return 1;
      i++;
    }
  }
    
  return (n==1); // se o tamanho for 1, então o vetor está ordenado.
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
int somarOsQuadradosAnterioresDe(int inteiroN){
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
  char letraMinuscula=letra, letraMaiuscula;
    
  if((letra > 64) && (letra < 91)) letraMinuscula += 32;
  letraMaiuscula = letraMinuscula-32;
    
  for(i=0; nome[i] != '\0'; i++){
    if( nome[i] == letraMinuscula || nome[i] == letraMaiuscula )
      vezesQueAparece++;
  }
    
  return vezesQueAparece;
}


// 9
int verSeEhPalindromo(char nome[]){
  int tamanho = strlen(nome);
  int i=0, j=tamanho - 1;
    
  for(; i < j; i++, j--){
    if(nome[i] != nome[j])
      return 0;
  }
    
  return tamanho;
}


// 10
int verSeRepete_binarySearch(int x, int v[], int n){
  int inicio=0, fim = n-1, meio;
    
  while( inicio <= fim ){
    meio = (inicio + fim)/2;
        
    if(v[meio] < x)
      inicio = meio + 1;
    else if(v[meio] > x)
      fim = meio - 1;
    else{
      return ((v[meio+1] != x) && (v[meio-1] != x));
    }
  }
    
  return 0;
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
void inverterSubstituicoes2(int v[], int n){
  int i=1;
  for(; i<n; i++ )
    v[i] += v[i-1];
}


// 14 -
// a) R: 40, 12, 3
// b) R: 40, 90, 50, 55
 
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


// 15
int matrizQuadrada(int matriz[][N], int K){
  int i=0, j;
  int vezesQueAparece=0;
    
  for(; i < N ; i++){
    for(j=0; j < N; j++){
      if(matriz[i][j] == K) vezesQueAparece++;
      if (vezesQueAparece > 4) return 0;
    }
  }
    
  return (vezesQueAparece == 4);
}


// 16
int maiorElementoDaMatrizQuadrada(int matriz[N][N]){
  int i=1, j;
  int maior = matriz[0][0];
    
  for(; i < N; i++){
    for(j=1; j < N; j++){
      if(matriz[i][j] > maior)
	maior = matriz[i][j];
    }
  }
  return maior;
}


// 17
int somaDiagonalSecundaria(int matriz[N][N]){
  int i;
  int soma = 0;
    
  for(i=0; i < N; i++)
    soma += matriz[i][N - (i+1)];
    
  return soma;
}


// 18
float desvioPadraoDe(int v[], int n){
  int i;
  float somaDosQuadradosDasDifrencas=0;
  float mediaGeral, variancia=0;
    
  for(i=0; i<n; i++)
    mediaGeral += v[i];
  mediaGeral /= n;
    
  for(i=0; i<n; i++)
    somaDosQuadradosDasDifrencas += pow(v[i] - mediaGeral, 2) ;
    
  variancia = somaDosQuadradosDasDifrencas / (n-1);
    
  return sqrt(variancia);
}


/* EXTRAS: ------------------------------------------------------------------ */

// quantas vezes a chave se repete no vetor ordenado (busca binaria):
int vezesQueRepete(int chave, int v[], int n){
  int inicio = 0, fim = n-1;
  int meio;
  int i, vezes = 0;

  while( inicio <= fim ){
    meio = (inicio+fim)/2;

    if(v[meio] < chave) inicio = meio+1;
    else if(v[meio] > chave) fim = meio-1;
    else{
      i = meio-1; // para percorrer o lado esquerdo
      meio++;     // para percorrer o lado direito

      while( (i >= inicio) || (meio <= fim) ){
        vezes = vezes + (v[i] == chave) + (v[meio] == chave);      
        i--;
        meio++;
      }

      return vezes+1;				
    }
  }
  return vezes;
}



// Calcular a media de altura dos porcos de uma fazenda,
// cujos dados estao armazenados em um vetor.
// Considere que o vetor e o numero de porcos sera
// passado como parametro. Os porcos com altura 0
// devem ser descartados no calculo.
typedef struct{
  int idade;
  int peso;
  float altura;
} tipoPorco;

float mediaDasAlturas(tipoPorco v[], int nPorcos){
  float soma = 0;
  int i;
  
  for(i=0; i<nPorcos; i++)  
    if(v[i].altura != 0.0) soma += v[i].altura;
  
  return soma / nPorcos;
}



// Escreva uma função que faça uma busca binária em um vetor de ponteiros 
// para o tipo Funcionario, cujos elementos estão em ordem alfabética dos
// nomes dos funcionários. Essa função deve receber como parâmetros o 
// número de funcionários, o vetor e o nome do funcionário que se deseja 
// buscar, e deve ter como valor de retorno um ponteiro para o registro do 
// funcionário procurado. Se não houver um funcionário com o nome procurado, 
// a função deve retornar NULL.
typedef struct {
  char nome[81]; 		/* nome do funcionário */
  float valor_hora;	/* valode da hora de trabalho em Reais */
  int hora_mes;		/* horas trabalhadas em um mês */
} Funcionario;

Funcionario* buscarFuncionario(int n, Funcionario* v[], char nome[]){
  int inicio = 0, fim = n-1;
  int meio;

  while(inicio <= fim){
    meio = (inicio+fim)/2;

    switch(strcmp(nome, v[meio]->nome)){
    case -1: // nome vem antes
      fim = meio - 1;
      break;
    case 1:	// nome vem depois
      inicio = meio + 1;
      break;
    case 0:
      return v[meio];
    }
  }
  return NULL;
}



// Escreva uma função que faça uma busca binária em um vetor de ponteiros
// para o tipo Licenca, cujos elementos estão em ordem cronológica, de
// acordo com a data de início das licenças, com desempate pela ordem
// alfabética de acordo com o nome dos funcionários. Se existir mais de uma
// licença com início na data procurada, a função deve retornar o índice da
// primeira delas. Se não houver uma licença com a data procurada,
// a função deve retornar -1. 
typedef struct{
  int dia, mes, ano;
}Data;

struct licenca{
  char nome[51];         /* nome do funcionário */
  Data inicio;           /* data de início da licença */
  Data final;            /* data de final da licença */
};
typedef struct licenca tipoLicenca;

int dataCmp(Data d1, Data d2){
  if(d1.ano != d2.ano) return d1.ano - d2.ano;
  if(d1.mes != d2.mes) return d1.mes - d2.mes;
  if(d1.dia != d2.dia) return d1.dia - d2.dia;
  return 0;
}

int buscarLicenca(tipoLicenca* v[], int n, Data d){
  int i=0, f=n-1, m;

  while(i <= f){
    m = (i+f)/2;

    if(dataCmp(d, v[m]->inicio) < 0)
      f = m -1;

    else if(dataCmp(d, v[m]->inicio) > 0)
      i = m + 1;

    else{
      while( (m > 0) && dataCmp(d, v[m-1]->inicio)==0 )
	m--;
      return m;
    }    
  }    
  return -1;
}
