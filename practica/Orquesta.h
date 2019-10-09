

#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct {

int id;
char nombre[20];
char lugar[20];
int tipo;
int isEmpty;
} eOrquesta;


#endif // ORQUESTA_H_INCLUDED


int altaOrquesta(eOrquesta vec[], int id, int tam);
eOrquesta newOrquesta(int id,char nombre[],char lugar[],int tipo);
int buscarLibre(eOrquesta vec[], int tam);
void inicializarOrquestas(eOrquesta vec[], int tam);
void mostrarOrquestas(eOrquesta vec[], int tam);
void mostrarOrquesta(eOrquesta orquesta);


int buscarOrquesta(int id, eOrquesta vec[], int tam);
