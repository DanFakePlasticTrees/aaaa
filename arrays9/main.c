#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarVectorInt (int vec [], int tam);
void mostrarVectorChar(char vec [], int tam);
void mostrarVectorFloat(float vec [], int tam);
void ordenarVectorInt (int vec[], int tam, int criterio);

int main()
{
    int numeros [] = {23,21,43,54,28,96,74,12,3,6};
    char x [] = {'a', 'e', 'i', 'o','u'};
    float y []= {45.5, 66.7, 99.98, 66.7, 0.88};
    char s[] = {'J', 'o', 's', 'e', '\0'};
    char t[] = {'J', 'o', 's', 'e', 'P', '\0', 'e', 'r', 'e','z'};
    int vector[TAM]= {7,8,6,5,3,};
//int aux;


    mostrarVectorInt(numeros, 10);
    mostrarVectorChar(x,5);
    mostrarVectorFloat(y, 5);
    printf("%s \n",s);
    printf("%s \n",t);

    printf(("Vector sin ordenar: \n"));
    mostrarVectorInt(vector,TAM);

    /*for(int i=0; i<TAM-1; i++){

        for(int j= i+1; j<TAM; j++){
            if(vector[j]< vector [i]){

                aux = vector[j];
                vector[j]=vector[i];
                vector[i]=aux;
            }
        }

    }

    printf(("Vector ordenado \n"));
    mostrarVectorInt(vector,TAM);
    */

    printf("Vector ordenado ascendente:\n");
    ordenarVectorInt(vector, TAM, 0);
    printf("Vector ordenado descendente:\n");
    ordenarVectorInt(vector, TAM, 1);

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{

    for (int i=0; i<tam; i++)
    {

        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

void mostrarVectorChar(char vec[], int tam)
{

    for (int i=0; i<tam; i++)
    {

        printf("%c ", vec[i]);
    }
    printf("\n\n");
}

void mostrarVectorFloat(float vec [], int tam)
{

    for (int i=0; i<tam; i++)
    {

        printf("%.2f ", vec[i]);
    }
    printf("\n\n");
}

void ordenarVectorInt (int vec[], int tam, int criterio)
{
    int aux;

    /*while(criterio!=0 && criterio!=1){

        printf("Ingrese criterio valido: \n");
        scanf("%d", criterio);
    }
    */
    for(int i=0; i<tam-1; i++ )
    {
        for(int j=i+1; j<tam; j++)
        {


            if(vec[j]<vec[i] && !criterio)  //criterio==0. 0 es falso. por eso !criterio==0
            {
                aux=vec[j];
                vec[j]=vec[i];
                vec[i]=aux;
            }
            else
            {
                if(vec[j]>vec[i] && criterio)
                {
                    aux=vec[j];
                    vec[j]=vec[i] ;
                    vec[i]=aux;
                }

            }
        }
    }
    mostrarVectorInt(vec,tam);
}

