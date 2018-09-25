#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

typedef struct{
    int id;
    char apellido[51];
    char nombre[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;

int buscarPorId(eEmpleado emp[],int CANT,int idAux);
int obtenerEspacioLibre(eEmpleado emp[],int CANT);
void alta(eEmpleado emp[],int CANT);
void baja(eEmpleado emp[],int CANT);
void ordenarLista(eEmpleado emp[],int CANT);
int init(eEmpleado emp[],int CANT);
#endif // EMPLOYEE_H_INCLUDED
