#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
static int getInt(int* pBuffer)
{
    return scanf("%d",pBuffer);
}

static int getFloat(float* pBuffer)
{
    return scanf("%f",pBuffer);
}
static int getCaracter(char* pBuffer)
{
    /*int cantidad;
    fgets(pBuffer,sizeof(pBuffer)-2,stdin);

    cantidad = strlen(pBuffer);
    pBuffer[cantidad-1] = '\0';
    if (cantidad==1){
        printf("Ingreso al if getCaracter");
        return 1;
    }
    else{
            printf("Ingreso al else getCaracter");
    return 0;
    }*/
    return scanf("%c",pBuffer);
}




int utn_getEntero(  int* pEntero, char* msg,
                    char* msgErr,int min, int max,
                    int reintentos)

{
    int retorno=-1; //lo uso para corroborar si devuelve bien o no la funcion
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)//Todo lo que sea puntero preguntamos si es distinto de null
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) && //reemplazamos el scanf por el getInt si scanf lee lo que mandamos hacer devuelve un 1, si no lo logra hacer devuelve un 0
                (bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;//rompe el bucle mas cercano que tenga
            }
            else
            {
                fflush(stdin); //limpio el buffer por si ingreso mal algun dato no quede guardado en la posicion de memoria
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}



int utn_getFlotante(  float* pFlotante, char* msg, char* msgErr,int min, int max,
                    int reintentos)
{
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



int utn_getChar(char* input,char* msg,char* msgErr, char lowLimit, char hiLimit, int reintentos)
{
    int retorno=-1;
    char bufferChar;
    if( msg != NULL && msgErr != NULL
       &&lowLimit<=hiLimit&&reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            fflush(stdin);
            if( (getCaracter(&bufferChar) == 1)&&bufferChar>=lowLimit&&bufferChar<=hiLimit) //(bufferChar==lowLimit||bufferChar==hiLimit) para elegir dos letras como por ej el sexo m o f
            //bufferChar>=lowLimit&&bufferChar<=hiLimit para elegir un rango de letras
            {

                *input = bufferChar;
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
