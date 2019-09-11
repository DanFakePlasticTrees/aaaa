#include <stdio.h>
#include <stdlib.h>
void mostrarNombres(char mat[][20], int tamFilas);//completar cantidad de columnas

int main()
{
    char nombres [5] [20];

    /*printf("Ingrese un nombre: ");


    gets(nombres[0]);//tengo que aclarar la fila*/

        for(int i=0; i<5; i++){
        printf("Ingrese un nombre: ");
       fflush(stdin);
       gets(nombres[i]);
    }
 printf("\n\n");

   /* for(int i=0; i<5; i++){
        printf("%s\n",nombres[i]);
      }
    printf("\n\n");
*/
    return 0;
}

void mostrarNombres(char mat[][20], int tamFilas){

 for(int i=0; i<tamFilas; i++){
        printf("%s\n",mat[i]);
      }
    printf("\n\n");


}
