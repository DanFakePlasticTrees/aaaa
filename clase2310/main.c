#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int dia;
    int mes;
    int anio;

} eFecha;


typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fIngreso;

} eEmpleado;

eEmpleado* newEmpleado();
int mostrarEmpleado(eEmpleado* emp);
eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio);//
int agregarEmpleado(eEmpleado* vec, int tam, eEmpleado* emp);
int mostrarEmpleados(eEmpleado* vec, int tam);

int main()
{

    eEmpleado* pEmp;

    eEmpleado* lista= (eEmpleado*) malloc (sizeof(eEmpleado));

    int tam=0;

    if(lista==NULL)
    {

        printf("No se pudo conseguir lugar\n");
        exit(EXIT_FAILURE);
    }

//pEmp=newEmpleado();

//CREO UN NUEVO EMPLEADO HARDCODEADO
    pEmp =newEmpleadoParam(1234,"Jorge",'m',25000,12, 5,2010);
  eEmpleado*   pEmp2 =newEmpleadoParam(1234,"Matias",'m',25000,12, 5,2010);
  eEmpleado* pEmp3 =newEmpleadoParam(1234,"Ana",'m',25000,12, 5,2010);
 eEmpleado*  pEmp4 =newEmpleadoParam(1234,"Juana",'m',25000,12, 5,2010);
//AGREGO EL EMPLEADO LA LISTA

  //  *(lista+tam)= *pEmp;

//mostrarEmpleado(pEmp);


if(agregarEmpleado(lista,tam, pEmp)){

    printf("Empleado agregado con exito\n");
tam++;

    //RECOMENDABLE QUE EL TAMAÑOP SE CAMBIE EN LA FUNCION
} else {

printf("No se pudo agregar el empleado\n ");

}
agregarEmpleado(lista,tam,pEmp)

//    mostrarEmpleado(lista);







    free(pEmp);
    return 0;
}

eEmpleado* newEmpleado()
{

    eEmpleado* p;

    p = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(p!=NULL)
    {

        p->legajo=0;
        strcpy(p->nombre, "");
        p->sexo=' ';
        p->sueldo=0;
        p->fIngreso= (eFecha)
        {
            1,1,1990
        };
    }


    return p;

}


int mostrarEmpleado(eEmpleado* emp)
{

    int todoOk=0;


    if(emp!=NULL)
    {

        printf("%d  %s  %c  %.2f   %02d/%02d/%d \n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, emp->fIngreso.dia, emp->fIngreso.mes, emp->fIngreso.anio);
        todoOk=1;
    }

    return todoOk;
}


eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio)
{

    eEmpleado* nuevoEmpleado;

    nuevoEmpleado=newEmpleado();

    if(nuevoEmpleado!=NULL)
    {

        nuevoEmpleado->legajo=leg;
        strcpy(nuevoEmpleado->nombre,nombre);
        nuevoEmpleado->sexo= sexo;
        nuevoEmpleado->sueldo=sueldo;
        nuevoEmpleado->fIngreso.dia=dia;
        nuevoEmpleado->fIngreso.mes=mes;
        nuevoEmpleado->fIngreso.anio=anio;
    }
}


int agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp)
{
    int todoOk=0;
    eEmpleado* aux;

    if(vec!=NULL&& tam=! NULL&&emp!=NULL)
    {

        *(vec+tam)= *emp;

        aux=(eEmpleado*)realloc(vec, sizeof(eEmpleado)* (tam+1));

        if(aux!=NULL)
        {

            vec=aux;
            todoOk=1;
        }

    }

return todoOk;
}



int mostrarEmpleados(eEmpleado* vec, int tam){

int todoOk=0;

if(vec!=NULL){

    for (int i=0; i<tam-1; i++){
        //en realidad habrìa que utilizar capmpo estado o is empty ara las bajas logicas y que no mustre basura

        mostrarEmpleado(vec+i);
    }

    todoOk=1;
}

return todoOk;
}
