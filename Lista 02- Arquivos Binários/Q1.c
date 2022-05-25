// Ayla Rodrigues
// Questao 1 - Programacao com arquivos

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct agenda
{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
	char assunto[20];

}Agenda;

void GravarAgenda(int dia, int mes, int ano, int hora, int minuto, char assunto[])
{
	FILE *arq;

	Agenda agenda;
	arq= fopen("agenda.bin", "ab");

	if (arq ==NULL)
	{
		printf("Erro\n");
	}

	agenda.dia=dia;
	agenda.mes=mes;
	agenda.ano=ano;
	agenda.hora=hora;
	agenda.minuto=minuto;
	strcpy(agenda.assunto, assunto);
	
	system("cls");
	fwrite(&agenda,sizeof(Agenda),1,arq);//acho que ta gravando errado no arquivo
	printf("\n");
	printf("Reuniao registrada com sucesso\n\n");

	fclose(arq);
	system("cls");
}

void ProcurarReuniao(int dia, int mes, int ano)
{
	FILE *arquivo;

	Agenda agenda;

	arquivo = fopen("agenda.bin", "rb");

	if (arquivo==NULL)
	{
		printf("Problemas na leitura do arquivo\n");
	}
	else
	{
		printf(" REUNIOES DO DIA %d/%d/%d\n\n",dia,mes,ano);

		while(fread(&agenda, sizeof(Agenda),1,arquivo)==1)
		{
			if (dia == agenda.dia && mes == agenda.mes  && ano == agenda.ano)
			{
				printf("> Horario: %d:%d\n", agenda.hora,agenda.minuto);
				printf("> Assunto: %s\n", agenda.assunto);
				printf("\n");
			}
		}
		
	}
	system("cls");
	fclose(arquivo);
}

int main() 
{
	setlocale(LC_ALL, "");

	int opcao=0;
	int diaM,mesM,anoM;
	int dia,mes,ano;
	int hora,minuto;
	char assunto[20];

	while(opcao!=3)
	{
		printf("O que deseja fazer?\n\n1.Registrar uma nova reunião\n2.Mostrar reuniões agendadas\n3.Sair\n\n>");
		scanf("%d", &opcao);
		printf("\n");
		system("cls");

		if (opcao==1)
		{
			printf("> Qual o dia da reuniao?\n\n");
			printf("\t");
			scanf("%d/%d/%d", &dia, &mes, &ano);
			printf("\n");

			printf("> Qual o horario da reuniao?\n\n");
			printf("\t");
			scanf("%d:%d", &hora, &minuto);
			printf("\n");

			fflush(stdin);
			printf("> Qual o assunto da reuniao?\n\n");
			printf("\t");
			scanf("%[^\n]s", assunto);
			printf("\n");

			GravarAgenda(dia, mes, ano, hora, minuto, assunto);
		}
		else if(opcao==2)
		{
			printf("> Qual o dia que deseja ver as reunioes marcadas?\n\n");
			printf("\t");
			scanf("%d/%d/%d", &diaM, &mesM, &anoM);
			printf("\n");

			ProcurarReuniao(diaM, mesM ,anoM);			
		}
	}

	
	system("cls");
	printf("O usuário saiu");

	return 0;
}
