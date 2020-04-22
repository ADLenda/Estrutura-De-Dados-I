#include <iostream>


struct Lista{
	int valor[N];
	int tamanho;
};

typedef struct Lista lista;

Lista inicializaLista(lista *l, int tam){
	for(int i=0; i<N;i++){
		l->valor[i] = 0;
	}
	
}

void insereInicio(lista *l,int valor){
	if(l->tamanho == 0){
		l->valor[0] = valor;
		l->tamanho++;
	}else{
		if(l->tamanho > N){
			printf("\nLista cheia!");
		}else{
			for(int i = l->tamanho; i>0 ;i--){
				l->valor[i] = l->valor[i-1];
			}
			l->valor[0] = valor;
			l->tamanho++;
		}
	}
}
void insereFim(lista *l,int valor){
	if(l->tamanho < N){
		l->valor[l->tamanho] = valor;
		l->tamanho++;
	}else{
		printf("\nLista cheia!");
	}	
}
void inserePosicao(lista *l, int valor, int posicao){
	if(l->tamanho > N){
		printf("\nLista Cheia!");
	}else{
		if(posicao > l->tamanho){
			l->valor[posicao] = valor;
			l->tamanho++;
			printf("\nValor %d adicionado!",l->valor[posicao]);			
		}else{
			//descola todos pra esquerda
			for(int i = l->tamanho; i>posicao ;i--){
				l->valor[i] = l->valor[i-1];	
			}
			l->valor[posicao] = valor;
			l->tamanho++;
			printf("\nValor %d adicionado!",l->valor[posicao]);			
		}
	}
}
int removeInicio(lista *l){
	int aux;
		if(l->tamanho > N || l->tamanho == 0){
			printf("\nLista vazia!");
			return 0;
		}else{
			aux = l->valor[0];
			for(int i=0; i<l->tamanho; i++){
				l->valor[i] = l->valor[i+1];
			}
			l->tamanho--;	
			printf("\nValor removido: %d", aux);
			return aux;
		}
	}
int removeFim(lista *l){
	int aux;
		if(l->tamanho > N || l->tamanho == 0){
			printf("\nLista vazia!");
			return 0;
		}else{
			aux = l->valor[l->tamanho-1];
			l->tamanho--;
			printf("\nValor removido: %d", aux);
			return aux;
		}	
}


void showLista(lista *l){
		for(int i=0; i<N;i++){
			printf("\n %d - [%d]",i,l->valor[i]);
		}	 
}

int main(){
	//CODIGO PRINCIPAL
	lista l;
	l.tamanho =0;
	inicializaLista(&l);
	
	insereInicio(&l,10);
	insereInicio(&l,14);
	insereInicio(&l,17);
	insereInicio(&l,21);
	insereInicio(&l,64);
	insereInicio(&l,43);
	insereFim(&l,5);
	inserePosicao(&l,500,9);
	inserePosicao(&l,500,5);
	inserePosicao(&l,1000,5);
	showLista(&l);

	/*
	removeInicio(&l);
	removeInicio(&l);
	removeInicio(&l);
	removeFim(&l);
	removeFim(&l);
	removeFim(&l);
	removeFim(&l);
	*/
	
	
	//showLista(&l);
	
	return 0;
}
