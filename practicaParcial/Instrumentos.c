#include "Instrumentos.h"


void inicializarInstrumentos(eInstrumento vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}




int buscarLibreInstrumento(eInstrumento vec[], int tam)
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




eInstrumento newInstrumento (int id,int tipo,char nombre[]){

    eInstrumento ins;
    ins.id = id;
    strcpy( ins.nombre, nombre);
    ins.tipo = tipo;
    ins.isEmpty = 0;

    return ins;
}


int altaInstrumento(eInstrumento vec[], int id, int tam)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    int tipo;


    system("cls");

    printf("*****Alta Instrumento*****\n\n");

    indice = buscarLibreInstrumento(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        getString(nombre, 20,"\nIngrese nombre: " );
        convertToProperNoun(nombre);

 printf("\nIngrese tipo: ");
        printf("\n1.Cuerda");
          printf("\n2.Viento-madera");
            printf("\n3.Viento-metal\n");

        scanf("%d", &tipo);
            while(!(tipo==1||tipo==2||tipo==3)){



        printf("\n Error. Ingrese tipo: ");
      printf("\n1.Cuerda");
          printf("\n2.Viento-madera");
            printf("\n3.Viento-metal\n");

        scanf("%d", &tipo);

            }



        vec[indice] = newInstrumento(id,tipo,nombre);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;

}




void mostrarInstrumentos(eInstrumento vec[], int tam){

    printf(" Id        Nombre     Tipo\n\n");

    for(int i=0; i < tam; i++){
        mostrarInstrumento( vec[i]);
    }
    printf("\n");
}

void mostrarInstrumento(eInstrumento instrumento){




    if(!instrumento.isEmpty){

    printf("  %d      %10s       %d\n", instrumento.id, instrumento.nombre, instrumento.tipo);
    }

}




int cargarDescInstrumento(int id, eInstrumento vec[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == vec[i].id){
            strcpy(desc, vec[i].nombre);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
