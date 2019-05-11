#include <stdio.h>
#include <stdlib.h>
#include "sll.h"


typedef struct _dados_{
	char nome[100];
	int idade;
	int NumFilhos;
	float salario;
	int cpf;
}dados;



dados *cadastro(dados *pessoa){
	printf("Nome: ");
	scanf("%s*c",&(pessoa -> nome));
	printf("Idade: ");
	scanf("%d*c",&(pessoa -> idade));
	printf("Numero de Filhos: ");
	scanf("%d*c",&(pessoa -> NumFilhos));
	printf("Salario: R$");
	scanf("%f*c",&(pessoa -> salario));
	printf("cpf: ");
	scanf("%d*c",&(pessoa -> cpf));
	return pessoa;
}

int main(){
	int opc;
	//sllist *usuarios;// lista usuarios
	//dados *pessoa;// estrutura pessoa

//---------- (Menu) --------------------------
	while(1){
		scanf("%d*c",&opc);
	}
//---------- end (Menu) ----------------------
	return 0;
}
