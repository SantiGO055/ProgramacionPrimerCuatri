#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#define CANT 3

int main()
{
    int opcion,sector,flag=0,id=0,findEmployeeAux,idAux,contEmp=0;
    char name[51], lastName[51];
    float salary;
    employee emp[CANT];
    do{
    printf("\tMenu\n");
        printf("1- Alta empleados\n");
        printf("2- Modificar empleados\n");
        printf("3- Baja empleados\n");
        printf("4- Imprimir empleados\n\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                system("cls");
                if(flag==0){
                    if(initEmployee(emp,CANT)==0){
                        initEmployee(emp,CANT);
                        flag=1;
                    }
                }
                if(getFreeSpace(emp,CANT)!=-1){
                    id++;
                    contEmp++;
                }
                else{
                    printf("No hay espacio para agregar empleados!");
                    break;
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
                system("cls");
                if(firstEmployee(flag)!=0){ //si no es la primera vez
                    printEmployee(emp,CANT);
                    printf("Ingrese id a modificar: ");
                    scanf("%d",&idAux);
                    findEmployeeAux=findEmployeeById(emp,CANT,idAux);
                    if(findEmployeeAux!=-1){ //si lo encontro
                        printf("Ingrese Nombre: ");
                        scanf("%s",name);
                        printf("Ingrese Apellido: ");
                        scanf("%s",lastName);
                        printf("Ingrese Salario: ");
                        scanf("%f",&salary);
                        printf("Ingrese Sector: ");
                        scanf("%d",&sector);
                        modifyEmployee(emp,CANT, name, lastName,
                                       salary,sector,findEmployeeAux);
                        system("cls");
                        printf("Accion: Empleado modificado correctamente\n");
                    }
                    else{
                        system("cls");
                        printf("No se encuentra el ID\n");
                    }
                }
                break;
            case 3:
                system("cls");
                if(firstEmployee(flag)!=0){ //si no es la primera vez
                        printEmployee(emp,CANT);
                        printf("Ingrese id a eliminar: ");
                        scanf("%d",&id);
                        removeEmployee(emp,CANT,id);
                }
                break;
            case 4:
                system("cls");
                if(firstEmployee(flag)!=0){ //si no es la primera vez

                        sortEmployee(emp,CANT,name,lastName);
                        printEmployee(emp,CANT);
                        if(totalSalary(emp,CANT)!=-1)
                            printf("El total de salarios es: %.02f\n",totalSalary(emp,CANT));
                        if(averageSalary(emp,CANT)!=-1)
                            printf("El promedio de salarios es: %d\n",
                                   averageSalary(emp,CANT));
                        if(excSalary(emp,CANT)!=-1)
                        printf("La cantidad de empleados que superan el salario promedio es de: %d\n",excSalary(emp,CANT));
                        printf("_________________________________________________________\n");
                    break;
                }
            }
    }while(opcion!=5);

    return 0;
}