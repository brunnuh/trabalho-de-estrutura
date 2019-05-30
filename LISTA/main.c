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
int CompCPF(void *cpf, void *pessoa){
	int *key = (int*)cpf;
	dados *p = (dados*)pessoa;
	if(*key == p->cpf){
		return True;
	}
	return False;
}
dados *Aloca(void){
	dados *p;
	p = (dados*)malloc(sizeof(dados));
	if(p != NULL){
		return p;
	}
	return NULL;
}

void PrinNfoiCriado(void){
		system("cls");
		printf("==================================");
		printf("\n\tLista nao foi criada");
		printf("\n=================================\n");
		system("pause");
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
	dados *RespGetF, *RespGetN, *RespQuery, *RespRemov;
	int opcao = -1;
	int cpfInput;
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
						printf("=============================\n");
						printf("\tLista destruida\n");
						printf("=============================\n");
						system("pause");
					}else{
						system("cls");
						printf("==================================");
						printf("\n  A Lista nao pode ser destruida\n  Verifique se esta vazia.\n");
						printf("==================================\n");
						system("pause");
					}
				}
			}else{
				PrinNfoiCriado();
			}
		}else if(opcao == 3){
			if(Gcriado == True){
				if(usuarios != NULL){
					pessoa = Aloca();
					if(pessoa != NULL){
						pessoa = Cadastro(pessoa);
						RespInserf = sllInsertLast(usuarios,(void*)pessoa);
						if(RespInserf == True){
							system("cls");
							printf("=============================");
							printf("\n\tAdicionado na lista\n");
							printf("=============================\n");
							system("pause");	
						}else{
							system("cls");
							printf("=================================");
							printf("\n\tNao foi Adicionado na lista\n");
							printf("=================================\n");
							system("pause");	
						}
					}
				}
			}else{
				PrinNfoiCriado();	
			}
		}else if(opcao == 4){
			if(Gcriado == True){
				if(usuarios != NULL){
					printf("Buscar Cpf: ");
					scanf("%i*c",&cpfInput);
					RespQuery = Aloca();
					if(RespQuery != NULL){
						RespQuery = (dados*)sllQuery(usuarios,(void*)&cpfInput,CompCPF);
						if(RespQuery != NULL){
							system("cls");
							printf("=============================");
							printf("\n\tNome: %s\n\tcpf: %i\n\tIdade %d \n\tFilhos %d \n\tSalario:R$ %.2f\n",(RespQuery->nome),(RespQuery->cpf), (RespQuery->idade), (RespQuery->NumFilhos), (RespQuery->salario));
							printf("=============================\n");
							system("pause");
						}else{
							system("cls");
							
							printf("=============================");
							printf("\n\tCPF Nao encontrado");
							printf("\n=============================\n");
							system("pause");
						}
					}
				}
			}else{
				PrinNfoiCriado();
				}
		}else if(opcao == 5){
			if(Gcriado == True){
				if(usuarios != NULL){
					printf("Buscar Cpf: ");
					scanf("%i*c",&cpfInput);
					RespRemov = Aloca();
					if(RespRemov != NULL){
						RespRemov = (dados*)sllRemoveSpec(usuarios,(void*)&cpfInput,CompCPF);
						if(RespRemov != NULL){
							system("cls");
							printf("========== Removido ==========");
							printf("\n\t Nome: %s\n\t cpf: %i",(RespRemov->nome),(RespRemov->cpf));
							printf("\n=============================\n");
							system("pause");
						}else{
							system("cls");
							printf("=============================");
							printf("\n\tCPF Nao encontrado");
							printf("\n=============================\n");
							system("pause");
						}	
					}	
				}
			}else{
				PrinNfoiCriado();
			}
		}else if(opcao == 6){
			if(Gcriado == True){
				if(usuarios != NULL){
					RespGetF = Aloca();
					if(RespGetF != NULL){
						RespGetF = (dados*)sllGetFirst(usuarios);
						if(RespGetF != NULL){
							system("cls");
							printf("=========== LISTA ===========");
							printf("\n\tnome: %s\n\tCPF: %i\n",(RespGetF -> nome),(RespGetF->cpf));
							RespGetN = Aloca();
							if(RespGetN != NULL){
								RespGetN = RespGetF;
								while(RespGetN != NULL){
									RespGetN = (dados*)sllGetNext(usuarios);
									if(RespGetN != NULL){
										printf("\n\tnome: %s\n\tCPF: %i\n",(RespGetN -> nome),(RespGetN->cpf));
										
									}
								}
								printf("=============================\n");
								system("pause");	
							}
						}else{
							system("cls");
							printf("=============================");
							printf("\n ERRO EM RETORNO DE LISTA");
							printf("\n=============================\n");
							system("pause");
						}
					}
				}
			}else{
				PrinNfoiCriado();
			}
		}//fim opcao
		
	}//fim while
	return 0;
}
