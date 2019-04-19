#ifndef _cofo_h
#define _cofo_h
#define True 1
#define False 0
int Gcriado;
typedef struct _cofo_ cofo;
#ifdef _cofo_c
	cofo *CofCreate(int n);
	int CofInsert(cofo *c, void* n);
	int CofDestroy(cofo *c);
	void *CofQuery(cofo *c, void *key, int(*cmp)(void *,void *));
	void *CofRemove(cofo *c, void *key, int(*cmp)(void *,void *));
	void *CofGetNext(cofo *c);
	void *CofGetFirst(cofo *c);
#else
	extern cofo *CofCreate(int n);
	extern int CofInsert(cofo *c, void* n);
	extern int CofDestroy(cofo *c);
	extern void *CofQuery(cofo *c, void *key, int(*cmp)(void *, void *));
	extern void *CofRemove(cofo *c, void *key, int(*cmp)(void *,void *));
	extern void *CofGetNext(cofo *c);
	extern void *CofGetFirst(cofo *c);
#endif
#endif
