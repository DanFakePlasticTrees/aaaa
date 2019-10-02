#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20





int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[],eComida comida[], eAlmuerzo almuerzos[], int tamAlmuerzo, int tamAlum, eCarrera carreras[], int tamC, int tamComidas);
void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera);
void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarFechaAlmuerzo(eComida comidas[], int tamC, eAlmuerzo almuerzos [], int tamAlm);
int compararFechas(eFecha f1, eFecha f2);
int cantidadAlmuerzosCarrera(int idCarrera, eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo);
void informarAlmuerzosxCarrera(eCarrera carreras [], int tamCar,eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo);
int cantidadAlmuerzosMilanesaxCarrera(int idCarrera, eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo);
float totalDeudaAlumno(int legajo,eAlmuerzo almuerzos[], int tamAlmuerzos, eComida comidas [], int tamComidas);
void informarDeudaAlumno ( eAlumno alumnos[], int tamAlumno, eAlmuerzo almuerzos[], int tamAlmuerzos, eComida comidas [], int tamComidas, eCarrera carreras[], int tamCarrera);


int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM]= {{5000,"Bife",250},{5001,"Fideos",180},{5002,"Pizza",200}, {5003,"Arroz",160},{5004,"Milanesa",220}};
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);
    inicializarAlmuerzos( almuerzos, TAMAL);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 9);

    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 10);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:
            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            InformesAlumnos(lista, comidas,almuerzos,TAMAL,TAM,carreras,TAMC, TAMCOM);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            mostrarComidas(comidas, TAMCOM);
            break;

        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;

        case 10:
            if (altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, lista, TAM, comidas, TAMCOM, carreras, TAMC))
            {
                idAlmuerzo++;
            }
            break;

        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("11-Alta Almuerzo\n");
    printf("12-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas incriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Mostrar almuerzos de una fecha determinada\n");
    printf("10-Listar alumnos que comieron una determinada comida\n");
    printf("11-Listar Cantidad de almuerzos por carrera\n");
    printf("12-Carera amante de las milanesas\n");
    printf("13-Informe deuda alumno seleccionado\n");
    printf("14-Informe ganancia por comida\n");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void InformesAlumnos(eAlumno alumnos[],eComida comida[], eAlmuerzo almuerzos[], int tamAlmuerzo, int tamAlum, eCarrera carreras[], int tamC, int tamComidas)
{



    char salir = 'n';
    system("cls");
    printf("***** Informes Alumnos ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosDeUnaCarrera(alumnos, tamAlum, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosXCarrera(alumnos, tamAlum, carreras, tamC);
            break;

        case 3:
            mostrarCantidadAlumnosXCarrera(alumnos, tamAlum, carreras, tamC);
            break;

        case 4:
            carreraMasCursada(alumnos, tamAlum, carreras, tamC);
            break;

        case 5:
            mejoresPromediosXCarrera(alumnos, tamAlum, carreras, tamC);
            break;

        case 6:
            printf("Informe 6\n");
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Informe 8\n");
            break;
        case 9:
            mostrarFechaAlmuerzo(comida, tamC, almuerzos,tamAlmuerzo);
            break;
        case 10:
            printf("Informe 10\n");
            break;
        case 11:

            informarAlmuerzosxCarrera(carreras,tamC,almuerzos,alumnos, tamAlum,tamAlmuerzo);
break;
       case 13:
      informarDeudaAlumno(alumnos,tamAlum,almuerzos,tamAlmuerzo,comida,tamComidas,carreras,tamC);


            break;
        case 20:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}



void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int idCarrera;
    system("cls");
    printf("***Carreras***\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);

}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera)
{

    char desc[20];
    int flag = 0;
    cargarDescCarrera(idCarrera, carreras, 20,desc);

    printf("Carrera: %s\n\n", desc);

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("No hay Alumnos cursando %s", desc);
    }
    printf("\n\n");
}

void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    system("cls");
    printf("***Listado de Alumnos por Carrera***\n\n");

    for(int i=0; i < tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

    printf("\n\n");
}

void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int contador = 0;
    char desc[20];

    system("cls");
    printf("***Cantidad de Alumnos por Carrera***\n\n");

    // Recorro vector de carreras
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
        printf("Carrera: %s\n\n", desc);

        for(int j= 0; j < tam; j++)
        {
            if( alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }
    printf("\n\n");
}

int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera)
{
    int cant = 0;

    for(int i= 0; i < tam; i++ )
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            cant++;
        }
    }
    return cant;
}

void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int cantidades[tamC];
    int mayor;
    int flag = 0;
    char desc[20];

    for( int i=0; i < tamC; i++)
    {
        cantidades[i] = cantidadAlumnosCarrera(alumnos, tam, carreras[i].id);
    }


    for(int i=0; i < tamC; i++)
    {
        if( mayor < cantidades[i] || flag==0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    for(int i=0; i < tamC; i++)
    {
        if( cantidades[i]== mayor)
        {

            cargarDescCarrera( carreras[i].id, carreras, tamC, desc);
            printf("Carrera: %s %d alumnos\n", desc, mayor);

        }
    }
}

void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    char desc[20];
    float mayor;
    int flag = 0;
    system("cls");
    printf("***Mejores Promedios por Carrera***\n\n");

    for( int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
        printf("Carrera: %s\n\n", desc);

        for(int j=0; j < tam; j++)
        {
            if( ((mayor < alumnos[j].promedio && alumnos[j].isEmpty == 0) && (alumnos[j].idCarrera == carreras[i].id)) || ( flag == 0  && alumnos[j].idCarrera == carreras[i].id))
            {
                mayor = alumnos[j].promedio;
                flag = 1;
            }
        }

        printf("Promedio: %.2f\n\n", mayor);
        mayor = 0;
        flag = 0;
    }
}


