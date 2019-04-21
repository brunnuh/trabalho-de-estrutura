#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

typedef struct _dados_{
	char nome[100];
	int idade;
	int NumFilhos;
	float salario;
	int cpf;
}dados;

int CompCPF(void *cpf, void *pessoa){
	int *key = (int*)cpf;
	dados* p =  (dados*)pessoa;
	if(*key == p->cpf){
		return True;
	}else{
		return False;
	}
}

dados *Aloca(int n){
	dados *p;
	p = (dados*)malloc(n*sizeof(dados));
	if(p != NULL){
		return p;
	}
	return NULL;
}

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
//---------- declaracoes -----------------------
	cofo *usuarios;// cofo de usuarios
	dados *pessoa;// estrutura pessoa; resposta retornada pelo query.
	int i;// pra controle
	int opcao = -1;//inicia a opcao valendo -1
	int CpfInput;//a entrada do cpf que o usuario quer procurar/apagar
	int NumUsuarios;//numero max que o cofo usuarios vai suportar de pessoas
	int RespDest;//pra receber o retorno true ou false da funcao cofdestroy
	int RespInse;//pra receber o retorno true ou false da funcao cofinsert
	dados *RespQuery;//pra receber o retorno aux ou NULL da funcao cofquery
	dados *RespRemove;//pra receber o retorno aux ou NULL da funcao cofremove
	dados *RespGet;//pra receber o retorno das variaveis contida dentro dele
