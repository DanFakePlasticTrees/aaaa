#include <stdio.h>
#include <stdlib.h>

#include "Musico.h"
#include "Instrumento.h"
#include "Function.h"


#define TAMO 3
#define TAMI 3
#define TAMM 3

typedef  struct{
int id;
char nombre[20];
char lugar[20];
int tipo;
int isEmpty;
} eOrquesta;




int altaOrquesta(eOrquesta vec[], int id, int tam);
eOrquesta newOrquesta(int id,char nombre[],char lugar[],int tipo);
int buscarLibre(eOrquesta vec[], int tam);
void inicializarOrquestas(eOrquesta vec[], int tam);
void mostrarOrquestas(eOrquesta vec[], int tam);
void mostrarOrquesta(eOrquesta orquesta);
int altaMusico(eMusico vec[], int id, int tam, eOrquesta vecO[], int tamO, eInstrumento vecI[], int tamI);


int buscarOrquesta(int id, eOrquesta vec[], int tam);

int modificarMusico(eMusico vec[], int tam, eInstrumento vecI[], int tamI, eOrquesta vecO[], int tamO);
int bajaMusico(eMusico vec[], int tam, eOrquesta vecC[], int tamC, eInstrumento vecI[], int tamI);
void inicializarMusicos(eMusico vec[], int tam);
int buscarLibreMusico (eMusico vec[], int tam);
eMusico newMusico(int id,char nombre[],char apellido[],int edad,int idOrquesta,int idInstrumento);


void mostrarMusico(eMusico musico, eInstrumento vec[], int tamI);


void mostrarMusicos(eMusico vec[], int tam, eInstrumento vecI[], int tamI);
int buscarMusico(int id, eMusico vec[], int tam);

int bajaOrquesta(eOrquesta vec[], int tam, eMusico vecM[], int tamM, eInstrumento vecI[], int tamI);



int main()
{
    int id=1;
    int flag=0;
    int idI=1;
    int flagI=0;
    int idM=1;
    int flagM=0;

    eOrquesta vec [TAMO];
eInstrumento vecI[TAMI];
eMusico vecM [TAMM];

char close='n';



inicializarOrquestas(vec,TAMO);
inicializarInstrumentos(vecI,TAMI);
inicializarMusicos(vecM,TAMM);

     do
        {
            switch(menu())
            {
            case 1:

                if(altaOrquesta(vec,id,TAMO))
                {


                    flag=1;

                    printf("\nEl id de la nueva orquesta es: %d\n",id);

                      id++;
                } else {

                 printf("No se dio de alta ninguna orquesta\n\n");

                }

                break;
            case 2:


               if(flag)
                {



                  if(bajaOrquesta(vec,TAMO,vecM,TAMM,vecI,TAMI)){

                     printf("\n\nLa orquesta fue dada de baja\n\n");
                  } else {

                   printf("\n\nNo se dio de baja ninguna orquesta\n\n");
                  }

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos una orquesta previamente.\n");
                }

                break;

            case 3:
                if(flag)
                {
                     mostrarOrquestas(vec,TAMO);

                }
                else
                {
                    printf("\nNo hay orquestas que mostrar\n");
                }

                break;

            case 4:

 if(altaMusico(vecM,idM,TAMM,vec,TAMO,vecI,TAMI))
                {


                    flagM=1;

                    printf("\nEl id del nuevo musico es: %d\n",idM);

                      id++;
                } else {

                 printf("No se dio de alta ningun musico\n\n");

                }

                break;


            case 5:


                 if(flagM)
                {
                    modificarMusico(vecM,TAMM,vecI,TAMI,vec,TAMO);

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un musico previamente.\n");
                }

break;


            case 6:

                if(flagM)
                {


                  if(bajaMusico(vecM,TAMM,vec,TAMO,vecI,TAMI)){

                     printf("\n\nEl musico fue dado de baja\n\n");
                  } else {

                   printf("\n\nNo se dio de baja ningun musico\n\n");
                  }

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un musico previamente.\n");
                }
                break;


            case 7:

                if(flagM)
                {
                     mostrarMusicos(vecM,TAMM,vecI,TAMI);

                }
                else
                {
                    printf("\nNo hay músicos que mostrar\n");
                }


                break;

            case 8:

                if(altaInstrumento(vecI,idI,TAMI))
                {


                    flagI=1;

                    printf("\nEl id del nuevo instrumento es: %d\n",idI);

                 idI++;
                } else {

                 printf("No se dio de alta ningun instrumento\n\n");
                 break;

                }


            case 9:
                  if(flagI)
                {
                     mostrarInstrumentos(vecI,TAMI);

                }
                else
                {
                    printf("\nNo hay instrumentos que mostrar\n");
                }
break;


            case 10:

               close=confirmar("Confirma salir? s/n",20);

                break;

            default:
                printf("Opcion invalida\n");
            }
            system("pause");
        }
        while(close == 'n');

    return 0;
}


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

    printf("\n Id        Nombre     Lugar      Tipo\n\n");

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



int buscarOrquesta(int id, eOrquesta vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id== id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int bajaOrquesta(eOrquesta vec[], int tam, eMusico vecM[], int tamM, eInstrumento vecI[], int tamI)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Orquesta *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarOrquesta(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe una orquesta con ese id\n\n");

    }
    else
    {

        mostrarOrquesta(vec[indice]);

        for(int i=0; i<tamM; i++){



                if (!vecM[i].isEmpty&& vecM[i].idOrquesta==id){

        mostrarMusico(vecM[i],vecI,tamI);

            }




        }


        printf("\nConfirma baja de orquesta y músicos asociados? s/n");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {


            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");




        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}


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

int buscarMusico(int id, eMusico vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id== id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int modificarMusico(eMusico vec[], int tam, eInstrumento vecI[], int tamI, eOrquesta vecO[], int tamO)
{

    int todoOk = 0;
    int id;
    int indice;
    system("cls");
    printf("***** Modificar Musico *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    int opcion;

    indice = buscarMusico(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un musico con ese id\n\n");

    }
    else
    {

        mostrarMusico(vec[indice],vecI,tamI);

        printf("1- Modificar edad\n");
        printf("2- Modificar id de la orquesta\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nueva edad: ");
            scanf("%d", &vec[indice].edad);
            break;

        case 2:
            printf("Ingrese nuevo id de orquesta: ");
            mostrarOrquestas(vecO,tamO);
            scanf("%d", &vec[indice].idOrquesta);
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
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

    printf(" Id        Nombre     Apellido  Edad  ID Orq    ID Inst    Inst \n\n");

    for(int i=0; i < tam; i++){
        mostrarMusico( vec[i], vecI,tamI);
    }
    printf("\n");
}

void mostrarMusico(eMusico musico, eInstrumento vec[], int tamI){

    char desc[20];

 cargarDescInstrumento(musico.idInstrumento, vec, tamI, desc);

    if(!musico.isEmpty){

    printf("  %d      %10s       %10s      %d   %d       %d       %10s\n", musico.id, musico.nombre, musico.apellido, musico.edad, musico.idOrquesta, musico.idInstrumento, desc);
    }
}




int bajaMusico(eMusico vec[], int tam, eOrquesta vecC[], int tamC, eInstrumento vecI[], int tamI)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Musico *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarMusico(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un musico con ese id\n\n");

    }
    else
    {
        mostrarMusico(vec[indice],vecI,tamI);

        confirma=confirmar("Confirma la baja? s/n",25);


        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}




