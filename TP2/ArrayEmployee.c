#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployee.h"


int initEmployee(employee* emp,int CANT){
    int i;
    int retorno=-1;
    for(i=0;i<CANT;i++){
        emp[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
int getFreeSpace(employee* emp, int CANT)
{
    int i,retorno=-1;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==1){ //encontro un lugar libre
            retorno=i;
            break;
        }
    }
    return retorno;
}
int addEmployee(employee *emp,int CANT,char* name, char* lastName, float salary,int sector,int id){
    int i,retorno=-1;
    i=getFreeSpace(emp,CANT);
        if(i!=-1){ //si hay espacio libre
            emp[i].isEmpty=0;
            strcpy(emp[i].name,name);
            strcpy(emp[i].lastName,lastName);
            emp[i].salary=salary;
            emp[i].sector=sector;
            emp[i].id=id;
            retorno=0;
        }
    return retorno;
}
int findEmployeeById(employee* emp, int CANT,int id){
    int i;
    int retorno=-1;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){ //si esta ocupado
            if(emp[i].id==id){
                retorno=i;
                break;
            }
        }
    retorno=-1;
    }
    return retorno;
}

int removeEmployee(employee* emp,int CANT,int id){
    int i;
    char rta;
     //muestro empleados dados de alta para elegir cual eliminar
    printEmployee(emp,CANT);
    for(i=0;i<CANT;i++){
        while(findEmployeeById(emp,CANT,id)!=-1){//lo encontro
            printf("Apellido: %s\nNombre: %s\nID de empleado: %d\n",emp[i].lastName,emp[i].name,emp[i].id);
            do{ //validad entre s y n
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch()); //lo que tecleo lo paso a mayuscula y lo asigno en rta
            }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                emp[i].isEmpty=1;
                system("cls");
                printf("Accion: Registro eliminado correctamente\n");
                break;
                }
            if(rta=='N'){
                system("cls");
                break;
            }
        }
    }
    return 0;
}

int sortEmployee(employee* emp,int CANT,char* name, char* lastName){
employee empAux;
int i, j;
    for(i=0;i<CANT-1;i++){
        if(emp[i].isEmpty==0){
            for(j=i+1;j<CANT;j++){
                if(emp[i].sector>emp[j].sector){
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                }
            }
            for(j=i+1;j<CANT;j++){
                if(strcmp(emp[i].lastName,emp[j].lastName)>0){
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                }
                if(strcmp(emp[i].lastName,emp[j].lastName)==0){
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                    }
            }
        }
    }
    return 0;
}
int firstEmployee(int flag){
    int retorno=-1;
    if(flag!=1){
        system("cls");
        printf("ERROR! Debera realizar la carga de un empleado al menos!\n");
        retorno=0;
    }
    return retorno;
}

int printEmployee(employee* emp,int CANT){
    int i;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            printf("Empleado:\nApellido: %s Sector: %d ID: %d\n",emp[i].lastName,emp[i].sector,emp[i].id);
        }
    }
    return 0;
}

int validarCadena(char* emp, int min, int max){
    int i;
    int retorno;
    int largo;
    largo=strlen(emp);

    for(i=0;emp!='\0';i++){
        if((emp[i] != ' ') && (emp[i] < 'a' || emp[i] > 'z') && (emp[i] < 'A' || emp[i] > 'Z')){
            retorno=-1;
            break;
        }
        else if(largo<min||largo>max){
            retorno=0;
        }
        else{
            retorno=1;
        }
    }
    return retorno;
}
void modifyEmployee(employee *emp,int CANT,char* name, char* lastName, float salary,int sector,int id){
            strcpy(emp[id].name,name);
            strcpy(emp[id].lastName,lastName);
            emp[id].salary=salary;
            emp[id].sector=sector;
}
