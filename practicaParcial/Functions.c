#include "Functions.h"


int menu()
{

    int option;
    system("cls");
    printf("************Menu de Opciones************\n\n");
    printf("1- Alta orquesta\n");
    printf("2- Eliminar Orquesta\n");
    printf("3- Mostrar Orquestas\n");
    printf("4- Agregar músico\n");
    printf("5- Modifica músico\n\n");
     printf("6- Eliminar musico\n");
    printf("7.Imprimir musicos\n");
    printf("8-Agregar insrumento\n\n");
      printf("9 Imprimir instrumentos\n");
    printf("10-Salir\n");


    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}




void getString(char string [], int length, char message[])
{

    char auxString[100];



    printf("%s", message);
    fflush(stdin);
    gets(auxString);



    while(strlen(auxString)>length)
    {

        printf("\nError, demasiado largo. La cantidad permitida es de %d caracteres. Reingrese: ", length-1);
        fflush(stdin);
        gets(auxString);
    }

    strcpy(string, auxString);


}


void convertToProperNoun(char string[])
{

    char aux[100];
    int i=0;

    strcpy(aux,string);

    strlwr(aux);

    aux[0]=toupper(aux[0]);

    while(aux[i] != '\0')
    {

        if(aux[i]== ' ')
        {
            aux[i+1]= toupper(aux[i+1]);
        }
        i++;
    }

    strcpy(string, aux);
}
