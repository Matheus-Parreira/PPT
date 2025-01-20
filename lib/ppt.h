#ifndef PPT_H
#define PPT_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct
{
	int jog;
	int vit;
	int der;
	int emp;
}stats;

void concluida();
void ppt(char[], char[][10], stats[]);
void atribuir(char[][10]);
void selecionar(int, char[], char[][10], stats[]);
void registrar(stats[]);
void leitura(stats[]);
void exibir(stats[]);

#endif