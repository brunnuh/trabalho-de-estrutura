#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
#define True 1
#define False 0
#define _cofo_c

int Gcriado = False;// liga e desliga pra saber se estar criado ou nao

//-------------------------- estruturas --------------------------------------------

typedef struct _cofo_{ //tipo de estrutura que sera usado para adc as pessoas
	void** elementos; // elemento do vetor
	int max; //numero maximo de elementos no vetor.
	int Nelementos; // numero de elementos ocupado no max.
	int cur;
}cofo;
//-------------------------- end(estruturas) ----------------------------------------




//-------------------------- funcoes ------------------------------------------------
cofo *CofCreate(int n){
	cofo *c;
	if(n > 0){ // se o numero que foi passado como parametro for maior que zero
		c = (cofo*)malloc(sizeof(cofo));// aloca o vetor do tipo cofo com n posicoes
		if(c != NULL){
			c->elementos = (void**)malloc(sizeof(void*));
			if(c->elementos != NULL){
				c->Nelementos = 0;// inicia numero de elementos ocupado com zero
				c->max = n;// inicia numero maximo de elementos do vetor com n elementos
				c->cur = -1;//ajuda a retorna o cofo por posicao
				Gcriado = True;
				return c;
			}
		}else{
			free(c);//caso dê erro na alocacao, libere
		}
	}
	return NULL;
}

int CofInsert(cofo *c, void* n){// vetor , numero à ser add
	if(c != NULL){
		if(c->Nelementos < c->max){// se numero de elementos for menor que o numero max do vetor
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

void *CofQuery(cofo *c, void *key, int(*cmp)(void*,void*)){
	int stat, i;
	if(c != NULL){
		if(c->Nelementos > 0){
			i = 0;
			stat = cmp((void*)key, c->elementos[i]);
			while(stat == False && i < c->Nelementos){
				i++;
				stat = cmp((void*)key, c->elementos[i]);
			}
			
			if(stat == True){
				return c->elementos[i];
			}
		}
	}
	return NULL;
}

void *CofRemove(cofo *c, void *key, int(*cmp)(void*,void*)){
	void *aux;
	int i = -1,j,stat = False;
	aux = (void**)malloc(sizeof(void*));
	if(c != NULL){
		if(aux != NULL){
			if(c->Nelementos > 0){
				while(stat == False && i < c->Nelementos){
					i++;
					stat = cmp((void*)key,c->elementos[i]);	
				}
				if(stat == True){
					aux = c->elementos[i];
					for(j = i;j < c->Nelementos;j++){
						c->elementos[j] = c->elementos[j+1];	
					}
					c->Nelementos--;
					if(c->Nelementos == 0){
						Gcriado == False;
					}
					return aux;
				}
			}
		}
	}
	free(aux);
	return NULL;	
}
void *CofGetFirst(cofo *c){//se quiser todo o cofo, sempre chamar essa funcao primeiro, para zerar o cur
	if(c != NULL){
		if(c->Nelementos > 0){
			c->cur = 0; // sempre o primeiro elemento
			return c->elementos[c->cur];
		}
	}
	return NULL;
}

void *CofGetNext(cofo *c){
	if(c != NULL){
		if(c->Nelementos > 0){
			c->cur++;
			if(c->cur < c->Nelementos){
				return c->elementos[c->cur];
			}
		}
	}
	return NULL;
}


//-------------------------- end(funcoes) ---------------------------------------------
