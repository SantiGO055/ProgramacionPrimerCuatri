#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main(){
    Persona personas[8];
    int r,i;
    r = parseData("datos.csv",personas,8);
    for(i=0; i<r; i++){
        printf("id:%d \nnombre:%s \napellido:%s \nedad:%d\n------------------\n",personas[i].id,
        personas[i].nombre,
        personas[i].apellido,
        personas[i].edad);
    }

    return 0;
}


