#include <stdio.h>
#include <stdlib.h>

int main()
{
  char sexos[5];
  int contadorM=0;
  int contadorF=0;

  for(int i=0; i<6;i++){

  printf("Ingrese sexo: ");
  fflush(stdin);
scanf("%c",&sexo[i]);

   sexo[i]=tolower(sexo[i]);

  while (!(sexo=='f'||sexo=='m')){
     printf("Error. Ingrese sexo f o m: ");
  fflush(stdin);
scanf("%c",&sexo[i]);

   sexo[i]=tolower(sexo[i]);

  }

   if(sexo[i]=='f'){
    contadorF++;
    } else(sexo[i]=='m'){
    contadorM++;
    }
  }

  printf("Los sexos ingresados son: ");
for(int i=0; i<6;i++){

  printf("%c ",sexo);
}

printf("La cantidad de femeninos es %d y de masculinos %d", contadorF, cont)

    return 0; }




