#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[64];
    int cantidad;
    printf("Ingrese nombre: ");
    fgets(buffer,sizeof(buffer)-2,stdin); //le resto 2 por que sizeof(buffer) lee los bytes o caracteres de buffer, va a leer 64, le resto \0 y \n

    cantidad = strlen(buffer); //devuelve la cantidad de caracteres a la variable cantidad

    buffer[cantidad-1] = '\0'; //le resto 1 para posicionarse antes del \0, luego almacena en esa posicion el \n

    printf("%s", buffer);

    return 0;
}
