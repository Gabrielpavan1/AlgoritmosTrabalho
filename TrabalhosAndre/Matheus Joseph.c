#include <stdio.h>
#include <string.h>
void grav(char result[],int fna){
FILE *saida;
saida = fopen (result, "a" );
if(fna==1){
	fprintf(saida,"frase completa\n");
}
else if(fna==2){
	fprintf(saida,"frase quase completa\n");
}
else if(fna==3){
	fprintf(saida,"frase mal elaborada\n");
}
fclose(saida);
}
void proc(char *url){
char frase[1000];
int N,X=0,Y,tamanho,cont,alfa=0,fna=0;
FILE *arquivo;
arquivo=fopen(url,"r");
if(arquivo==NULL)
printf("Erro, nao foi possivel abrir o arquivo\n");
else
fscanf(arquivo,"%d",&N);
printf("%d\n",N);
for(Y=0;Y<N;Y++){
char ABC[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
fscanf(arquivo,"\n%[^\n]c",frase);
printf("%s\n",frase);
tamanho = strlen(frase);
for(X=0;X<tamanho;X++){
	for(cont=0;cont<26;cont++){
		if(frase[X]==ABC[cont]){
			alfa++;
			ABC[cont]='-';
		}
	}
}
if(alfa>=26){
	fna=1;
	grav("saida.txt",fna);
	printf("frase completa\n");
}
else if(alfa>=13){
	fna=2;
	grav("saida.txt",fna);
	printf("frase quase completa\n");
}
else if(alfa<13){
	fna=3;
	grav("saida.txt",fna);
	printf("frase mal elaborada\n");
	}
   alfa=0;
}
fclose(arquivo);
}
int main(){
remove("saida.txt");
proc("in.txt");
return 0;}
