#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char nombre[15];
    char apellido[15];
    char apeNom[30];
    int cantidad,i;
    printf("Ingrese nombre: ");
    fgets(nombre,sizeof(nombre)-2,stdin);
    cantidad = strlen(nombre);
    nombre[cantidad-1] = '\0';
    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);

    printf("Ingrese apellido: ");
    fgets(apellido,sizeof(apellido)-2,stdin); //le resta el ultimo \0 que es donde termina el nombre y el \n que es el enter que se le da para pasar a la siguiente linea
    cantidad = strlen(apellido);
    apellido[cantidad-1] = '\0';
    strlwr(apellido);
    apellido[0]=toupper(apellido[0]);
    for(i=0;i<cantidad;i++){ //recorro el vector con la cantidad de indices del vector
        if(nombre[i]==' '&&nombre[i+1]!='\0'){ //si i es igual a espacio y el que le sigue es distinto de '\0'
            nombre[i+1]=toupper(nombre[i+1]);
        }
        if(apellido[i]==' '&&nombre[i+1]!='\0'){
            apellido[i+1]=toupper(apellido[i+1]);
        }
    }


    strcpy(apeNom,apellido); //al vector apeNom le almaceno apellido
    //apeNom[0]='\0'; //por que si concateno como esta, va a concatenar basura + luego del \0 que encuentre
    //strcat (apeNom,apellido);   |
    //strcat (apeNom," ");        |-------> puedo usar esta o la que no esta comentada para concatenar
    //strcat (apeNom,nombre);     |
    strcat (apeNom," "); //concateno un espacio
    strcat (apeNom,nombre); //concateno el nombre



    printf("Su apellido y nombre es: %s",apeNom);

    return 0;
}
