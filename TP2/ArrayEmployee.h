#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}employee;


int initEmployee(employee* ,int CANT);
int getFreeSpace(employee* ,int CANT);
int addEmployee(employee* ,int CANT,char* name, char* lastName, float salary,int sector,int id);
int findEmployeeById(employee* ,int CANT, int id);
int removeEmployee(employee* ,int CANT,int id);
int sortEmployee(employee* ,int CANT, char name[], char lastName[]);
int printEmployee(employee* ,int CANT);
int firstEmployee(int flag);
void modifyEmployee(employee *emp,int CANT,char* name, char* lastName, float salary,int sector,int id);
int validarCadena(char* ,int min, int max);

#endif // EMPLOYEE_H_INCLUDED
