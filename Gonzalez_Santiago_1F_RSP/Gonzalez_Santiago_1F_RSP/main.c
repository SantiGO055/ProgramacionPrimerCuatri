#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "envios.h"
#include "utn.h"
/****************************************************
    GONZALEZ SANTIAGO 1F RSP
*****************************************************/


int main()
{
    int option,i=0;
    char path[10],zonaAux[10];
    eEnvio* e;
    LinkedList* listaEnvios = ll_newLinkedList();

    do{
        utn_getEntero(&option,"MENU\n- 1-Cargar el archivo\n"
                             "2- Imprimir envios\n"
                             "3- Calcular costos\n"
                             "4- Generar archivo de costos para zona\n"
                             "5- Imprimir lista de zonas\n"
                             "6- Salir\n",
                             "Error, ingrese numero entre 1 y 5",1,6,2);
        switch(option)
        {
            case 1:
                system("cls");
                utn_getString(path,"Ingrese el nombre del archivo a abrir\n");
                controller_loadFromText(path,listaEnvios);
                break;
            case 2:
                system("cls");
                envios_printList(listaEnvios);
                break;
            case 3:
                system("cls");
                controller_ll_map(listaEnvios);
                envios_printCostoEnvio(listaEnvios);
                break;
            case 4:
                system("cls");
                utn_getString(zonaAux,"Ingrese la zona a filtrar\n");
                ll_filter(listaEnvios,zonaAux);
                controller_saveAsText(zonaAux ,listaEnvios);
                break;
            case 5:
                break;
            case 6:
                break;
        }

    }while(option != 4);
    return 0;
}
