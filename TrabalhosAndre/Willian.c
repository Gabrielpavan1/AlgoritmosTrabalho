#include<stdio.h>
#include<string.h>
#define t 10100

char digito=1,num[t],string[t];

void process(){
    int i,j=0;
    for(i=0;num[i]!='\0';i++){
        if(num[i]!=digito){
            string[j]=num[i];
            j++;
        }
    }
    string[j]='\0';
}

void write(char *nome){
    FILE *arquivo;
    arquivo=fopen(nome,"a");
    int i,ok=0;
    for(i=0;string[i]!='\0';i++){
            if(string[i]=='0' && ok) fprintf(arquivo,"%c",string[i]);
            if(string[i]>'0'){
                fprintf(arquivo,"%c",string[i]);
                ok=1;
            }
        }
        if(ok) fprintf(arquivo,"\n");
        else fprintf(arquivo,"0\n");
    fclose(arquivo);
}

int read(char *nome){
    FILE *arquivo;
    arquivo = fopen(nome,"r");
    if(arquivo==NULL) return 0;
    int i,j,ok;
    while(digito!='0'){
        fscanf(arquivo,"\n%c %s",&digito,num);
        if(digito=='0' && num[0]=='0') break;
        process();
        write("out.txt");
    }
}
int main(){
    read("in.txt");
    return 0;
}
