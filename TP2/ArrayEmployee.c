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
int getFreeSpace(employee* emp, int CANT){
    int i,retorno=-1;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==1){ //encontro un lugar libre
            retorno=i; //si es distinto de -1 esta libre
            break;
        }
    }
    return retorno;
}
int addEmployee(employee *emp,int CANT,char* name,
                char* lastName, float salary,int sector,int id){
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
    int i,iAux;
    char rta;
    for(i=0;i<CANT;i++){
        iAux=findEmployeeById(emp,CANT,id);
        if(iAux!=-1){//lo encontro
            do{ //validad entre s y n
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch());
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
        else{
            system("cls");
            printf("No se encuentra el ID\n");
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
        printf("ERROR! Debera realizar la carga de un empleado\n");
        retorno=0;
    }
    return retorno;
}

int printEmployee(employee* emp,int CANT){
    int i,retorno=-1;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            printf("\tEmpleado:\nApellido: %s Sector: %d ID: %d\n",
                   emp[i].lastName,emp[i].sector,emp[i].id);
            printf("_________________________________________________________\n");
            retorno=i;
        }

    }
    return retorno;
}

int validarCadena(char* emp, int min, int max){
    int i;
    int retorno;
    int largo;
    largo=strlen(emp);

    for(i=0;emp!='\0';i++){
        if((emp[i]!=' ')&&(emp[i]<'a'||emp[i]>'z')&&(emp[i]<'A'||emp[i]>'Z')){
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
void modifyEmployee(employee *emp,int CANT,char* name,
                    char* lastName, float salary,int sector,int id){
            strcpy(emp[id].name,name);
            strcpy(emp[id].lastName,lastName);
            emp[id].salary=salary;
            emp[id].sector=sector;
}

int averageSalary(employee* emp,int CANT){
    int i,retorno=-1;
    float salaryAux=0;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            salaryAux+=emp[i].salary;
            retorno=i;
        }
        else{
            retorno=-1;
        }
    }
    if(retorno!=-1){
        retorno=salaryAux/(i-1);
    }
    return retorno;
}

float totalSalary(employee* emp,int CANT){
    int i,retorno=-1;
    float totalSalary=0;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            totalSalary+=emp[i].salary;
            retorno=totalSalary;
        }
    }
    return retorno;
}
int excSalary(employee* emp,int CANT){
    int i,retorno=-1,count=0;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            if(emp[i].salary>=averageSalary(emp,CANT)){
                count++;
            }
            retorno=count;
        }
    }
    return retorno;
}
