#include <stdio.h>
#include <stdlib.h>
int buscarNumero(int num, int vec[], int tam);
int main()
{
    int numeros[]={2,4,5,3,6,5,8,8,9,10};
    int esta;

    esta=buscarNumero(4,numeros, 10);

    if(esta==1){
            printf ("Esta\n");
    } else {

    printf("No esta \n");
    }


    return 0;
}

int buscarNumero(int num, int vec[], int tam){
int esta;
for(int i =0; i<tam; i++){

if (num ==vec[i]){
return 1;
  } else {

  return 0;}

 }

}

