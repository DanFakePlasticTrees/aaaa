#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED

typedef struct {
int id;
int tipo;
char nombre[20];
int isEmpty;
} eInstrumento;

#endif // INSTRUMENTOS_H_INCLUDED


void mostrarInstrumento(eInstrumento instrumento);
void mostrarInstrumentos(eInstrumento vec[], int tam);
int altaInstrumento(eInstrumento vec[], int id, int tam);


eInstrumento newInstrumento (int id,int tipo,char nombre[]);


int buscarLibreInstrumento(eInstrumento vec[], int tam);


void inicializarInstrumentos(eInstrumento vec[], int tam);


int cargarDescInstrumento(int id, eInstrumento vec[], int tam, char desc[]);
