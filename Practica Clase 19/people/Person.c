#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Person.h"



static void initialize(Persona* this, int *id, char *nombre, char *apellido, int *edad);

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
int parseData(char* fileName,Persona* arrayPersonas){
        Persona *p;
        FILE *pFile;
        int r,i=0;
        char id[50],nombre[50],apellido[50],edad[50];
        pFile = fopen(fileName,"r");
        if(pFile == NULL){
        return -1;}

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,edad);
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,edad);
            if(r==4){
            person_new(id,nombre,apellido,edad);
            p->id = atoi(id);
            strcpy(p->nombre,nombre);
            strcpy(p->apellido,apellido);
            p->edad=atoi(edad);
            i++;
            }
        else
            break;
        }while(!feof(pFile));

        fclose(pFile);
        return i;
}

Persona* person_new ()
{
    Persona* this = malloc(sizeof(Persona));
    //if(this != NULL)
        //initialize(this,id,nombre,apellido,edad);

    return this;
}

/** \brief  Inicializa a una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
/*static void initialize(Persona* this, int id, char *nombre, char *apellido, int edad)
{
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
}*/

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
/*void person_setAge(Persona* this, int age)
{
    if(age > 0)
        this->age = age;
}*/

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
/*int person_getAge(Persona* this)
{
    return this->age;
}*/


/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Persona * this) {
    // Do any other freeing required here.
    free(this);
}


void person_setId(Persona* this, int id)
{
    if(id > 0)
        this->id = id;
}


