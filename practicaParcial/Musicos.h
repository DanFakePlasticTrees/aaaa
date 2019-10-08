#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED
#include "Functions.h"
#include "Orquestas.h"
#include "Instrumentos.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct{

int id;
char nombre[20];
char apellido[20];
int edad;
int idOrquesta;
int idInstrumento;
int isEmpty;

} eMusico;

#endif // MUSICOS_H_INCLUDED




void inicializarMusicos(eMusico vec[], int tam);
int buscarLibreMusico (eMusico vec[], int tam);
eMusico newMusico(int id,char nombre[],char apellido[],int edad,int idOrquesta,int idInstrumento);

int altaMusico(eMusico vec[], int id, int tam, eOrquesta vecO[], int tamO, eInstrumento vecI[], int tamI);
void mostrarMusico(eMusico musico, eInstrumento vec[], int tamI);


void mostrarMusicos(eMusico vec[], int tam, eInstrumento vecI[], int tamI);
