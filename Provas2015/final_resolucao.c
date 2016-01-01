//
//  final_resolucao.c
//  Created by Micael Levi on 15/12/21.
//  Copyright (c) 2015 Micael Levi L. Cavalcante. All rights reserved
//

// ---------------- //
typedef struct no{
  int dado;
  struct no *prox;
}tipoNo;

typedef struct{
  tipoNo *prim;
}tipoLista;

typedef struct{
  char nome[30];    
  char endereco[20];
  float altura;     
}tipoPessoa;      
// ---------------- //


/// (1): ORDENAR O ARQUIVO COM O MELHOR ALGORITMO DE ORDENACAO, SELECAO, INSERCAO, QUICK OU MERGE.  
//       i)  OS DADOS ESTAO MUITO EMBARALHADOS E COM NENHUMA REPETIÇÃO DE CHAVE;
//       ii) O CONTEÚDO DO ARQUIVOO CABE COMPLEMENTE NA MEMORIA PRINCIPAL MAS O SEU DOBRO NAO;
//       iii)HA MAIS DE 10 MILHOES DE ITENS NO ARQUIVO.
//       A ORDENACAO DEVE SER FEITA PELO NOME.
void ordenarPorInsercao(FILE *fp){
  int nElementos = tamanhoDoArquivo(fp)/sizeof(tipoPessoa);
  tipoPessoa buffer[nElementos], pivot;
  int i, j;
  
  rewind(fp);
  if( fread(buffer, sizeof(tipoPessoa), nElementos, fp) == nElementos ){
    for(i=1; i < nElementos; i++){
      pivot = buffer[i];
      j = i-1;
      
      while( (j >= 0) && (strcmp(buffer[j].nome, pivot.nome) > 0) ){
	buffer[j+1] = buffer[j];
	j--;
      }
      buffer[j+1] = pivot;      
    }
    
    rewind(fp);
    fwrite(buffer, sizeof(tipoPessoa), nElementos, fp);
  }  
}



/// (2): RETORNA VERDADEIRO CASO DUAS LISTAS ENCADEADAS PASSADAS TENHAM INTERSECAO VAZIA.
int nenhumElementoEmComum(tipoLista A, tipoLista B){
  tipoNo *aux;

  if(!B.prim) return 1;
  
  while(A.prim){
    for(aux = B.prim; aux; aux = aux->prox)
      if(A.prim->dado == aux->dado) return 0;
    A.prim = A.prim->prox;
  }

  return 1;
}


/// (3): IMPRIME O NUMERO DE VEZES QUE DIGITOS ENTRE '0' E '9' OCORREM DENTRO DO ARQUIVO.
//       IMPRIME A OCORRENCIA DE CADA UM DESSES DÍGITOS.
void frequenciaDosDigitos(FILE *descritor){
  unsigned frequencia;
  char buf, digito;

  for(digito='0'; digito < 58; digito++){
    rewind(descritor); // "Rebobinar".
    frequencia = 0;    // Zerar contador.
    
    while((fread(&buf, sizeof(char), 1, descritor))==1) // Ler 1 byte.
      if(buf == digito) frequencia++;
    printf(" Vezes que o digito '%c' aparece: %u\n", digito, frequencia);
  }  
}



/// (4): GERAR ARQUIVO TEXTO COM OS REGISTROS DE UM VETOR DO TIPO tipoPessoa PASSADO.
//       O NOME DO ARQUIVO A SER CRIADO EH "saída.out".
void gerarArquivo(tipoPessoa pessoas[], int n){
  FILE *fp = fopen("saída.out", "w");
  int i;
  
  if(fp){
    for(i=0; i < n; i++){
      fprintf(fp, "%s\n", pessoas[i].nome);
      fprintf(fp, "%s\n", pessoas[i].endereco);
      fprintf(fp, "%.2f\n\n", pessoas[i].altura);
    }
    fclose(fp);  
  }  
}
