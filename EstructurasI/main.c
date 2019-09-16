#include <stdio.h>
#include <stdlib.h>
typedef struct{

int dia;
int mes;
int anio;

}eFechaIngreso;

typedef struct{

int legajo;
char nombre[20];
int edad;
char sexo;
int nota1;
int nota2;
float promedio;
eFechaIngreso fechaIngreso;

}eAlumno;

int main()
{
  eAlumno alumno1={ 1234, "Jose", 23,'m',6,5,5.5,{3,5,2016}};
/*
  printf("Ingrese nombre: ");
  gets(alumno1.nombre);

printf("Ingrese Edad: ");
scanf("%d",&alumno1.edad);

printf("Ingrese legajo: ");
scanf("%d",&alumno1.legajo);

printf("Ingrese sexo: ");
fflush(stdin);
scanf("%c",&alumno1.sexo);

printf("Ingrese Nota 1: ");
scanf("%d",&alumno1.nota1);

printf("Ingrese Nota 2: ");
scanf("%d",&alumno1.nota2);

alumno1.promedio= (float)(alumno1.nota1 + alumno1.nota2)/2;

printf("Ingrese dia de ingreso: ");
scanf("%d",&alumno1.fechaIngreso.dia);

printf("Ingrese mes de ingreso: ");
scanf("%d",&alumno1.fechaIngreso.mes);

printf("Ingrese anio de ingreso: ");
scanf("%d",&alumno1.fechaIngreso.anio);

*/
printf("\nNombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota 1: %d\nNota 2: %d\nPromedio: %.2f \n%02d/%02d/%d",
       alumno1.nombre, alumno1.legajo, alumno1.edad, alumno1.sexo, alumno1.nota1, alumno1.nota2, alumno1.promedio,
       alumno1.fechaIngreso.dia, alumno1.fechaIngreso.mes, alumno1.fechaIngreso.anio );

    return 0;
}
