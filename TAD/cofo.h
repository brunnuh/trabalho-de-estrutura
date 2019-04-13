#define _cofo_h
#define True 1
#define False 0
int Gcriado;

typedef struct _cofo_ cofo;
#ifdef _cofo_c
	cofo *CofCreate(int n);
	int CofInsert(cofo *c, void* n);
	int CofDestroy(cofo *c);
	int CofExist(cofo *c);
#else
	
	extern cofo *CofCreate(int n);
	extern int CofInsert(cofo *c, void* n);
	extern int CofDestroy(cofo *c);
	extern int CofExist(cofo *c);
	
#endif
