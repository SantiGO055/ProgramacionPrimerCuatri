#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#define CANT 3

int main()
{
    int opcion,sector,flag=0,id=0;
    char name[51], lastName[51];
    float salary;
    employee emp[CANT];
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
                if(flag==0){
                    if(initEmployee(emp,CANT)==0){
                        initEmployee(emp,CANT);
                        flag=1;
                    }
                }
                if(getFreeSpace(emp,CANT)!=-1){
                    id++;
                }
                printf("Ingrese Nombre: ");
                scanf("%s",name);
                printf("Ingrese Apellido: ");
                scanf("%s",lastName);
                printf("Ingrese Salario: ");
                scanf("%f",&salary);
                printf("Ingrese Sector: ");
                scanf("%d",&sector);
                addEmployee(emp,CANT, name, lastName,salary,sector,id);
                system("cls");
                printf("Accion: Empleado agregado correctamente\n");
                break;
            case 2:
                printf("Ingrese id a eliminar");
                scanf("%d",&id);
                removeEmployee(emp,CANT,id);
                break;
            case 3:
                sortEmployee(emp,CANT,name,lastName);
                printEmployee(emp,CANT);
                break;

        }
    }while(opcion!=5&&opcion<=5);

    return 0;
}
