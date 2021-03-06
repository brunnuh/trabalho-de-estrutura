#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int menu(void){
/*------------------------ Declara�oes ---------------------------------------*/
	int opc = -1;	
/*------------------------ end Declara�oes ---------------------------------------*/
	
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

float *Transposta(int n, int m, float *Vm){
/*------------------------ Declara�oes ---------------------------------------*/
	float *Vt;
	int i, j;
/*------------------------ end Declara�oes -----------------------------------*/

/*------------------------ Fazendo a transposicao ----------------------------*/
	Vt = (float*)malloc(n*m*sizeof(float));
	if(Vt != NULL){
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				Vt[m*i+j] = Vm[m*j+i]; 
			}
		}
		return Vt;
/*------------------------ end( Fazendo a transposicao ) ----------------------*/
	}
	printf("ERRO, na transposicao.");
	exit(0);//finaliza o programa em caso de ERRO
}

void *MultAB(int n, int m, int p, int q, float *Vma, float *Vmb){
/*------------------------ Declara�oes ---------------------------------------*/
	float *Mc;
	int i, j, l, k;
/*------------------------ end Declara�oes ---------------------------------------*/



/*------------------------ Multiplicar Ma x Mb ---------------------------------------*/
	if(m == p){// se coluna de Vma for igual a linha de Vmb. continue
		Mc = (float*)malloc(m*p*sizeof(float));
		if(Mc != NULL){
			for(i = 0;i < n;i++){
				for(j = 0; j < q; j++){
					Mc[n*i+j] = 0.0;
					for(l = 0;l < m; l++){
						Mc[n*i+j] += Vma[m*i+l] * Vmb[q*l+j];
					}
				}
			}
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
			for(i = 0; i < n; i++){
				for(j = 0; j < q; j++){
					printf("\t%.0f ",Mc[n*i+j]);
				}
				printf("\n");
			}
			printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			system("PAUSE");
			system("cls");
			return;
		}
/*------------------------ end( Multiplicar Ma x Mb )---------------------------------------*/
		printf("ERRO NA ALOCACAO DO Mc");
		exit(0);
	}
	else{
		printf("\nNumero de colunas de Ma eh diferente do numero de linhas de Mb");
		exit(0);
	}
}

void *MultABT(int n,int m,int p,int q,float *Vma,float *Vmb){//n - linha, m - coluna, p - linha, q - coluna
	float *Mc;
	int i, j, l, k;


	Mc = (float*)malloc(m*q*sizeof(float));
	if(Mc != NULL){
		Vmb = Transposta(p,q,Vmb);//retorna agora q como linha e p como coluna
		if(Vmb != NULL){
			if(m == q){// se coluna de Vma for igual a Coluna da transposta de Vmb ,continue ..
				for(i = 0;i < n;i++){
					for(j = 0; j < p; j++){
						Mc[n*i+j] = 0.0;
						for(l = 0;l < m; l++){
								Mc[n*i+j] += Vma[m*i+l] * Vmb[q*l+j];
						}
					}
				}
				printf("\n~~~~~~~~~~~~ Ma x MbT ~~~~~~~~~~~~~\n\n");
				for(i = 0; i < n; i++){
					for(j = 0; j < p; j++){
						printf("\t%.0f ",Mc[n*i+j]);
					}
					printf("\n");
				}
				printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				system("pause");
				system("cls");
				return;
			}
			else{
				printf("\nNumero de colunas de Ma eh diferente do numero de linhas da transposta Mb");
				exit(0);
			}
		}
		printf("ERRO NA TRANSPOSICAO DE Mb");
		exit(0);
	}
	printf("ERRO NA ALOCACAO DO Mc");
	exit(0);
}

void *TranspostaMa(int n, int m, float *Ma){
	float *MaT;
	int i, j;
	MaT = (float*)malloc(n*m*sizeof(float));
	if(MaT != NULL){
		MaT = Transposta(n,m,Ma);
		printf("\n~~~~~~~~~~~~ MAT ~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		for( i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				printf("\t%.0f ",MaT[m*i+j]);
			}
			printf("\n");
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		system("pause");
		system("cls");
	}
	else{
		printf("ERRO, na transposicao de Ma\nVERIFIQUE...");
		exit(0);
	}
}

