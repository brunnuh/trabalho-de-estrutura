#include <stdio.h>
#include <stdlib.h>

float *LerArqui(){
	float *VetorM;
	FILE *ArquiMatrizA;//criando um ponteiro para um arquivo
	int m, n;
	int i, j;
	ArquiMatrizA = fopen("ArquivoMatrizA.txt","r");//mostrando para o ponteiro seu caminho e o que é pra fazer, r -- ler
	if(ArquiMatrizA != NULL){
		fscanf(ArquiMatrizA, "%i %i",&m,&n);//lendo linhas e colunas
		VetorM = (float*)malloc(m*n*sizeof(float));
		if(VetorM != NULL){
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					fscanf(ArquiMatrizA, "%f",&VetorM[m*i+j]);
				}
				fscanf(ArquiMatrizA, "\n");
			}
			return VetorM,m,n;
		}
		else{
			printf("\nERRO, alocacao da matriz Ma.");
			return NULL;//receber null e mata o programa
		}
	}
	else{
		printf("ERRO, arquivo nao encontrado.");
		return NULL;
	}
	
}

int main(){
	int m, n;
	int i, j;
	float *Ma;
	
	
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("\t%.0f ",Ma[m*i+j]);
		}
		printf("\n");
	}
	
	
	return 0;
}

