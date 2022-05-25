// Ayla Rodrigues
// Questao 1 - Programacao com arquivos

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct reuniao
{
	int id;
	int dia,mes,ano;
	int hora,minuto;
	int qtdPessoas;
};

void verificarArqTxt()
{
	//verificar qual a letra no inicio da linha do arquivo
	/*	if (==I)
	{
		incluir();
	}
	else if(==M)
	{
		modificar();
	}
	else
	{
		excluir();
	}*/
}

void incluir()
{

}

void excluir()
{


}

void modificar()
{

}

void abrirArq()
{
	FILE *arqBin;
	FILE *arqTxt;

	struct reuniao reuniao;

	arqBin = fopen("original.bin", "rb");
	arqTxt = fopen("correcoes.txt", "r");

	if (arqBin==NULL)
	{
		printf("Problemas na leitura do arquivo binario\n");

		if (arqTxt==NULL)
		{
			printf("Problemas na leitura do arquivo texto\n");
		}
	}
	else
	{
		fread(&reuniao, sizeof(reuniao),1,arqBin);
		printf("> Data %d/%d/%d", reuniao.dia, reuniao.mes,reuniao.ano);
		
	}
	Sleep(5000);
	system("cls");
	fclose(arqBin);
	fclose(arqTxt);

}

int main()
{
	abrirArq();


	return 0;
}
