#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "ppt.h"

void concluida()
{
	printf("\n\nAcao concluida.\nDigite qualquer tecla para continuar.");
	fflush(stdin);
	getchar();
	system("cls");
}

void ppt(char dig[], char palavra_maquina[][10], stats estat[])
{
	srand(time(NULL));
	
	int i = rand() % 3;
	
	char escolhido[10];
	strcpy(escolhido, palavra_maquina[i]);
	
	system("cls");
	printf("Pedra, papel, tesou-ra!\n\nVoce jogou: %s\nA maquina jogou: %s\n\n", dig, escolhido);
	
	if(strcmp(dig, escolhido) == 0)
	{
		printf("Deu empate!");
		estat[0].emp++;
	}
	else
	{
		if(strcmp(dig, "Pedra") == 0)
		{
			if(strcmp(escolhido, "Tesoura") == 0)
			{
				printf("Voce venceu!\nParabens!");
				estat[0].vit++;
			}						
			else
			{
				printf("Voce perdeu!\nQue pena...");
				estat[0].der++;
			}			
		}
		
		else if(strcmp(dig, "Papel") == 0)
		{
			if(strcmp(escolhido, "Pedra") == 0)
			{
				printf("Voce venceu!\nParabens!");
				estat[0].vit++;
			}		
			else
			{
				printf("Voce perdeu!\nQue pena...");
				estat[0].der++;
			}
		}
		
		else if(strcmp(dig, "Tesoura") == 0)
		{
			if(strcmp(escolhido, "Papel") == 0)
			{
				printf("Voce venceu!\nParabens!");
				estat[0].vit++;
			}	
			else
			{
				printf("Voce perdeu!\nQue pena...");
				estat[0].der++;
			}
		}
	}
	estat[0].jog++;
	concluida();	
}

void atribuir(char palavra_maquina[][10])
{
	strcpy(palavra_maquina[0], "Pedra");
  	strcpy(palavra_maquina[1], "Papel");
  	strcpy(palavra_maquina[2], "Tesoura");
}

void selecionar(int sel, char dig[], char palavra_maquina[][10], stats estat[])
{
	printf("1 - Pedra\n2 - Papel\n3 - Tesoura\nEscolha uma das opcoes: ");
	scanf("%i", &sel);
	
	if(sel <= 3)
	{
		if(sel == 1)
			strcpy(dig, "Pedra");			
		else if(sel == 2)
			strcpy(dig, "Papel");			
		else if(sel == 3)
			strcpy(dig, "Tesoura");		
		ppt(dig, palavra_maquina, estat);
	}				
	else
	{
		printf("\nOpcao invalida.");
		concluida();
	}					
}

void registrar(stats estat[])
{
	FILE* fregistro;
	fregistro = fopen("..\\log\\log.txt", "w");
	fprintf(fregistro, "Total de partidas jogadas: %i\nVitorias: %i\nDerrotas: %i\nEmpates: %i \n", estat[0].jog, estat[0].vit, estat[0].der, estat[0].emp);
	fclose(fregistro);
	concluida();
}

void leitura(stats estat[])
{
	FILE* fleitura;
	
	fleitura = fopen("..\\log\\log.txt", "r");
	fscanf(fleitura, "Total de partidas jogadas: %i\nVitorias: %i\nDerrotas: %i\nEmpates: %i", 
	&estat[0].jog, &estat[0].vit, &estat[0].der, &estat[0].emp);
	fclose(fleitura);
}

void exibir(stats estat[])
{
	system("cls");
	printf("Total de partidas jogadas: %i\nVitorias: %i\nDerrotas: %i\nEmpates: %i", estat[0].jog, estat[0].vit, estat[0].der, estat[0].emp);
}