#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;

    do {
        printf("Ingrese Edad: ");
        scanf("%d",&edad);
        }
    while(edad<0||edad>100);

    return 0;
}
