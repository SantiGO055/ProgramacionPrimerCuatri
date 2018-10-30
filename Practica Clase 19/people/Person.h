#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED
struct S_Persona{
        int id;
        char nombre[32];
        char apellido[32];
        int edad;
    };
    typedef struct S_Persona Persona;
    int parseData(char* fileName,Persona* arrayPersonas);
#endif //PEOPLE_H_INCLUDED

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Persona* person_new ();

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Persona* this, int age) ;

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Persona* this);

/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Persona * this);

void person_setId(Persona* this, int id);
