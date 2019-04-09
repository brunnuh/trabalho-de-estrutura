#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"



typedef struct _people_{
	char nome[30];
	int idade;
	int NumFilhos;
	float salario;
	double cpf;
}people;


int main() {
	cofo *usuarios;
	people *pessoa;
	int teste;
	
	
	usuarios = CofCreate(10);
	if(usuarios != NULL){
		pessoa = (people*)malloc(sizeof(people));
		if(pessoa != NULL){
			pessoa->idade = 10;
			teste = CofInsert(usuarios,(void*)pessoa);	
			if(teste == 1){
				printf("\nAdicionado ao usuario");
			}else{
				printf("\nNao foi adicionado ao usuario");
			}
		}
	}else{
		printf("\nERRO NA CRIACAO DOS USUARIOS");
	}
	
	return 0;
}
