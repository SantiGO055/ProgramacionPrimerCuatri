#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Usuarios.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los usrleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListusrloyee LinkedList*
 * \return int
 *
 */
int parser_UsuariosFromText(FILE* pFile , LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char nombreStr[20];
    char emailStr[60];
    char sexoStr[8];
    char paisStr[60];
    char passwordStr[128];
    char ip_addressStr[20];
    //char sueldoStr[6];

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",
                          idStr, nombreStr, emailStr, sexoStr, paisStr, passwordStr,ip_addressStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",
                          idStr, nombreStr, emailStr, sexoStr, paisStr, passwordStr,ip_addressStr);

            if(cant != 7)
            {
                printf("Error al cargar Archivo\n\n");
                system("pause");
            }
            else
            {
                Usuarios* usr = eUsuarios_new();
                usr->id = atoi(idStr);
                strcpy(usr->nombre, nombreStr);
                strcpy(usr->email, emailStr);
                strcpy(usr->sexo, sexoStr);
                strcpy(usr->pais, paisStr);
                strcpy(usr->password, passwordStr);
                strcpy(usr->ip_address, ip_addressStr);

                ll_add(pArrayListUsuarios, usr);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Archivo sin datos\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Parsea los datos los datos de los usrleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListusrloyee LinkedList*
 * \return int
 *
 */
int parser_TemasFromText(FILE* pFile , LinkedList* pArrayListTemas)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char nombre_temaStr[20];
    char artistaStr[60];
    int cont=-1;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,\n]\n", idStr, nombre_temaStr, artistaStr);
        while(!feof(pFile))
        {

            cant = fscanf(pFile,"%[^,],%[^,],%[^,\n]\n", idStr, nombre_temaStr, artistaStr);
            cont++;
            if(cant != 3)
            {
                printf("Error al cargar archivo\n\n");
                printf("el registro %d no se pudo cargar",cont);
                system("pause");
            }
            else
            {
                Temas* tema = eTemas_new();
                tema->id = atoi(idStr);
                strcpy(tema->nombre_tema, nombre_temaStr);
                strcpy(tema->artista, artistaStr);

                ll_add(pArrayListTemas, tema);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Archivo sin datos\n\n");
        system("pause");
    }

    return ret;
}



/** \brief Parsea los datos los datos de los usrleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
int parser_UsuariosFromBinary(FILE* pFile , LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Usuarios* usr = eUsuarios_new();
                ret = fread(usr, sizeof(Usuarios),1,pFile);
                if(ret != 1)
                {
                    printf("Error al caargar datos\n");
                }
                else
                {
                    ll_add(pArrayListUsuarios, usr);
                }
        }
    fclose(pFile);
    ret = RETURN_OK;
    }
    else
    {
        printf("No hay datos");
        system("pause");
    }

    return ret;
}


