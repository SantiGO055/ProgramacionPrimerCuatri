#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
struct S_Persona{
        int id;
        char nombre[32];
        char apellido[32];
        int edad;
    };
    typedef struct S_Persona Persona;
    int parseData(char* fileName,Persona* arrayPersonas, int len);
#endif // PERSONA_H_INCLUDED
