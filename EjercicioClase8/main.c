#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define CANT 2

int main()
{
    int opcion;
    ePersona per[CANT];
    do{
    system("cls");
    printf("Menu\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                alta(per,CANT);
                system("cls");
                break;

        }
    }while(opcion!=4&&opcion<=4);

    return 0;
}
