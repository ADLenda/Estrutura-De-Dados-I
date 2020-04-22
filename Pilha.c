#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct tipoPilha{
	int valor[TAM];
	int qtd_valores=0;
};
typedef struct tipoPilha Pilha;

bool insere(Pilha *p,int v){
	
	if(p->qtd_valores < TAM){
		p->valor[p->qtd_valores] = v;
		p->qtd_valores++;
	}else{
		printf("\nPilha cheia!");
	}
}

bool remove(Pilha *p){
	if(p->qtd_valores > 0){
		p->qtd_valores--;
		printf("\nValor %d removido!\n",p->valor[p->qtd_valores]);
	}else{
		printf("\nPilha vazia!\n");
	}	
}

void showPilha(Pilha *p){
	printf("\nPilha inteira: \n");
	for(int i=0; i < p->qtd_valores;i++){
		printf("\n%d - [%d]",i,p->valor[i]);
	}
}

int main(){
	Pilha p1;

	insere(&p1,6);
	insere(&p1,3);
	insere(&p1,7);
	insere(&p1,9);
	insere(&p1,1);
	insere(&p1,2);
	insere(&p1,6);
	insere(&p1,8);
	insere(&p1,5);
	insere(&p1,12);

	showPilha(&p1);
	
	remove(&p1);
	remove(&p1);
	remove(&p1);
	remove(&p1);
	
	showPilha(&p1);
	
	return 0;
}
