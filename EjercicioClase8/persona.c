#include <stdlib.h>
#include <stdio.h>
#include "persona.h"


int init(ePersona per[],int CANT){
    int i;
    int retorno=-1;
    for(i=0;i<CANT;i++){
        per[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
int obtenerEspacioLibre(ePersona per[], int CANT)
{
    int i,retorno=-1;
    for(i=0;i<CANT;i++){
        if(per[i].isEmpty==1){ //encontro un lugar libre

            retorno=i;
            break;
        }
    }
    return retorno;
}
void alta(ePersona per[],int CANT){
    int index,i;
    long int dniAux;
    index=init(per, CANT);
    if(index!=-1){
            //validar dni con funcion

            printf("Ingrese DNI: ");
            scanf("%ld",&dniAux);
            if(buscarPorDni(per[i].dni,CANT,dniAux)==-1) {
                printf("DNI existente\n");
                printf("Reingrese DNI: \n");
                scanf("%ld",&per[i].dni);
                }



            printf("Ingrese Apellido: ");
            scanf("%s",per[i].apellido);
            printf("Ingrese Nombre: ");
            scanf("%s",per[i].nombre);
            printf("Ingrese dia de nacimiento: "); //hacer funcion para comparar dni y ver si ya esta ingresado
            scanf("%d",&per[i].fechaNac.dia);
            printf("Ingrese mes de nacimiento: ");
            scanf("%d",&per[i].fechaNac.mes);
            printf("Ingrese año de nacimiento: ");
            scanf("%d",&per[i].fechaNac.anio);

    }
}

void baja(ePersona per[],int CANT){
    int i;
    long int dniAux;
    char rta;
    printf("DNI: ");
    scanf("%ld",&dniAux);
    for(i=0;i<CANT;i++){
        if(dniAux==per[i].dni){//lo encontro
            printf("%s %s %ld",per[i].apellido,per[i].nombre,per[i].dni);
            do{ //validad entre s y n
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch()); //lo que tecleo lo paso a mayuscula y lo asigno en rta
            }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                per[i].isEmpty=0;
                break;
                }

        }
    }
}

void ordenarLista(ePersona per[],int CANT){
ePersona perAux;
int i, j;
    for(i=0;i<CANT-1;i++){
        for(j=i+1;j<CANT;j++){
            if(strcmp(per[i].apellido,per[j].apellido)>0){//Si devuelve mayor a cero i apellido es mayor que j apellido
            /*strcpy(apellidoAux,per[i].apellido);    no se hace por que hay que escribir mucho codigo
            strcpy(per[i].apellido,per[j].apellido);*/
            perAux=per[i];
            per[i]=per[j];
            per[j]=perAux;
            }
            if(strcmp(per[i].apellido,per[j].apellido)==0){
                if(strcmp(per[i].nombre,per[j].nombre)>0){
                perAux=per[i];
                per[i]=per[j];
                per[j]=perAux;
                }
            }


        }
    }
}

int buscarPorDni(ePersona per[], int CANT,long int dniAux){
    int i;
    int retorno=-1;
    for(i=0;i<CANT;i++){
        if(per[i].isEmpty==0)
        {
            if(per[i].dni==dniAux){
                retorno=-1;
                break;
            }
            else{
                retorno=i;
            }
        }

    }
    return retorno;
}
