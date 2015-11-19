#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int valor;
	unsigned quantidade;
} tipoDado;

typedef struct no{
	tipoDado dado;
	struct no *prox;
} tipoNo;

typedef struct{
	tipoNo *atual;	
} tipoListaCircular;


void criarListaCircular(tipoListaCircular *a){
	a->atual = NULL;
}


void inserirNaListaCircular(tipoListaCircular *a, tipoDado elemento){ // insere depois do 'atual'
	tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
	tipoNo *temp;

	if(aux){
		aux->dado = elemento;

		if(!a->atual) a->atual = aux;
		temp 		   = a->atual->prox;
		a->atual->prox = aux;
		aux            = temp;
	}
}


tipoNo* haElementosNaListaCircular(tipoListaCircular *a){
	return a->atual;
}


// [lista nunca vazia]
tipoDado removerDaListaCircular(tipoListaCircular *a){ // remove o posterior ao 'atual' e atualiza o ponteiro
	tipoNo *aux  = a->atual;
	tipoNo *proximo= aux->prox;;
	tipoDado temp = proximo->dado;

	// para lista de 1 elemento
	if(aux == proximo) a->atual = NULL;

	// para lista com mais de 1 elemento
	else aux->prox = proximo->prox;
	free(proximo);

	return temp;
}


void mostrarElementosDaListaCircular(tipoListaCircular *a){
	tipoNo *aux = a->atual;

	while(aux){
		printf(" valor: %d | quantidade: %u \n", aux->dado.valor, aux->dado.quantidade);
		aux = aux->prox;
	}
}


int main(){

	tipoListaCircular lista;
	tipoDado d1, d2, d3;
	d1.valor = 1;     d2.valor = 1;       d3.valor = 3;
	d1.quantidade = 2; d2.quantidade = 3; d3.quantidade = 4;

	criarListaCircular(&lista);

	printf("\n>> Ha elementos? ");
	(haElementosNaListaCircular(&lista)) ? printf(" SIM\n") : printf(" NAO\n");

	inserirNaListaCircular(&lista, d1); // atual
	inserirNaListaCircular(&lista, d2);
	inserirNaListaCircular(&lista, d3);
	
	printf("\n>> Mostrando elementos: \n");
	mostrarElementosDaListaCircular(&lista);
	/*
	>> Removendo o proximo de atual: \n");
	removerDaListaCircular(&lista);
	*/
}
