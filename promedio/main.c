#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=0;
    int acumulador=0;
    int edad, promedio;
    /*float promedio;*/
    for(contador;contador<4;contador++){
        printf("Ingrese edad: ");
        scanf("%d",&edad);
        acumulador=acumulador+edad;
    }
    promedio=acumulador/contador;
    printf("%i",promedio);

    return 0;
}
