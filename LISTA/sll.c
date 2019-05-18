#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#define True 1
#define False 0
#define _sll_c


int Gcriado = False;
//-------------------------- estruturas --------------------------------------------
typedef struct _sllelem_{
	struct _sllelem_ *next;
	void *data;
}SLLNODE;

typedef struct _sllist_{
	SLLNODE *first;
	void *cur;
}sllist;
//-------------------------- end(estruturas) ----------------------------------------


//-------------------------- funcoes ------------------------------------------------
sllist *sllCreate(){
	sllist *l;
	l = (sllist*)malloc(sizeof(sllist));
	if(l != NULL){
		l->first = NULL;
		Gcriado = True;
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
			Gcriado = False;
			return True;
		}
	}
	return False;
}
void *sllGetFirst(sllist *l){
	
	if(l != NULL){
		if(l->first != NULL){
			l->cur = l->first->next;
			return (l->first)->data;
		}
	}
}
void *sllGetNext(sllist *l){
	SLLNODE *aux;
	if(l!= NULL){
		if((l->cur) != NULL){
			aux = l->cur;
			l->cur = aux->next;
			return aux->data;	
		}
	}
	return NULL;
}








