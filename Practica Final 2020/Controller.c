#include <stdio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Usuarios.h"
#define RETURN_OK 1
#define RETURN_ERROR 0



int controller_loadFromTextUsuarios(char* path , LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("usuarios.dat", "r");
    if(pFile != NULL)
    {
        ret = parser_UsuariosFromText(pFile, pArrayListUsuarios);
    }
    else
    {
        printf("El Archivo no existe\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Carga los datos de los temas desde el archivo temas.dat (modo texto).
 *
 * \param path char*
 * \param pArrayListTemas LinkedList*
 * \return int
 *
 */
int controller_loadFromTextTemas(char* path , LinkedList* pArrayListTemas)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("temas.dat", "r");
    if(pFile != NULL)
    {
        ret = parser_TemasFromText(pFile, pArrayListTemas);
    }
    else
    {
        printf("El Archivo no existe\n\n");
        system("pause");
    }

    return ret;
}


/** \brief Carga los datos de los usrleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        ret = parser_UsuariosFromBinary(pFile, pArrayListUsuarios);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Alta de usrleados
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
/*int controller_addUsuarios(LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    Usuarios* usr = Usuarios_new();
    Usuarios* usrAux = Usuarios_new();
    int id;
    int idAdd;
    char nombre[20];
    int horasTeabajadas;
    int sueldo;

    if(pArrayListUsuarios != NULL)
    {
        printf("Ingrese ID: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListUsuarios); i++)
        {
            usrAux = (Usuarios*) ll_get(pArrayListUsuarios, i);

            ret = Usuarios_getId(usrAux, &id);


            if(ret == RETURN_OK)
            {
                if(id == idAdd)
                {
                    printf("Ya existe este ID");
                    ret = RETURN_ERROR;
                    break;
                }
                else{
                    printf("Ingrese Nombre: ");
                    scanf("%s", nombre);
                    ret = Usuarios_setNombre(usr, nombre);

                    printf("Ingrese Horas Trabajadas: ");
                    scanf("%d", &horasTeabajadas);
                    ret = Usuarios_setHorasTrabajadas(usr, horasTeabajadas);

                    printf("Ingrese Sueldo: ");
                    scanf("%d", &sueldo);
                    ret = Usuarios_setSueldo(usr, sueldo);

                    ret = ll_add(pArrayListUsuarios, usr);
                    break;
                }
            }
        }



    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;
}
*/
/** \brief Modificar datos de usrleado
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
 /*
int controller_editUsuarios(LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    int id;
    int idEdit;
    char nombreusr[20];
    int horasTrabajadas;
    int sueldo;

    Usuarios* usrAux = Usuarios_new();

    if(pArrayListUsuarios != NULL)
    {
        system("cls");
        printf("\nIngrese Id: ");
        scanf("%d", &idEdit);

        for(int i = 0; i < ll_len(pArrayListUsuarios); i++)
        {
            usrAux = (Usuarios*) ll_get(pArrayListUsuarios, i);
            ret = Usuarios_getId(usrAux, &id);

            if(ret == RETURN_OK)
            {
                if(id == idEdit)
                {
                    switch(menuEdit())
                    {
                    case 1:
                            Usuarios_showUsuarios(usrAux);
                            printf("Ingrese Nombre: ");
                            scanf("%s",nombreusr);
                            strcpy(usrAux->nombre, nombreusr);
                            break;
                    case 2:
                            Usuarios_showUsuarios(usrAux);
                            printf("Ingrese Horas Trabajadas: ");
                            scanf("%d",&horasTrabajadas);
                            usrAux->horasTrabajadas = horasTrabajadas;
                            break;
                    case 3:
                            Usuarios_showUsuarios(usrAux);
                            printf("Ingrese Sueldo: ");
                            scanf("%d",&sueldo);
                            usrAux->sueldo = sueldo;
                            break;
                    case 4:
                            break;

                    }
                    ret = ll_set(pArrayListUsuarios, i, usrAux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }




    return ret;
}
*/
/** \brief Baja de usrleado
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
 /*
int controller_removeUsuarios(LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    char seguir;
    int id = 0;
    int indice;

    if(pArrayListUsuarios != NULL)
    {
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListUsuarios); i++)
        {
            indice = (Usuarios*) ll_get(pArrayListUsuarios, i);
            ret = Usuarios_getId(indice, &id);

            if(ret == RETURN_OK)
            {
                 Usuarios_showUsuarios(ret);

                 printf("\nConfima borrado s/n: ");
                 fflush(stdin);
                 scanf("%c", &seguir);

                 if(seguir == 'n')
                 {
                     printf("Baja cancelada\n\n");

                 }
                 else

                 {
                     ll_remove(pArrayListUsuarios, indice);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }

    return ret;
}
 */
/** \brief Listar usrleados
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
int controller_ListUsuarios(LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListUsuarios);

    if(pArrayListUsuarios != NULL)
    {
        if(len != 0)
        {
            printf("ID - Nombre - Email - Sexo - Pais - Ip_address\n\n");
            for(int i = 0; i < len; i++)
            {
                Usuarios_showUsuarios(pArrayListUsuarios);
                ret = RETURN_OK;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            system("pause");
        }
    }
    return ret;
}

/** \brief Listar temas
 *
 * \param path char*
 * \param pArrayListTemas LinkedList*
 * \return int
 *
 */
int controller_ListTemas(LinkedList* pArrayListTemas)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayListTemas);

    if(pArrayListTemas != NULL)
    {
        if(len != 0)
        {
            printf("ID - Nombre del tema - Artista\n\n");
            for(int i = 0; i < len; i++)
            {
                Temas_showTemas(pArrayListTemas);
                ret = RETURN_OK;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            system("pause");
        }
    }
    return ret;
}



/** \brief Ordenar usrleados
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */

int controller_sortUsuarios(LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;
    if(pArrayListUsuarios != NULL)
    {
        switch(menuSortUsuario())
        {
        case 1:
                ll_sort(pArrayListUsuarios, Usuarios_sortByName,1);
                ll_sort(pArrayListUsuarios, Usuarios_sortByNac,1);
                Usuarios_showUsuarios(pArrayListUsuarios);
                break;
        case 2:

                Usuarios_showUsuarios(pArrayListUsuarios);
                break;
        }
    }
    else
    {
        printf("No hay datos\n");
    }
    system("pause");

    return ret;
}

int controller_escucharTemas(LinkedList* pArrayListUsuarios, LinkedList* pArrayListTemas)
{
    int ret;
    int retUsr = RETURN_ERROR;
    int retPass = RETURN_ERROR;
    int retTema = RETURN_ERROR;
    int id;
    int idEdit;
    char usuarioAuxIngr[50];
    char usuarioAux[50];
    char passAux[60];
    char passAuxIngr[120];
    int idTema;
    int sueldo;

    Usuarios* UsuariosAux = eUsuarios_new();
    Temas* TemasAux = eTemas_new();

    if(pArrayListUsuarios != NULL)
    {
        system("cls");
        printf("\nIngrese Usuario: ");
        scanf("%s", &usuarioAuxIngr);
        printf("\nIngrese Contraseña: ");
        scanf("%[^\n]", &passAuxIngr);


        for(int i = 0; i < ll_len(pArrayListUsuarios); i++)
        {
            UsuariosAux = (Usuarios*) ll_get(pArrayListUsuarios, i);

            retUsr = Usuarios_getNombre(UsuariosAux, usuarioAux);
            retPass = Usuarios_getPassword(passAux, &passAuxIngr);

            if(retUsr == RETURN_OK && retPass == RETURN_OK)
            {
                if((strcmp(usuarioAux, usuarioAuxIngr)==0) && (strcmp(passAux,passAuxIngr)==0))
                {
                    printf("Ingrese el id del tema a escuchar");
                    scanf("%d", &idTema);
                    Temas_showTemas(TemasAux);

                    for(int i = 0; i < ll_len(pArrayListTemas); i++)
                    {
                        TemasAux = (Temas*) ll_get(pArrayListTemas, i);
                        retTema = temas_getId(TemasAux, &id);

                        if(ret == RETURN_OK)
                        {
                            if(id == idTema)
                            {
                                TemasAux->contadorEscuchados++;
                            }
                        }

                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;



}
/** \brief Guarda los datos de los usrleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
/*
int controller_saveAsText(char* path , LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen("estadisticas.dat", "w");
    Usuarios* usr;


    if(pArrayListUsuarios != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListUsuarios);i++)
        {
            usr = (Usuarios*)ll_get(pArrayListUsuarios, i);
            fprintf(pFile, "%d,%s,%d,%d,",usr->id ,usr->nombre ,usr->horasTrabajadas, usr->sueldo);
        }
        fclose(pFile);
        ret = RETURN_OK;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}
*/
/** \brief Guarda los datos de los usrleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListUsuarios LinkedList*
 * \return int
 *
 */
 /*
int controller_saveAsBinary(char* path , LinkedList* pArrayListUsuarios)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pFile;
    pFile = fopen("data.bin", "wb");
    Usuarios* usr;

    if(ll_len(pArrayListUsuarios)!= 0)
    {
        if(pArrayListUsuarios != NULL)
        {
            for(int i = 0; i<ll_len(pArrayListUsuarios);i++)
            {
                usr = (Usuarios*)ll_get(pArrayListUsuarios, i);
                fwrite(usr, sizeof(Usuarios*), 1, pFile);
            }
            fclose(pFile);
            ret = RETURN_OK;
        }
        else
        {
            printf("No hay Archivo\n");
            system("pause");
        }
     }
     else
     {
         printf("No hay Datos\n");
     }

    return ret;
}
*/

