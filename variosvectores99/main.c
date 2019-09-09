#include <stdio.h>
#include <stdlib.h>

# define TAM 1

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom);

int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexos[TAM];
    int notasp1[TAM];
    int notasp2[TAM];
    float promedios[TAM];

    for(int i =0; i< TAM; i++)
    {

        printf("Ingrese legajo:\n");
        scanf("%d", &legajos[i]);

        printf("Ingrese edad:\n");
        scanf("%d", &edades[i]);

        printf("Ingrese sexo:\n");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese nota 1 parcial:\n");
        scanf("%d", &notasp1[i]);

        printf("Ingrese nota 2 parcial:\n");
        scanf("%d", &notasp2[i]);

        promedios[i]= (float) (notasp1[i] + notasp2[i]) / 2;

    }
mostrarAlumnos(legajos,edades,sexos,notasp1,notasp2,promedios,TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{
printf("Legajo Edad Sexo Nota1 Nota2 Promedio\n\n");
    for(int i=0; i<tam; i++)
    {
        mostrarAlumno(leg[i],age[i],sex[i],n1[i],n2[i],prom[i]);
}
printf("\n\n");
}

void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom){

printf(" %d    %d    %c    %d    %d    %.2f\n", leg, age, sex, n1, n2, prom);

}
