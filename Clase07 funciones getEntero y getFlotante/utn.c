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
    return scanf("%c",pBuffer);
}




int utn_getEntero(  int* pEntero, char* msg,
                    char msgErr[],int min, int max,
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



int utn_getFlotante(  float* pFlotante, char* msg, char msgErr[],int min, int max,
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



int utn_getChar(char* input,char* msg,char* msgErr, char hiLimit, char lowLimit, int reintentos)
{
    int retorno=-1;
    char bufferChar;
    if( msg != NULL && msgErr != NULL
        && lowLimit>=0&&hiLimit<=255 &&reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getCaracter(&bufferChar) == 1) &&
                (bufferChar >= lowLimit && bufferChar <= hiLimit))
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







