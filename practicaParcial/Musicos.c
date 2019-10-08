#include "Musicos.h"


void inicializarMusicos(eMusico vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}




int buscarLibreMusico (eMusico vec[], int tam)
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




eMusico newMusico(int id,char nombre[],char apellido[],int edad,int idOrquesta,int idInstrumento){

    eMusico mus;
    mus.id = id;
    strcpy( mus.nombre, nombre);
    strcpy( mus.apellido, apellido);
    mus.edad = edad;
 mus.idOrquesta= idOrquesta;
 mus.idInstrumento=idInstrumento;
    mus.isEmpty = 0;

    return mus;
}


int altaMusico(eMusico vec[], int id, int tam, eOrquesta vecO[], int tamO, eInstrumento vecI[], int tamI)
{
    int todoOk = 0;
    int indice;

  char nombre[20];
  char apellido[20];
  int edad;
  int idOrquesta;
      int idInstrumento;


    system("cls");

    printf("*****Alta Carrera*****\n\n");

    indice = buscarLibreMusico(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        getString(nombre, 20,"\nIngrese nombre: " );
        convertToProperNoun(nombre);

getString(apellido,20,"\nIngrese apellido: " );
convertToProperNoun(apellido);



        printf("\nIngrese edad: ");
        scanf("%d", &edad);

mostrarOrquestas(vecO,tamO);

        printf("\nIngrese id de la orquesta: ");
        scanf("%d", &idOrquesta);


        mostrarInstrumentos(vecI, tamI);

        printf("\nIngrese id del instrumento: ");
        scanf("%d", &idInstrumento);



        vec[indice] = newMusico(id,nombre,apellido,edad,idOrquesta,idInstrumento);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}




void mostrarMusicos(eMusico vec[], int tam, eInstrumento vecI[], int tamI){

    printf(" Id        Nombre     Apellido   ID Orq    ID Inst    Inst \n\n");

    for(int i=0; i < tam; i++){
        mostrarMusico( vec[i], vecI,tamI);
    }
    printf("\n");
}

void mostrarMusico(eMusico musico, eInstrumento vec[], int tamI){

    char desc[20];

 cargarDescInstrumento(musico.idInstrumento, vec, tamI, desc);

    if(!musico.isEmpty){

    printf("  %d      %10s       %10s       %d       %d       %10s\n", musico.id, musico.nombre, musico.apellido, musico.idOrquesta, musico.idInstrumento, desc);
    }
}
