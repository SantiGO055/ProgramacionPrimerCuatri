#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    long int dni;
    char apellido[31];
    char nombre[31];
    eFecha fechaNac;
    int isEmpty;
}ePersona;

int buscarPorDni(ePersona per[],int CANT,long int dniAux);

int obtenerEspacioLibre(ePersona per[],int CANT);

void alta(ePersona per[],int CANT);
void baja(ePersona per[],int CANT);
void ordenarLista(ePersona per[],int CANT);
int init(ePersona per[],int CANT);
#endif // PERSONA_H_INCLUDED