void *TriangSuperiorMa(int n, float *Ma){
	float *Vc;
	int i, j, k;
	Vc = (float*)malloc(((pow(n,2)-n)/2)*sizeof(float));
	if(Vc != NULL){
/*------------------------ recebendo o tringulo superior ---------------------------------------*/
		for(i = 0; i < n - 1; i++){
			for(j = i+1; j < n; j++){
				Vc[n*i+j] = Ma[i*n+j];
			}
		}
/*------------------------ end(recebendo o tringulo superior) ---------------------------------------*/
		
/*------------------------ escrevendo o tringulo superior ---------------------------------------*/
		for(i = 0; i < n -1; i++){
			for(j = i + 1; j < n; j++){
				printf("\t%0.f ",Vc[n*i+j]);
			}
			printf("\n\t");
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		system("pause");
		system("cls");
/*------------------------ end(escrevendo o tringulo superior) ---------------------------------------*/
	}
	else{
		printf("ERRO, na alocacao de Vc\nVERIFIQUE...");
		exit(0);
	}
	
}

void *DiagonalMa(int n, int m, float *Ma){
	
	
/*------------------------ Declaracoes ---------------------------------------*/
	float *Va;
	int Ndiag, i, j, k = 0, Maior;
	Ndiag = n;
	
	if(Ndiag > m){//recebendo o menor, para gastar o minimo de memoria na alocacao
		Ndiag = m;
	}
/*------------------------end( Declaracoes ) ---------------------------------------*/

/*------------------------ Recebendo Diagonal ---------------------------------------*/
	Va = (float*)malloc(Ndiag*sizeof(float));
	
	if(Va != NULL){
		for(i = 0; i < Ndiag; i++){
			Va[i] = Ma[m*i+k];
			k++;
		}
/*------------------------ end( Recebendo Diagonal ) ---------------------------------------*/


/*------------------------ imprimindo Diagonal ---------------------------------------*/
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		for(i = 0; i < Ndiag; i++){
			printf("\t%.0f ",Va[i]);
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		system("pause");
		system("cls");
/*------------------------ end( imprimindo Diagonal )---------------------------------------*/
	}else{
		printf("ERRO, na alocacao de Va\nVerifique...\n");
		exit(0);
	}
}






int main(){
/*------------------------ Declara�oes ---------------------------------------*/
	int n, m;// n -- linhas, m -- colunas
	int p, q;// p -- linhas, q -- colunas
	int i, j;
	int k;
	int opcao = -1;
	float *Ma;//vetor de matriz m x n
	float *Mb;//Vetor de matriz p x q

	FILE *ArquiMatriz;//criando um ponteiro para um arquivo
/*------------------------ end Declara�oes ---------------------------------------*/

/*------------------------ lendo matriz Ma ---------------------------------------*/
	ArquiMatriz = fopen("ArquivoMatrizA.txt","r");//mostrando para o ponteiro seu caminho e o que � pra fazer, r -- ler
	if(ArquiMatriz != NULL){
		fscanf(ArquiMatriz, "%i %i",&n,&m);
		Ma = (float*)malloc(m*n*sizeof(float));
		if(Ma != NULL){
			for(i = 0; i < n; i++){
				for(j = 0; j < m; j++){
					fscanf(ArquiMatriz, "%f",&Ma[m*i+j]);
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
	ArquiMatriz = fopen("ArquivoMatrizB.txt","r");//mostrando para o ponteiro seu caminho e o que � pra fazer, r -- ler
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



/*------------------------ escrevendo matriz Ma ---------------------------------------*/
	printf("\n\t---------%ix%i--------\n",n,m);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("\t%.0f ",Ma[m*i+j]);
		}
		printf("\n");
	}
	
	printf("\n");
/*------------------------ escrevendo matriz Mb ---------------------------------------*/
	printf("\n\t---------%ix%i--------\n",p,q);
	for(i = 0; i < p; i++){
		for(j = 0; j < q; j++){
			printf("\t%.0f ",Mb[q*i+j]);
		}
		printf("\n");
	}
	

/*------------------------ Opcao ---------------------------------------*/
	
	
	while(1){
		opcao = menu();
		if(opcao == 1){
			system("cls");
			MultAB(n,m,p,q,Ma,Mb);
		}else if(opcao == 2){
			system("cls");
			MultABT(n, m, p, q, Ma, Mb);
		}else if(opcao == 3){
			system("cls");
			TranspostaMa(n,m,Ma);
		}else if(opcao == 4){
			if(n == m){
				system("cls");
				TriangSuperiorMa(n,Ma);
			}else{
				system("cls");
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("\n\tERRO, so matriz quadrada.\n");
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				system("pause");
				system("cls");
			}
			
		}else if(opcao == 5){
			DiagonalMa(n, m , Ma);
		}else if(opcao == 6){
			printf("Digite a linha que deseja: ");
			scanf("%i*c",&k);
			if(k > 0 && k <= n){
				system("cls");
				k--; // para aparecer a linha que o usuario pediu, nao a posicao que o computador dar
				for(i = 0; i < n; i++){
						printf("\t%0.f ", Ma[k * m + i]);
				}
			}	
		}
		
		else if(opcao == 7){
			printf("Digite a coluna que deseja: ");
			scanf("%i*c",&k);
			if(k > 0 && k <= m){
				//system("cls");
				k--;
				for(i = 0; i < n; i++){
					printf("\t%0.f ", Ma[n * i + k]);
				}
			}
		
		
		}
		else if(opcao == 8){
			printf("\nFINALIZANDO...");
			break;
		}
	}
/*------------------------ end opcao ---------------------------------------*/	
	

	
	return 0;
}







