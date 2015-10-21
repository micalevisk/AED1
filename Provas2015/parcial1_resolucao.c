//
//  parcial1_resolucao.c
//  Matr�cula 21554923
//  Created by Micael Levi on 21/10/15.
//  Copyright (c) 2015 Micael Levi L. Cavalcante. All rights reserved
//


// 1: VER SE O N�MERO � PRIMO
int ehPrimo(int numero){
  int i = 2;

  while(i < numero){
    if((numero % i)==0)
      return 0;
    i++;
  }

  return (numero != 0);
}



// 2: M�DIA DA ALTURA DOS VEGETARIANOS (tem 'S' no campo "veg")
typedef struct{
  char nome[20];
  char veg;      
  float altura;
} tipoPessoa;

float alturaMediaDosVegetarianos(tipoPessoa v[], int nElementos){
  float media    = 0.0;
  int quantidade = 0;
  nElementos--; // contador;

  for(; nElementos >= 0; nElementos--){
    if(v[nElementos].veg == 'S'){
      media += v[nElementos].altura;
      quantidade++;
    }
  }
  return (media/quantidade);
}



// 3: ELEMENTO QUE MAIS SE REPETE NUM VETOR DE INTEIROS N�O ORDENADO
int maisSeRepete(int v[], int n){
  int numero, i = 0;
  int vezes, aux= 0, maisSeRepete, j;

  for(; i < n; i++){
    numero = v[i];
    vezes  = 0;
    
    for(j = i+1; j < n; j++){
      if(v[j] == numero) vezes++;
    }

    if(vezes > aux){
      aux = vezes;
      maisSeRepete = v[i];
    }
  }

  if(n>0) return maisSeRepete;
  else return -1; // 'erro' caso seja um vetor nulo;
}



// 4: PREENCHER O VETOR COM OS ELEMENTOS QUE DAR�O O MAIOR PRODUTO INTERNO
void alterarVetor(int vet[], int mat[N][N]){
  int i, j, pInterno;
  int linha, aux=0;
  
  for(i=0; i < N; i++){
    pInterno=0;
    
    for(j=0; j < N; j++)
      pInterno += vet[j] * mat[i][j];  
          
    if(pInterno > aux){
      aux   = pInterno;
      linha = i;
    }
  }

  for(j=0; j < N; j++)
    vet[j] = mat[linha][j];
}

