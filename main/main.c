#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "..\lib\ppt.h"

int main()
{
	stats estat[1];
	leitura(estat);
	
	int op = 1, sel;
	char palavra_maquina[3][10], dig[10];	
	
	atribuir(palavra_maquina);
	
	while(op != 3)
	{
		printf("Pedra, Papel, Tesoura!\nDesenvolvido por Matheus Henrique Parreira.\n\n1 - Jogar\n2 - Estatisticas\n3 - Sair \nSelecione uma opcao: ");
		scanf("%i", &op);
		
		system("cls");
		switch(op)
		{
			case 1:
				selecionar(sel, dig, palavra_maquina, estat);
			break;
			case 2:
				exibir(estat);				
				registrar(estat);
			break;
			case 3:				
				printf("Saindo... ");
				return 0;
			break;
			default:
				printf("Opcao invalida.");
				concluida();
			break;
		}
	}
}