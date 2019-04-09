#define _cofo_h_


typedef struct _cofo_ cofo;
#ifdef _cofo_c
	cofo *CofCreate(int n);
	int CofInsert(cofo *c, void* n);
	int CofDestroy(cofo *c);
#else

	extern cofo *CofCreate(int n);
	extern int CofInsert(cofo *c, void* n);
	extern int CofDestroy(cofo *c);
#endif
