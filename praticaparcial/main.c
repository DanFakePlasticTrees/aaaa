#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAMO 3
#define TAMI 3
#define TAMM 3

typedef struct {

int id;
char nombre[20];
char lugar[20];
int tipo;
int isEmpty;
} eOrquesta;

typedef struct{

int id;
char nombre[20];
char apellido[20];
int edad;
int idOrquesta;
int idInstrumento;
} eMusico;


typedef struct {
int id;
int tipo;
char nombre[];
} eInstrumento;

int altaCarrera(eOrquesta vec[], int id, int tam);
eOrquesta newOrquesta(int id,char nombre[],char lugar[],int tipo);
int buscarLibre(eOrquesta vec[], int tam);
void inicializarCarreras(eOrquesta vec[], int tam);
int menu();




int main()
{
    int id=1;
    int flag;
    eOrquesta vec [];

     do
        {
            switch(menu())
            {
            case 1:
                if(altaCarrera(vec,id,TAMO))
                {

                    id++;
                    flag=1;

                    printf("\nEl id de la nueva orquesta es: %d\n",id);
                } else {

                 printf("No se dio de alta ninguna orquesta\n\n");

                }

                break;
            case 2:
                if(flag)
                {
                  remove = removeEmployee(list,TAM,id);

                  if(!remove){

                     printf("\n\nEl empleado fue dado de baja\n\n");
                  } else {

                   printf("\n\nNo se dio de baja ningun empleado\n\n");
                  }

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un empleado previamente.\n");
                }
                break;

            case 3:
                if(flag)
                {
                    updateEmployee(list,TAM);

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un empleado previamente.\n");
                }

                break;
            case 4:

                if(flag)
                {
                    informs(list,TAM);

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un empleado previamente.\n");
                }

                break;

            case 5:
                printf("\nCorfirma Salida? s/n \n");
                fflush(stdin);
                close = getchar();
                close= tolower(close);


                while(!(close=='s'||close=='n'))
                {

                    printf("Ingrese opción válida. Confirma salir? s/n:\n");
                    fflush(stdin);

                    close = getchar();
                    close= tolower(close);
                }

                break;

            default:
                printf("Opcion invalida\n");
            }
            system("pause");
        }
        while(close == 'n');

    return 0;
}



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
     printf("3- Mostrar Orque\n");
    printf("4- Modificar músico mús\n");
    printf("5- Eliminar músico\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}

void inicializarCarreras(eOrquesta vec[], int tam)
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
    al.tipo = tipo;
    al.isEmpty = 0;

    return car;
}


int altaCarrera(eOrquesta vec[], int id, int tam)
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
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nombre);


        printf("\nIngrese lugar: ");
        fflush(stdin);
        gets(lugar);

        printf("\nIngrese tipo: ");
        scanf("%d", &tipo);



        vec[indice] = newOrquesta(id,nombre,lugar,tipo);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}
