#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "persona.h"
int parseData(char* fileName,Persona* arrayPersonas, int len){
        FILE *pFile;
        int r,i=0;
        char var1[50],var3[50],var2[50],var4[50];
        pFile = fopen(fileName,"r");
        if(pFile == NULL){
        return -1;}

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
            strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
            arrayPersonas[i].edad = atoi(var4);
            i++;
            }
        else
            break;
        }while(!feof(pFile) && i<len);

        fclose(pFile);
        return i;
}
