#include <stdio.h>
#define tam 1000

void arqleitura (char *nome_arquivo, int *vetor, int *num_entradas)
{
	FILE *arquivo = fopen (nome_arquivo, "r");
	if (arquivo == NULL)
	{
		perror ("O seguinte error ocorreu");
	}
	int a[1000], i = 0; //, j = 0;
	
	fscanf (arquivo, "%d %d", &a[i], &a[i+1]);
	while (!feof (arquivo))
	{	
		vetor[i] = a[i];
		vetor[i+1] = a[i+1];
	
		i += 2;
		num_entradas[0] = i;
		
		fscanf (arquivo, "%d %d", &a[i], &a[i+1]);
	}
	
	fclose (arquivo);
}

void pcomputacao (int num_i, int num_f, int *saida, int *l, int *num_saida)
{
	int num, cont, cond, tam_num, i, j, k, c;
	char vet_num[4]; 	
	c = l[0];
	cont = 0;
	
	for (i = num_i; i <= num_f; i++)
	{
		num = i;
		cond = 0;
		tam_num = 0;
		while (num != 0)
		{
			vet_num[tam_num] = num % 10;
			num /= 10;
			tam_num++;
		}				
		for (j = 0; j < tam_num; j++)
		{
			for (k = j+1; k < tam_num; k++)
			{
				if (vet_num[j] == vet_num[k])
				{
					cond = 1;
				}
			}
		}
		if (cond == 0)
		{
			cont++;
		}
	}
	
	saida[c] = cont;
	c++;
	l[0] = c;
	num_saida[0]++;
	
	//printf ("%d\n", connt);
	vet_num[0] = '\0';
}

void arqescrever (char *nome_arquivo, int *vetor, int *num_vet)
{
	FILE *arquivo = fopen (nome_arquivo, "w");
	if (arquivo == NULL)
	{
		perror ("O seguinte error ocorreu");
	}
	int i, j = *num_vet;
	
	for (i = 0; i < j; i++)
	{
		fprintf (arquivo, "%d\n", vetor[i]);
	}
	
	fclose (arquivo);
}

int main ()
{
	int n[tam], ni, nf, i, j[1], k[1], resultado[tam], num_res[1], l[1];
	num_res[0] = 0;
	l[0] = 0;
	char arquivo_entrada[tam], arquivo_saida[tam];
		
	printf ("Digite o nome do arquivo de entradas: ");
	scanf("%s", arquivo_entrada);	
	arqleitura (arquivo_entrada, n, j);
	
	for (i = 0; i < j[0]; i += 2)
	{
		ni = n[i];
		nf = n[i+1];
		pcomputacao (ni, nf, resultado, l, num_res);
	}

	printf ("Digite o nome do arquivo de saida(s): ");
	scanf("%s", arquivo_saida);
	arqescrever (arquivo_saida, resultado, num_res);
	
	return 0;
}
