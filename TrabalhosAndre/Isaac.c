#include <stdio.h>
FILE *arquivol;
FILE *arquivoe;
int ler(){
	int v;
	fscanf(arquivol,"%d",&v);
	return v;
}
void escrever(int opt,int cidade, int va, int vb, double cm){
	if(opt==1){
		fprintf(arquivoe,"Cidade# %d:\n",cidade);
	}
	else if(opt==2){
		fprintf(arquivoe,"%d-%d ",va,vb);
	}
	else if(opt==3){
		fprintf(arquivoe,"\nConsumo medio: %0.2lf m3.\n",cm);
	}
}
int main(){
	arquivol=fopen("entrada.txt","r");
	arquivoe=fopen("saida.txt","w");
	int nl,i,j,aux0,aux1,aux2,cidade=0,x;
	double consmedio,somam=0.0,somac=0.0;
	while(0==0){
		somac=0;somam=0;
		nl=ler();
		if(nl==0){
			break;
		}
		int matriz[nl][3];
		cidade=cidade+1;
		for(i=0;i<nl;i=i+1){
			for(j=0;j<2;j=j+1){
				matriz[i][j]=ler();
			}
		}
		for(i=0;i<nl;i=i+1){
			matriz[i][2]=matriz[i][1]/matriz[i][0];
			somam=somam+matriz[i][0];
			somac=somac+matriz[i][1];
		}
		for(i=0;i<nl-1;i=i+1){
			for(j=i+1;j<nl;j=j+1){
				if(matriz[i][2]>matriz[j][2]){
					aux0=matriz[i][0];
					aux1=matriz[i][1];
					aux2=matriz[i][2];
					matriz[i][0]=matriz[j][0];
					matriz[i][1]=matriz[j][1];
					matriz[i][2]=matriz[j][2];
					matriz[j][0]=aux0;
					matriz[j][1]=aux1;
					matriz[j][2]=aux2;
				}
			}
		}
		consmedio=somac/somam;
		escrever(1,cidade,0,0,0);
		for(i=0;i<nl;i=i+1){
			if(matriz[i][2]==matriz[i+1][2]){
				matriz[i][0]=matriz[i][0]+matriz[i+1][0];
				x=1;
			}
			escrever(2,cidade,matriz[i][0],matriz[i][2],0);
			if(x==1){
				i=i+1;
				x=0;
			}
		}
		escrever(3,cidade,0,0,consmedio);
	}
	fclose(arquivol);
	fclose(arquivoe);
	return 0;
}
