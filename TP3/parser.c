#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
//mostrar error al cargar el archivo binario ya que no existe
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    int idAux;
    int nameAux[128];
    int horasTrabajadasAux;
    int sueldoAux;
    int retorno=-1;
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            //llamo a addemployee
            employee_new(pFile,pArrayListEmployee);
            retorno=1;
        }
        else
            break;
    }while(!feof(pFile));

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
