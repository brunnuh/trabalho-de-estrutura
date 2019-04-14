#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
#define True 1
#define False 0
#define _cofo_c

int Gcriado = False;

//-------------------------- estruturas --------------------------------------------

typedef struct _cofo_{ //tipo de estrutura que sera usado para adc as pessoas
	void* *elementos; // elemento do vetor
	int max; //numero maximo de elementos no vetor.
	int Nelementos; // numero de elementos ocupado no max.
	int cmp; //
}cofo;
//-------------------------- end(estruturas) ----------------------------------------




//-------------------------- funcoes ------------------------------------------------
cofo *CofCreate(int n){
	cofo *c;
	if(n > 0){ // se o numero que foi passado como parametro for maior que zero
		c = (cofo*)malloc(n*sizeof(cofo));// aloca o vetor do tipo cofo com n posicoes
		if(c != NULL){
			c->Nelementos = 0;// inicia numero de elementos ocupado com zero
			c->max = n;// inicia numero maximo de elementos do vetor com n elementos
			Gcriado = True;
			return c;
		}else{
			free(c);//caso dê erro na alocacao, libere
		}
	}
	return NULL;
}

int CofInsert(cofo *c, void* n){// vetor , numero à ser add
	if(c != NULL){
		if(c->Nelementos < c->max){// se numero de elementos for menor que o numero max do vetor
			printf("\n-------------");
			c->elementos = (void*)malloc(sizeof(void*));
			c->elementos[c->Nelementos] = n; //o vetor recebe o n, na posicao numero de elementos
			c->Nelementos ++;// o numero de elementos do vetor é atualizado
			return True;
		}
	}
	return False;
}

int CofDestroy(cofo *c){
	if(c != NULL){
		if(c-> Nelementos == 0){// se o vetor estiver vazio
			free(c->elementos);//libere o vetor de elementos
			free(c);//libere a estrutura
			Gcriado = False;
			return True;
		}
	}
	return False;
}
int CofExist(cofo *c){// como saber se ele ja foi criado, sendo que nao tem como testar != NULL
	if(c -> max > 0){
		return True;
	}	
	return False;
}

void *CofQuery(cofo *c, void *key, int(*cmp)(void*a,void*b)){
	void *aux;
	int stat = 0, i;
	if(c != NULL){
		if(c->Nelementos > 0){
			i = 0;
			stat = cmp(key, c->elementos[i]);
			while(stat == True && i < c->Nelementos){
				i++;
				stat = cmp(key, c->elementos[i]);
			}
			if(stat == True){
				aux = c->elementos[i];
				return aux;
			}
		}
	}
	return NULL;
}
//-------------------------- end(funcoes) ---------------------------------------------
