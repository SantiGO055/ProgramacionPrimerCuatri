#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{
    Persona* arrayPersonas[50];
    /*int i;
    for(i = 0; i < 10; i++)
    {
        arrayPersonas[i] = person_new();
    }
    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nId: %d",);
    }
    scanf(" ");*/

    int r,i;
    r = parseData("datos.csv",arrayPersonas);
    for(i=0; i<r; i++){
        printf("id:%d \nnombre:%s \napellido:%s \nedad:%d\n------------------\n",arrayPersonas[i].id,
        arrayPersonas[i].nombre,
        arrayPersonas[i].apellido,
        arrayPersonas[i].edad);
    }


    return 0;
}

