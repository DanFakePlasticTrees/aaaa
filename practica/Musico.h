

#include "Instrumento.h"
#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED


typedef struct{

int id;
char nombre[20];
char apellido[20];
int edad;
int idOrquesta;
int idInstrumento;
int isEmpty;

} eMusico;

#endif // MUSICO_H_INCLUDED
