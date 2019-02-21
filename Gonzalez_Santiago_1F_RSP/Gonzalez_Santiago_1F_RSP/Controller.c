#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envios.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvios LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEnvios)
{
    FILE *pFile;
    int retorno=-1;
    if (1){
        pFile=fopen(path,"r");
        if (pFile==NULL){
            printf("El archivo no puede ser abierto");
            retorno=-1;
            return retorno;
        }
        else {
            parser_enviosFromText(pFile,pArrayListEnvios);
            retorno=1;
        }
        //employee_print(pArrayListEnvios);
    }
    fclose(pFile);
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvios LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvios)
{
    FILE* pFile;
    pFile = fopen(path, "w");
    int retorno=-1,i;
    eEnvio* auxEnv;
    if(path!=NULL&&pFile!=NULL&&pArrayListEnvios!=NULL){
        fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id_envio","nombre_producto","id_camion","zona_destino",
                "km_recorridos","tipo_entrega","costo_envio");
        for(i=0; i<ll_len(pArrayListEnvios);i++){
            auxEnv = (eEnvio*)ll_get(pArrayListEnvios, i);
            fprintf(pFile,"%d,%s,%d,%s,%d,%d,%.02f\n",auxEnv->id,auxEnv->nombre,
                    auxEnv->idCamion,auxEnv->zonaDestino,auxEnv->kmRecorridos,auxEnv->tipoEntrega,auxEnv->costoEnvio);
            fwrite(auxEnv, sizeof(eEnvio), 1, pFile);
        }
        if(i==ll_len(pArrayListEnvios)){
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_ll_map(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    if(pArrayListEmployee == NULL){
        printf("No hay datos en la lista.\n");
    }
    else
    {
        LinkedList* newLinker=ll_clone(pArrayListEmployee);
        if(newLinker!=NULL){
            ll_map(newLinker,ll_costoEnvio);
                retorno=1;
            ll_deleteLinkedList(newLinker);
        }
    }
    return retorno;
}


