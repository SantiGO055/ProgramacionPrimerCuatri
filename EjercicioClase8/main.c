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
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
        }
    }while(opcion!=5&&opcion<=5);
    /*for(i=0;i<CANT;i++){
        printf("Ingrese DNI: ");
        scanf("%ld",&per[i].dni);
        printf("Ingrese Apellido: ");
        scanf("%s",per[i].apellido);
        printf("Ingrese Nombre: ");
        scanf("%s",per[i].nombre);
        printf("Ingrese dia de nacimiento: ");
        scanf("%d",&per[i].fechaNac.dia);
        printf("Ingrese mes de nacimiento: ");
        scanf("%d",&per[i].fechaNac.mes);
        printf("Ingrese año de nacimiento: ");
        scanf("%d",&per[i].fechaNac.anio);
    }
    for(i=0;i<CANT;i++){
        printf("DNI: %ld\nApellido: %s\nNombre: %s\nFecha: %d/%d/%d\n",
               per[i].dni,per[i].apellido,per[i].nombre,
               per[i].fechaNac.dia,per[i].fechaNac.mes,per[i].fechaNac.anio);
    }*/
    return 0;
}
