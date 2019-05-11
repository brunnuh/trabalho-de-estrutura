#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#define True 1
#define False 0
#define _sll_c


//int Gcriado = False;// liga e desliga pra saber se estar criado ou nao

//-------------------------- estruturas --------------------------------------------
typedef struct _sllelem_{
	struct _sllelem_ *next;
	void *data;
}SLLNODE;

typedef struct _sllist_{
	SLLNODE *first;
}sllist;
//-------------------------- end(estruturas) ----------------------------------------


//-------------------------- funcoes ------------------------------------------------
sllist *sllCreate(){
	sllist *l;
	l = (sllist*)malloc(sizeof(sllist));
	if(l != NULL){
		l->first = NULL;
		return l;
	}
	return NULL;
}

int sllInsertFirst(sllist *l, void *elem){
	SLLNODE *NewNode;
	if(l != NULL){
		NewNode = (SLLNODE*)malloc(sizeof(SLLNODE));
		if(NewNode != NULL){
			NewNode->data = elem;
			NewNode->next = l->first;
			l->first = NewNode;
			return True;
		}
	}
	return False;
}
void *sllRemoveFirst(sllist *l){
	SLLNODE * aux; //nao precisa alocar, pois ele so vai apontar pra alguem que ja esteja alocado
	void *data;
	if(l != NULL){
		if(l->first != NULL){
			aux = l->first;
			l->first = aux->next;
			data = aux->data;
			free(aux);
			return aux->data;
		}
	}
	return NULL;
}
int sllDestroy(sllist *l){
	if(l != NULL){
		if(l->first == NULL){
			free(l);
			return True;
		}
	}
	return False;
}









