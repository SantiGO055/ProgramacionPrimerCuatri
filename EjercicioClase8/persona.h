#ifndef FUNCIONESCARGAPERS_H_INCLUDED
#define FUNCIONESCARGAPERS_H_INCLUDED
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


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int cantidad);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni);

void alta(ePersona[],int);
#endif // FUNCIONESCARGAPERS_H_INCLUDED
