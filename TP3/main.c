#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 1,i;
    Employee* e;
    LinkedList* listaEmpleados = ll_newLinkedList();
    utn_getEntero(&option,"Ingrese opcion\n1- Cargar empleados desde archivo de texto\n","Opcion incorrecta",
                  0,1,2);
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
        //for(i=0; i<20; i++){
        //printf("Id:%d Nombre:%s Horas Trabajadas:%d Sueldo:%d\n", employee_getId(e), employee_getNombre(e),
               //employee_getHorasTrabajadas(e), employee_getSueldo(e));
               //}
                //break;
        }
    }while(option != 10);
    return 0;
}
