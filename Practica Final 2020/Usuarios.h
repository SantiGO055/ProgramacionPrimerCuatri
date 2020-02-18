#ifndef Usuarios_H_INCLUDED
#define Usuarios_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char email[128];
    char sexo[128];
    char pais[128];
    char password[128];
    char ip_address[128];
}Usuarios;

typedef struct
{
    int id;
    char nombre_tema[128];
    char artista[128];
    int contadorEscuchados;
}Temas;

Usuarios* eUsuarios_new();
Usuarios* eUsuarios_newParametros(char* idStr,char* nombreStr,char* emailStr,
                                  char* sexoStr,char* paisStr,char* passwordStr,char* ipAddressStr);
void Usuarios_delete();

Temas* eTemas_new();
Temas* eTemas_newParametros(char* idStr, char* nombre_temaStr, char* artistaStr);

int Usuarios_setId(Usuarios* this,int id);
int Usuarios_getId(Usuarios* this,int* id);

int Usuarios_setNombre(Usuarios* this,char* nombre);
int Usuarios_getNombre(Usuarios* this,char* nombre);

int Usuarios_setEmail(Usuarios* this,char* email);
int Usuarios_getEmail(Usuarios* this,char* email);

int Usuarios_setSexo(Usuarios* this,char* sexo);
int Usuarios_getSexo(Usuarios* this,char* sexo);

int Usuarios_setPais(Usuarios* this,char* pais);
int Usuarios_getPais(Usuarios* this,char* pais);

int Usuarios_setPassword(Usuarios* this,char* password);
int Usuarios_getPassword(Usuarios* this,char* password);

int Usuarios_setIpAddress(Usuarios* this,char* ip_address);
int Usuarios_getIpAddress(Usuarios* this,char* ip_address);

int temas_getId(Temas* this,int* id);

void  Usuarios_showUsuario(Usuarios* this);
void  Usuarios_showUsuarios(Usuarios* this);

void  temas_showTema(Temas* this);
void  temas_showTemas(Temas* this);

int Usuarios_sortByName(void* empleadoA, void* empleadoB);
int Usuarios_sortByNac(void* empleadoA, void* empleadoB);

#endif // Usuarios_H_INCLUDED
