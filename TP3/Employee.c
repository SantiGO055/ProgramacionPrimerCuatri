#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){

    Employee* this = malloc(sizeof(LinkedList));
    return this;
}
Employee* employee_newParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr){
    Employee* e=employee_new();
    if(e!=NULL && idStr!=NULL && nombre!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL){
        employee_setId(e, idStr);
        employee_setNombre(e, nombre);
        employee_setHorasTrabajadas(e,horasTrabajadasStr);
        employee_setSueldo(e,sueldoStr);


    }

    return e;
}

int employee_setId(Employee* this,int id){
    id=atoi(id);
    if(id>0)
        this->id = id;
}

int employee_getId(Employee* this){
    return this->id;
}

int employee_setNombre(Employee* this,char* nombre){
    if(nombre[0] != '\0')
        strncpy(this->nombre, nombre, sizeof(this->nombre));
}
int employee_getNombre(Employee* this){
    return this->nombre;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    horasTrabajadas = atoi(horasTrabajadas);
    if(horasTrabajadas>0)
        this->horasTrabajadas = horasTrabajadas;
}
int employee_getHorasTrabajadas(Employee* this){
    return this->horasTrabajadas;
}
int employee_setSueldo(Employee* this,int sueldo){
    sueldo = atoi(sueldo);
    if(sueldo>0)
        this->sueldo = sueldo;
}
int employee_getSueldo(Employee* this){
    return this->sueldo;
}
