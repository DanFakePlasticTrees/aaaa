#include "Orquestas.h"

void inicializarOrquestas(eOrquesta vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}




int buscarLibre(eOrquesta vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}




eOrquesta newOrquesta(int id,char nombre[],char lugar[],int tipo){

    eOrquesta car;
    car.id = id;
    strcpy( car.nombre, nombre);
    strcpy( car.lugar, lugar);
    car.tipo = tipo;
    car.isEmpty = 0;

    return car;
}


int altaOrquesta(eOrquesta vec[], int id, int tam)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    char lugar[20];
    int tipo;


    system("cls");

    printf("*****Alta Carrera*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        getString(nombre, 20,"\nIngrese nombre: " );
        convertToProperNoun(nombre);

getString(lugar,20,"\nIngrese lugar: " );
convertToProperNoun(lugar);



        printf("\nIngrese tipo: ");
        printf("\n1.Filármonica");
          printf("\n2.Sinfónica");
            printf("\n3.Cámara\n");

        scanf("%d", &tipo);
            while(!(tipo==1||tipo==2||tipo==3)){



        printf("\n Error. Ingrese tipo: ");
        printf("\n1.Filármonica");
          printf("\n2.Sinfónica");
            printf("\n3.Cámara\n");

        scanf("%d", &tipo);

            }




        vec[indice] = newOrquesta(id,nombre,lugar,tipo);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}




void mostrarOrquestas(eOrquesta vec[], int tam){

    printf(" Id        Nombre     Lugar      Tipo\n\n");

    for(int i=0; i < tam; i++){
        mostrarOrquesta( vec[i]);
    }
    printf("\n");
}

void mostrarOrquesta(eOrquesta orquesta){



    if(!orquesta.isEmpty){

    printf("  %d      %10s       %10s     %d\n", orquesta.id, orquesta.nombre, orquesta.lugar, orquesta.tipo);
    }
}
