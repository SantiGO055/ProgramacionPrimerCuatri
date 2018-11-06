#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(char* id, char* nombre, char* horasTrabajadas, char* sueldo){

    Employee* this = malloc(sizeof(LinkedList));
        if(this!=NULL){
            employee_newParametros(this,id,nombre,horasTrabajadas,sueldo);
        }
    return this;
}
Employee* employee_newParametros(Employee* this , char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr){
    int id, horasTrabajadas,sueldo;
    id=atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);
    employee_setId(this, id);
    employee_setNombre(this, nombre);
    employee_setHorasTrabajadas(this,horasTrabajadas);
    employee_setSueldo(this,sueldo);
}

int employee_setId(Employee* this,int id){
    if(id>0)
        this->id = id;
}

int employee_getId(Employee* this,int* id){

}

int employee_setNombre(Employee* this,char* nombre){
    if(nombre[0] != '\0')
        strncpy(this->nombre, nombre, sizeof(this->nombre));
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    if(horasTrabajadas>0)
        this->horasTrabajadas = horasTrabajadas;
}
int employee_setSueldo(Employee* this,int sueldo){
    if(sueldo>0)
        this->sueldo = sueldo;
}
