#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Usuarios.h"
#include "parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Listar usuarios
     3. Listar temas
     4. Escuchar Tema
     5. Guardar Estadistica
     7. Informar
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* eUsuarios = ll_newLinkedList();
    LinkedList* eTemas = ll_newLinkedList();
    //LinkedList* eEmpleadoDos = ll_newLinkedList();


    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                controller_loadFromTextUsuarios("usuarios.dat",eUsuarios);
                break;
            case 2:
                controller_loadFromTextTemas("temas.dat",eTemas);
                //ll_map(eEmpleado, employee_loadSueldo);
                //controller_loadFromBinary("data.csv",eEmpleado);
                break;
            case 3:
                controller_sortUsuarios(eUsuarios);
                break;
            case 4:
                controller_escucharTemas(eUsuarios,eTemas);
                break;
            case 5:
                controller_ListTemas(eTemas);
                break;
            case 6:

                break;
            case 7:

                break;
            case 8:
                //controller_saveAsText("info.csv", eEmpleado);
                break;
           /* case 9:
                controller_saveAsBinary("data.bin", eEmpleado);
                break;*/
        }
    }while(option != 10);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar los datos de los usuarios desde el archivo usuarios.dat (modo texto).\n");
        printf("  2. Cargar los datos de los temas desde el archivo temas.dat (modo texto).      \n");
        printf("  3. Ordenar usuarios                                                            \n");
        printf("  4. Escuchar tema                                                               \n");
        printf("  5. Listar empleados                                                            \n");
        printf("  6. Ordenar empleados                                                           \n");
        printf("  7. Guardar los datos de los empleados en el archivo info.csv (modo texto).     \n");
       // printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   \n");
        printf(" 10. Salir                                                                       \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

int menuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("     4. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 4);

    return r;
}

int menuSortUsuario()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione el sort:           \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Nacionalidad.              \n");
        printf("     3. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 3);

    return r;
}

