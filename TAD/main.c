#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cofo.h"

typedef struct _dados_{
	char nome[100];
	int idade;
	int NumFilhos;
	float salario;
	int cpf;
}dados;

int CompCPF(void*cpf, void *pessoa){
	int key = (int*)cpf;
	dados* p =  (dados*)pessoa;
	if(key == p->cpf){
		return True;
	}else{
		return False;
	}
}

dados *cadastro(dados *pessoa){
	printf("Nome: ");
	scanf("%s*c",&(pessoa -> nome));
	/*printf("Idade: ");
	scanf("%d*c",&(pessoa -> idade));
	printf("Numero de Filhos: ");
	scanf("%d*c",&(pessoa -> NumFilhos));
	printf("Salario: R$");
	scanf("%f*c",&(pessoa -> salario));*/
	printf("cpf: ");
	scanf("%d*c",&(pessoa -> cpf));
	return pessoa;
}





int main(){
//---------- declaracoes -----------------------
	cofo *usuarios;// cofo de usuarios
	dados *pessoa;// estrutura pessoa; resposta retornada pelo query.
	int opcao = -1;//inicia a opcao valendo -1
	int CpfInput;//a entrada do cpf que o usuario quer procurar
	int NumUsuarios;//numero max que o cofo usuarios vai suportar de pessoas
	int RespDest;//pra receber o retorno true ou false da funcao cofdestroy
	int RespInse;//pra receber o retorno true ou false da funcao cofinsert
	dados *RespQuery;//pra receber o retorno aux ou NULL da funcao cofquery
//---------- (Menu) --------------------------
	while(opcao != 0){
		printf("1 - Criar Cofo\n2 - Destruir Cofo\n3 - Inserir no Cofo\n4 - Consultar Dados De um usuario pelo cpf\n5 - Remover Dados De um usuario pelo cpf\n6- Mostrar Cofo Completo\n0 - Sair\n>>>>");
		scanf("%d*c",&opcao);
		if(opcao == 1){
			if(Gcriado == False){
				printf("Quantos Usuarios: ");
				scanf("%d*c",&NumUsuarios);
				usuarios = CofCreate(NumUsuarios);
				if(usuarios != NULL){
					printf("\nCOFO CRIADO...\n");
				}
				else{
					printf("\nCOFO NAO CRIADO...\n");
				}
			}
			else{
				printf("\nJa existe um cofo criado...\n");
			}
		}
		else if(opcao == 2){
			if(Gcriado == True){
				if(usuarios != NULL){
					RespDest = CofDestroy(usuarios);
					if(RespDest == True){
						printf("\nCofo Destruido\n");
					}
					else{
						printf("\nFalha na Destruicao...\n");
					}
				}
			}
			else{
				printf("\nNao existe cofo para ser apagado.\n");
			}
		}
		else if(opcao == 3){
			if(Gcriado == True){
				if(usuarios != NULL){
					pessoa = (dados*)malloc(sizeof(dados));
					if(pessoa != NULL ){
						pessoa = cadastro(pessoa);
						RespInse = CofInsert(usuarios, (void*)pessoa);
						if(RespInse == True){
							printf("\nInserido...\n");
							//free(pessoa);
							
						}
						else{
							printf("\nErro na insercao...\n");
						}
					}
				}
			}
			else{
				printf("\nErro, cofo cheio ou nao existe...\n");
			}
		}
		else if(opcao == 4){
			if(Gcriado == True){
				if(usuarios != NULL){
					printf("\nBuscar CPF: ");
					scanf("%d*c",&CpfInput);
					RespQuery = (dados*)malloc(sizeof(dados));
					RespQuery = (dados*)CofQuery(usuarios,(void*)CpfInput,CompCPF);
					if(RespQuery != NULL){
						printf("\n\nNome: %s\nCpf:%d\n",(RespQuery->nome),(RespQuery->cpf));
						//free(RespQuery);
					}
					else{
						printf("\nErro na busca...\n");
					}
				}
			}else{
				printf("\nNao existe cofo...\n");
			}
		}
		else if(opcao > 8 && opcao < 0){
			printf("ERRO, Escolha uma opcao valida!");
		}
	}



//---------- end(Menu) -----------------------

	return 0;
}
