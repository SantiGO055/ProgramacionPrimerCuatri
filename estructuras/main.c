#include <stdio.h>
#include <stdlib.h>
#define CANT 3

//se usa la manera de arriba o la manera de abajo, es lo mismo
struct eEmpleado{
	int legajo; //datos miembro o campo
	char nombre[31]; //datos miembro o campo
	float salario; //datos miembro o campo
	int isEmpty; //datos miembro o campo
};
int main()
{
    struct eEmpleado emple[CANT];
    int i;
    for(i=0;i<CANT;i++){
        printf("Legajo:\n");
        scanf("%d", &emple[i].legajo);
        printf("Nombre:\n");
        fflush(stdin);
        scanf("%s", emple[i].nombre);
        printf("Salario:\n");
        scanf("%f", &emple[i].salario);

        emple[i].isEmpty = 0;
        system("cls");
    }
    system("cls");
    for(i=0;i<CANT;i++){
        printf("Legajo: %d\nNombre: %s\nSalario: %.02f\n",emple[i].legajo,emple[i].nombre,emple[i].salario);
    }


    //emple.isEmpty=0;
    return 0;
}
