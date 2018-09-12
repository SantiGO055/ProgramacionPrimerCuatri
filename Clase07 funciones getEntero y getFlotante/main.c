#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 6

int main()
{
    //float edades[CANTIDAD_EMPLEADOS];
    char sexo[CANTIDAD_EMPLEADOS];

    int i;
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    /*{
        utn_getFlotante(&edades[i],"\nEdad?","\nEdad fuera de rango",0,200,2);

    }
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("\nLas edades son: %.02f",edades[i]);
    }*/


    for(i=0;i < CANTIDAD_EMPLEADOS;i++){
        utn_getChar(&sexo[i], "\nSexo? [F] o [M]","\nSexo Incorrecto",'F','M',2);
    }

    return 0;
}






