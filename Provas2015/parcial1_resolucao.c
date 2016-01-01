//
//  parcial1_resolucao.c
//  Created by Micael Levi on 15/10/21.
//  Copyright (c) 2015 Micael Levi L. Cavalcante. All rights reserved
//


/// (1): VER SE O NUMERO POSITIVO PASSADO EH PRIMO.
int ehPrimo(int numero){
  unsigned i = 2;
  int limite = sqrt(numero);

  for(; i <= limite; i++){
    if((numero % i)==0)
      return 0;
  }
  return (numero > 1); // Considerando 1 e 0 nao primos.
}



/// (2): MEDIA DA ALTURA DOS VEGETARIANOS (TEM 'S' NO CAMPO "veg").
typedef struct{
  char nome[20];
  char veg;      
  float altura;
} tipoPessoa;

float alturaMediaDosVegetarianos(tipoPessoa v[], int nElementos){
  float soma     = 0.0;
  int quantidade = 0;
  nElementos--; // contador;

  for(; nElementos >= 0; nElementos--){
    if(v[nElementos].veg == 'S'){
      soma += v[nElementos].altura;
      quantidade++;
    }
  }
  if(quantidade) return (soma/quantidade);
  return 0;
}



/// (3): ELEMENTO QUE MAIS SE REPETE NUM VETOR DE INTEIROS NAO ORDENADO. (admitindo tamanho mínimo = 1)
int maisSeRepete(int v[], int n){
  int numero, aux;
  int vezes, cont=0;
  int i, j;

  aux = v[0]; // Definido que o primeiro é o que mais se "repete".
 
  for(i=1; i < n; i++){
    numero = v[i];
    vezes  = 0;
    
    for(j = i+1; j < n; j++)
      if(v[j] == numero) vezes++;

    if(vezes >= cont){
      cont = vezes;
      aux  = numero;
    }
  }

  return aux;
}



/// (4): PREENCHER O VETOR COM OS ELEMENTOS QUE DARAO O MAIOR PRODUTO INTERNO (VETOR ORIGINAL E LINHA DA MATRIZ).
void alterarVetor(int vet[], int mat[N][N]){
  int i, j, pInterno;
  int linha, aux=0;

  if(N > 0){
    for(j=0; j < N; j++) // Definindo um comparador.
      aux += vet[j] * mat[0][j];
  
    for(i=1; i < N; i++){
      pInterno=0;
    
      for(j=0; j < N; j++)
	pInterno += vet[j] * mat[i][j];  
          
      if(pInterno > aux){
	aux   = pInterno;
	linha = i;
      }
    }

    // Alterando os valores do vetor.
    for(j=0; j < N; j++) vet[j] = mat[linha][j];
  }
}
