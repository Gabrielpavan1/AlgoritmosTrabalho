#include <stdio.h>
double leitura(char *nome){
	FILE *arquivo;
	int entrada = 0, num = 0;
	char oper;
	double result = 1.0;
	arquivo=fopen(nome,"r");
	if(arquivo == NULL) return 0;
	fscanf(arquivo,"%d",&entrada);
	while(entrada--){
		fscanf(arquivo,"%d %c", &num, &oper);
		result = (oper == '*') ? result * num : result / num;
	}
	fclose(arquivo);
	return result;
}
void gravar(char *saida,double *out){
	FILE *arquivo;
	arquivo=fopen(saida,"a");
	fprintf(arquivo,"%.0lf\n",*out);
	fclose(arquivo);
}
int main(void){
	double result;
	result = leitura("in.txt");
	gravar("out.txt",&result);
	printf("TO PRONTO.\n");
	return 0;
}
