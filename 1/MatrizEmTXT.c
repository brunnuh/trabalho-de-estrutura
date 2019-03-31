#include <stdio.h>
#include <stdlib.h>

int main(){
	int m, n;
	int i, j;
	float *Ma;
	FILE *ArquiMatrizA;//criando um ponteiro para um arquivo
	ArquiMatrizA = fopen("ArquivoMatrizA.txt","r");//mostrando para o ponteiro seu caminho e o que é pra fazer, r -- ler
	
	if(ArquiMatrizA != NULL){
		fscanf(ArquiMatrizA, "%i %i",&m,&n);
		Ma = (float*)malloc(m*n*sizeof(float));
		if(Ma != NULL){
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					fscanf(ArquiMatrizA, "%f",&Ma[m*i+j]);
				}
				fscanf(ArquiMatrizA, "\n");
			}
			
			for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
					printf("%.0f ",Ma[m*i+j]);
				}
				printf("\n");
			}
		}
		else{
			printf("ERRO, alocacao da matriz Ma.");
			exit(0);
		}
	}
	else{
		printf("ERRO, arquivo nao encontrado.");
	}
	
	
	return 0;
}

