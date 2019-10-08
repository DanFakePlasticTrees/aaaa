#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Orquestas.h"
#include "Instrumentos.h"
#include "Musicos.h"
#define TAMO 3
#define TAMI 3
#define TAMM 3












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


              /*  if(flag)
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
                */
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

                    printf("\nEl id del nuevo musico es: %d\n",id);

                      id++;
                } else {

                 printf("No se dio de alta ningun musico\n\n");

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



