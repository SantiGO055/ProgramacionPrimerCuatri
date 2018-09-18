#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 2
///////////////////////////////////////ordenamiento de apellidos y nombres
typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    long int dni;
    char apellido[31];
    char nombre[31];
    eFecha fechaNac;
    int isEmpty;
}ePersona;

int main()
{
    ePersona per[CANT],perAux;
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
    return 0;
}
