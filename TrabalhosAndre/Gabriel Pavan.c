#include <stdio.h>
#include <math.h>

void gravar(char *saida, double *AC, double *AT, double *ACM){
	FILE *aula;
	aula=fopen(saida,"a");
	fprintf(aula,"%lf %lf %lf\n",*AC,*AT,*ACM);
	fclose(aula);
}
void processamento(char *saida, double *A, double *B, double *C){
	double SEMIPE,RAIOMENOR,RAIOMAIOR,AREACMENOR,AREATRIAN,AREACMAIOR,AC,AT,ACM;
	SEMIPE = ((*A)+(*B)+(*C))/2;
	AREATRIAN = sqrt(SEMIPE*(SEMIPE-(*A))*(SEMIPE-(*B))*(SEMIPE-(*C)));
	RAIOMENOR = AREATRIAN/SEMIPE;
	AREACMENOR = M_PI*pow(RAIOMENOR,2);
	RAIOMAIOR = ((*A)*(*B)*(*C))/sqrt(((*A)+(*B)+(*C))*((*A)+(*B)-(*C))*((*A)-(*B)+(*C))*((*B)+(*C)-(*A)));
	AREACMAIOR = M_PI*pow(RAIOMAIOR,2);
	AC=AREACMAIOR-AREATRIAN;
	AT=AREATRIAN-AREACMENOR;
	ACM=AREACMENOR;
	gravar(saida,&AC,&AT,&ACM);
}
int leitura(char *entrada, char *saida){
	double A,B,C;
	FILE *arquivo;
	arquivo=fopen(entrada,"r");
	if(arquivo==NULL) return 0;
	while(fscanf(arquivo,"\n%lf %lf %lf",&A,&B,&C)!=EOF){
		processamento(saida,&A,&B,&C);
	}
	fclose(arquivo);
	return 1;
}

void main(){
	char entrada[100]="teste.txt";
	char saida[100]="saida.txt";
	remove(saida);
	if(leitura(entrada,saida)){
		printf("Arquivo criado com sucesso!\n");
	} else{
		printf("Arquivo nao foi encontrado!\n");
	}
	
}

//Explicacao formula do raio R: http://www.paulomarques.com.br/arq4-12.htm
