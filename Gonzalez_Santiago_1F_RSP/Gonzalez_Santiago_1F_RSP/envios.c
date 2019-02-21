#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "envios.h"
#include "utn.h"

eEnvio* envio_new(){

    eEnvio* this = malloc(sizeof(eEnvio));
    return this;
}
eEnvio* envios_newParametros(char* idStr,char* nombre,char* idCamion,char* zonaDestino,char* kmRecorridos,char* tipoEntrega){
    eEnvio* e=envio_new();
    int flagCostoEnvio=0;
    if(e!=NULL && idStr!=NULL && nombre!=NULL && idCamion!=NULL&&
       zonaDestino!=NULL&&kmRecorridos!=NULL&&tipoEntrega!=NULL){
        envios_setId(e, idStr);
        envios_setNombre(e, nombre);
        envios_setIdCamion(e,idCamion);
        envios_setZonaDestino(e,zonaDestino);
        envios_setKmRecorridos(e,kmRecorridos);
        envios_setTipoEntrega(e,tipoEntrega);
        envios_setCostoEnvio(e,1,flagCostoEnvio);
        flagCostoEnvio=1;
    }
    return e;
}
int ll_costoEnvio(void* envioA)
{
    int returnAux = -1;
    float costoEnvioAux;
    float kmRecorridoAux;
    int tipoEntregaAux;
    char costoEnvioAuxChar;
    if(envioA!=NULL){
        //costoEnvioAux=envios_getCostoEnvio(((eEnvio*)envioA));
        kmRecorridoAux=envios_getKmRecorridos(((eEnvio*)envioA));
        tipoEntregaAux=envios_getTipoEntrega(((eEnvio*)envioA));
        if(kmRecorridoAux<50){
            costoEnvioAux=100*kmRecorridoAux;
        }
        else{
            costoEnvioAux=50*kmRecorridoAux;
        }

        if(tipoEntregaAux==0){
            costoEnvioAux=costoEnvioAux+250;
            envios_setCostoEnvio(((eEnvio*)envioA),costoEnvioAux,1);
            returnAux = 1;
        }
        if(tipoEntregaAux==1){
            costoEnvioAux=costoEnvioAux+420;
            envios_setCostoEnvio(((eEnvio*)envioA),costoEnvioAux,1);
            returnAux = 1;
        }
        if(tipoEntregaAux==2){
            costoEnvioAux=costoEnvioAux+75;
            envios_setCostoEnvio(((eEnvio*)envioA),costoEnvioAux,1);
            returnAux = 1;
        }
    }
    return returnAux;
}


int envios_setId(eEnvio* this,char* id){
    id=atoi(id);
    if(id>0)
        return this->id = id;
}

int envios_getId(eEnvio* this){
    return this->id;
}

void envios_setNombre(eEnvio* this,char* nombre){
    if(nombre[0] != '\0')
        strncpy(this->nombre, nombre, sizeof(this->nombre));
}
char* envios_getNombre(eEnvio* this){
    return this->nombre;
}
int envios_setIdCamion(eEnvio* this,char* idCamion){
    idCamion = atoi(idCamion);
    if(idCamion>=0)
        return this->idCamion = idCamion;
}
int envios_getIdCamion(eEnvio* this){
    return this->idCamion;
}
void envios_setZonaDestino(eEnvio* this,char* zonaDestino){
    if(zonaDestino[0] != '\0')
        strncpy(this->zonaDestino, zonaDestino, sizeof(this->zonaDestino));
}
char* envios_getZonaDestino(eEnvio* this){
    return this->zonaDestino;
}
int envios_setKmRecorridos(eEnvio* this,char* kmRecorridos){
    kmRecorridos = atoi(kmRecorridos);
    if(kmRecorridos>0)
        return this->kmRecorridos= kmRecorridos;
}
float envios_getKmRecorridos(eEnvio* this){
    return this->kmRecorridos;
}
int envios_setTipoEntrega(eEnvio* this,char* tipoEntrega){
    tipoEntrega = atoi(tipoEntrega);
    if(tipoEntrega>0)
        return this->tipoEntrega= tipoEntrega;
}
int envios_getTipoEntrega(eEnvio* this){
    return this->tipoEntrega;
}

float envios_setCostoEnvio(eEnvio* this,float costoEnvio,int flagCostoEnvio){
    //float costoEnvioAux;
    //costoEnvioAux = atof(costoEnvio);
    if(flagCostoEnvio==0){
        return this->costoEnvio=0;
        }
    else if(costoEnvio>0)
        return this->costoEnvio= costoEnvio;
}
float envios_getCostoEnvio(eEnvio* this){
    return this->costoEnvio;
}
/*
void employee_print(eEmpleado* employee){
    printf("-----------------------------------------------------\n");
    printf("ID      : %d\n", eEmpleado->id);
    printf("Nombre  : %s\n", eEmpleado->nombre);
    printf("Nivel : %d\n", eEmpleado->nivel);
    printf("Productos vendidos : %d\n", eEmpleado->productosVendidos);
    printf("Monto vendido : %.02f\n", eEmpleado->montoVendido);
    printf("Comision : %d\n", eEmpleado->comision);
    printf("-----------------------------------------------------\n");
}*/
void envios_printList(LinkedList* listaEnvios){
    eEnvio* eAux;
    int i;
    for(i=0;i<ll_len(listaEnvios);i++){
        eAux=(eEnvio*)ll_get(listaEnvios, i);
        printf("ID      : %d\n", eAux->id);
        printf("Nombre producto : %s\n", eAux->nombre);
        printf("id Camion : %d\n", eAux->idCamion);
        printf("Zona de destino : %s\n", eAux->zonaDestino);
        printf("KM Recorridos  : %d\n", eAux->kmRecorridos);
        printf("Tipo Entrega : %d\n", eAux->tipoEntrega);
    }
}

void envios_printCostoEnvio(eEnvio* this){
    eEnvio* eAux;
    int i;
    for(i=0;i<ll_len(this);i++){
        eAux=(eEnvio*)ll_get(this, i);
        printf("ID      : %d\n", eAux->id);
        printf("Nombre  : %s\n", eAux->nombre);
        printf("idCamion : %d\n", eAux->idCamion);
        printf("zonaDestino : %d\n", eAux->zonaDestino);
        printf("kmRecorridos : %d\n", eAux->kmRecorridos);
        printf("tipoEntrega : %d\n", eAux->tipoEntrega);
        printf("Costo Envio : %.02f\n", eAux->costoEnvio);
    }
}

/*
int ven_filtrarNormal(eEnvio* this)
{
    int returnAux = 0, entregaAux;

    if (this != NULL)
    {
        envios_getTipoEntrega(this);

        if (entregaAux == 0)
            returnAux = 1;
    }
    return returnAux;
}
int ven_filtrarExpress(eEnvio* this)
{
    int returnAux = 0, entregaAux;

    if (this != NULL)
    {
        envios_getTipoEntrega(this);

        if (entregaAux == 0)
            returnAux = 1;
    }
    return returnAux;
}
int ven_filtrarSegDisp(eEnvio* this)
{
    int returnAux = 0, entregaAux;

    if (this != NULL)
    {
        envios_getTipoEntrega(this);

        if (entregaAux == 0)
            returnAux = 1;
    }
    return returnAux;
}
*/
