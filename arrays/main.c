#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int array[]={1,2,3,4,5,6,7,8,9,10};
    printf("Los numeros cargados son: ");

   for(int i=0; i<9; i++){

    printf("%d ", array[i]);
   }*/

   int numeros[5];
   int mayor;
   int flag=0;


   for(int i=0; i<5;i++){

    printf("Ingrese numero positivo en la posicion %d: ",i);
    scanf("%d",&numeros[i]);

    while(numeros[i]<0){
    printf("Error, el numero no es positivo. Ingrese numero positivo en la posicion %d: ",i);
    scanf("%d",&numeros[i]);
    }

   }

   printf("Lo numeros ingresados son: ");


   for(int i=0; i<5;i++){
   printf("%d ", numeros[i]);
   }

   for(int i=0; i<5;i++){

  if(numeros[i]> mayor || flag==0){
    mayor= numeros[i];
    flag =1;
  }
}

printf("\nEl numero mayor es %d y esta en el indice ", mayor);



   for(int i=0; i<5;i++){

if(numeros[i]== mayor){

 printf("%d ", i);
 }

}



 return 0;
}
