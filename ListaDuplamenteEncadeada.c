#include <stdio.h>
#include <stdlib.h>

typedef struct listaDupla tipoListaDupla;
struct listaDupla{
	int valor;
	tipoListaDupla *prox;
	tipoListaDupla *ant;
};

void insereFimListaDupla(tipoListaDupla **lst, int vlr){	
	tipoListaDupla *novoNo, *aux;
	novoNo = (tipoListaDupla*)malloc(sizeof(tipoListaDupla));
	novoNo->valor = vlr;
	novoNo->prox = NULL;
	novoNo->ant = NULL;
	if(*lst == NULL){
		*lst = novoNo;
	}else{
		aux = *lst;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novoNo;
		novoNo->ant = aux;
	}
}

void insereInicioListaDupla(tipoListaDupla **lst, int vlr){
	tipoListaDupla *novoNo, *aux;
	novoNo = (tipoListaDupla*)malloc(sizeof(tipoListaDupla));

		if(novoNo !=NULL){
			novoNo->valor = vlr;
			novoNo->prox = *lst;
			printf("\nANTES");
			novoNo->ant = novoNo;
			printf("\nDEPOIS");
			*lst = novoNo;
		}
}

void mostraListaDupla(tipoListaDupla **lst){
	if((*lst) == NULL){
		printf("\nLISTA VAZIA!");
	}else{
		tipoListaDupla *novoNo;
		novoNo = *lst;
		while(novoNo != NULL){
			int i;
			printf("\n%d - %d",novoNo->valor,i++);
			novoNo = novoNo->prox;
			if(novoNo == NULL){
				printf("\nACABOU A LISTA!");
			}
		}
	}
}

void inserePosDupla(tipoListaDupla **lst, int pos, int vlr){
	int cont;
	tipoListaDupla *novoNo,*aux,*aux_ant;
	novoNo = (tipoListaDupla *) malloc(sizeof(tipoListaDupla));
	aux = (tipoListaDupla *) malloc(sizeof(tipoListaDupla));
	aux_ant = (tipoListaDupla *) malloc(sizeof(tipoListaDupla));
	
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
		novoNo->ant = aux_ant;
		aux_ant->prox = novoNo;
	}else{
		novoNo->prox = *lst;
		novoNo->ant = aux_ant;
		*lst = novoNo;
	}
}
int main (){
	
	tipoListaDupla* lista = NULL;
	malloc(sizeof(lista));
	
	insereInicioListaDupla(&lista,2);
	insereInicioListaDupla(&lista,3);
	insereInicioListaDupla(&lista,4);
	mostraListaDupla(&lista);
}
