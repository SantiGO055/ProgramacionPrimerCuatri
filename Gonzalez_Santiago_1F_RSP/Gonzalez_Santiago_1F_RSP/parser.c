#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envios.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_enviosFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{
    int r,i=0;
    char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
    int retorno=-1;
    //Employee* auxStruct;
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
        if(r==6){
            eEnvio* auxStruct=envios_newParametros(var1,var2,var3,var4,var5,var6);
            if(auxStruct!=NULL)
            ll_add(pArrayListEnvio,auxStruct);
            retorno=1;
        }
        else{
            retorno=-1;
            }
    }while(!feof(pFile));

    return retorno;
}

