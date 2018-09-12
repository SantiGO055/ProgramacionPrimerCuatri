#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[10];

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%[^\n]",nombre); //[^\n] va a tomar todo menos el enter
    //strcpy(nombre, );
    printf("%s",nombre);



    return 0;
}
