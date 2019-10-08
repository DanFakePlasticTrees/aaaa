#ifndef ORQUESTAS_H_INCLUDED
#define ORQUESTAS_H_INCLUDED
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
typedef struct {

int id;
char nombre[20];
char lugar[20];
int tipo;
int isEmpty;
} eOrquesta;

#endif // ORQUESTAS_H_INCLUDED
int altaOrquesta(eOrquesta vec[], int id, int tam);
eOrquesta newOrquesta(int id,char nombre[],char lugar[],int tipo);
int buscarLibre(eOrquesta vec[], int tam);
void inicializarOrquestas(eOrquesta vec[], int tam);
void mostrarOrquestas(eOrquesta vec[], int tam);
void mostrarOrquesta(eOrquesta orquesta);
