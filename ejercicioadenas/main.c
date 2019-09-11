#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char nombre[20];
  char apellido[20];
  char aux[100];
  char nombreCompleto[41];
  int i=0;


  printf("Ingrese nombre: ");
  gets(aux);

  while (strlen(aux)>19){
    printf("Muy largo, reingrese: ");
    fflush(stdin);
    gets(aux);
    }

    strcpy(nombre, aux);

  printf("Ingrese apellido: ");
  gets(aux);

    while (strlen(aux)>19){
    printf("Muy largo, reingrese: ");
    fflush(stdin);
    gets(aux);
    }

    strcpy(apellido, aux);

/*  strlwr(nombre);
  strlwr(apellido);

  nombre[0]=toupper(nombre[0]);
apellido[0]=toupper(apellido[0]);
*/

strcpy(nombreCompleto,apellido);
strcat(nombreCompleto, ", ");
strcat(nombreCompleto,nombre);

strlwr(nombreCompleto);

nombreCompleto[0]=toupper(nombreCompleto[0]);

while(nombreCompleto[i] != '\0'){

    if(nombreCompleto[i]== ' '){
        nombreCompleto[i+1]= toupper(nombreCompleto[i+1]);
    }
  i++;
}


printf("El nombre completo es %s\n", nombreCompleto);
    return 0;
}