//---------- (Menu) --------------------------
	while(opcao != 0){
		system("cls");
		printf("================================================");
		printf("\n1 - Criar Cofo\n2 - Destruir Cofo\n3 - Inserir no Cofo\n4 - Consultar Dados De um usuario pelo cpf\n5 - Remover Dados De um usuario pelo cpf\n6 - Mostrar Cofo Completo\n0 - Sair");
		printf("\n================================================");
		printf("\n>>>>");
		scanf("%d*c",&opcao);
		if(opcao == 1){
			if(Gcriado == False){
				printf("Quantos Usuarios: ");
				scanf("%d*c",&NumUsuarios);
				usuarios = CofCreate(NumUsuarios);
				if(usuarios != NULL){
					system("cls");
					printf("=============================");
					printf("\n\tCOFO CRIADO...\n");
					printf("=============================\n");
					system("pause");
				}
				else{
					system("cls");
					printf("=============================");
					printf("\n\tCOFO NAO CRIADO...\n");
					printf("=============================\n");
					system("pause");
				}
			}
			else{
				system("cls");
				printf("=============================");
				printf("\n Ja existe um cofo criado...\n");
				printf("=============================\n");
				system("pause");
			}
		}
		else if(opcao == 2){
			if(Gcriado == True){
				if(usuarios != NULL){
					RespDest = CofDestroy(usuarios);
					if(RespDest == True){
						system("cls");
						printf("=============================");
						printf("\n\tCOFO DESTRUIDO\n");
						printf("=============================\n");
						system("pause");	
					}
					else if(RespDest == False){
						system("cls");
						printf("================================");
						printf("\n\tFalha na Destruicao\n");
						printf("================================\n");
						system("pause");
					}
				}
			}
			else{
				system("cls");
				printf("==================================");
				printf("\n Nao existe cofo para ser apagado.\n");
				printf("==================================\n");
				system("pause");
			}
		}
		else if(opcao == 3){
			if(Gcriado == True){
				if(usuarios != NULL){
					//pessoa = (dados*)malloc(sizeof(dados));
					pessoa = Aloca(1);
					if(pessoa != NULL ){
						pessoa = cadastro(pessoa);
						RespInse = CofInsert(usuarios, (void*)pessoa);
						if(RespInse == True){
							system("cls");
							printf("===============================");
							printf("\n\tInserido...\n");
							printf("===============================\n");
							//free(pessoa);
							system("pause");			
						}
						else if(RespInse == False){
							system("cls");
							printf("===============================");
							printf("\n\tErro, cofo cheio...\n");
							printf("===============================\n");
							system("pause");
						}
					}
				}
			}
			else{
				system("cls");
				printf("=================================");
				printf("\n    Erro, cofo nao existe...\n");
				printf("=================================\n");
				system("pause");
			}
		}
		else if(opcao == 4){
			if(Gcriado == True){
				if(usuarios != NULL){
					printf("\nBuscar CPF: ");
					scanf("%d*c",&CpfInput);
					//RespQuery = (dados*)malloc(sizeof(dados));// ps: criar funcao para alocar
					RespQuery = Aloca(1);
					if(RespQuery != NULL){
						RespQuery = (dados*)CofQuery(usuarios,(void*)&CpfInput,CompCPF);
						if(RespQuery != NULL){
							system("cls");
							printf("=================================");
							printf("\n\t Nome:\t%s\n\t Cpf:\t%d\n",(RespQuery->nome),(RespQuery->cpf));
							printf("================================\n");
							system("pause");
							//free(RespQuery);
						}
						else{
							system("cls");
							printf("=================================");
							printf("\nERRO, na busca\n");
							printf("================================\n");
						}
						
					}
					else{
						system("cls");
						printf("=================================");
						printf("\n\tErro na alocacao...\n");
						printf("=================================\n");
						system("pause");	
					}
				}
			}else{
				system("cls");
				printf("=================================");
				printf("\n\tNao existe cofo...\n");
				printf("================================\n");
				system("pause");
			}
		}
		else if(opcao == 5){
			if(Gcriado == True){
				if(usuarios != NULL){
					printf("\nBuscar CPF: ");
					scanf("%d*c",&CpfInput);
					//RespRemove = (dados*)malloc(sizeof(dados));
					RespRemove = Aloca(1);
					RespRemove = (dados*)CofRemove(usuarios,(void*)&CpfInput,CompCPF);
					if(RespRemove != NULL){
						system("cls");
						printf("================= REMOVIDO =================");
						printf("\n\t\tNome:\t%s\n\t\tCpf:\t%d\n",(RespRemove->nome),(RespRemove->cpf));
						printf("=============================================\n");
						system("pause");
						//free(RespQuery);
					}
					else{
						system("cls");
						printf("===================================");
						printf("\n Nao Existe ou Ja foi removido\n");
						printf("===================================\n");
						system("pause");
					}
				}
			}
			else{
				system("cls");
				printf("===================================");
				printf("\n\tCofo nao existe...\n");
				printf("===================================\n");
				system("pause");
			}
		}
		else if(opcao == 6){
			if(Gcriado == True){
				if(usuarios != NULL){
					//RespGet = (dados*)malloc(sizeof(dados));
					RespGet = Aloca(1);
					if(RespGet != NULL){
						RespGet = (dados*)CofGetFirst(usuarios);//pedindo o primeiro dado, para zerar o cur do cofo
						if(RespGet != NULL){
							system("cls");
							printf("=============== COFO ===============");
							//printf("\n\tnome:\t%s\n\tCpf:\t%i",RespGet->nome,RespGet->cpf);
							while(RespGet != NULL){				
								printf("\n\tnome:\t%s\n\tCpf:\t%i",RespGet->nome,RespGet->cpf);			
								RespGet = (dados*)CofGetNext(usuarios);
								
							}
							printf("\n===================================\n");
							system("pause");
						}else{
							system("cls");
							printf("===================================\n");
							printf(" ERRO,getfirst retornou NULL");
							printf("\n===================================\n");
							system("pause");
						}
					}else{
						system("cls");
						printf("===================================\n");
						printf(" ERRO, na alocacao do RespGet");
						printf("\n===================================\n");
						system("pause");
					}
				}
			}
			else{
				system("cls");
				printf("===================================\n");
				printf("\tErro,Nao existe cofo");
				printf("\n===================================\n");
				system("pause");
			}
		}
		else if(opcao > 7 || opcao < 0){
			system("cls");
			printf("===================================\n");
			printf(" ERRO, Escolha uma opcao valida!");
			printf("\n===================================\n");
			system("pause");
		}
	}

//---------- end(Menu) -----------------------
	system("cls");
	printf("===================================\n");
	printf("\tFINALIZANDO...");
	printf("\n===================================\n");
	system("pause");
	return 0;
}
