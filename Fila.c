#include <stdio.h>
#define TAM 10

struct tipoFila{
	int valor[TAM];
	int qtd_valores = 0;
};
typedef struct tipoFila Fila;

void insereFila(Fila *f,int v){
	if(f->qtd_valores == TAM){
		printf("\nFila cheia!");
	}else{
	f->valor[f->qtd_valores] = v;
	f->qtd_valores++;
	}
}

void removeFila(Fila *f){
	for(int i=0;i < f->qtd_valores-1;i++){
		f->valor[i] = f->valor[i+1];
	}
	f->qtd_valores--;
}

void showFila(Fila *f){
	for(int i=0;i < f->qtd_valores;i++){
		printf("\n %d -[%d]",i,f->valor[i]);
	}
}

int main(){
	
	Fila f1;
	
	insereFila(&f1,10);
	insereFila(&f1,5);
	insereFila(&f1,10);
	insereFila(&f1,5);
	insereFila(&f1,10);
	insereFila(&f1,5);
	insereFila(&f1,10);
	insereFila(&f1,5);
	insereFila(&f1,10);
	insereFila(&f1,5);
	showFila(&f1);
	
	removeFila(&f1);
	removeFila(&f1);
	printf("\n");		
	
	showFila(&f1);
	
	return 0;
}
