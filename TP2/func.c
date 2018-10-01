#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "func.h"


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
    int iAux;
    char rta;
        iAux=findEmployeeById(emp,CANT,id);
        if(iAux!=-1){//lo encontro
            do{
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch());
            }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                emp[iAux].isEmpty=1;
                system("cls");
                printf("Accion: Registro eliminado correctamente\n");
                }
            if(rta=='N'){
                system("cls");
                printf("Accion: No se elimino el registro\n");
            }
        }
        else{
            system("cls");
            printf("Accion: No se encuentra el ID\n");
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
        }
    }
    for(i=0;i<CANT-1;i++){
            for(j=i+1;j<CANT;j++){
                if(strcmp(emp[i].lastName,emp[j].lastName)>0&&emp[i].sector==emp[j].sector){
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                }
                if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector){
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                }
            }
        }

    return 0;
}
int firstEmployee(int flag){
    int retorno=-1;
    if(flag!=1){
        system("cls");
        printf("___________________________________________________________________\n");
        printf("ERROR! Debera realizar la carga de un empleado\n");
        printf("___________________________________________________________________\n");
        retorno=0;
    }
    return retorno;
}

int printEmployee(employee* emp,int CANT){
    int i,retorno=-1;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            printf("___________________________________________________________________\n");
            printf("\tEmpleado:\nApellido: %s Sector: %d ID: %d\n",
                   emp[i].lastName,emp[i].sector,emp[i].id);
            printf("___________________________________________________________________\n");
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

static int getInt(int* pBuffer){
    return scanf("%d",pBuffer);
}

static int getFloat(float* pBuffer){
    return scanf("%f",pBuffer);
}
int utn_getEntero(  int* pEntero, char* msg,
                    char* msgErr,int min, int max,
                    int reintentos){
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) &&
                (bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}

int utn_getFlotante(  float* pFlotante, char* msg, char* msgErr,int min, int max,
                    int reintentos){
    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getFloat(&bufferFloat) == 1) &&
                (bufferFloat >= min && bufferFloat <= max))
            {
                *pFlotante = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}
int esLetra(char* input){
    int retorno=-1,i=0;
    while (input[i]!='\0'){
        if((input[i]!=' ')&&(input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')){
            retorno=-1;
            break;
        }
            i++;
    }
    if(input[i]=='\0'){
        retorno=1;
    }
    return retorno;
}
void utn_getString(char* input, char* msg) {
    fflush(stdin);
    printf("%s", msg);
    fgets(input,100,stdin);
    input[strcspn(input, "\n")] = 0;
}
int utn_getStringAvanzado(char* input,char* msg,char* msgErr,int cant, int reintentos){
    char aux[cant];
    do{
        utn_getString(aux,msg);
        if(esLetra(aux)!=-1){
            strcpy(input,aux);
            return 1;
        }
        else{
            reintentos--;
            printf("%s",msgErr);
        }
    }while(reintentos>=0);
    return 0;
}
