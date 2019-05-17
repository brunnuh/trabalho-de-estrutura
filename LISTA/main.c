#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

typedef struct _dados_{
	char nome[30];
	int idade;
	int cpf;
	int NumFilhos;
	float salario;	
}dados; 

dados *Aloca(void){
	dados *p;
	p = (dados*)malloc(sizeof(dados));
	if(p != NULL){
		return p;
	}
	return NULL;
}

dados *Cadastro(dados *pessoa){
	printf("Nome:");
	scanf("%s*c",&(pessoa->nome));
	printf("Idade:");
	scanf("%i*c",&(pessoa->idade));
	printf("Filhos:");
	scanf("%i*c",&(pessoa->NumFilhos));
	printf("Salario:R$");
	scanf("%f*c",&(pessoa->salario));
	printf("CPF:");
	scanf("%i*c",&(pessoa->cpf));
	return pessoa;
}
int main(){
	sllist *usuarios;
	dados *pessoa;
	int opcao = -1;
	int RespDest, RespInserf;
	while(opcao != 0){
		system("cls");
		printf("================================================");
		printf("\n1 - Criar Lista\n2 - Destruir Lista\n3 - Inserir na Lista\n4 - Consultar Dados De um usuario pelo cpf\n5 - Remover Dados De um usuario pelo cpf\n6 - Mostrar Lista Completo\n0 - Sair");
		printf("\n================================================");
		printf("\n>>>>");
		scanf("%d*c",&opcao);
		if(opcao == 1){
			if(Gcriado == False){
				usuarios = sllCreate();
				if(usuarios != NULL){
					system("cls");
					printf("=============================");
					printf("\n\tLISTA CRIADA...\n");
					printf("=============================\n");
					system("pause");
				}else{
					system("cls");
					printf("=============================");
					printf("\n\tLISTA NAO CRIADA...\n");
					printf("=============================\n");
					system("pause");
				}
			}else{
				system("cls");
				printf("=============================");
				printf("\n\tJA EXISTE UMA LISTA\n");
				printf("=============================\n");
				system("pause");
			}	
		}else if(opcao == 2){
			if(Gcriado == True){
				if(usuarios != NULL){
					RespDest = sllDestroy(usuarios);
					if(RespDest == True){
						system("cls");
						printf("Lista destruida\n");
						system("pause");
					}else{
						system("cls");
						printf("A Lista nao pode ser destruida\nVerifique se esta vazia.\n");
						system("pause");
					}
				}
			}else{
				system("cls");
				printf("Nao existe lista\n");
				system("pause");
			}
		}else if(opcao == 3){
			if(Gcriado == True){
				if(usuarios != NULL){
					pessoa = Aloca();
					if(pessoa != NULL){
						pessoa = Cadastro(pessoa);
						RespInserf = sllInsertFirst(usuarios,(void*)pessoa);
						if(RespInserf == True){
							system("cls");
							printf("Adicionado na lista\n");
							system("pause");	
						}else{
							system("cls");
							printf("Nao foi Adicionado na lista\n");
							system("pause");	
						}
					}
				}
			}else{
				system("cls");
				printf("Nao Existe Lista\n");
				system("pause");	
			}
		}//fim opcao
		
	}//fim while
	return 0;
}
