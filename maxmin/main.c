#include <stdio.h>
#include <stdlib.h>
#define ESC 27
int main()
{
    char seguir;
    int numero, max, min,flag=0;
    do{
        system("cls");
        printf(" Ingrese numero: ");
        scanf("%d",&numero);
        /*
        if(flag==0){
            max=numero;
            min=numero;
            flag=1;
        }
        if(numero>max){
            max=numero;
        }
        if(numero<min){
            min=numero;
            }*/
        //variante de maximo y minimo
        if (flag==0||numero>max){
            max=numero;
        }
        if(flag==0||numero<min){
            min=numero;
            flag=1;
        }

        printf("Presione ESC para salir, cualquier otra tecla para continuar");
        seguir=getch();
    }
    while(seguir!=ESC);
    system("cls");
    printf("Mayor: %d\nMenor: %d",max,min);

    return 0;
}
