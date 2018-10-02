#include <stdio.h>
#include <stdlib.h>
#define CANT_EMP 2
#define CANT_ALM 4
#define CANT_PAIS 3
typedef struct{
    int dia, mes, anio;
}eFecha;

typedef struct{
    long int dni;
    char nombre[31];
    char apellido[31];
    eFecha feNac;
    int idPais;
    int isEmpty;
}ePersona;

typedef struct{
    int id;
    char descripcion[31];
    int isEmpty;
}ePais;

typedef struct{
    int id;
    char descripcion[31];
}eAlmuerzo;

typedef struct{
    long int idPersona;
    int idAlmuerzo;
    int isEmpty;
}ePersonaAlmuerzo;

int main()
{
    ePersona pers[2] = {
                        {30000000, "Juan", "Perez", 1,1,1980,1,0},
                        {31000000, "Jose", "Araoz", 2,2,1990,3,0}
                        };
    ePais paises[3]={
                    {1, "Argentina",0},
                    {2, "Peru",0},
                    {3, "Brasil",0}
                    };

    eAlmuerzo alm[4]={
                    {1, "Milanesa"},
                    {2, "Sopa"},
                    {3, "Pizza"},
                    {4, "Empanadas"}
                    };
    ePersonaAlmuerzo perAlm[2]={
                                {30000000,4,0},
                                {30000000,3,0},
                                };

    int i, j,k;

    /*for(i=0; i<2;i++){
        for(j=0; j<3; j++){
            if(pers[i].idPais == paises[j].id){
                printf("%s\t%s\n", pers[i].nombre, paises[j].descripcion);
                break;
            }
        }
    }*/
    for(i=0; i<2;i++){
        for(j=0; j<2*4; j++){
            if(pers[i].dni == perAlm[j].idPersona){
                    for(k=0; k<4; k++){
                        if(perAlm[j].idAlmuerzo == alm[k].id){
                            printf("%s\t%s\n", pers[i].nombre, alm[k].descripcion);
                            break;
                        }
                    }
            }
        }
    }
    return 0;
}
