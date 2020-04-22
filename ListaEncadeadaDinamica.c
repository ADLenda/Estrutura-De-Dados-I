#include <stdio.h>
#include <stdlib.h>

typedef struct No tipoNo;
void mostraLista(tipoNo **lst);
void insereFim(tipoNo **lst,int vlr);
void insereInicio(tipoNo **lst,int vlr);
void inserePos(tipoNo **lst,int pos, int vlr);
void removeFim(tipoNo **lst);

int main(){
	
	tipoNo* GOMO = NULL;
	malloc(sizeof(GOMO));
	
	insereFim(&GOMO,2);
	insereFim(&GOMO,5);
	insereFim(&GOMO,5);
	insereInicio(&GOMO,10);
	inserePos(&GOMO,4,50);
	printf("\nLISTA ANTES ");
	mostraLista(&GOMO);
	removeFim(&GOMO);
	removeFim(&GOMO);
	removeFim(&GOMO);
	removeFim(&GOMO);
	removeFim(&GOMO);
	printf("\nLISTA DEPOIS ");
	mostraLista(&GOMO);

	return 0;
}
struct No{
	int valor;
	tipoNo *prox;
};

void insereFim(tipoNo **lst,int vlr){
	tipoNo *novoNo, *aux;
	novoNo = (tipoNo *) malloc(sizeof(tipoNo));
	aux = (tipoNo *) malloc(sizeof(tipoNo));
	novoNo->valor = vlr;
	novoNo->prox = NULL;	
	if((*lst) == NULL){
		*lst = novoNo;
	}else{
		aux = *lst;

		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novoNo;
	}
}
void insereInicio(tipoNo **lst,int vlr){
	tipoNo *novoNo, *aux;
	novoNo = (tipoNo *) malloc(sizeof(tipoNo));

	novoNo->valor = vlr;
	novoNo->prox = *lst;
	*lst = novoNo;
}
void inserePos(tipoNo **lst,int pos, int vlr){
	int cont;
	tipoNo *novoNo,*aux,*aux_ant;
	novoNo = (tipoNo *) malloc(sizeof(tipoNo));
	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux_ant = (tipoNo *) malloc(sizeof(tipoNo));
	
	novoNo->valor = vlr;
	cont = 0;
	aux = (*lst);

	while((cont<pos) && (aux != NULL)){
		cont = cont+1;
		aux_ant = aux;
		aux = aux->prox;
	}
	if((cont == pos) && pos > 0){
		novoNo->prox = aux;
		aux_ant->prox = novoNo;
	}else{
		novoNo->prox = *lst;
		*lst = novoNo;
	}
}

void removeFim(tipoNo **lst){
	tipoNo *aux, *noRemover, noCopia;

	if((*lst)->prox == NULL){
		noCopia = **lst;
		free(*lst);
		(*lst) = NULL;
		//return noCopia;
	}else{
		noRemover = (*lst);
		while(noRemover->prox != NULL){
			aux = noRemover;
			noRemover = noRemover->prox;
		}
		noCopia = *noRemover;
		free(noRemover);
		aux->prox = NULL;
		//return noCopia;
	}
}

//FUNCAO MOSTRA A LISTA
void mostraLista(tipoNo **lst){
	if((*lst) == NULL){
		printf("\nLISTA VAZIA!");
	}else{
		tipoNo *novoNo;
		novoNo = *lst;
		while(novoNo != NULL){
			printf("\n%d",novoNo->valor);
			novoNo = novoNo->prox;
			if(novoNo == NULL){
				printf("\nACABOU A LISTA!");
			}
		}
	}
}
