#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
#define True 1
#define False 0

typedef struct _dados_{
	char nome[30];
	int idade;
	int NumFilhos;
	float salario;
	double cpf;
}dados;

void cadastro(dados *pessoa){
	if(Gcriado == False){
		printf("\nCuidado, seus dados estao sendo sobreposto\nPorfavor, crie um cofo.\n");
	}
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
	int RespInse;
	int opcao = -1;
	int NumPessoas, LibPessoa = False;


//---------- end(declaracoes) ------------------	

//---------- Menu -----------------------	
   	while(opcao != 0){
		system("cls");
		printf("1 - Inserir pessoa\n2 - Criar Cofo\n3 - Destruir Cofo\n4 - Inserir ultimos dados cadastrados no Cofo\n5 - Consultar Dados De um usuario pelo cpf\n6 - Remover Dados De um usuario pelo cpf\n7 - Mostrar Cofo Completo\n0 - Sair\n>>>>");
		scanf("%i*c",&opcao);
		if(opcao == 1){
			if(LibPessoa == True){
				free(pessoa);
				LibPessoa = False;
			}
			pessoa = (dados*)malloc(sizeof(dados));
			if(pessoa != NULL){
				cadastro(pessoa);
				LibPessoa = True;
			}
			else{
				printf("ERRO, alocacao de pessoa...");
				free(pessoa);
				exit(0);
			}
		}
		else if(opcao == 2){
			printf("Numero maximo de pessoas no cofo: ");
			scanf("%d*c",&NumPessoas);
			usuarios = CofCreate(NumPessoas);// ps: fazer pergunta para o usuario de quantos dados podem ser guardados
			if(usuarios == NULL){
				printf("ERRO, na criacao do cofo");
				CofDestroy(usuarios);
				exit(0);
			}
			else{
				system("cls");
				printf("\n--Cofo criado com sucesso--\n\n");
				system("PAUSE");
			}
		}
		else if(opcao == 3){
			if(Gcriado == True){
				CofDestroy(usuarios);
				system("cls");
				printf("\n--Cofo Destruido com sucesso--\n\n");
				system("PAUSE");
			}else{
				system("cls");
				printf("\nERRO, cofo nao foi criado ou foi apagado\n\n");
				system("PAUSE");
			}
		}
		else if(opcao == 4){
			if(Gcriado == True){
				if(pessoa != NULL && LibPessoa == False){
					RespInse = CofInsert(usuarios,(void*)pessoa);
					free(pessoa);
					if(RespInse == 1){
						system("cls");
						printf("\nAdicionado ao usuario");
						system("PAUSE");
					}
					else{
						system("cls");
						printf("\nNao foi adicionado ao usuario");
						system("PAUSE");
					}		
				}
				else{
					printf("\nERRO, alocacao de pessoa ou ainda nao foi alocada...");
					exit(0);
				}	
			}
			else{
				printf("ERRO, criacao do cofo ou nao existe...");
				exit(0);
			}
		}
		else if(opcao == 5){
			
		}
		else if(opcao > 7 || opcao < 0){
			printf("\nERRO, opcao nao existe...\nTente Novamente.\n");
			system("PAUSE");
		}
		
	}
//---------- end(Menu) -----------------------	
	
	return 0;
}
