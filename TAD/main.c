#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
typedef struct _dados_{
	char nome[30];
	int idade;
	int NumFilhos;
	float salario;
	double cpf;
}dados;

void cadastro(dados *pessoa){

	printf("Nome: ");
	scanf("%s*c",&(pessoa -> nome));
	printf("Idade: ");
	scanf("%d",&(pessoa -> idade));
	printf("Numero de Filhos: ");
	scanf("%d",&(pessoa -> NumFilhos));
	printf("Salario: R$");
	scanf("%f",&(pessoa -> salario));
	printf("cpf: ");
	scanf("%d",&(pessoa -> cpf));
}





int main(){
//---------- declaracoes -----------------------
	cofo *usuarios;
	dados *pessoa;
	int retorno;
	int opcao = -1;
//---------- end(declaracoes) ------------------	

//---------- Menu -----------------------	
	while(opcao != 0){
		system("cls");
		printf("1 - Inserir pessoa\n2 - Criar Cofo\n3 - Destruir Cofo\n4 - Inserir ultimos dados cadastrados no Cofo\n5 - Consultar Dados De um usuario pelo cpf\n6 - Remover Dados De um usuario pelo cpf\n7 - Mostrar Cofo Completo\n0 - Sair\n>>>>");
		scanf("%i*c",&opcao);
		if(opcao == 1){
			pessoa = (dados*)malloc(sizeof(dados));
			if(pessoa != NULL){
				cadastro(pessoa);
			}else{
				printf("ERRO, alocacao de pessoa...");
				exit(0);
			}
			
		}else if(opcao > 7 || opcao < 0){
			printf("ERRO, opcao nao existe...\nTente Novamente.\n");
			system("PAUSE");
		}
		
	}
//---------- end(Menu) -----------------------	
	/*
	usuarios = CofCreate(10);// ps: fazer pergunta para o usuario de quantos dados podem ser guardados
	if(usuarios != NULL){
		pessoa = (dados*)malloc(sizeof(dados));
		if(pessoa != NULL){
			pessoa->idade = 10;
			retorno = CofInsert(usuarios,(void*)pessoa);	
			if(retorno == 1){
				printf("\nAdicionado ao usuario");
			}else{
				printf("\nNao foi adicionado ao usuario");
			}
		}
	}else{
		printf("\nERRO NA CRIACAO DOS USUARIOS");
	}
	*/
	return 0;
}
