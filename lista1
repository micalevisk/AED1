#include <stdio.h>
#include "funcAuxiliares.h"
#include <string.h>
#include <math.h>


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

  for(i=0, j=n-1 ; i < j ; i++, j--){
    aux  = v[i];
    v[i] = v[j];
    v[j] = aux;
  }
}


// 4
int textoVerdadeiro(char texto[]){
  int i=0, j;
  int limite = strlen(texto);
  char palavra[4] = "FAM";

  for(; i < limite; i++){

    if(texto[i] == 'U'){
      j=0;
      while( texto[i+1] == palavra[j] ){
	if(j==2) return 1;
	j++;
	i++;
      }
    }

  }
  return 0;
}


// 5
int estaEmOrdemCrescente(int v[], int tamanho){
  int posCorrente, posAnterior;

  if(tamanho>1){
    posAnterior=0;
    for(posCorrente=1; posCorrente < tamanho; posCorrente++){
      if(v[posCorrente] < v[posAnterior])
	return 0;
      posAnterior++;
    }
    return 1;
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
int somaDosQuadradosDe(int N){
    int acumulador=0;

    while(N > 0){
        acumulador = acumulador + N*N;
        N--;
    }
    return acumulador;
}


// 8
int letraNoNome(char nome[], char letra){
    int n = strlen(nome), i;
    int vezesQueAparece = 0;
    char letraMinuscula = (letra > 64 && letra < 91) ? letra+32 : letra;
    char letraMaiuscula = letraMinuscula-32;

    for(i=0; i < n; i++){
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
        if(nome[i] != nome[j])
            return 0;
    }

    return tamanho;
}


// 10
int verSeRepete_binarySearch(int x, int v[], int n){
    int i=0;
    int inicio=0, fim = n-1, meio;
    unsigned acumulador = 0;

    while( inicio <= fim ){
        meio = (inicio + fim)/2;
        if(v[meio] < x)
            inicio = meio + 1;
        else if(v[meio] > x)
            fim = meio - 1;
        else{
            if(v[meio+1] != x && v[meio-1] != x) return 1; // valida que a chave não se repete (considerando o vetor ordenado)
            return 0; // a chave se repete pelo menos uma vez
        }
    }
    return 0; // 'falso' caso a chave não exista no vetor
}


// 11
void substituirElementos(int v[], int n, int delta){
    int i=0;
    for(; i<n; i++ )
        v[i] -= delta;
}


// 12
void substituirElementos2(int v[], int n){
    int i=1;
    for(; i<n; i++ )
        v[i] -= v[i-1];
}


//13
void inverterSubstituicoes(int v[], int n){
    int i, aux, aux2;

    if(n>1){
        aux = v[0];

        for(i=1; i<n; i++){
            aux2 = v[i] + aux;
            aux  = v[i];
            v[i] = aux2;
        }
    }
}


#define N 4
// 15
int matrizQuadrada(int matriz[][N], int K){
    int i, j;
    int acumulador=0;

    for(i=0; i < N ; i++){
        for(j=0; j < N; j++)
//            printf("%d ", matriz[i][j]);
            if(matriz[i][j] == K) acumulador++;
    }

    return (acumulador == 4) ? 1 : 0;
}


// 16
int maiorElementoDaMatrizQuadrada(int matriz[][N]){
    int i, j;
    int maior = matriz[0][0];

    for(i=0; i < N ; i++){
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
    int i; // contador
    int somaDosQuadradosDasDifrencas=0;
    float mediaGeral, variancia;
    int *p = &n; // número de elementos

    // definindo média geral
    for(i=0; i<n; i++)
        mediaGeral += (float)v[i] * (1 / (float)*p);

    // subtraindo cada elemento da mediaGeral, elevando ao quadrado e somando tudo
    for(i=0; i<n; i++)
        somaDosQuadradosDasDifrencas += pow((v[i] - mediaGeral), 2) ;

    variancia = somaDosQuadradosDasDifrencas / *p; // media dos quadrados das diferenças

    return sqrt(variancia); // desvio padrão
}




int main(){

    /* 1 - FUNÇÃO PARA CALCULAR FATORIAL DE n
    int n;
    printf(" Calcular o fatorial de: ");
    scanf("%d",&n);
    printf(" %d! = %d \n\n", n, fatorialDe(n));
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 2 - FUNÇÃO PARA MODIFICAR UM VETOR DE INTEIROS
    int vetor[] = {1,2,9,4,5,-3,7,0}, n = 8;
    modificarVetor(vetor, n);
    printf("\n 'vetor' mudou para: ");
    imprimirVetor(vetor, n);
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 3 - FUNÇÃO PARA INVERTER POSIÇÕES DE UM VETOR
    int vetor[] = {1,2,3,4,5,6,7,8,9};
    inverterPosicoesVetor(vetor, 9);
    imprimirVetor(vetor, 9);
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 4 - FUNÇÃO SE CONTEM A PALAVRA "UFAM"
    char texto[] = "eu estudo na UFAM, Universidade Federal do Amazonas";
    printf(" %s \n\n", (textoVerdadeiro(texto)==1) ? "verdadeiro":"falso" );
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 5 - FUNÇÃO PARA VERIFICAR SE UM VETOR ESTÁ ORDENANDO
    int V[] = {1,0,3,4,5,6,7,8,9,46,46}, n = 11;
    printf(" %s \n\n",(estaEmOrdemCrescente(V, n)==1) ? "verdadeiro":"falso" );
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 6 - IMPLEMENTAÇÃO DO ALGORITMO DE ORDENÇÃO POR INSERÇÃO
    int vetor[] = {2,4,3,1,6,5,8,0,9,7};
    printf(" Antes da ordenacao : ");
    imprimirVetor(vetor, 10);
    insertionSort(vetor, 10); // ordena em ordem crescente
    printf("\n Depois da ordenacao: ");
    imprimirVetor(vetor, 10);
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 7 - FUNÇÃO PARA RETORNAR A SOMA DOS QUADRADOS DE UM INTEIRO
    printf(" %d \n", somaDosQuadradosDe(0)); // 3² + 2² + 1² = 14
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 8 - FUNÇÃO QUE RETORNA QUANTAS VEZES UMA LETRA SE REPETE NO NOME
    char nome[] = "João das dores santos silvA junior";
    char letra = 'a';
    printf(" a letra '%c' se repete %d vezes \n", letra, letraNoNome(nome, letra) );
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 9 - FUNÇÃO QUE VERIFICA SE UM NOME É PALÍNDROMO
    char nome[] = "abccba";
    printf(" eh palindromo? R: %s \n",(palindromo(nome)!=0) ? "verdadeiro":"falso");
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 10 - FUNÇÃO QUE RETORNA VERDADEIRO CASO A CHAVE OCORRA SÓ 1 VEZ NO VETOR
    int numeros[] = {1,2,3,3,4,6,7,8,9,10};
    printf(" a chave nao se repete? R: %s \n" , ( verSeRepete_binarySearch(3, numeros, 10) == 0 ) ? "falso":"verdadeiro" );
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 11 - SUBSTITUI CADA ELEMENTO DO VETRO PELA DIFERENÇA ENTRE SEU V.O. E DELTA
    int numeros[] = {1,2,3,3,4,6,7,8,9,10};
    substituirElementos(numeros, 10, 1);
    imprimirVetor(numeros, 10);
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 12 - SUBSTITUI CADA ELEMENTO DO VETOR PELA DIFERENÇA ENTRE SEU V.O. E O VALOR DA POSIÇÃO ANTERIOR A ELE
    int numeros[] = {1,3,5,4,6};
    substituirElementos2(numeros, 5);
    imprimirVetor(numeros, 5);
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 13  - INVERTE OS EFEITOS DA FUNÇÃO ANTERIOR (QUESTÃO 12)
    int numeros[] = {1,2,3,1,5};
    inverterSubstituicoes(numeros, 5);
    imprimirVetor(numeros, 5);
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 14 -
    /// { 3, 12, 20, 25, 40, 50, 55, 90, 95, 99 } | n = 10
    /// a) Buscando a Chave '4'
    /// inicio = 0 | fim = 9 | meio := (0+9)/2 = 4 ---> v[4] = 40
    /// inicio = 0 | fim = 3 | meio := (0+3)/2 = 1 ---> v[1] = 12
    /// inicio = 0 | fim = 0 | meio := (0+0)/2 = 0 ---> v[0] = 3
    /// inicio == fim --> retorna -1

    /// b) Buscando a Chave '55'
    /// inicio = 0 | fim = 9 | meio := (0+9)/2 = 4 ---> v[4] = 40
    /// inicio = 5 | fim = 9 | meio := (5+9)/2 = 7 ---> v[7] = 90
    /// inicio = 5 | fim = 6 | meio := (5+6)/2 = 5 ---> v[5] = 50
    /// inicio = 6 | fim = 6 | meio := (6+6)/2 = 6 ---> v[6] = 55
    /// x == v[meio] --> retorna 6
    */
//------------------------------------------------------------------------------------------------------------------------

    /* 15 - RETORNA VERDADEIRO CASO A MATRIZ QUADRADA DE ORDEM N CONTENHA QUATRO POSIÇOES COM O VALOR K
    int matriz[N][N] = {{1,2,3,4},
                        {5,6,7,8},
                        {0,-1,0,1},
                        {1,0,1,0}};
    printf(" Tem quatro posições com valor K? R: %s \n", (matrizQuadrada(matriz, 1) == 0) ? "falso" : "verdadeiro" );
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 16 - RETORNA O MAIOR ELEMENTO DE UMA MATRIZ QUADRADA DE ORDEM N
    int matriz[N][N] = {{1,10,3,4},
                        {5,6,7,8},
                        {0,-1,0,1},
                        {1,0,1,9}};
    printf(" Maior elemento da matriz: %d \n", maiorElementoDaMatrizQuadrada(matriz));
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 17 - SOMA DA DIAGONAL SECUNDÁRIA DE UMA MATRIZ QUADRADA
    int matriz[N][N] = {{1,10,3,4},
                        {5, 6,7,8},
                        {0,-1,0,1},
                        {1, 0,1,9}};
    /// 4 + 7 + -1 + 1 = 11
    printf(" A soma dos elementos da diagonal secundária de 'matriz' eh = %d \n", somaDiagonalSecundaria(matriz));
    */

//------------------------------------------------------------------------------------------------------------------------

    /* 18 - FUNÇÃO PARA CALCULAR O DESVIO PADRÃO DE UM VETOR DE INTEIROS
    int vetor[] = {7,10,6,8,4}; // 7 + 10 + 6 + 8 + 4 = 35
    printf(" o desvio padrão de 'vetor' eh = %.3f \n", desvioPadraoDe(vetor, 5));
    */

//------------------------------------------------------------------------------------------------------------------------




    return 0;
}
