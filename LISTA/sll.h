#ifndef _sll_h
#define _sll_h
#define True 1
#define False 0
int Gcriado;
typedef struct _sllelem_ SLLNODE;
typedef struct _sllist_ sllist;
#ifdef _sll_c
	sllist *sllCreate();
	int sllInsertFirst(sllist *l, void* elem);
	int sllDestroy(sllist *l);
	void *sllRemovefirst(sllist *l);
	//void *CofQuery(cofo *c, void *key, int(*cmp)(void *,void *));
	//void *CofGetNext(cofo *c);
	//void *CofGetFirst(cofo *c);
#else
	extern sllist *sllCreate();
	extern int sllInsertFirst(sllist *l, void* elem);
	extern int sllDestroy(sllist *l);
	extern void *sllRemovefirst(sllist *l);
#endif
#endif
