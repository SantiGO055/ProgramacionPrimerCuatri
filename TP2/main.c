#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#define CANT 1

int main()
{
    int opcion;
    eEmpleado emp[CANT];
    do{
    if(opcion!=3&&opcion!=4){
    }
    printf("\tMenu\n");
        printf("1- Alta empleado\n");
        printf("2- Baja empleado\n");
        printf("3- Imprimir lista ordenada por nombre y sector\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                alta(emp,CANT);
                system("cls");
                printf("Accion: Empleado agregado correctamente\n");
                break;
            case 2:
                baja(emp,CANT);
                break;
            case 3:
                ordenarLista(emp,CANT);
                system("cls");
                printf("Listado de empleados: ");
                imprimirEmpleados(emp,CANT);
                break;

        }
    }while(opcion!=5&&opcion<=5);

    return 0;
}
