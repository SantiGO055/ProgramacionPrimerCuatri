#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployee.h"


int init(eEmpleado emp[],int CANT){
    int i;
    int retorno=-1;
    for(i=0;i<CANT;i++){
        emp[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
int obtenerEspacioLibre(eEmpleado emp[], int CANT)
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
void alta(eEmpleado emp[],int CANT){
    int index,i,idAux;
    init(emp,CANT);

    for(i=0;i<CANT;i++){

            index=obtenerEspacioLibre(emp,CANT);
            if(index!=-1){ //si hay espacio libre

            system("cls");
            printf("Ingrese ID: ");
            fflush(stdin);
            scanf("%d",&idAux);


            buscarPorId(emp,CANT,idAux);
            printf("%d",buscarPorId(emp,CANT,idAux));

            while(buscarPorId(emp,CANT,idAux)!=-1) { //si es distinto de -1 es por que esta repetido el dni
                printf("ID existente\n");
                printf("Reingrese ID: \n");
                fflush(stdin);
                scanf("%d",&idAux);
                buscarPorId(emp,CANT,idAux);

                }



            emp[i].id=idAux;
            emp[i].isEmpty=0;
            printf("Ingrese Apellido: ");
            scanf("%s",emp[i].apellido);
            printf("Ingrese Nombre: ");
            scanf("%s",emp[i].nombre);
            printf("Ingrese salario: ");
            scanf("%f",&emp[i].salario);
            printf("Ingrese sector: ");
            scanf("%d",&emp[i].sector);
            }
    }

}
int buscarPorId(eEmpleado emp[], int CANT,int idAux){

    int i;
    int retorno=-1;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){ //si esta ocupado
            if(emp[i].id==idAux){
                retorno=i;
                break;
            }
        }
    retorno=-1;
    }

    return retorno;
}

void baja(eEmpleado emp[],int CANT){
    int i;
    int idAux;
    char rta;
     //muestro empleados dados de alta para elegir cual eliminar
    imprimirEmpleados(emp,CANT);
    printf("ID que desea eliminar: ");
    scanf("%d",&idAux);
    for(i=0;i<CANT;i++){
        while(idAux==emp[i].id){//lo encontro

            printf("Apellido: %s Nombre: %s ID de empleado: %d\n",emp[i].apellido,emp[i].nombre,emp[i].id);
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
}

void ordenarLista(eEmpleado emp[],int CANT){
eEmpleado empAux;
int i, j;
    for(i=0;i<CANT-1;i++){
        if(emp[i].isEmpty==0){
            for(j=i+1;j<CANT;j++){
                if(strcmp(emp[i].apellido,emp[j].apellido)>0){//Si devuelve mayor a cero i apellido es mayor que j apellido
                    /*strcpy(apellidoAux,per[i].apellido);    no se hace por que hay que escribir mucho codigo
                    strcpy(per[i].apellido,per[j].apellido);*/
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                }
                if(strcmp(emp[i].apellido,emp[j].apellido)==0){
                    if(emp[i].sector>emp[j].sector){
                    empAux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=empAux;
                    }
                }
            }
        }

    }

}

void imprimirEmpleados(eEmpleado emp[],int CANT){
    int i;
    for(i=0;i<CANT;i++){
        if(emp[i].isEmpty==0){
            printf("Apellido: %s ID: %d\n",emp[i].apellido,emp[i].id);
        }
    }
}
