#include <stdio.h> 
#include <stdlib.h>

	void gravar(int R);
	void processamento(int N , int M , int **matriz);
	int leitura();

// Grava o resultado .
void gravar(int R){
	FILE *saida;
	saida=fopen("saida.txt","a");
	fprintf(saida,"%d\n",R);
	fclose(saida);
	}

int leitura() {

	int i,j;
	int N,M;
	//declara um ponteiro para ponteiro de int
	//para poder alocar dinamicamente uma matriz bidimensional
	int **matriz;

	//abre o arquivo em modo texto apenas para leitura

	FILE *arquivo;
	arquivo = fopen("matriz.txt","r"); 
	  if (arquivo == NULL) { 
	  printf("Erro na abertura do arquivo!\n"); 
	return(0); 
	}

	//le numero de linhas e numero de colunas

	fscanf(arquivo, "%d %d",&N,&M);

	//aloca dinamicamente uma matriz de N linhas por M colunas

	matriz = (int **)malloc(sizeof(int*) * N);
	  for ( i = 0; i < N; i++) {
	  matriz[i] = (int *)malloc(sizeof(int) * M); 
	}
 	for ( i = 0; i < N; i++) {
	  for ( j = 0; j < M; j++) {
	  fscanf(arquivo,"%d", &matriz[i][j]); 
	  } 
	}

	processamento (N , M , matriz);

	}

	void processamento (int N , int M , int **matriz) {

	int i,j,S=0,y=0,C=0;

	//Ninguém resolveu todos os problemas.

	for ( i = 0; i < N; i++) {
	S = 0;
	  for ( j = 0; j < M; j++) {
	  S+=matriz[i][j];
	  }
	if ( S < M ) {
	  y++;
	  } 
	}
	if ( y == N ) {
	  C++;
	}
	  y=0;

	//Todo problema foi resolvido por pelo menos uma pessoa (não necessariamente a mesma).

	for ( j = 0; j < M; j++) {
	S = 0;  
	  for ( i = 0; i < N; i++) {
	  S+=matriz[i][j];
	  }
	if ( S > 0 ) {
	  y++;
	  }
	}
	if ( y == M ) {
	  C++;
	}
	  y = 0; 

	//Não há nenhum problema resolvido por todos.

	for ( j = 0; j < M; j++) {
	S = 0;
	  for ( i = 0; i < N; i++) {
	  S+=matriz[i][j];
	  }
	if ( S == N ) {
	  y++;
	  }
	}
	if ( y == 0 ) {
	  C++;
	}
	  y = 0;

	//Todos resolveram ao menos um problema (não   necessariamente o mesmo).

	for ( i = 0; i < N; i++) {
	S = 0;
	  for ( j = 0; j < M; j++) {
	  S+=matriz[i][j];
	  }
	if ( S > 0 ) {
	  y++;
	  }
	}
	if ( y == N ) {
	  C++;
	}
	gravar(C);
	  C = 0;
	  y = 0;
 }


int main () {

  leitura();

 return 0; 
 }
