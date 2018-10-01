#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"
#define CANT 1000
#define CHAR 51
int main()
{
    int opcion,sector,flag=0,id=0,findEmployeeAux,idAux,contEmp=0,idRem;
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
                    printf("No hay espacio para agregar empleados!\n");
                    break;
                }
                utn_getStringAvanzado(name,"Ingrese nombre: ","ERROR! El nombre debe ser solo letras\n",CHAR,2);
                utn_getStringAvanzado(lastName,"Ingrese apellido: ","ERROR! El apellido debe ser solo letras\n",CHAR,2);
                utn_getFlotante(&salary,"Ingrese salario: ","ERROR! Ingrese salario positivo\n",1,100000,2);
                utn_getEntero(&sector,"Ingrese sector","ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
                addEmployee(emp,CANT, name, lastName,salary,sector,id);
                system("cls");
                printf("Accion: Empleado agregado correctamente\n");
                break;
            case 2:
                system("cls");

                if(firstEmployee(flag)!=0){ //si no es la primera vez
                    printEmployee(emp,CANT);
                    utn_getEntero(&idAux,"Ingrese ID a modificar: ","ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                    findEmployeeAux=findEmployeeById(emp,CANT,idAux);
                    if(findEmployeeAux!=-1){ //si lo encontro
                        utn_getStringAvanzado(name,"Ingrese nombre: ","ERROR! El nombre debe ser solo letras\n",CHAR,2);
                        utn_getStringAvanzado(lastName,"Ingrese apellido: ","ERROR! El apellido debe ser solo letras\n",CHAR,2);
                        utn_getFlotante(&salary,"Ingrese salario: ","ERROR! Ingrese salario positivo\n",1,100000,2);
                        utn_getEntero(&sector,"Ingrese sector: ","ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
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
                        utn_getEntero(&idRem,"Ingrese ID a eliminar: ","ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);

                        removeEmployee(emp,CANT,idRem);
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
                        printf("___________________________________________________________________\n");
                    break;
                }
            }
    }while(opcion!=5);

    return 0;
}