void mostrarFechaAlmuerzo(eComida comidas[], int tamC, eAlmuerzo almuerzos [], int tamAlm)
{

    int flag=0;
    eFecha fecha;
    system("cls");
    printf("***Informe Almuerzos por fecha***\n\n");

    printf("Ingrese una fecha: dd/mm/aaaa");
    scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);

    for (int i=0; i <tamAlm; i++)
    {

        if(almuerzos[i].isEmpty==0 && compararFechas(fecha, almuerzos[i].fecha))
        {

            mostrarAlmuerzo(almuerzos[i],comidas,tamC);
            flag=1;
        }

        if(flag==0)
        {

            printf("no se encontrarn almuerzos \n\n");
        }
    }


}

int compararFechas(eFecha f1, eFecha f2)
{

    int sonIguales=0;

    if(f1.dia== f2.dia && f1.mes==f2.mes && f1.anio==f2.anio)
    {

        sonIguales=1;
    }

    return sonIguales;
}



int cantidadAlmuerzosCarrera(int idCarrera, eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo)
{




    int contador=0;

    for (int i=0; i<tamAlumno; i++)
    {

        if (!alumnos[i].isEmpty&&alumnos[i].idCarrera==idCarrera)
        {

            for(int j=0; j<tamAlmuerzo; j++)
            {


                if(!almuerzos[j].isEmpty&&almuerzos[j].legajo==alumnos[i].legajo)
                {

                    contador++;


                }


            }


        }



    }

    return contador;


}


void informarAlmuerzosxCarrera(eCarrera carreras [], int tamCar,eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo)
{

    int cant;

    system("cls");
    printf("*******Almuerzos por carrera*********\n\n");




    for (int i=0; i<tamCar; i++)
    {
        cant=cantidadAlmuerzosCarrera(carreras[i].id,almuerzos,alumnos,tamAlumno,tamAlmuerzo);
        printf("%s:  %d\n", carreras[i].descripcion,cant);


    }

}



int cantidadAlmuerzosMilanesaxCarrera(int idCarrera, eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo)
{




    int contador=0;

    for (int i=0; i<tamAlumno; i++)
    {

        if (!alumnos[i].isEmpty&&alumnos[i].idCarrera==idCarrera)
        {

            for(int j=0; j<tamAlmuerzo; j++)
            {


                if(!almuerzos[j].isEmpty&&almuerzos[j].legajo==alumnos[i].legajo&&almuerzos[j].idComida==5004)
                {

                    contador++;


                }


            }


        }



    }

    return contador;


}


void mostrarCarreraMasMilanesas (eCarrera carreras [], int tamCar,eAlmuerzo almuerzos[], eAlumno alumnos[], int tamAlumno, int tamAlmuerzo)
{


int mila[tamCar];
int mayor;
int flag=0;


    system("cls");
    printf("*******Carrera/s mas consumidoras de milanesas*********\n\n");


    for( int i=0 ; i< tamCar; i++){
mila[i]=cantidadAlmuerzosMilanesaxCarrera(1000,almuerzos,alumnos,tamAlumno,tamAlmuerzo);
mila[i]=cantidadAlmuerzosMilanesaxCarrera(1001,almuerzos,alumnos,tamAlumno,tamAlmuerzo);

mila[i]= cantidadAlmuerzosMilanesaxCarrera(1002,almuerzos,alumnos,tamAlumno,tamAlmuerzo);

    }


     for( int i=0 ; i< tamCar; i++){

      if(mila[i]> mayor||flag==0){
       mayor=mila[i];
        flag=1;
      }


     }
}

float totalDeudaAlumno(int legajo,eAlmuerzo almuerzos[], int tamAlmuerzos, eComida comidas [], int tamComidas){

float total=0;

for (int i=0; i<tamAlmuerzos; i++)
    {

        if (!almuerzos[i].isEmpty&&almuerzos[i].legajo==legajo)
        {

            for(int j=0; j<tamComidas; j++)
            {


                if(comidas[j].id==almuerzos[i].idComida)
                {   total += comidas[j].precio;

                }
            }
        }
    }

return total;
}

void informarDeudaAlumno ( eAlumno alumnos[], int tamAlumno, eAlmuerzo almuerzos[], int tamAlmuerzos, eComida comidas [], int tamComidas, eCarrera carreras[], int tamCarrera){

int legajo;
float deuda;

system("cls");
printf("*************Deudas alumnos*************\n\n");

printf("Ingrese legajo: ");
scanf("%d", &legajo);

deuda= totalDeudaAlumno(legajo,almuerzos, tamAlmuerzos,comidas, tamComidas);

for(int i=0; i<tamAlumno;i++){
        if(!alumnos[i].isEmpty&&legajo==alumnos[i].legajo){
mostrarAlumno(alumnos[i],carreras,tamCarrera);}
}

printf("La deuda es $%.2f\n\n", deuda);

system("pause");
}
