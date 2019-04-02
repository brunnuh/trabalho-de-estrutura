#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu(void){
/*------------------------ Declaraçoes ---------------------------------------*/
	int opc = -1;	
/*------------------------ end Declaraçoes ---------------------------------------*/
	
	while (1){
		printf("\n");
		printf("======= MENU =======\n");
		printf("\n1 - A x B\n2 - A x BT\n3 - AT\n4 - Triangulo superior de A\n5 - Diagonal de A\n6 - Digite um numero para mostrar a linha de A\n7 - Digite um numero para mostrar a coluna de A\n8 - sair\n>>>>>>>");
		scanf("%i*c",&opc);
		if(opc > 0 && opc < 9){
			return opc;
		}
		printf("\n===================\nOpcao invalida\nDigite Novamente\n===================\n");
		system("pause");
		system("cls");
	}
	return 0;
}


void *MultAB(int m, int n, int p, int q, float *Vma, float *Vmb){
/*------------------------ Declaraçoes ---------------------------------------*/
	float *Mc;
	int i, j, l, k;
/*------------------------ end Declaraçoes ---------------------------------------*/
	if(n == p){
		Mc = (float*)malloc(m*q*sizeof(float));
		if(Mc != NULL){
			for(i = 0;i < n;i++){
				for(j = 0; j < p; j++){
					Mc[p*i+j] = 0.0;
					for(l = 0;l < m; l++){
						Mc[p*i+j] += Vma[p*i+l] * Vmb[p*l+j];
					}
				}
			}
			for(i = 0; i < n; i++){
				for(j = 0; j < p; j++){
					printf("\t%.0f ",Mc[p*i+j]);
				}
				printf("\n");
			}
			system("pause");
			system("cls");
		}
		printf("ERRO NA ALOCACAO DO Mc");
		return NULL;
	}
	else{
		printf("\nNumero de colunas de Ma eh diferente do numero de linhas de Mb");
		return NULL;
	}
}


int main(){
/*------------------------ Declaraçoes ---------------------------------------*/
	int m, n;// m -- linhas, m -- colunas
	int p, q;// p -- linhas, q -- colunas
	int i, j;
	int opcao = -1;
	float *Ma;//vetor de matriz m x n
	float *Mb;//Vetor de matriz p x q
	FILE *ArquiMatriz;//criando um ponteiro para um arquivo
/*------------------------ end Declaraçoes ---------------------------------------*/
	
/*------------------------ lendo matriz Ma ---------------------------------------*/
	ArquiMatriz = fopen("ArquivoMatrizA.txt","r");//mostrando para o ponteiro seu caminho e o que é pra fazer, r -- ler
	if(ArquiMatriz != NULL){
		fscanf(ArquiMatriz, "%i %i",&m,&n);
		Ma = (float*)malloc(m*n*sizeof(float));
		if(Ma != NULL){
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					fscanf(ArquiMatriz, "%f",&Ma[n*i+j]);
				}
				fscanf(ArquiMatriz, "\n");
			}
		}
		else{
			printf("ERRO, alocacao da matriz Ma.");
			exit(0);
		}
	}
	else{
		printf("ERRO, arquivo Ma nao encontrado.");
		exit(0);
	}
/*------------------------ end (ler matriz Ma) ---------------------------------------*/
	
/*------------------------ lendo matriz Mb ---------------------------------------*/
	ArquiMatriz = fopen("ArquivoMatrizB.txt","r");//mostrando para o ponteiro seu caminho e o que é pra fazer, r -- ler
	if(ArquiMatriz != NULL){
		fscanf(ArquiMatriz, "%i %i",&p,&q);
		Mb = (float*)malloc(p*q*sizeof(float));
		if(Mb != NULL){
			for(i = 0; i < p; i++){
				for(j = 0; j < q; j++){
					fscanf(ArquiMatriz, "%f",&Mb[q*i+j]);
				}
				fscanf(ArquiMatriz, "\n");
			}
		}
		else{
			printf("ERRO, alocacao da matriz Mb.");
			exit(0);
		}
	}
	else{
		printf("ERRO, arquivo Mb nao encontrado.");
		exit(0);
	}
/*------------------------ end (ler matriz Mb) ---------------------------------------*/
	
/*------------------------ Opcao ---------------------------------------*/
	while(opcao != 8){
		opcao = menu();
		if(opcao == 1){
			MultAB(m,n,p,q,Ma,Mb);
		}else if(opcao == 8){
			printf("\nFINALIZANDO...");
		}
	}
/*------------------------ end opcao ---------------------------------------*/	
	
/*------------------------ escrevendo matriz Ma ---------------------------------------
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("\t%.0f ",Ma[n*i+j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	for(i = 0; i < p; i++){
		for(j = 0; j < q; j++){
			printf("\t%.0f ",Mb[q*i+j]);
		}
		printf("\n");
	}*/
	
	return 0;
}







