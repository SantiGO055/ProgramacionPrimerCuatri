#include <stdio.h>
#include <stdlib.h>
#define CANT 5 //defino una constante
int main()
{
    int  i;
    float salario[CANT];
    int edad[CANT]; //Defino el array con la cantidad de la constante
    for(i=0;i<CANT;i++){ //recorro el array
        printf("Ingrese edad: ");
        scanf("%d",&edad[i]); //almaceno los valores ingresados en cada posicion del array
        printf("Ingrese salario: ");
        scanf("%f",&salario[i]);
    }
    for(i=0;i<CANT;i++){ //recorro el array
        printf("Los numeros ingresados son: %d\n",edad[i]);//muestro en pantalla el array
        printf("Los salarios ingresados son: %.3f\n",salario[i]);
    }
    return 0;
}
//relaciono el indice de la edad con la del salario, estan en paralelo
