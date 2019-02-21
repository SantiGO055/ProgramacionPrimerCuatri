#ifndef ENVIOS_H_INCLUDED
#define ENVIOS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int idCamion;
    char zonaDestino[128];
    int kmRecorridos;
    int tipoEntrega;
    float costoEnvio;
}eEnvio;

eEnvio* envio_new();

eEnvio* envios_newParametros(char* idStr,char* nombre,
                             char* idCamion,char* zonaDestino,
                             char* kmRecorridos,char* tipoEntrega); //agregar sueldo,inicializa
int envio_calcularSueldo(eEnvio* this);
void envio_delete();

int envios_setId(eEnvio* this,char* id);
int envios_getId(eEnvio* this);

void envios_setNombre(eEnvio* this,char* nombre);
char* envios_getNombre(eEnvio* this);

int envios_setIdCamion(eEnvio* this,char* idCamion);
int envios_getIdCamion(eEnvio* this);

void envios_setZonaDestino(eEnvio* this,char* zonaDestino);
char* envios_getZonaDestino(eEnvio* this);

int envios_setKmRecorridos(eEnvio* this,char* kmRecorridos);
float envios_getKmRecorridos(eEnvio* this);

int envios_setTipoEntrega(eEnvio* this,char* tipoEntrega);
int envios_getTipoEntrega(eEnvio* this);

float envios_setCostoEnvio(eEnvio* this,float costoEnvio,int flagCostoEnvio);
float envios_getCostoEnvio(eEnvio* this);
//void envios_printList(LinkedList* listaEnvios);

//void envios_printCostoEnvio(eEnvio* this);
//void employee_printList(LinkedList* lista);
//int printMenu(int option);
int ll_costoEnvio(void* envioA);

int ven_filtrarNormal(eEnvio* this);
int ven_filtrarExpress(eEnvio* this);
int ven_filtrarSegDisp(eEnvio* this);

#endif // ENVIOS_H_INCLUDED
