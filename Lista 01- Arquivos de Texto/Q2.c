// Ayla Rodrigues
// Questao 2 - Programacao com arquivos

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
setlocale(LC_ALL, "");

FILE *arq;
arq = fopen("valores.txt", "rt");
char vet[100];
char *result;
char *x;
int inteiro=0;
int reais=0;
int string=0;

if (arq ==NULL)
{
	printf("Problemas na criacao do arquivo\n");
}
else
{
	int i = 1;
	while (!feof(arq))
	{
		result = fgets(vet, 100, arq); 
		if (result)  
		{
			x =strtok(vet,",");
			while(x!=NULL)
			{
				//nao soube como comparar o ponteiro com o codigo ASCII (nem sei se era pra ser feito dessa forma)
				if ((x>64 && x<91)|| (x>96 && x<123))
				{
					string++;
				}
				else if (x==46)
				{
					reais++;
				}
				else
				{
					inteiro++;
				}
				printf("Na linha %d tem:\n", i);
				printf("%d inteiros\n",inteiro);
				printf("%d reais\n",reais);
				printf("%d strings\n",string);
				x =strtok(NULL,",");
			}
		}i++;
		inteiro=0;
		reais=0;
		string=0;
	}
}

fclose(arq);
return 0;
}
